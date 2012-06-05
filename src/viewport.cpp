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


#include "viewport.h"

ViewPort::ViewPort() {
  
}
ViewPort::~ViewPort() {
  
}
void ViewPort::create() {
  // Create one viewport, entire window
  Ogre::Viewport* vp = Window::getSingletonPtr()->addViewport(Camera::getSingleton());
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

  // Alter the camera aspect ratio to match the viewport
  Camera::getSingletonPtr()->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}