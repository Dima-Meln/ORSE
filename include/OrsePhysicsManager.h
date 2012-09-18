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


#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <string>

#include <BulletDynamics/btBulletDynamicsCommon.h>
#include "physics/OrseRigidBody.h"
#include "physics/OrseOgbt_convert.h"

using namespace std;

/**
 * PhysicsManager
 */
class PhysicsManager {
  public:
    PhysicsManager();
    PhysicsManager(const PhysicsManager& other);
    virtual ~PhysicsManager();
    //virtual PhysicsManager& operator=(const PhysicsManager& other);
    //virtual bool operator==(const PhysicsManager& other) const;
    
    void stepSimulation(float elapsedTime);
    RigidBody* createRigidBody();
    RigidBody* createRigidBody(RigidBodyInfo* rbInfo);
    RigidBody* createRigidBody(Ogre::SceneNode* node, Ogre::Entity* ent, RigidBodyInfo* rbInfo);
    RigidBody* createRigidBody(const string name, Ogre::SceneNode* node, Ogre::Entity* ent, RigidBodyInfo* rbInfo);
    
    void addRigidBody(const string name, RigidBody* bod);
    /*
    template <typename TWorld>
    void createDynamicsWorld(void);
    template <typename TDispatcher>
    void createDispatcher(void);
    template <typename TBroadphaseInterface>
    void createBroadphaseInterface(void);
    template <typename TSolver>
    void createSolver(void);
    template <typename TCollisionConfiguration>
    void createCollisionConfiguration(void);*/
    
    void setDynamicsWorld(btDynamicsWorld* world);
    void setDispatcher(btDispatcher* dispatcher);
    void setBroadphaseInterface(btBroadphaseInterface* broadphase);
    void setSolver(btConstraintSolver* solver);
    void setCollisionConfiguration(btCollisionConfiguration* config);
    
    btDynamicsWorld* getDynamicsWorld() const {return m_World;}
    RigidBody* getRigidBody(const string name) const {return m_RigidBodies.at(name);}
    
    void _init();
  private:
    btDynamicsWorld* m_World;
    btCollisionConfiguration* m_CollConf;
    btDispatcher* m_Dispatcher;
    btBroadphaseInterface* m_BroadphaseInterface;
    btConstraintSolver* m_Solver;
    
    typedef map<string, RigidBody*> RigidBodies_t;
    RigidBodies_t m_RigidBodies;
};

#endif // PHYSICSMANAGER_H
