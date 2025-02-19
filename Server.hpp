/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:36 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 17:57:16 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPPHPP

# include <iostream>
#include <netinet/in.h>  // For sockaddr_in and INADDR_ANY
#include <arpa/inet.h>   // For htons function
#include <cstring>    
#include <vector>
#include <poll.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
 #include <sys/socket.h>
#include "Client.hpp"

class Server{
    private:
        int fd;
        int port;
        std::string password;
        std::vector<Client> Clients;
    public:
        Server();
        ~Server();

        Server(Server const &other);
        Server& operator=(Server const &other);

        int Get_port();
        void Set_port(int p);
        
        int Get_fd();
        void Set_fd(int fd);

        std::string Get_password();
        void Set_password(std::string p);
        
        bool bindSocket();
        bool acceptConnections();
};

#endif