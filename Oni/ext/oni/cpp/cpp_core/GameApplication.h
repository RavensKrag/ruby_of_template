#ifndef __GameApplication_h_
#define __GameApplication_h_

#include "BaseApplication.h"
//#include <vector>

extern "C"
{
	typedef void (*updateCallback)(double dt, void* data);
	typedef void (*keyDownCallback)(unsigned int key_id, void* ruby_window);
	typedef void (*keyUpCallback)(unsigned int key_id, void* ruby_window);
}


class GameApplication : public BaseApplication
{

public:
    GameApplication(updateCallback update_callback,
					keyDownCallback down_callback, keyUpCallback up_callback);
    virtual ~GameApplication(void);
    
    virtual bool setup(Ogre::String& window_title);
    
	void loadEnv();			// Load the buildings or ground plane, etc.
	void setupEnv();		// Set up the lights, shadows, etc
	void loadObjects();		// Load other props or objects (e.g. furniture)
	void loadCharacters();	// Load actors, agents, characters

	void addTime(Ogre::Real deltaTime);		// update the game state
	
	bool keyPressed( const OIS::KeyEvent &arg );
	bool keyReleased( const OIS::KeyEvent &arg );
	bool mouseMoved( const OIS::MouseEvent &arg );
	bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

protected:
	updateCallback mUpdateCallback;
	keyDownCallback mKeyDownCallback;
	keyUpCallback mKeyUpCallback;
	
    virtual void createScene(void);
};

#endif // #ifndef __GameApplication_h_
