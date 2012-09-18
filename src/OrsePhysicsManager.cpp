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


#include "OrsePhysicsManager.h"

PhysicsManager::PhysicsManager() {
  btDefaultCollisionConfiguration* config = new btDefaultCollisionConfiguration();
  setCollisionConfiguration(config);
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(m_CollConf);
  setDispatcher(dispatcher);
  btBroadphaseInterface* broadphase = new btDbvtBroadphase();
  setBroadphaseInterface(broadphase);
  btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
  setSolver(solver);
}

PhysicsManager::PhysicsManager(const PhysicsManager& other)
{

}

PhysicsManager::~PhysicsManager() {
    delete m_World;
}
/*
PhysicsManager& PhysicsManager::operator=(const PhysicsManager& other)
{
    return *this;
}

bool PhysicsManager::operator==(const PhysicsManager& other) const
{
///TODO: return ...;
}*/
void PhysicsManager::stepSimulation(float elapsedTime) {
  static_cast<btDiscreteDynamicsWorld*>(m_World)->stepSimulation(elapsedTime);
  
  m_World->debugDrawWorld();
}
void PhysicsManager::_init() {
  btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(m_Dispatcher,m_BroadphaseInterface,m_Solver,m_CollConf);
  this->setDynamicsWorld(dynamicsWorld);
}
RigidBody* PhysicsManager::createRigidBody() {
  RigidBody* rigBod = new RigidBody();
  //m_World->addRigidBody(rigBod);
  //m_RigidBodies[name] = rigBod;
  return rigBod;
}
RigidBody* PhysicsManager::createRigidBody(RigidBodyInfo* rbInfo) {
  RigidBody* rigBod = new RigidBody();
  rigBod->setConstructionInfo(rbInfo);
  return rigBod;
}
RigidBody* PhysicsManager::createRigidBody(Ogre::SceneNode* node, Ogre::Entity* ent, RigidBodyInfo* rbInfo) {
  RigidBody* rigBod = new RigidBody();
  rigBod->setConstructionInfo(rbInfo);
  rigBod->setNode(node);
  rigBod->setEntity(ent);
  return rigBod;
}
RigidBody* PhysicsManager::createRigidBody(const string name, Ogre::SceneNode* node, Ogre::Entity* ent, RigidBodyInfo* rbInfo) {
  RigidBody* rigBod = new RigidBody();
  rigBod->setConstructionInfo(rbInfo);
  rigBod->setNode(node);
  rigBod->setEntity(ent);
    static_cast<btDiscreteDynamicsWorld*>(m_World)->addRigidBody(rigBod->getbtRigidBody());
    m_RigidBodies[name] = rigBod;
  return rigBod;
}
void PhysicsManager::addRigidBody(const string name, RigidBody* bod) {
  static_cast<btDiscreteDynamicsWorld*>(m_World)->addRigidBody(bod->getbtRigidBody());
  m_RigidBodies[name] = bod;
}
/*
template <typename TWorld>
void PhysicsManager::createDynamicsWorld(void) {
  m_World = new TWorld(m_Dispatcher, m_BroadphaseInterface, m_Solver, m_CollConf);
}
template <typename TDispatcher>
void PhysicsManager::createDispatcher(void) {}
template <typename TBroadphaseInterface>
void PhysicsManager::createBroadphaseInterface(void) {}
template <typename TSolver>
void PhysicsManager::createSolver(void) {}
template <typename TCollisionConfiguration>
void PhysicsManager::createCollisionConfiguration(void) {}
*/
void PhysicsManager::setDynamicsWorld(btDynamicsWorld* world) {m_World = world;}
void PhysicsManager::setDispatcher(btDispatcher* dispatcher) {m_Dispatcher = dispatcher;}
void PhysicsManager::setBroadphaseInterface(btBroadphaseInterface* broadphase) {m_BroadphaseInterface = broadphase;}
void PhysicsManager::setSolver(btConstraintSolver* solver) {m_Solver = solver;}
void PhysicsManager::setCollisionConfiguration(btCollisionConfiguration* config) {m_CollConf = config;}
