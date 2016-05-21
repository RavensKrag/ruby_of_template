#ifndef ONI_LIGHT_H
#define ONI_LIGHT_H

#include "BaseApplication.h"

namespace Oni
{
	class Light
	{
	public:
		Light();
		virtual ~Light();
		
		virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, Ogre::Node* parentNode=NULL);
		virtual void update(Ogre::Real deltaTime);
		
		std::string getName(){return mLight->getName();};
		
		Ogre::Node* getParentNode();
		
		// Manipulate Node the light is attached to
			// Position
			void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
			const Ogre::Vector3& getPosition();
			
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
		// ----------
		
		void setType(Ogre::Light::LightTypes type){mLight->setType(type);};
		Ogre::Light::LightTypes getType(void) const{ return mLight->getType();};
			// LT_POINT 	
			// 	Point light sources give off light equally in all directions, so require only position not direction.
			// 
			// LT_DIRECTIONAL 	
			// 	Directional lights simulate parallel light beams from a distant source, hence have direction but no position.
			// 
			// LT_SPOTLIGHT 	
			// 	Spotlights simulate a cone of light from a source so require position and direction, plus extra values for falloff.
		
		void setDiffuseColour(Ogre::Real red, Ogre::Real green, Ogre::Real blue){mLight->setDiffuseColour(red, green, blue);};
		const Ogre::ColourValue& getDiffuseColour(void) const{ return mLight->getDiffuseColour();};
		
		void setSpecularColour(Ogre::Real red, Ogre::Real green, Ogre::Real blue){mLight->setSpecularColour(red, green, blue);};
		const Ogre::ColourValue& getSpecularColour(void) const{ return mLight->getSpecularColour();};

		void setAttenuation(Ogre::Real range, Ogre::Real constant, Ogre::Real linear, Ogre::Real quadratic){mLight->setAttenuation(range, constant, linear, quadratic);};
			Ogre::Real getAttenuationRange(void) const{ return mLight->getAttenuationRange();};
			Ogre::Real getAttenuationConstant(void) const{ return mLight->getAttenuationConstant();};
			Ogre::Real getAttenuationLinear(void) const{ return mLight->getAttenuationLinear();};
			Ogre::Real getAttenuationQuadric(void) const{ return mLight->getAttenuationQuadric();};
		
