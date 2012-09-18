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


#include "../../include/physics/OrseRigidBody.h"
#include <Shapes/OgreBulletCollisionsTrimeshShape.h>

RigidBody::RigidBody():m_StaticConverter(new StaticMeshToShapeConverter()),
			m_AnimatedConverter(new AnimatedMeshToShapeConverter){}
void RigidBody::setNode(Ogre::SceneNode* node) {
  m_Node = node;
  m_MotionState = new PhysMotionState( m_Node);
}
void RigidBody::setEntity(Ogre::Entity* ent) {
  m_Entity = ent;
  if(m_Entity->hasSkeleton()) {
    m_AnimatedConverter->addEntity(m_Entity);
    m_Shape = m_AnimatedConverter->createConvex();
  } else {
    m_StaticConverter->addEntity(m_Entity);
    m_Shape = m_StaticConverter->createConvex();
  }
  
  btVector3 locInert;
  m_Shape->calculateLocalInertia(m_info->mass,locInert);
  m_btRigidBody = new btRigidBody(m_info->mass,m_MotionState,m_Shape,locInert);
}
void RigidBody::setConstructionInfo(RigidBodyInfo* info) {
  m_info = info;
  /*m_btInfo->m_additionalAngularDampingFactor = info->additionalAngularDampingFactor;
  m_btInfo->m_additionalAngularDampingThresholdSqr = info->additionalAngularDampingThresholdSqr;
  m_btInfo->m_additionalDamping = info->additionalDamping;
  m_btInfo->m_additionalDampingFactor = info->additionalDampingFactor;
  m_btInfo->m_additionalLinearDampingThresholdSqr = info->additionalLinearDampingThresholdSqr;
  m_btInfo->m_angularDamping = info->angularDamping;
  m_btInfo->m_angularSleepingThreshold = info->angularSleepingThreshold;
  m_btInfo->m_friction = info->friction;
  m_btInfo->m_localInertia = info->localInertia;*/
  
}
