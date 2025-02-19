/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:31 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/02/19 09:23:56 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Irc.hpp"


Irc::Irc() :port(0){
    std::cout << "Irc Constructor Called" << std::endl;
}
Irc::~Irc(){
    std::cout << "Irc Dostructor Called" << std::endl;
}

Irc::Irc(Irc const &other){
    this->port = other.port;
    this->password = other.password;
}
Irc& Irc::operator=(Irc const &other){
    if (this != &other)
    {
        this->port = other.port;
        this->password = other.password;
    }
    return (*this);
}

int Irc::Get_port(){
    return (this->port);
}
void Irc::Set_port(int p){
    this->port = p;
}

std::string Irc::Get_password(){
    return (this->password);
}
void Irc::Set_password(std::string p){
    this->password = p;
}
