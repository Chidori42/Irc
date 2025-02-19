/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:50:39 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/18 12:07:44 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Irc.hpp"

int main(int ac, char **av)
{
    Irc pr;

    if (ac != 3)
    {
        std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }
    pr.Set_port(std::atoi(av[1]));
    pr.Set_password(av[2]);

    std::cout << "port = " << pr.Get_port() << std::endl;
    std::cout << "password = " << pr.Get_password() << std::endl;
    return 0;
}