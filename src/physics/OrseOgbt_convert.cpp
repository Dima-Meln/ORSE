/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Dmitro Melnichuk <email>

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


#include "physics/OrseOgbt_convert.h"

btVector3 ogbt_convert(const Ogre::Vector3& vec) {return btVector3(vec.x, vec.y, vec.z);}
Ogre::Vector3 ogbt_convert(btVector3& vec) {return Ogre::Vector3(vec.x(), vec.y(), vec.z());}
Ogre::Quaternion ogbt_convert(btQuaternion& Q) {return Ogre::Quaternion(Q.w(), Q.x(), Q.y(), Q.z());}
Ogre::Quaternion ogbt_convert(btQuaternion Q) {return Ogre::Quaternion(Q.w(), Q.x(), Q.y(), Q.z());}
btQuaternion ogbt_convert(const Ogre::Quaternion& Q) {return btQuaternion(Q.x, Q.y, Q.z, Q.w);}
