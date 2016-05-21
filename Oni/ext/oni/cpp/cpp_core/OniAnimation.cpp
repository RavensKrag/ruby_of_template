#include "OniAnimation.h"

namespace Oni
{
	Animation::Animation()
	{
		
	}

	Animation::~Animation()
	{
		// TODO: Memory - Delete all Oni::AnimationTrack objects in mAnims
	}

	void
	Animation::initialize(Oni::Model* model)
	{
		mModel = model;
		
		
		Ogre::Entity* entity = mModel->getEntity();
		
		// this is very important due to the nature of the exported animations
		entity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);
		
		// populate our animation list
		Ogre::AnimationStateSet* aSet = entity->getAllAnimationStates();
		Ogre::AnimationStateIterator iter = aSet->getAnimationStateIterator();
		while (iter.hasMoreElements())
		{
			Ogre::AnimationState* a = iter.getNext();
			
			Oni::AnimationTrack* track = new Oni::AnimationTrack();
			track->initialize(a);
			
			track->setLoop(true);
			
			mAnims[a->getAnimationName()] = track;
		}
	}

	void
	Animation::update(Ogre::Real deltaTime)
	{
		// NOTE: Iterates over all animation tracks, but the track will only update if animation is active.
		for(
			std::map<std::string, Oni::AnimationTrack*>::iterator iter = mAnims.begin();
			iter != mAnims.end();
			iter++
		)
		{
			(*iter).second->update(deltaTime);
		}
		
		
		// apply smooth transitioning between our animations
		// fadeAnimations(deltaTime);
	}
	
	// TODO: Add animations from another skeleton
	// The following method also exists for Ogre::SkeletonInstance
	// instances should be modified, not whole skeletons, so that different characters
	// can have different animation sets
	// void Ogre::Skeleton::addLinkedSkeletonAnimationSource(const Ogre::String &skelName, Ogre::Real scale = 1.0f)
	
	// TODO: Share skeleton instances among entities
	// Useful for tying equipment sets together
	// Should load the animations in from the linked skeleton as well
	// 		Should that be done automatically at C++ level?
	// shareSkeletonInstanceWith (Entity *entity)
	void
	Animation::shareSkeletonWith(Oni::Animation* animation, double scale)
	{
		Ogre::Entity* otherEntity = animation->getModel()->getEntity();
		Ogre::Entity* entity = mModel->getEntity();
		
		// add linked animations
		entity->getSkeleton()->addLinkedSkeletonAnimationSource(
			otherEntity->getSkeleton()->getName(), scale
		);
		// share skeletons
		entity->shareSkeletonInstanceWith(otherEntity);
	}
	
	Oni::AnimationBone*
	Animation::getBone(std::string& name)
	{
		Ogre::SkeletonInstance* skeleton = mModel->getEntity()->getSkeleton();
		Ogre::Bone* bone = skeleton->getBone(name);
		
		Oni::AnimationBone* oni_bone = new Oni::AnimationBone();
		oni_bone->initialize(bone);
		
		return oni_bone;
	}

	Ogre::AnimationStateIterator
	Animation::getAnimationNames()
	{
		Ogre::Entity* entity = mModel->getEntity();
		
		Ogre::AnimationStateSet* aSet = entity->getAllAnimationStates();
		Ogre::AnimationStateIterator iter = aSet->getAnimationStateIterator();
		
		return iter;
	}
	
	Oni::AnimationTrack*
	Animation::getAnimationTrack(std::string name){
		std::map<std::string, Oni::AnimationTrack*>::iterator track_iter = mAnims.find(name);
		
		// Return legit value, or NULL, must check for iter being end
		if(track_iter == mAnims.end())
		{
			// Does not exist
			return NULL;
		}
		
		// Does exist
		return track_iter->second;
	}
}