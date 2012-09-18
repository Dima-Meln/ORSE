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


#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <OgrePrerequisites.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <BulletDynamics/Dynamics/btRigidBody.h>

#include "MeshToShapeConverter.h"
#include "OrseMotionState.h"

struct RigidBodyInfo;

class RigidBody {
  public:
    RigidBody();
    ~RigidBody();
    
    void setNode(Ogre::SceneNode* node);
    void setEntity(Ogre::Entity* ent);
    void setConstructionInfo(RigidBodyInfo* info);
    
    btRigidBody* getbtRigidBody() const {return m_btRigidBody;}
    Ogre::SceneNode* getSceneNode() const {return m_Node;}
    Ogre::Entity* getEntity() const {return m_Entity;}
    
    Ogre::Vector3 oldPhysPosition;
    Ogre::Quaternion oldPhysOrientation;
  private:
    btRigidBody* m_btRigidBody;
    btCollisionShape* m_Shape;
    Ogre::SceneNode* m_Node;
    Ogre::Entity* m_Entity;
    PhysMotionState* m_MotionState;
    
    RigidBodyInfo* m_info;
    btRigidBody::btRigidBodyConstructionInfo* m_btInfo;
    
    AnimatedMeshToShapeConverter* m_AnimatedConverter;
    StaticMeshToShapeConverter* m_StaticConverter;
};

struct RigidBodyInfo {
  Ogre::Real mass;
  Ogre::Vector3 localInertia;
  Ogre::Real linearDamping;
  Ogre::Real angularDamping;
  Ogre::Real friction;
  Ogre::Real restitution;
  Ogre::Real linearSleepingThreshold;
  Ogre::Real angularSleepingThreshold;
  bool additionalDamping;
  Ogre::Real additionalDampingFactor;
  Ogre::Real additionalLinearDampingThresholdSqr;
  Ogre::Real additionalAngularDampingThresholdSqr;
  Ogre::Real additionalAngularDampingFactor;
};

#endif // RIGIDBODY_H
