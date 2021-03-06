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


#ifndef AUDIO_H
#define AUDIO_H

#include <sys/types.h>

#include "common.h"

BeginNamespace;
namespace Config {

enum chenels {
  mono,
  stereo,
  n5_1
};

class Audio {
  public:
    Audio();
    virtual ~Audio();
    void setVolume(uint volume);
    uint getVolume();
    void setChenels(int);//mono or stereo or 5.1
};

}
EndNamespace;
#endif // SOUND_H
