#include "OniLight.h"

namespace Oni
{
	Light::Light()
	{
		// mLight = NULL;
	}
	
	Light::~Light()
	{
		// TODO: Remember to destroy scene node as well - or not? See OniNode.cpp#~Node() comments
		mSceneMgr->destroyLight(mLight);
	}
	
	void
	Light::initialize(Ogre::SceneManager* sceneMgr, std::string& name, Ogre::Node* parentNode)
	{
		mSceneMgr = sceneMgr;
		
		mLight = sceneMgr->createLight(name);
		this->attachToNewSceneNode(parentNode);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
	
	Ogre::Node*
	Light::getParentNode()
	{
		return mLight->getParentNode();
	}
	
	
	// Manipulate Node the light is attached to
		// Position
		void
		Light::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
		{
			mLight->getParentNode()->setPosition(x,y,z);
		}
		
		const Ogre::Vector3&
		Light::getPosition()
		{
			return mLight->getParentNode()->getPosition();
		}
		
		void
		Light::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
		{
			// Moves the node along the Cartesian axes.
			mLight->getParentNode()->translate(x,y,z, relativeTo);
		}
		
		void
		Light::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
		{
			// Moves the node along arbitrary axes.
			mLight->getParentNode()->translate(axes, x,y,z, relativeTo);
		}
		
		
		// Rotation
		void
		Light::resetOrientation()
		{
			mLight->getParentNode()->resetOrientation();
		}
		
		void
		Light::setOrientation(Ogre::Real w, Ogre::Real x, Ogre::Real y, Ogre::Real z)
		{
			mLight->getParentNode()->setOrientation(w,x,y,z);
		}
		
		void
		Light::rotate(const Ogre::Quaternion &q, Ogre::Node::TransformSpace relativeTo)
		{
			mLight->getParentNode()->rotate(q, relativeTo);
		}
		
		void
		Light::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
		{
			mLight->getParentNode()->pitch(angle, relativeTo);
		}

		void
		Light::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
		{
			mLight->getParentNode()->yaw(angle, relativeTo);
		}

		void
		Light::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
		{
			mLight->getParentNode()->roll(angle, relativeTo);
		}
		
		void
		Light::rotateTo(double x, double y, double z)
		{
			Ogre::Vector3 vec = Ogre::Vector3(x,y,z);
			
			mLight->getParentNode()->resetOrientation();
			
			Ogre::Quaternion quat = Ogre::Vector3::UNIT_X.getRotationTo(vec);
			mLight->getParentNode()->setOrientation(quat);
		}
		
	// ----------
	
	// ===== Private
	Ogre::SceneNode*
	Light::attachToNewSceneNode(Ogre::Node* parentNode){
		Ogre::SceneNode* node = mSceneMgr->createSceneNode();
		
		if(parentNode == NULL)
		{
			parentNode = mSceneMgr->getRootSceneNode();
		}
		
		// NOTE: May have to detach light from previous parent, and destroy old parent node
		parentNode->addChild(node);
		
		node->attachObject(mLight);
		node->setPosition(mLight->getPosition());
		mLight->setPosition(0,0,0);
		
		return node;
	}
}