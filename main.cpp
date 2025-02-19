/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:50:39 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 16:59:46 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int ac, char **av)
{
    Server pr;

    if (ac != 3)
    {
        std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }
    pr.Set_port(std::atoi(av[1]));
    pr.Set_password(av[2]);
    
    pr.Set_fd(socket(AF_INET, SOCK_STREAM, 0)); //Set the family to AF_INET (IPv4), the type to SOCK_STREAM (TCP), and the protocol to 0 (IP)
    if (pr.Get_fd() == -1)
    {
        std::cerr << "Error: socket creation failed" << std::endl;
        return 1;
    }
    // Bind the socket to the port
    if (!pr.bindSocket())
        return 1;
    if (listen(pr.Get_fd(), 10) == -1)
    {
        std::cerr << "Error: listen failed" << std::endl;
        return 1;
    }
    //accept incoming connections
    if (!pr.acceptConnections())
        return 1;
    return 0;
}