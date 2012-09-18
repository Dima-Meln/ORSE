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


#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

#include <OgreResourceGroupManager.h>
#include <OgreConfigFile.h>
#include <algorithm>
#include <boost/bind.hpp>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUIDefaultResourceProvider.h>
#include <CEGUI/CEGUIXMLParser.h>
#include <CEGUI/CEGUI.h>

using namespace std;

namespace Orse {
class ResourceMgr { /*:public Ogre::Singleton<ResourceMgr>*/
  public:
    ResourceMgr();
    ResourceMgr(const ResourceMgr& other);
    virtual ~ResourceMgr();
    /**
     * @param path
     * @param type FileSystem, Zip
     * @param group
     */
    void addLocation(string path, string group = "General", string type = "FileSystem") const;
    void setup(Ogre::String file);
    void setup();
    void load();
  private:
    vector<Ogre::String> media;
};
}

#endif // RESOURCEMGR_H
