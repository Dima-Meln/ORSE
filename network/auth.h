/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef AUTH_H
#define AUTH_H

#include <boost/asio.hpp>

using namespace boost;

class auth {
  public:
    auth();
    auth(const auth& other);
    virtual ~auth();
    
    bool connFacebook(string login, string pass);
    bool connServer(string host, uint32_t port);
    
  private:
    asio::io_service m_ioservice;
    asio::ip::address m_address;
    asio::ip::tcp m_tcp;
    asio::socket_acceptor_service<> m_socket;
};

#endif // AUTH_H
