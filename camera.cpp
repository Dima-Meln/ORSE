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


#include "camera.h"

Camera::Camera() {

}

Camera::~Camera() {

}
bool Camera::create(string name) {
  // Create the camera
  m_Camera = m_SceneMgr->createCamera(name);

  // Position it at 500 in Z direction
  //m_Camera->setPosition(Ogre::Vector3(0,0,80));
  // Look back along -Z
  //m_Camera->lookAt(Ogre::Vector3(0,0,-300));
  m_Camera->setNearClipDistance(5);

  //m_CameraMan = new OgreBites::SdkCameraMan(m_Camera);   // create a default camera controller
}
Ogre::Camera& Camera::getSingleton() {
  return &m_Camera;
}
Ogre::Camera* Camera::getSingletonPtr() {
  return *m_Camera;
}