		void setLightPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z){mLight->setPosition(x,y,z);};
		const Ogre::Vector3& getLightPosition(void) const{ return mLight->getPosition();};
		void setDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z){mLight->setDirection(x,y,z);};
		const Ogre::Vector3& getDirection(void) const{ return mLight->getDirection();};
		
		
		// Spotlight
		/** Sets the range of a spotlight, i.e. the angle of the inner and outer cones and the rate of falloff between them.
		    @param
		        innerAngle Angle covered by the bright inner cone
		        @node
		            The inner cone applicable only to Direct3D, it'll always treat as zero in OpenGL.
		    @param
		        outerAngle Angle covered by the outer cone
		    @param
		        falloff The rate of falloff between the inner and outer cones. 1.0 means a linear falloff, less means slower falloff, higher means faster falloff.
		*/
			void setSpotlightRange(const Ogre::Radian& innerAngle, const Ogre::Radian& outerAngle, Ogre::Real falloff = 1.0){mLight->setSpotlightRange(innerAngle, outerAngle, falloff);};
			const Ogre::Radian& getSpotlightInnerAngle(void) const{ return mLight->getSpotlightInnerAngle();};
			const Ogre::Radian& getSpotlightOuterAngle(void) const{ return mLight->getSpotlightOuterAngle();};
			void setSpotlightFalloff(Ogre::Real val){mLight->setSpotlightFalloff(val);};
			Ogre::Real getSpotlightFalloff(void) const{ return mLight->getSpotlightFalloff();};
			void setSpotlightInnerAngle(const Ogre::Radian& val){mLight->setSpotlightInnerAngle(val);};
			void setSpotlightOuterAngle(const Ogre::Radian& val){mLight->setSpotlightOuterAngle(val);};
			
			void setSpotlightNearClipDistance(Ogre::Real nearClip) {mLight->setSpotlightNearClipDistance(nearClip);};
			
			Ogre::Real getSpotlightNearClipDistance() const {return mLight->getSpotlightNearClipDistance();};
		// ==============
		
		/** Set a scaling factor to indicate the relative power of a light.
		@remarks
			This factor is only useful in High Dynamic Range (HDR) rendering.
			You can bind it to a shader variable to take it into account,
			@see GpuProgramParameters
		@param power The power rating of this light, default is 1.0.
		*/
		void setPowerScale(Ogre::Real power){mLight->setPowerScale(power);};
		Ogre::Real getPowerScale(void) const{ return mLight->getPowerScale();};
		
		
		/** Overridden from MovableObject */
		const Ogre::AxisAlignedBox& getBoundingBox(void) const{ return mLight->getBoundingBox();};
		
		/** Overridden from MovableObject */
		const Ogre::String& getMovableType(void) const{ return mLight->getMovableType();};
		
		// Includes any transforms from nodes it is attached to. 
		// @param cameraRelativeIfSet If set to true, returns data in camera-relative units if that's been set up (render use)
		const Ogre::Vector3& getDerivedPosition(bool cameraRelativeIfSet = false) const{ return mLight->getDerivedPosition(cameraRelativeIfSet);};
		const Ogre::Vector3& getDerivedDirection(void) const{ return mLight->getDerivedDirection();};

		// "invisible" lights do not affect the scene
		void setVisible(bool visible){mLight->setVisible(visible);};
		bool getVisible(){return mLight->getVisible();};
		
		/** Overridden from MovableObject */
		Ogre::Real getBoundingRadius(void) const { return mLight->getBoundingRadius(); /* not visible */ }
		
		/** Gets the details of this light as a 4D vector.
		@remarks
			Getting details of a light as a 4D vector can be useful for
			doing general calculations between different light types{mLight->;}; for
			example the vector can represent both position lights (w=1.0f)
			and directional lights (w=0.0f) and be used in the same 
			calculations.
		@param cameraRelativeIfSet If set to true, returns data in camera-relative units if that's been set up (render use)
		*/
		Ogre::Vector4 getAs4DVector(bool cameraRelativeIfSet = false) const{ return mLight->getAs4DVector(cameraRelativeIfSet);};
		
		/// Override to return specific type flag
		Ogre::uint32 getTypeFlags(void) const{ return mLight->getTypeFlags();};
		
		/// @copydoc AnimableObject::createAnimableValue
		Ogre::AnimableValuePtr createAnimableValue(const Ogre::String& valueName){return mLight->createAnimableValue(valueName);};
		
		/** Set this light to use a custom shadow camera when rendering texture shadows.
		@remarks
			This changes the shadow camera setup for just this light,  you can set
			the shadow camera setup globally using SceneManager::setShadowCameraSetup
		@see ShadowCameraSetup
		*/
		void setCustomShadowCameraSetup(const Ogre::ShadowCameraSetupPtr& customShadowSetup){return mLight->setCustomShadowCameraSetup(customShadowSetup);};
		void resetCustomShadowCameraSetup(void){mLight->resetCustomShadowCameraSetup();};
		const Ogre::ShadowCameraSetupPtr& getCustomShadowCameraSetup(void) const{ return mLight->getCustomShadowCameraSetup();};
		
		/// @copydoc MovableObject::visitRenderables
		void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false){return mLight->visitRenderables(visitor, debugRenderables);};
		
		
		bool getCastShadows(){return mLight->getCastShadows();};
		void setCastShadows(bool enabled){mLight->setCastShadows(enabled);}
		
		
		// maximum distance away from the camera that shadows by this light will be visible.
		void setShadowFarDistance(Ogre::Real distance){mLight->setShadowFarDistance(distance);};
		void resetShadowFarDistance(void){mLight->resetShadowFarDistance();};
		Ogre::Real getShadowFarDistance(void) const{ return mLight->getShadowFarDistance();};
		Ogre::Real getShadowFarDistanceSquared(void) const{ return mLight->getShadowFarDistanceSquared();};
		
		// clip plane distance to be used by the shadow camera, if this light casts texture shadows
		/*
			This is different from the 'shadow far distance', which is
			always measured from the main camera. This distance is the far clip plane
			of the light camera.
		*/
		void setShadowNearClipDistance(Ogre::Real nearClip) { mLight->setShadowNearClipDistance(nearClip); }
		Ogre::Real getShadowNearClipDistance() const { return mLight->getShadowNearClipDistance(); }
		void setShadowFarClipDistance(Ogre::Real farClip) { mLight->setShadowFarClipDistance(farClip); }
		Ogre::Real getShadowFarClipDistance() const { return mLight->getShadowFarClipDistance(); }

		// Custom parameter
		void setCustomParameter(Ogre::uint16 index, const Ogre::Vector4& value) {mLight->setCustomParameter(index, value);};
		const Ogre::Vector4& getCustomParameter(Ogre::uint16 index) const {return mLight->getCustomParameter(index);};
	
	private:
		Ogre::SceneManager* mSceneMgr;
		Ogre::Light* mLight;
		
		Ogre::SceneNode* attachToNewSceneNode(Ogre::Node* parentNode=NULL);
	};
}

#endif