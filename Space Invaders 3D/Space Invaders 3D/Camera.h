/**
 * File contains declaration of Camera class. 
 * @file    Camera.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-26
 * @version 1.0
 */


#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneEntity.h"

/**
 * Class represents one of main 3D scene objects - Camera. In Space Invaders 3D there is static camera. 
 * All scene objects extends SceneEntity class to use Composite pattern.
 * @remarks
 */
class Camera : public SceneEntity
{
public:
	Vector3D rotation;

	Camera(Vector3D position);
	~Camera() {};

	void initCamera();
	void renderEntity() {}
	void updateEntity(const float elapsedTime);

	void wKeyPressed();
	void sKeyPressed();
	void aKeyPressed();
	void dKeyPressed();
	void eKeyPressed();
	void qKeyPressed();
};
#endif
