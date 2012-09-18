/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  alosha <email>

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


#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISJoyStick.h>
//#include <OISMultiTouch.h>
#include <OISInputManager.h>
 
#include <OgreRenderWindow.h>

using namespace std;

namespace Orse {
class InputManager : public OIS::KeyListener, 
		     public OIS::MouseListener, 
		     public OIS::JoyStickListener
		     //OIS::MultiTouchListener 
		     {
  public:
    virtual ~InputManager( void );
 
    void initialise( Ogre::RenderWindow *renderWindow );
    void capture( void );
 
    void addKeyListener( OIS::KeyListener *keyListener, const std::string& instanceName );
    void addMouseListener( OIS::MouseListener *mouseListener, const std::string& instanceName );
    void addJoystickListener( OIS::JoyStickListener *joystickListener, const std::string& instanceName );
    void addMultiTouchListener( OIS::MultiTouchListener *MultiTouchListener, const std::string& instanceName );
 
    void removeKeyListener( const std::string& instanceName );
    void removeMouseListener( const std::string& instanceName );
    void removeJoystickListener( const std::string& instanceName );
    //void removeMultiTouchListener( const std::string& instanceName );
 
    void removeKeyListener( OIS::KeyListener *keyListener );
    void removeMouseListener( OIS::MouseListener *mouseListener );
    void removeJoystickListener( OIS::JoyStickListener *joystickListener );
    //void removeMultiTouchListener( OIS::MultiTouchListener *MultiTouchListener );
 
    void removeAllListeners( void );
    void removeAllKeyListeners( void );
    void removeAllMouseListeners( void );
    void removeAllJoystickListeners( void );
    //void removeAllMultiTouchListeners( void );
 
    void setWindowExtents( int width, int height );
 
    OIS::Mouse*    getMouse( void );
    OIS::Keyboard* getKeyboard( void );
    OIS::JoyStick* getJoystick( unsigned int index );
    //OIS::MultiTouch* getMultiTouch( void );
 
    int getNumOfJoysticks( void );
 
    static InputManager* getSingletonPtr( void );
  private:
    InputManager( void );
    InputManager( const InputManager& ) { }
    InputManager & operator = ( const InputManager& );
 
    bool keyPressed( const OIS::KeyEvent &e );
    bool keyReleased( const OIS::KeyEvent &e );
 
    bool mouseMoved( const OIS::MouseEvent &e );
    bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );
 
    bool povMoved( const OIS::JoyStickEvent &e, int pov );
    bool axisMoved( const OIS::JoyStickEvent &e, int axis );
    bool sliderMoved( const OIS::JoyStickEvent &e, int sliderID );
    bool buttonPressed( const OIS::JoyStickEvent &e, int button );
    bool buttonReleased( const OIS::JoyStickEvent &e, int button );
    
    /*bool touchMoved( const OIS::MultiTouchEvent &e );
    bool touchPressed( const OIS::MultiTouchEvent &e );
    bool touchReleased( const OIS::MultiTouchEvent &e );
    bool touchCancelled( const OIS::MultiTouchEvent &e );*/
 
    OIS::Mouse        *mMouse;
    OIS::Keyboard     *mKeyboard;
    //OIS::MultiTouch   *mMultiTouch;
    OIS::InputManager *mInputSystem;
    
    std::vector<OIS::JoyStick*> mJoysticks;
    std::vector<OIS::JoyStick*>::iterator itJoystick;
    std::vector<OIS::JoyStick*>::iterator itJoystickEnd;
 
    std::map<std::string, OIS::KeyListener*> mKeyListeners;
    std::map<std::string, OIS::MouseListener*> mMouseListeners;
    std::map<std::string, OIS::JoyStickListener*> mJoystickListeners;
    //std::map<std::string, OIS::MultiTouchListener*> mMultiTouchListeners;
 
    std::map<std::string, OIS::KeyListener*>::iterator itKeyListener;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListener;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListener;
    //std::map<std::string, OIS::MultiTouchListener*>::iterator itMultiTouchListener;
 
    std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListenerEnd;
    //std::map<std::string, OIS::MultiTouchListener*>::iterator itMultiTouchListenerEnd;
 
    static InputManager *mInputManager;
};
}

#endif // INPUTMANAGER_H

