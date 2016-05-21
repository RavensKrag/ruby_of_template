#include "Node.h"


extern "C" {
	Oni_NodePtr Oni_Node_new(){
		Oni::Node* node = new Oni::Node();
		
		return (Oni_NodePtr)node;
	}

	void Oni_Node_delete(Oni_NodePtr obj){
		printf("======DELETING NODE\n");
		Oni::Node* node = (Oni::Node*)(obj);
		
		delete node;
	}

	void Oni_Node_markgc(Oni_NodePtr obj){
		printf("======MARK FOR COLLECTION\n");
		// Oni::Node* node = (Oni::Node*)(obj);
		
	}

	void Oni_Node_initialize(Oni_NodePtr obj, Ogre_WindowPtr obj2, char* name, Ogre_NodePtr parent){
		Oni::Node* node = (Oni::Node*)(obj);
		GameApplication* game = (GameApplication*)obj2;
		
		std::string cpp_name(name);
				
		Ogre::Node* parentNode = (Ogre::Node*)(parent);
		
		node->initialize(game->getSceneMgr(), cpp_name, parentNode);
	}

	void Oni_Node_update(Oni_NodePtr obj, double dt){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->update(dt);
	}
	
	const char* Oni_Node_getName(Oni_NodePtr obj){
		Oni::Node* node = (Oni::Node*)(obj);
		
		return node->getName().c_str();
	}
	
	Ogre_NodePtr Oni_Node_getNode(Oni_NodePtr obj){
		Oni::Node* node = (Oni::Node*)(obj);
		
		// NOTE: This cast should work, but has the possibility of breakage
		return (Ogre_NodePtr)(node->getNode());
	}
	
	void Oni_Node_getPosition(Oni_NodePtr obj, double* vector){
		Oni::Node* node = (Oni::Node*)(obj);
		
		Ogre::Vector3 position = node->getPosition();
		
		vector[0] = position.x;
		vector[1] = position.y;
		vector[2] = position.z;
	}
	
	void Oni_Node_setPosition(Oni_NodePtr obj, double x, double y, double z){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->setPosition(x,y,z);
	}
	
	void Oni_Node_translate(Oni_NodePtr obj, double x, double y, double z, OniTransformSpace ts){
		// void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		Oni::Node* node = (Oni::Node*)(obj);
		
		switch(ts){
			case LOCAL:
				node->translate(x,y,z, Ogre::Node::TS_LOCAL);
				break;
			case PARENT:
				node->translate(x,y,z, Ogre::Node::TS_PARENT);
				break;
			case WORLD:
				node->translate(x,y,z, Ogre::Node::TS_WORLD);
				break;
		}
	}
	
	void Oni_Node_scale(Oni_NodePtr obj, double x, double y, double z){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->scale(x,y,z);
	}
	
	void Oni_Node_setScale(Oni_NodePtr obj, double x, double y, double z){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->setScale(x,y,z);
	}
	
	void Oni_Node_resetOrientation(Oni_NodePtr obj)
	{
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->resetOrientation();
	}
	
	void Oni_Node_setOrientation(Oni_NodePtr obj, double w, double x, double y, double z)
	{
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->setOrientation(w,x,y,z);
	}
	
	void Oni_Node_rotate(Oni_NodePtr obj, double w, double x, double y, double z)
	{
		Oni::Node* node = (Oni::Node*)(obj);
		
		Ogre::Quaternion quat = Ogre::Quaternion(w,x,y,z);
		node->rotate(quat);
	}
	
	void Oni_Node_pitch(Oni_NodePtr obj, double radians){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->pitch(Ogre::Radian(radians));
	}
	
	void Oni_Node_yaw(Oni_NodePtr obj, double radians){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->yaw(Ogre::Radian(radians));
	}
	
	void Oni_Node_roll(Oni_NodePtr obj, double radians){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->roll(Ogre::Radian(radians));
	}
	
	// Set rotation in horizontal plane
	void Oni_Node_setRotation(Oni_NodePtr obj, double radians){
		Oni::Node* node = (Oni::Node*)(obj);
		
		node->setHorizontalPlaneRotation(Ogre::Radian(radians));
	}
	
	double Oni_Node_getRotation(Oni_NodePtr obj){
		Oni::Node* node = (Oni::Node*)(obj);
		
		return node->getHorizontalPlaneRotation().valueRadians();
	}
	
}