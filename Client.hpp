/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:11:57 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 09:20:59 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client{
    private:
        int fd;
        std::string ip;
    public:
        Client();
        ~Client();
        Client(Client const& other);

        Client &operator=(Client const& other);

        int Get_fd();
        void Set_fd(int fd);

        std::string Get_ip();
        void Set_ip( std::string ip);
};






#endif