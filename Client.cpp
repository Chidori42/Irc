/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:15:37 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 09:22:01 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"


Client::Client() : fd(0){
    std::cout << "Client Constructor Called" << std::endl;
}
Client::~Client(){
    std::cout << "Client Destructor Called" << std::endl;
}
Client::Client(Client const& other){
    this->fd = other.fd;
    this->ip = other.ip;
}
Client &Client::operator=(Client const& other){
    if (this != &other)
    {
        this->fd = other.fd;
        this->ip = other.ip;
    }
    return (*this);
}
int Client::Get_fd(){
    return (this->fd);
}
void Client::Set_fd(int fd){
    this->fd = fd;
}
std::string Client::Get_ip(){
    return (this->ip);
}
void Client::Set_ip(std::string ip){
    this->ip = ip;
}