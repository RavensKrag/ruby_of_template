#include "Camera.h"

extern "C" {
	Ogre_CameraPtr Ogre_Camera_new(Ogre_WindowPtr window, char* name){
		BaseApplication* game = (BaseApplication*)window; //TODO: Use proper C++ static cast
		
		std::string cpp_name(name);
		
		Ogre::Camera* camera = game->getSceneMgr()->createCamera(cpp_name);
		
		return (Ogre_CameraPtr)camera;
	}
	
	void Ogre_Camera_delete(Ogre_CameraPtr obj){
		printf("======DELETING CAMERA\n");
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		delete camera;
	}
	
	void Ogre_Camera_initialize(Ogre_CameraPtr obj, Ogre_WindowPtr obj2, int z_order){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		BaseApplication* game = (BaseApplication*)obj2;
		
		// ===== Create viewport
		// Create one viewport, entire window
	    Ogre::Viewport* vp = game->getWindow()->addViewport(camera, z_order);
	    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

	    // Alter the camera aspect ratio to match the viewport
	    camera->setAspectRatio(
	        Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
	}
	
	void Ogre_Camera_setPosition(Ogre_CameraPtr obj, double x, double y, double z){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setPosition(Ogre::Vector3(x,y,z));
	}
	
	void Ogre_Camera_lookAt(Ogre_CameraPtr obj, double x, double y, double z){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->lookAt(Ogre::Vector3(x,y,z));
	}
	
	double Ogre_Camera_getNearClipDistance(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		return camera->getNearClipDistance();
	}

	
	void Ogre_Camera_setNearClipDistance(Ogre_CameraPtr obj, double distance){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setNearClipDistance(distance);
	}
	
	void Ogre_Camera_setProjectionType(Ogre_CameraPtr obj, OniCameraProjectionType type){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		Ogre::ProjectionType pt;
		if(type == ORTHOGRAPHIC){
			pt = Ogre::PT_ORTHOGRAPHIC;
		}
		else// if(type == PERSPECTIVE)
		{
			pt = Ogre::PT_PERSPECTIVE;
		}
		
		camera->setProjectionType(pt);
	}
	
	// Return horizontal FOV in degrees
	double Ogre_Camera_getFOVx(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		// Should be correct, based on Ogre_Camera_setFOV
		Ogre::Radian rad_fov = camera->getFOVy() * camera->getAspectRatio();
		return rad_fov.valueDegrees();
	}
	
	void Ogre_Camera_setFOVx(Ogre_CameraPtr obj, double x_angle){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setFOVy(Ogre::Degree(x_angle)/camera->getAspectRatio());
	}
	
	double Ogre_Camera_getFOVy(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		// Should be correct, based on Ogre_Camera_setFOV
		Ogre::Radian rad_fov = camera->getFOVy();
		return rad_fov.valueDegrees();
	}
	
	void Ogre_Camera_setFOVy(Ogre_CameraPtr obj, double y_angle){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setFOVy(Ogre::Degree(y_angle));
	}
	
	void Ogre_Camera_setOrthoWindow(Ogre_CameraPtr obj, double w, double h){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setOrthoWindow(w,h);
	}
	
	void Ogre_Camera_setOrthoWindowHeight(Ogre_CameraPtr obj, double h){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setOrthoWindowHeight(h);
	}
	
	void Ogre_Camera_setOrthoWindowWidth(Ogre_CameraPtr obj, double w){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		camera->setOrthoWindowWidth(w);
	}
	
	double Ogre_Camera_getOrthoWindowHeight(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		return camera->getOrthoWindowHeight();
	}
	
	double Ogre_Camera_getOrthoWindowWidth(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		return camera->getOrthoWindowWidth();
	}
}