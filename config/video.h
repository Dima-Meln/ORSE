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


#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <OGRE/OgreRenderSystem.h>

#include "../base.h"
#include "../common.h"

BeginNamespace;
namespace Config {

class Video :private base {
  public:
    Video();
    virtual ~Video();
    
    void showConfigDialog();
    
    void getAvalibleRenders();
    void setRender(string render);
    void setConfigOption(string name,string value);
  private:
    //ogre config vodeo and sdl config vodeo
};

}
EndNamespace
#endif // VIDEO_H
