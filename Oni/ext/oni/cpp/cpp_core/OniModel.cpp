#include "OniModel.h"

namespace Oni
{
	Model::Model()
	{
		
	}

	Model::~Model()
	{
		Ogre::Node* parent = mEntity->getParentNode();
		bool isTagPoint = mEntity->isParentTagPoint();
		
		mEntity->detachFromParent();
		
		if(isTagPoint)
		{
			// std::cout << "TAG POINT" << std::endl;
			// If the current mesh is bound to a tag point, should alert Entity which controls the skeleton that the tag point must be freed
			
			// remember to delete tag point if mesh is bound to skeleton
			// mEntity->getSkeleton()->freeTagPoint();
		}
		else
		{
			// std::cout << "NOT tag point" << std::endl;
			// Destroy parent node if it is a scene node
			// may be poor reasoning.  might there be multiple Model objects per node?
			// perhaps destroy parent if it is a scene node such that numChildren == 0 ?
			mSceneMgr->destroySceneNode(static_cast<Ogre::SceneNode*>(parent));
		}
		
		// Detach all objects attached to this one, so they don't freak out when this is gone.
		// Iterate over all objects attached to bones
			// detach them from bones, and re-attach them to scene nodes
			// make those scene nodes direct children of the root node
		Ogre::Entity::ChildObjectListIterator iter = mEntity->getAttachedObjectIterator();
		while(iter.hasMoreElements())
		{
			Ogre::MovableObject* child = iter.getNext();
			
			mEntity->detachObjectFromBone(child);
			
			Ogre::SceneNode* node;
			node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
			node->attachObject(child);
		}
		
		// std::cout << "destroy entity" << std::endl;
		mSceneMgr->destroyEntity(mEntity);
	}

