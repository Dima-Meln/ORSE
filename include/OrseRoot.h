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


#ifndef ROOT_H
#define ROOT_H

#include <OrsePreRequisites.h>

#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSingleton.h>
#include <OgreString.h>

#include <OISInputManager.h>

#include "sound/OgreOggSoundManager.h"

#include "OrseInputManager.h"
#include "OrsePhysicsManager.h"

#include <memory>
#include <string>

#include <OrseWorld.h>

using namespace std;

namespace Orse { class Root; }
template class _ORSE_Export
Ogre::Singleton<Orse::Root>;

namespace Orse {
class _ORSE_Export Root : public Ogre::Singleton<Root> {
  public:
    Root();
    //Root( const Root& ) { }
    //Root & operator = ( const Root& );
    virtual ~Root();

    OIS::InputManager* createInputSystem(Ogre::RenderWindow* Window);
    
    PhysicsManager* createPhysicsMgr(const Ogre::String& intenseName, bool init);
    /*template <typename TWorld>
    PhysicsManager* createPhysicsMgr(string intenseName, bool init);*/
    PhysicsManager* getPhysicsMgr(const string& intenseName) {return m_PhysMgrs[intenseName];}
    
   // OgreOggSound::OgreOggSoundManager* getSoundMgr() {return m_SoundMgr;}
    
    World* createWorld(string intenseName);
    World* getWorld(string intenseName) {return m_Worlds[intenseName];}

    static Root& getSingleton(void);
    static Root* getSingletonPtr(void);
  private:
   // OgreOggSound::OgreOggSoundManager* m_SoundMgr;
    
    typedef map<string, PhysicsManager*> PhysMgrs_t;
    PhysMgrs_t m_PhysMgrs;
    typedef map<string, World*> Worlds_t;
    Worlds_t m_Worlds;
};
}

#endif // ROOT_H

