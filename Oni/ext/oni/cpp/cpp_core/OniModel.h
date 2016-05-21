#ifndef ONI_MODEL_H
#define ONI_MODEL_H

#include "BaseApplication.h"

namespace Oni
{
	class Model
	{
	public:
		Model();
		virtual ~Model();
		
		virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename, Ogre::Node* parentNode=NULL);
		virtual void update(Ogre::Real deltaTime);
		
		std::string getName(){return mEntity->getName();};
		
		// Necessary for extensibility
		// May want to use Friend classes instead
		Ogre::Entity* getEntity();
		
		void attachObjectToBone(std::string bone, Oni::Model* otherModel);
		void detachObjectFromBone(Oni::Model* otherModel);
		bool isAttachedToBone();
		
		// Visibility
		bool getVisible();
		void setVisible(bool visible);
		
		// Shadow casting
		bool getCastShadows();
		void setCastShadows(bool enabled);
		
		// Bounding Box
		Ogre::Real getBoundingBoxWidth();
		Ogre::Real getBoundingBoxDepth();
		Ogre::Real getBoundingBoxHeight();
		
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
		const Ogre::Vector3& getScale();
		void setScale(double x, double y, double z);
	
	protected:
		Ogre::SceneManager* mSceneMgr; // TODO: Consider optimizing using flyweight pattern
		
		Ogre::Entity* mEntity;
	
	private:
		Ogre::SceneNode* attachToNewSceneNode(Ogre::Node* parentNode=NULL);
	};
}

#endif /* ONI_MODEL_H */