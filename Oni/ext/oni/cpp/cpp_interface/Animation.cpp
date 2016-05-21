#include "Animation.h"
#include "../cpp_core/OniAnimationTrack.h"

extern "C" {
	Oni_AnimationPtr Oni_Animation_new(){
		Oni::Animation* animation = new Oni::Animation();
		
		return (Oni_AnimationPtr)animation;
	}

	void Oni_Animation_delete(Oni_AnimationPtr obj){
		printf("======DELETING ANIMATION\n");
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		delete animation;
	}

	void Oni_Animation_markgc(Oni_AnimationPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::Animation* animation = (Oni::Animation*)(obj);
	}

	void Oni_Animation_initialize(Oni_AnimationPtr obj, Oni_ModelPtr obj2){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		Oni::Model* model = (Oni::Model*)(obj2);
		
		animation->initialize(model);
	}

	void Oni_Animation_update(Oni_AnimationPtr obj, double dt){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		animation->update(dt);
	}
	
	
	void Oni_Animation_shareSkeletonWith(Oni_AnimationPtr obj, Oni_AnimationPtr obj2, double scale){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		Oni::Animation* otherAnimation = (Oni::Animation*)(obj2);
		
		animation->shareSkeletonWith(otherAnimation, scale);
	}
	
	Oni_Animation_BonePtr Oni_Animation_getBone(Oni_AnimationPtr obj, char* name){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		std::string cpp_name(name);
		Oni::AnimationBone* bone = animation->getBone(cpp_name);
		
		Oni_Animation_BonePtr ptr_bone = (Oni_Animation_BonePtr)bone;
		
		return ptr_bone;
	}


	char** Oni_Animation_getAnimationNames(Oni_AnimationPtr obj){
		// DANGER:  Liable to be a source of memory leaks, as it allocates memory
		//          but expects the caller to deal with the consequences
		
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		Ogre::AnimationStateIterator iter = animation->getAnimationNames();
		
		int animation_count = 0;
		while (iter.hasMoreElements())
		{
			Ogre::AnimationState* a = iter.getNext();
			
			animation_count++;
		}

		// Can't know animation count at compile time
		// Must use dynamic memory allocation
		char** string_array = new char* [animation_count+1]; // Leave space for null at the end

		// Fill the array
		iter = animation->getAnimationNames();
		int i;
		for(i=0; iter.hasMoreElements(); i++)
		{
			Ogre::AnimationState* a = iter.getNext();
			
			std::string name = a->getAnimationName();
			
			char* cstr = new char [name.size()+1]; // Add one for the null terminator
			strcpy (cstr, name.c_str());
			
			string_array[i] = cstr;
		}
		
		// Set the last element in the array to NULL
		string_array[animation_count] = NULL;
		
		return string_array;
	}
	
	Oni_Animation_TrackPtr Oni_Animation_getAnimationTrack(Oni_AnimationPtr obj, char* name){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		std::string cpp_name(name);
		Oni::AnimationTrack* track = animation->getAnimationTrack(cpp_name);
		
		Oni_Animation_TrackPtr ptr_track = (Oni_Animation_TrackPtr)track;
		
		return ptr_track;
	}
}