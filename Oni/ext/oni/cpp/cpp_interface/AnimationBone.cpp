#include "AnimationBone.h"
#include "../cpp_core/OniAnimationBone.h"

extern "C" {
	void Oni_Animation_Bone_delete(Oni_Animation_BonePtr obj){
		printf("======DELETING BONE\n");
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		delete bone;
	}
	
	void Oni_Animation_Bone_markgc(Oni_Animation_BonePtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
	}
	
	void Oni_Animation_Bone_update(Oni_Animation_BonePtr obj, double dt){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		bone->update(dt);
	}
	
	void Oni_Animation_Bone_getPosition(Oni_Animation_BonePtr obj, double* position){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Vector3 vect = bone->getPosition();
		
		position[0] = vect.x;
		position[1] = vect.y;
		position[2] = vect.z;
	}
	
	void Oni_Animation_Bone_getOrientation(Oni_Animation_BonePtr obj, double* orientation){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Quaternion quat = bone->getOrientation();
		
		orientation[0] = quat.w;
		orientation[1] = quat.x;
		orientation[2] = quat.y;
		orientation[3] = quat.z;
	}
	
	
	void Oni_Animation_Bone_getInitialPosition(Oni_Animation_BonePtr obj, double* position){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Vector3 vect = bone->getInitialPosition();
		
		position[0] = vect.x;
		position[1] = vect.y;
		position[2] = vect.z;
	}
	
	void Oni_Animation_Bone_getInitialOrientation(Oni_Animation_BonePtr obj, double* orientation){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Quaternion quat = bone->getInitialOrientation();
		
		orientation[0] = quat.w;
		orientation[1] = quat.x;
		orientation[2] = quat.y;
		orientation[3] = quat.z;
	}
	
	
	void Oni_Animation_Bone_getPositionDelta(Oni_Animation_BonePtr obj, double* position){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Vector3 vect = bone->getPosition();
		Ogre::Vector3 vect_0 = bone->getInitialPosition();
		
		position[0] = vect.x - vect_0.x;
		position[1] = vect.y - vect_0.y;
		position[2] = vect.z - vect_0.z;
	}
	
	void Oni_Animation_Bone_getOrientationDelta(Oni_Animation_BonePtr obj, double* orientation){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		Ogre::Quaternion quat = bone->getOrientation();
		Ogre::Quaternion quat_0 = bone->getInitialOrientation();
		
		orientation[0] = quat.w - quat_0.w;
		orientation[1] = quat.x - quat_0.x;
		orientation[2] = quat.y - quat_0.y;
		orientation[3] = quat.z - quat_0.z;
	}

}