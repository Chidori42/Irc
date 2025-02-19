/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:36 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 09:28:00 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_HPP
# define IRC_HPP

# include <iostream>
#include <vector>
#include <cstdlib>
#include "Client.hpp"

class Irc{
    private:
        int port;
        std::string password;
        std::vector<Client> Clients;
    public:
        Irc();
        ~Irc();

        Irc(Irc const &other);
        Irc& operator=(Irc const &other);

        int Get_port();
        void Set_port(int p);

        std::string Get_password();
        void Set_password(std::string p);
};

#endif