	void
	Model::initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename, Ogre::Node* parentNode)
	{
		mSceneMgr = sceneMgr;
		
		mEntity = sceneMgr->createEntity(name, filename);
		
		this->attachToNewSceneNode(parentNode);
	}
	
	void
	Model::update(Ogre::Real deltaTime)
	{
		
	}
	
	Ogre::Entity*
	Model::getEntity()
	{
		return mEntity;
	}
	
	// Attach to new parent node
	
	// Attach Moveable to skeleton tagpoint
	void
	Model::attachObjectToBone(std::string bone, Oni::Model* otherModel)
	{
		if(!mEntity->hasSkeleton())
		{
			// If this Model does not contain a skeleton, leave this method immediately.
			return;
		}
		
		if(otherModel->getEntity()->isParentTagPoint())
		{
			// Object is already attached to a bone.
			// Though, perhaps not the bone specified.
			// Exit function.
			return;
		}
		
		// Discard old parent scene node, so TagPoint can be used instead
		Ogre::Node* parent = otherModel->getEntity()->getParentNode();
		otherModel->getEntity()->detachFromParent();
		mSceneMgr->destroySceneNode(static_cast<Ogre::SceneNode*>(parent));
		
		// attachObjectToBone (const String &boneName, MovableObject *pMovable, const Quaternion &offsetOrientation=Quaternion::IDENTITY, const Vector3 &offsetPosition=Vector3::ZERO)
		mEntity->attachObjectToBone(bone, otherModel->getEntity());
	}
	
	void
	Model::detachObjectFromBone(Oni::Model* otherModel)
	{
		if(!mEntity->hasSkeleton())
		{
			// If this Model does not contain a skeleton, leave this method immediately.
			return;
		}
		
		// attachObjectToBone (const String &boneName, MovableObject *pMovable, const Quaternion &offsetOrientation=Quaternion::IDENTITY, const Vector3 &offsetPosition=Vector3::ZERO)
		mEntity->detachObjectFromBone(otherModel->getEntity());
		otherModel->attachToNewSceneNode();
	}
	
	bool
	Model::isAttachedToBone()
	{
		return mEntity->isParentTagPoint();
	}
	
	// Visibility
	bool
	Model::getVisible()
	{
		return mEntity->getVisible();
	}

	void
	Model::setVisible(bool visible)
	{
		mEntity->setVisible(visible);
	}
	
	// Shadow casting
	bool Model::getCastShadows()
	{
		return mEntity->getCastShadows();
	}
	
	void Model::setCastShadows(bool enabled)
	{
		mEntity->setCastShadows(enabled);
	}
	
	// Bounding Box
	Ogre::Real Model::getBoundingBoxWidth()
	{
		Ogre::Vector3 max = mEntity->getBoundingBox().getMaximum();
		Ogre::Vector3 min = mEntity->getBoundingBox().getMinimum();
		
		return max.x - min.x;
	}
	
	Ogre::Real Model::getBoundingBoxDepth()
	{
		Ogre::Vector3 max = mEntity->getBoundingBox().getMaximum();
		Ogre::Vector3 min = mEntity->getBoundingBox().getMinimum();
		
		return max.z - min.z;
	}
	
	Ogre::Real Model::getBoundingBoxHeight()
	{
		Ogre::Vector3 max = mEntity->getBoundingBox().getMaximum();
		Ogre::Vector3 min = mEntity->getBoundingBox().getMinimum();
		
		return max.y - min.y;
	}
	
	// Position
	const Ogre::Vector3&
	Model::getPosition()
	{
		return mEntity->getParentNode()->getPosition();
	}
	
	void
	Model::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mEntity->getParentNode()->setPosition(x,y,z);
	}
	
	
	void
	Model::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along the Cartesian axes.
		mEntity->getParentNode()->translate(x,y,z, relativeTo);
	}
	
	void
	Model::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along arbitrary axes.
		mEntity->getParentNode()->translate(axes, x,y,z, relativeTo);
	}
	
	// Rotation
	void
	Model::resetOrientation()
	{
		mEntity->getParentNode()->resetOrientation();
	}
	
	void
	Model::setOrientation(Ogre::Real w, Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mEntity->getParentNode()->setOrientation(w,x,y,z);
	}
	
	void
	Model::rotate(const Ogre::Quaternion &q, Ogre::Node::TransformSpace relativeTo)
	{
		mEntity->getParentNode()->rotate(q, relativeTo);
	}
	
	void
	Model::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mEntity->getParentNode()->pitch(angle, relativeTo);
	}

	void
	Model::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mEntity->getParentNode()->yaw(angle, relativeTo);
	}

	void
	Model::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mEntity->getParentNode()->roll(angle, relativeTo);
	}
	
	void
	Model::rotateTo(double x, double y, double z)
	{
		Ogre::Vector3 vec = Ogre::Vector3(x,y,z);
		
		// Ogre::Vector3 src = mEntity->getParentNode()->getOrientation() * Ogre::Vector3::UNIT_X;
		mEntity->getParentNode()->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Vector3::UNIT_X.getRotationTo(vec);
		mEntity->getParentNode()->setOrientation(quat);
	}

	void
	Model::setHorizontalPlaneRotation(const Ogre::Radian &angle)
	{
		// Reset orientation, and set again
		mEntity->getParentNode()->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Quaternion(angle, Ogre::Vector3::UNIT_Y);
		mEntity->getParentNode()->setOrientation(quat);
		
		// mEntity->getParentNode()->getOrientation().getYaw(); // get rotation around Y axis
	}
	
	Ogre::Radian
	Model::getHorizontalPlaneRotation()
	{
		return mEntity->getParentNode()->getOrientation().getYaw();
	}
	
	// Scale
	void
	Model::scale(double x, double y, double z)
	{
		// Adjust scale
		mEntity->getParentNode()->scale(x,y,z);
	}
	
	const Ogre::Vector3&
	Model::getScale()
	{
		return mEntity->getParentNode()->getScale();
	}
	
	void
	Model::setScale(double x, double y, double z)
	{
		// Set scale to specified value
		mEntity->getParentNode()->setScale(x,y,z);
	}
	
	
	// ===== Private
	Ogre::SceneNode*
	Model::attachToNewSceneNode(Ogre::Node* parentNode){
		Ogre::SceneNode* node = mSceneMgr->createSceneNode();
		
		if(parentNode == NULL)
		{
			parentNode = mSceneMgr->getRootSceneNode();
		}
		
		parentNode->addChild(node);
		
		node->attachObject(mEntity);
		node->setPosition(0,0,0); // Spawn all objects at the origin
		
		return node;
	}
}