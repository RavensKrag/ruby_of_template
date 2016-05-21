#ifndef ONI_INTERFACE_ANIMATION
#define ONI_INTERFACE_ANIMATION

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniModel.h"
#include "../cpp_core/OniAnimation.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Oni_AnimationPtr Oni_Animation_new();
	void Oni_Animation_delete(Oni_AnimationPtr agent);
	void Oni_Animation_markgc(Oni_AnimationPtr obj);
	void Oni_Animation_initialize(Oni_AnimationPtr obj, Oni_ModelPtr obj2);
	void Oni_Animation_update(Oni_AnimationPtr obj, double dt);
	
	void Oni_Animation_shareSkeletonWith(Oni_AnimationPtr obj, Oni_AnimationPtr obj2, double scale);
	Oni_Animation_BonePtr Oni_Animation_getBone(Oni_AnimationPtr obj, char* name);
	
	char** Oni_Animation_getAnimationNames(Oni_AnimationPtr obj);
	
	Oni_Animation_TrackPtr Oni_Animation_getAnimationTrack(Oni_AnimationPtr obj, char* name);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION */