/**
 * File contains declaration of Camera class.
 * @file    Camera.hpp
 * @author  Szymon Jab³oñski 
 * @date    2010-10-28
 * @version 1.0
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneEntity.hpp"
#include "Quaternion.hpp"

using namespace math;

namespace engine
{

/**
 * Camera class represents world Scene Camera object. Camera uses Quaternions to implement orientation rotation
 * and avoid Gimbal Lock problem. Camera is the main object used to control X-Wing; user input from keyboard, mouse
 * and gamepad update Camera position. View is TPP, Camera is always behind X-wing object.
 * @remarks change name to QuaternionCamera, build abstract camera class and maybe implement EulerCamera.
 */
class Camera : public SceneEntity
{
private:
    static const Vector3D WORLD_XAXIS;
    static const Vector3D WORLD_YAXIS;
    static const Vector3D WORLD_ZAXIS;

	Vector3D viewDirection;
    Vector3D currentVelocity;
	Vector3D xAxis;
    Vector3D yAxis;
    Vector3D zAxis;
    Matrix4 viewMatrix;
    Matrix4 projectionMatrix;
    Matrix4 viewProjectionMatrix;
	Quaternion orientation;

    float accumPitchDegrees;
    float rotationSpeed;
    float fovX;
    float aspectRatio;
    float zNear;
    float zFar;
	
    void rotateFlight(float headingDegrees, float pitchDegrees, float rollDegrees);
    void updateVelocity(const Vector3D& direction, const float elapsedTime);
    void updateViewMatrix();
    void move(const float dx,const float dy,const float dz);
    void move(const Vector3D& direction, const Vector3D& amount);
    void perspective(const float fovx,const float aspect,const float znear,const float zfar);
    void rotate(float headingDegrees,float pitchDegrees,float rollDegrees);
    void rotateSmoothly(float headingDegrees,float pitchDegrees,float rollDegrees);
    void updatePosition(const Vector3D& direction,const float elapsedTime);

public:
    Camera();
    ~Camera();
	
	Vector3D direction;
	float dx;
	float dy;
	float dz;

	void wKeyPressed();
	void sKeyPressed();
	void aKeyPressed();
	void dKeyPressed();
	void eKeyPressed();
	void qKeyPressed();
	void mouseMoved();

	void initCamera();
	void updateEntity(const float elapsedTime);
	void renderEntity();
	void lookAt(const Vector3D& target);
    void lookAt(const Vector3D& position, const Vector3D& target, const Vector3D& up);

    void setAcceleration(const Vector3D& acceleration);
    void setCurrentVelocity(const Vector3D& currentVelocity);
    void setCurrentVelocity(const float x,const float y,const float z);
    void setPosition(const Vector3D& newPosition);
    void setRotationSpeed(const float rotationSpeed);
    void setVelocity(const Vector3D& velocity);
    void setVelocity(const float x,const float y,const float z);

    const Vector3D& getAcceleration() const;
    const Vector3D& getCurrentVelocity() const;
    const Vector3D& getPosition() const;
    Quaternion& getOrientation();
    float getRotationSpeed() const;
    const Matrix4& getProjectionMatrix() const;
    const Vector3D& getVelocity() const;
    const Vector3D& getViewDirection() const;
    const Matrix4& getViewMatrix() const;
    const Matrix4& getViewProjectionMatrix() const;
    const Vector3D& getXAxis() const;
    const Vector3D& getYAxis() const;
    const Vector3D& getZAxis() const;
};

}
#endif
