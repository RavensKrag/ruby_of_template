#ifndef ONI_INTERFACE_NODE
#define ONI_INTERFACE_NODE

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniNode.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif
	
	Oni_NodePtr Oni_Node_new();
	void Oni_Node_delete(Oni_NodePtr obj);
	void Oni_Node_markgc(Oni_NodePtr obj);
	void Oni_Node_initialize(Oni_NodePtr obj, Ogre_WindowPtr obj2, char* name, Ogre_NodePtr parent);
	void Oni_Node_update(Oni_NodePtr obj, double dt);
	
	const char* Oni_Node_getName(Oni_NodePtr obj);
	
	Ogre_NodePtr Oni_Node_getNode(Oni_NodePtr obj);
	
	void Oni_Node_getPosition(Oni_NodePtr obj, double* vector);
	void Oni_Node_setPosition(Oni_NodePtr obj, double x, double y, double z);
	void Oni_Node_translate(Oni_NodePtr obj, double x, double y, double z, OniTransformSpace ts);
	
	void Oni_Node_resetOrientation(Oni_NodePtr obj);
	void Oni_Node_setOrientation(Oni_NodePtr obj, double w, double x, double y, double z);
	
	void Oni_Node_rotate(Oni_NodePtr obj, double w, double x, double y, double z);
	void Oni_Node_pitch(Oni_NodePtr obj, double radians);
	void Oni_Node_yaw(Oni_NodePtr obj, double radians);
	void Oni_Node_roll(Oni_NodePtr obj, double radians);
	
	// Set rotation in horizontal plane
	void Oni_Node_setRotation(Oni_NodePtr obj, double radians);
	double Oni_Node_getRotation(Oni_NodePtr obj);
	
	void Oni_Node_scale(Oni_NodePtr obj, double x, double y, double z);
	void Oni_Node_setScale(Oni_NodePtr obj, double x, double y, double z);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_NODE */