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


#ifndef ENTITY_H
#define ENTITY_H

#include <Ogre/Entity.h>
#include <Ogre/Mesh>

#include <string>
#include <memory>

#include "physics/mesh_phys_info.h"/*?*/
#include "common.h"

BeginNamespace;

class Entity :public Ogre::Entity {
  public:
    Entity(string Name);
    Entity(string Name, string MeshFile);
    Entity(string Name, string MeshFile, mesh_phys_info_t MeshPhysInfo);
    ~Entity();
    
    addOgreMesh(Ogre::Mesh OgreMesh);
    addPhysInfo(_);
  private:
    std::shared_ptr<Ogre::Entity> m_OgreEntity;
};

EndNamespace;

#endif // ENTITY_H
