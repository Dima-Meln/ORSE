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


#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <map>
#include <boost/signals2.hpp>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMovableObject.h>
#include <boost/signals2.hpp>
#include "physics/OrseRigidBody.h"

using namespace boost;
using namespace std;
class GameObject {
  public:
    /**
     * geometry
     * phisics
     * conn sounds
     * events with boost_signals2
     */
    GameObject();
    ~GameObject();
    
    //void serialize();//from some file or internet
    
    //void setEvents(...);
    /**
     * @Event list
     *   Collide(Ogre::Vector3 coll_pos, Ogre::Quaternion coll_ornt, GameObject collided_with)
     */
    Ogre::SceneNode* getSceneNode();
    
    ///Sound
    void playSound(/*sound*/);
    void pauseSound(/*sound*/);
    void stopSound(/*sound*/);
    ///Events
    //signals2::signal<void (Ogre::Vector3 coll_pos, Ogre::Quaternion coll_ornt, GameObject collided_with)> onCollide();
    
    virtual void onCollide(Ogre::Vector3 coll_pos, Ogre::Quaternion coll_ornt, GameObject* collided_with);
  private:
    Ogre::SceneNode* m_RootNode;
  protected:   
    void _setSceneNode(Ogre::SceneNode* nod);
    void _setPhysInfo(RigidBodyInfo* physInfo);
    
    Ogre::SceneNode* _getSceneNode() {return m_RootNode;}
};

#endif // GAMEOBJECT_H
