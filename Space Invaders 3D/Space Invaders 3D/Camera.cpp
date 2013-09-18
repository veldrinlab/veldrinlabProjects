/**
 * File contains definition of Camera class.
 * @file    Camera.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */

#include "Camera.h"

/**
 * Class constructor with initiaize parameters.
 * @param	position is initialize Camera position.
 */
Camera::Camera(Vector3D position)
{
	this->position = position;
	this->rotation = Vector3D(20.0f,0.0f,0.0f);
	this->isDead = false;
	initCamera();
}

/**
 * Method is used to initialize camera, set positon, rotation and perspective.
 */
void Camera::initCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective (45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 30000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotation.x,1.0,0.0,0.0);
    glRotatef(rotation.y,0.0,1.0,0.0);
    glTranslated(-position.x,-position.y,-position.z);
}


/**
 * Method used to update entity.
 * @param	elapsedTime is time between frames in seconds.
 */
void Camera::updateEntity(const float elapsedTime)
{
	glRotatef(rotation.x,1.0,0.0,0.0);
    glRotatef(rotation.y,0.0,1.0,0.0);
    glTranslatef(-position.x,-position.y,-position.z);
}

/**
 * Method is used to handle wKeyPressed signal.
 */
void Camera::wKeyPressed()
{
    position.x += float(sin(rotation.y / 180 * 3.141592654f));
	position.z -= float(cos(rotation.y / 180 * 3.141592654f));
    position.y -= float(sin(rotation.x / 180 * 3.141592654f));

}

/**
 * Method is used to handle sKeyPressed signal.
 */
void Camera::sKeyPressed()
{
	position.x += float(sin(rotation.y / 180.0f * 3.141592654f));
	position.z += float(cos(rotation.y / 180.0f * 3.141592654f));
    position.y -= float(sin(rotation.x / 180.0f * 3.141592654f));
}

/**
 * Method is used to handle aKeyPressed signal.
 */
void Camera::aKeyPressed()
{
    position.x -= float(cos(rotation.y / 180.0f * 3.141592654f)) * 0.2f;
    position.z -= float(sin(rotation.y / 180.0f * 3.141592654f)) * 0.2f;	
}

/**
 * Method is used to handle dKeyPressed signal.
 */
void Camera::dKeyPressed()
{
	position.x += float(cos(rotation.y / 180.0f * 3.141592654f)) * 0.2f;
    position.z += float(sin(rotation.y / 180.0f * 3.141592654f)) * 0.2f;	
}

/**
 * Method is used to handle eKeyPressed signal.
 */
void Camera::eKeyPressed()
{
	rotation.x -= 1.0f;
    if (rotation.x < -360.0f)
		rotation.x += 360.0f;

}

/**
 * Method is used to handle qKeyPressed signal.
 */
void Camera::qKeyPressed()
{
	rotation.x += 1.0f;
    if (rotation.x > 360.0f)
		rotation.x -= 360.0f;
}
