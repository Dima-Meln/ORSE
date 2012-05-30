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

#include "video.h"

BeginNamespace;
namespace Config {

Video::Video()
{

}

Video::~Video()
{

}
void Video::showConfigDialog() {
  // Show the configuration dialog and initialise the system
  // You can skip this and use root.restoreConfig() to load configuration
  // settings if you were sure there are valid ones saved in ogre.cfg
  if(mRoot->showConfigDialog()) {
     // If returned true, user clicked OK so initialise
     // Here we choose to let the system create a default rendering window by passing 'true'
     mWindow = m_Root->initialise(true, "TutorialApplication Render Window");
     return true;
  } else {
     return false;
  }
}

Video::setRender() {
  Ogre::RenderSystem *rs = m_OgreRoot->getRenderSystemByName("OpenGL Rendering Subsystem");
}

}
EndNamespace;
