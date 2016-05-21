#ifndef ONI_INTERFACE_MODEL
#define ONI_INTERFACE_MODEL

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniModel.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif
	
	Oni_ModelPtr Oni_Model_new();
	void Oni_Model_delete(Oni_ModelPtr model);
	void Oni_Model_markgc(Oni_ModelPtr obj);
	void Oni_Model_initialize(Oni_ModelPtr obj, Ogre_WindowPtr obj2, char* name, char* filename, Ogre_NodePtr parent);
	void Oni_Model_update(Oni_ModelPtr obj, double dt);
	
	const char* Oni_Model_getName(Oni_ModelPtr obj);
	
	Ogre_NodePtr Oni_Model_getParentNode(Oni_ModelPtr obj);
	
	void Oni_Model_attachObjectToBone(Oni_ModelPtr obj, char* name, Oni_ModelPtr obj2);
	void Oni_Model_detachObjectFromBone(Oni_ModelPtr obj, Oni_ModelPtr obj2);
	int Oni_Model_isAttachedToBone(Oni_ModelPtr obj);
	
	int Oni_Model_getVisible(Oni_ModelPtr obj);
	void Oni_Model_setVisible(Oni_ModelPtr obj, int visible);
	
	int Oni_Model_getCastShadows(Oni_ModelPtr obj);
	void Oni_Model_setCastShadows(Oni_ModelPtr obj, int enabled);
	
	double Oni_Model_getBoundingBoxWidth(Oni_ModelPtr obj);
	double Oni_Model_getBoundingBoxDepth(Oni_ModelPtr obj);
	double Oni_Model_getBoundingBoxHeight(Oni_ModelPtr obj);
	
	void Oni_Model_getPosition(Oni_ModelPtr obj, double* vector);
	void Oni_Model_setPosition(Oni_ModelPtr obj, double x, double y, double z);
	void Oni_Model_translate(Oni_ModelPtr obj, double x, double y, double z, OniTransformSpace ts);
	
	void Oni_Model_resetOrientation(Oni_ModelPtr obj);
	void Oni_Model_setOrientation(Oni_ModelPtr obj, double w, double x, double y, double z);
	
	void Oni_Model_rotate(Oni_ModelPtr obj, double w, double x, double y, double z);
	void Oni_Model_pitch(Oni_ModelPtr obj, double radians);
	void Oni_Model_yaw(Oni_ModelPtr obj, double radians);
	void Oni_Model_roll(Oni_ModelPtr obj, double radians);
	
	// Rotate to face the given vector - DEPRECIATED
	void Oni_Model_rotateTo(Oni_ModelPtr obj, double x, double y, double z);
	
	// Set rotation in horizontal plane
	void Oni_Model_setRotation(Oni_ModelPtr obj, double radians);
	double Oni_Model_getRotation(Oni_ModelPtr obj);
	
	void Oni_Model_scale(Oni_ModelPtr obj, double x, double y, double z);
	void Oni_Model_getScale(Oni_ModelPtr obj, double* vector);
	void Oni_Model_setScale(Oni_ModelPtr obj, double x, double y, double z);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_MODEL */