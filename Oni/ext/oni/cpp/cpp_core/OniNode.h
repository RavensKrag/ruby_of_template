#ifndef ONI_NODE_H
#define ONI_NODE_H

#include "BaseApplication.h"

namespace Oni
{
	class Node
	{
	public:
		Node();
		virtual ~Node();
		
		virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, Ogre::Node* parentNode=NULL);
		virtual void update(Ogre::Real deltaTime);
		
		std::string getName(){return mNode->getName();};
		
		Ogre::SceneNode* getNode(){return mNode;};
		
		// Position
		const Ogre::Vector3& getPosition();
		void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
		
		void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		void translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		
		// Rotation
		void resetOrientation();
		void setOrientation(Ogre::Real w, Ogre::Real x, Ogre::Real y, Ogre::Real z);
		
		void rotate(const Ogre::Quaternion &q, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		
		void rotateTo(double x, double y, double z);
		
		// Set rotation in the horizontal plane (ie, around the y axis)
		// Transformation uses quaternions and is always local
		void setHorizontalPlaneRotation(const Ogre::Radian &angle);
		Ogre::Radian getHorizontalPlaneRotation();
		
		
		// Scale
		void scale(double x, double y, double z);
		void setScale(double x, double y, double z);
	
	protected:
		Ogre::SceneManager* mSceneMgr; // TODO: Consider optimizing using flyweight pattern
		
		Ogre::SceneNode* mNode;
	
	private:
		Ogre::SceneNode* attachToNewSceneNode(Ogre::Node* parentNode=NULL);
	};
}

#endif /* ONI_NODE_H */