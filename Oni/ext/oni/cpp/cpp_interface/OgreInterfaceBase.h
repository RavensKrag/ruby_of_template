#ifndef OGRE_INTERFACE_BASE
#define OGRE_INTERFACE_BASE


// Header which contains things needed by all interface files
// such as typedefs, and callbacks

#ifdef __cplusplus

typedef void* VALUE; // Mimic the ruby VALUE type

#endif /* __cplusplus */

typedef enum { LOCAL, PARENT, WORLD } OniTransformSpace;

typedef void* Ogre_WindowPtr;
typedef void* Ogre_CameraPtr;
typedef void* Ogre_NodePtr;

typedef void* Oni_NodePtr;

typedef void* Oni_LightPtr;

typedef void* Oni_ModelPtr;
typedef void* Oni_AnimationPtr;
	typedef void* Oni_Animation_TrackPtr;
	typedef void* Oni_Animation_BonePtr;

#ifdef __cplusplus
extern "C" {
#endif

	typedef void (*updateCallback)(double dt, void* data);
	typedef void (*keyDownCallback)(unsigned int key_id, void* ruby_window);
	typedef void (*keyUpCallback)(unsigned int key_id, void* ruby_window);

#ifdef __cplusplus
}
#endif


#endif /* OGRE_INTERFACE_BASE */