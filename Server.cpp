/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:31 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 18:14:47 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(){
    this->port = 0;
    this->fd = 0;
    std::cout << "Server Constructor Called" << std::endl;
}
Server::~Server(){
    std::cout << "Server Dostructor Called" << std::endl;
}

Server::Server(Server const &other){
    this->port = other.port;
    this->password = other.password;
    this->Clients = other.Clients;
}
Server& Server::operator=(Server const &other){
    if (this != &other)
    {
        this->port = other.port;
        this->password = other.password;
        this->Clients = other.Clients;
    }
    return (*this);
}

int Server::Get_port(){
    return (this->port);
}
void Server::Set_port(int p){
    this->port = p;
}

int Server::Get_fd(){
    return (this->fd);
}
void Server::Set_fd(int fd){
    this->fd = fd;
}

std::string Server::Get_password(){
    return (this->password);
}
void Server::Set_password(std::string p){
    this->password = p;
}

bool Server::bindSocket(){
    struct sockaddr_in addr;
    int opt = 1;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(this->port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        std::cerr << "Error: setsockopt failed" << std::endl;
        return false;
    }
    if (bind(this->fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Error: bind failed" << std::endl;
        return false;
    }
    return true;
}

bool Server::acceptConnections() {
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);
    int new_socket;
    char buffer[1024] = {0};

    while (true) {
        new_socket = accept(this->fd, (struct sockaddr *)&addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            std::cerr << "Error: accept failed" << std::endl;
            return false;
        }

        std::cout << "Connection accepted cliend id = " << new_socket << std::endl;
        int bytes_read = recv(new_socket, buffer, 1024, 0);
        if (bytes_read < 0) {
            std::cerr << "Error: read failed" << std::endl;
            close(new_socket);
            continue; 
        }

        if (bytes_read == 0) {
            std::cout << "Client disconnected" << std::endl;
            close(new_socket);
            continue;
        }

        std::cout << "Received message: " << buffer << std::endl;
        close(new_socket);
    }

    return true;
}

