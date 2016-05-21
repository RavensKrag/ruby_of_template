#ifndef ONI_ANIMATION_H
#define ONI_ANIMATION_H

#include "BaseApplication.h"
#include "OniModel.h"

#include "OniAnimationBone.h"

#include "OniAnimationTrack.h"

#include <deque>

namespace Oni
{
	class Animation
	{
	public:
		Animation();
		virtual ~Animation();
		virtual void initialize(Oni::Model* model);
		virtual void update(Ogre::Real deltaTime);
		
		void shareSkeletonWith(Oni::Animation* animation, double scale=1.0f);
		Oni::AnimationBone* getBone(std::string& name);
		
		Ogre::AnimationStateIterator getAnimationNames();
		
		Oni::AnimationTrack* getAnimationTrack(std::string name);
		
		Oni::Model* getModel(){return mModel;}; // Necessary to allow exposure of the entity
	
	private:
		Oni::Model* mModel;

		std::map<std::string, Oni::AnimationTrack*> mAnims; // TODO: Try to make values non-pointers
		// all of the animations our character has, and a null ID
		// some of these affect separate body parts and will be blended together
	};
}

#endif /* ONI_ANIMATION_H */