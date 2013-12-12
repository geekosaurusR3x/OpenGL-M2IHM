#ifndef CAMROTATE_H
#define CAMROTATE_H
#include "camera.h"


class CamRotate : public Camera
{
public:
	CamRotate();
	CamRotate(double x, double y, double z);
	~CamRotate();
	void TogleRotate();
	void PositonCamera();

	bool IsRotateCam() const {
		return Rotate_Cam;
	}
	
	double GetRayonRotation() const {
		return rayon_rotation;
	}
	
	void SetRayonRotation(double rayon_rotation) {
		if (rayon_rotation>0)
		{
			this->rayon_rotation = rayon_rotation;
		}
	}
	
	void UpdateChild();
	
private:
	bool Rotate_Cam;
	double angle_cam;
	double rayon_rotation;

};

#endif // CAMROTATE_H
