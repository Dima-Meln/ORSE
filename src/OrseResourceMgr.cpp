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


#include "OrseResourceMgr.h"

namespace Orse {

ResourceMgr::ResourceMgr() {

}
ResourceMgr::ResourceMgr(const ResourceMgr& other) {}
ResourceMgr::~ResourceMgr() {

}
void ResourceMgr::addLocation(string path, string group, string type) const {
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path, type, group);
}
void ResourceMgr::setup(Ogre::String file) {
  // Load resource paths from config file
  Ogre::ConfigFile cf;
  cf.load(file);

  // Go through all sections & settings in the file
  Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

  Ogre::String secName, typeName, archName;
  while(seci.hasMoreElements()) {
    secName = seci.peekNextKey();
    Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
    Ogre::ConfigFile::SettingsMultiMap::iterator i;
    for(i = settings->begin(); i != settings->end(); ++i) {
      typeName = i->first;
      archName = i->second;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
        archName, typeName, secName);
    }
  }
    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    // setup default group for validation schemas
    /*CEGUI::XMLParser* parser = CEGUI::System::getSingleton().getXMLParser();
    if(parser->isPropertyPresent("SchemaDefaultResourceGroup"))
      parser->setProperty("SchemaDefaultResourceGroup", "schemas");*/
}
/* some bugs(
void ResourceMgr::setup() {
  //setup Ogre resources
  media[0] = "./media";
  media[1] = "./media/models";
  media[2] = "./media/materials/textures";
  media[3] = "./media/materials/scripts";
  media[4] = "./media/materials/shaders";
  for_each(media.begin(), media.end(),boost::bind(&ResourceMgr::add_loc,*this, _2));
}*/
void ResourceMgr::load() {
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
}
