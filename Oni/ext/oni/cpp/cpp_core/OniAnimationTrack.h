#ifndef ONI_ANIMATION_TRACK_H
#define ONI_ANIMATION_TRACK_H

#include "BaseApplication.h"

namespace Oni
{
	class AnimationTrack
	{
	public:
		AnimationTrack();
		virtual ~AnimationTrack();
		
		virtual void initialize(Ogre::AnimationState* state);
		virtual void update(Ogre::Real deltaTime);
		
		// Accessors and Mutators
		void setPlaybackRate(Ogre::Real rate);
		Ogre::Real getPlaybackRate();
		
		// Delegation
		// Should expose ALL methods for Animation track
		
		const Ogre::String& getAnimationName(){return mAnimationState->getAnimationName();};
		Ogre::Real getTimePosition(void){return mAnimationState->getTimePosition();};
		void setTimePosition(Ogre::Real timePos){mAnimationState->setTimePosition(timePos);};
		Ogre::Real getLength(){return mAnimationState->getLength();};
		void setLength(Ogre::Real len){mAnimationState->setLength(len);};
		Ogre::Real getWeight(void){return mAnimationState->getWeight();};
		void setWeight(Ogre::Real weight){mAnimationState->setWeight(weight);};
		void addTime(Ogre::Real offset){mAnimationState->addTime(offset);};

		bool hasEnded(void){return mAnimationState->hasEnded();};

		bool getEnabled(void){return mAnimationState->getEnabled();};
		void setEnabled(bool enabled){mAnimationState->setEnabled(enabled);};

		// bool operator==(const Ogre::AnimationState& rhs) const;
		// bool operator!=(const Ogre::AnimationState& rhs) const;

		void setLoop(bool loop) { mAnimationState->setLoop(loop); };
		bool getLoop(void) const { return mAnimationState->getLoop(); }

		void copyStateFrom(const Ogre::AnimationState& animState){
			mAnimationState->copyStateFrom(animState);
		};

		Ogre::AnimationStateSet* getParent(void) const { return mAnimationState->getParent(); };

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
	
	private:
		Ogre::AnimationState* mAnimationState;
		
		Ogre::Real mPlaybackRate;
	};
}

#endif /* ONI_ANIMATION_TRACK_H */
