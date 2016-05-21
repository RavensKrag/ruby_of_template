#include "OniAnimationTrack.h"

namespace Oni
{
	AnimationTrack::AnimationTrack()
	{
		mPlaybackRate = 1.0;
	}

	AnimationTrack::~AnimationTrack()
	{
		
	}
	
	void
	AnimationTrack::initialize(Ogre::AnimationState* state)
	{
		mAnimationState = state;
	}
	
	void
	AnimationTrack::update(Ogre::Real deltaTime)
	{
		if(mAnimationState->getEnabled())
		{
			mAnimationState->addTime(deltaTime * mPlaybackRate);
		}
	}
	
	// Accessors and Mutators
	void
	AnimationTrack::setPlaybackRate(Ogre::Real rate)
	{
		mPlaybackRate = rate;
	}
	
	Ogre::Real
	AnimationTrack::getPlaybackRate()
	{
		return mPlaybackRate;
	}
}