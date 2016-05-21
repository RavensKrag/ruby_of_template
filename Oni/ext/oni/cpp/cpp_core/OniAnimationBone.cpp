#include "OniAnimationBone.h"

namespace Oni
{
	AnimationBone::AnimationBone()
	{
		
	}

	AnimationBone::~AnimationBone()
	{
		
	}

	void
	AnimationBone::initialize(Ogre::Bone* bone)
	{
		mBone = bone;
	}

	void
	AnimationBone::update(Ogre::Real deltaTime)
	{
		
	}
	
	const Ogre::Vector3&
	AnimationBone::getPosition()
	{
		return mBone->getPosition();
	}
	
	const Ogre::Quaternion&
	AnimationBone::getOrientation()
	{
		return mBone->getOrientation();
	}
	
	const Ogre::Vector3&
	AnimationBone::getInitialPosition()
	{
		return mBone->getInitialPosition();
	}
	
	const Ogre::Quaternion&
	AnimationBone::getInitialOrientation()
	{
		return mBone->getInitialOrientation();
	}
	
}