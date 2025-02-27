#include "CameraFactory.h"
#include "Camera.h"
#include "ArcballCamera.h"
#include <assert.h>

using std::string;

Camera* CameraFactory::makeNewCam(string _type)
{
	printf("CAM TYPE: %s \n", _type.c_str());
	if (_type == "CAMERA")
	{
		return new Camera(false);
	}
	else if (_type == "ARCBALL_CAMERA")
	{
		return new Camera(true);
	}
	else
	{
		printf("UNKNOWN CAMERA TYPE!");
		assert(0);
		return nullptr;
	}
}
