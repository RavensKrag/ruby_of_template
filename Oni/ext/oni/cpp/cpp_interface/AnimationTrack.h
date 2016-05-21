#ifndef ONI_INTERFACE_ANIMATION_TRACK
#define ONI_INTERFACE_ANIMATION_TRACK

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniAnimationTrack.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt);
	
	// Accessors and Mutators
	void Oni_Animation_Track_setPlaybackRate(Oni_Animation_TrackPtr obj, double rate);
	double Oni_Animation_Track_getPlaybackRate(Oni_Animation_TrackPtr obj);
	
	// Delegation
	const char* Oni_Animation_Track_getAnimationName(Oni_Animation_TrackPtr obj);
	double Oni_Animation_Track_getTimePosition(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_setTimePosition(Oni_Animation_TrackPtr obj, double timePos);
	double Oni_Animation_Track_getLength(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_setLength(Oni_Animation_TrackPtr obj, double len);
	double Oni_Animation_Track_getWeight(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_setWeight(Oni_Animation_TrackPtr obj, double weight);
	void Oni_Animation_Track_addTime(Oni_Animation_TrackPtr obj, double offset);

	int Oni_Animation_Track_hasEnded(Oni_Animation_TrackPtr obj);

	int Oni_Animation_Track_getEnabled(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_setEnabled(Oni_Animation_TrackPtr obj, int enabled);

	// bool operator==(const Ogre::AnimationState& rhs) const;
	// bool operator!=(const Ogre::AnimationState& rhs) const;

	void Oni_Animation_Track_setLoop(Oni_Animation_TrackPtr obj, int loop);
	int Oni_Animation_Track_getLoop(Oni_Animation_TrackPtr obj);

	// void Oni_Animation_Track_copyStateFrom(Oni_Animation_TrackPtr obj, const Ogre::AnimationState& animState){
	// 	mAnimationState->copyStateFrom(animState);
	// };
	
	// void createBlendMask(size_t blendMaskSizeHint, float initialWeight = 1.0f);
	// void destroyBlendMask();
	// void _setBlendMaskData(const float* blendMaskData);
	// void _setBlendMask(const BoneBlendMask* blendMask);
	// const BoneBlendMask* getBlendMask() const {return mBlendMask;}
	// bool hasBlendMask() const {return mBlendMask != 0;}
	// void setBlendMaskEntry(size_t boneHandle, float weight);
	// inline float getBlendMaskEntry(size_t boneHandle) const
	// {
	// assert(mBlendMask && mBlendMask->size() > boneHandle);
	// return (*mBlendMask)[boneHandle];
	// }

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION_TRACK */