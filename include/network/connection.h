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


#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>
#include <sys/types.h>

#include "auth.h"

#include "common.h"

class connection {
  public:
    connection();
    connection(const connection&);
    virtual ~connection();
    void setAuth(auth& auth);
    bool connect(string server, uint port);
    bool reed(string text);
    bool write(string text);

    //ioPtr* get_io_ptr();
};

#endif // CONNECTION_H
