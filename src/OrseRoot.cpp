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


#include "OrseRoot.h"
#include <sound/OgreOggSoundManager.h>

namespace Orse { class Root; }
template<> _ORSE_Export Orse::Root* 
Ogre::Singleton<Orse::Root>::ms_Singleton = 0;

namespace Orse {
Root::Root() /*m_SoundMgr(new OgreOggSound::OgreOggSoundManager())*/ {}
Root::~Root() {

}
OIS::InputManager* Root::createInputSystem(Ogre::RenderWindow* Window) {
  OIS::ParamList pl;
  size_t windowHnd = 0;
  std::ostringstream windowHndStr;
  Window->getCustomAttribute("WINDOW", &windowHnd);
  windowHndStr << windowHnd;
  pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
  return OIS::InputManager::createInputSystem(pl);
}
PhysicsManager* Root::createPhysicsMgr(const Ogre::String& intenseName, bool init) {
  PhysicsManager* PM = new PhysicsManager();
  m_PhysMgrs[ intenseName ] = PM;
  if(init) {PM->_init();}
  return PM;
}
/*template <typename TWorld>
PhysicsManager* Root::createPhysicsMgr(string intenseName, bool init) {
  PhysicsManager* PM = new PhysicsManager();
  m_PhysMgrs[intenseName] = PM;
  if(init) {PM->_init();}
  return PM;
}*/

World* Root::createWorld(string intenseName) {
  World* wd = new World();
  m_Worlds[ intenseName ] = wd;
  return wd;
}

Root& Root::getSingleton(void) {
#if OGRE_VERSION_MAJOR == 1 && OGRE_VERSION_MINOR <= 7
  if(!ms_Singleton)
#else
  if(!msSingleton)
#endif
#if OGRE_VERSION_MAJOR == 1 && OGRE_VERSION_MINOR <= 7
  assert(ms_Singleton);
  return (*ms_Singleton);
#else
  assert(msSingleton);
  return (*msSingleton);
#endif
}
Root* Root::getSingletonPtr(void) {
#if OGRE_VERSION_MAJOR == 1 && OGRE_VERSION_MINOR <= 7
  return ms_Singleton;
#else
  return msSingleton;
#endif
}
}

