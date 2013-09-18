	/**
 * File contans definition of Camera class.
 * @file    Camera.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-09
 * @version 1.0
 */

#include "Camera.hpp"

namespace engine
{

/**
 * Definition of Camera class static members that represent 3D world axis.
 */
const Vector3D Camera::WORLD_XAXIS(1.0f, 0.0f, 0.0f);
const Vector3D Camera::WORLD_YAXIS(0.0f, 1.0f, 0.0f);
const Vector3D Camera::WORLD_ZAXIS(0.0f, 0.0f, 1.0f);

/**
 * Default Camera class constructor.
 */
Camera::Camera()
{
	position.set(0.0f, 0.0f, 0.0f);
	viewDirection.set(0.0f, 0.0f, -1.0f);
    xAxis.set(1.0f, 0.0f, 0.0f);
    yAxis.set(0.0f, 1.0f, 0.0f);
    zAxis.set(0.0f, 0.0f, 1.0f);
  
    rotationSpeed = 0.3f;
    fovX = 90.0f;
    aspectRatio = 0.0f;
    zNear = 0.1f;
    zFar = 300000.0f;   
        
    acceleration.set(400.0f, 400.0f, 400.0f);
    currentVelocity.set(0.0f, 0.0f, 0.0f);
    velocity.set(100.0f, 100.0f, 100.0f);

    orientation.identity();
    viewMatrix.identity();
    projectionMatrix.identity();
    viewProjectionMatrix.identity();

	accumPitchDegrees = 0.0f;

	direction.set(0.0f, 0.0f, -1.0f);
	dx = 0.0f;
	dy = 0.0f;
	dz = 0.0f;
	isDead = false;

	
	collisionBox = new BoundingBox();
	collisionBox->min = Vector3D(0.0f,0.0f,0.0f);
	collisionBox->max = Vector3D(0.0f,0.0f,0.0f);
}

/**
 * Object destructor, nothing to be done.
 */
Camera::~Camera()
{
  delete collisionBox;
}

/**
 * Method used as slot for wKeyPressed signal. Use boost::signal. Changes camera z position.
 */
void Camera::wKeyPressed()
{
	direction.z += 1.0f;
}

/**
 * Method used as slot for sKeyPressed signal. Use boost::signal. Changes camera z position.
 */
void Camera::sKeyPressed()
{
	direction.z -= 1.0f;
}

/**
 * Method used as slot for aKeyPressed signal. Use boost::signal. Changes camera x position.
 */
void Camera::aKeyPressed()
{
	direction.x -= 1.0f;

}

/**
 * Method used as slot for dKeyPressed signal. Use boost::signal. Changes camera x position.
 */
void Camera::dKeyPressed()
{
	direction.x += 1.0f;
}

/**
 * Method used as slot for eKeyPressed signal. Use boost::signal. Changes camera y position.
 */
void Camera::eKeyPressed()
{
	direction.y += 1.0f;
}

/**
 * Method used as slot for qKeyPressed signal. Use boost::signal. Changes camera y position.
 */
void Camera::qKeyPressed()
{
	direction.y -= 1.0f;
}

/**
 * Method used as slot for mouseMoved signal. Use boost::signal. Changes camera view direction.
 */
void Camera::mouseMoved()
{
	int currentMouseX = 400;
	int currentMouseY = 300;

	SDL_GetMouseState(&currentMouseX,&currentMouseY);
	
	dy = static_cast<float>(-(300 - currentMouseY));
	dz = static_cast<float>(400 - currentMouseX);
}

/**
 * Method is used to initialize Camera start position and pespective.
 */
void Camera::initCamera()
{
	perspective(fovX, static_cast<float>(800) / static_cast<float>(600), zNear, zFar);
	SDL_WarpMouse(400, 300);
}

/**
 * Method is used to update entity.
 * @param   elapsedTime is delta time between frames used to update entity physics.
 */
void Camera::updateEntity(const float elapsedTime)
{
	rotateSmoothly(0.0f, dy, dz);

    if ((dx = -direction.x * 10.0f* elapsedTime) != 0.0f)
		rotate(dx, 0.0f, 0.0f);

    direction.x = 0.0f;
    updatePosition(direction, elapsedTime);

	SDL_WarpMouse(400, 300);
	direction.set(0.0f, 0.0f, 0.0f);
	dx = 0.0f;
	dy = 0.0f;
	dz = 0.0f;
}

/**
 * Method is used to render entity, set projection and view matrix calculated by camera.
 */
void Camera::renderEntity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(&getProjectionMatrix()[0][0]);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(&getViewMatrix()[0][0]);
}	

/**
 * Method is used to set camera looking point to target.
 * @param	targer is target point vector.
 */
void Camera::lookAt(const Vector3D& target)
{
	lookAt(position, target, yAxis);
}
/**
 * Method is used to set camera looking point to target.
 * @param	position is camera eye position.
 * @param	targer is target point vector.
 * @param	up is ortogonal y axis vector to camera.
 */

void Camera::lookAt(const Vector3D& position, const Vector3D& target, const Vector3D& up)
{
	this->position = position;

    zAxis = position - target;
    zAxis.normalize();
    viewDirection = -zAxis;
	
    xAxis = Vector3D::cross(up, zAxis);
    xAxis.normalize();

    yAxis = Vector3D::cross(zAxis, xAxis);
    yAxis.normalize();
    
    viewMatrix[0][0] = xAxis.x;
    viewMatrix[1][0] = xAxis.y;
    viewMatrix[2][0] = xAxis.z;
    viewMatrix[3][0] = -Vector3D::dot(xAxis, position);

    viewMatrix[0][1] = yAxis.x;
    viewMatrix[1][1] = yAxis.y;
    viewMatrix[2][1] = yAxis.z;
    viewMatrix[3][1] = -Vector3D::dot(yAxis, position);

    viewMatrix[0][2] = zAxis.x;
    viewMatrix[1][2] = zAxis.y;
    viewMatrix[2][2] = zAxis.z;    
    viewMatrix[3][2] = -Vector3D::dot(zAxis, position);
    
    orientation.fromMatrix(viewMatrix);
	updateViewMatrix();
}

/**
 * Method is used to move the camera by dx world units to the left or right, dy
   world units upwards or downwards and dz world units forwards or backwards.
 * @param   dx is xAxis world unit delta to move
 * @param   dy is yAxis world unit delta to move
 * @param   dz is zAxis world unit delta to move
 */
void Camera::move(const float dx,const float dy,const float dz)
{
    Vector3D position = this->position;
    Vector3D forwards = viewDirection;
    
	position += xAxis * dx;
    position += WORLD_YAXIS * dy;
    position += forwards * dz;

    setPosition(position);
}

/**
 * Method is used to move the camera by the specified amount of world units in the specified
 * direction in world space.
 * @param   direction is move direction vector.
 * @param   amount is specified amount of world units.
 */
void Camera::move(const Vector3D& direction, const Vector3D& amount)
{
    // Moves the camera by the specified amount of world units in the specified
    // direction in world space.

    position.x += direction.x * amount.x;
    position.y += direction.y * amount.y;
    position.z += direction.z * amount.z;

    updateViewMatrix();
}

/**
 * Method is used to construct projection matrix based on the horiznotal field of view.
 * @param   fovx is horizontal field of view.
 * @param   aspect  is the ratio of x (width) to y (height).              
 * @param   znear is the distance from the viewer to the near clipping plane.
 * @param   zfar is the distance from the viewer to the far clipping plane.
 */
void Camera::perspective(const float fovx,const float aspect,const float znear,const float zfar)
{
    // Construct a projection matrix based on the horizontal field of view
    // 'fovx' rather than the more traditional vertical field of view 'fovy'.

    float e = 1.0f / tanf( 3.14f*fovx/180 / 2.0f  );
    float aspectInv = 1.0f / aspect;
    float fovy = 2.0f * atanf(aspectInv / e);
    float xScale = 1.0f / tanf(0.5f * fovy);
    float yScale = xScale / aspectInv;

    projectionMatrix[0][0] = xScale;
    projectionMatrix[0][1] = 0.0f;
    projectionMatrix[0][2] = 0.0f;
    projectionMatrix[0][3] = 0.0f;

    projectionMatrix[1][0] = 0.0f;
    projectionMatrix[1][1] = yScale;
    projectionMatrix[1][2] = 0.0f;
    projectionMatrix[1][3] = 0.0f;

    projectionMatrix[2][0] = 0.0f;
    projectionMatrix[2][1] = 0.0f;
    projectionMatrix[2][2] = (zfar + znear) / (znear - zfar);
    projectionMatrix[2][3] = -1.0f;

    projectionMatrix[3][0] = 0.0f;
    projectionMatrix[3][1] = 0.0f;
    projectionMatrix[3][2] = (2.0f * zfar * znear) / (znear - zfar);
    projectionMatrix[3][3] = 0.0f;

    viewProjectionMatrix = viewMatrix * projectionMatrix;
    
    this->fovX = fovx;
    this->aspectRatio = aspect;
    this->zNear = znear;
    this->zFar = zfar;
}

/**
 * Method is used to rotate flight camera by euler angles.
 * @param   headingDegrees is zAxis angle
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle
 */
void Camera::rotate(float headingDegrees,float pitchDegrees,float rollDegrees)
{
    pitchDegrees = -pitchDegrees;
    headingDegrees = -headingDegrees;
    rollDegrees = -rollDegrees;

	rotateFlight(headingDegrees, pitchDegrees, rollDegrees);

    updateViewMatrix();
}

/**
 * Method is used to apply a scaling factor to the rotation angles prior to using these rotation
 * angles to rotate the camera. This method is usually called when the camera is being rotated using an
 * input device. 
 * @param   headingDegrees is zAxis angle
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle
 */
void Camera::rotateSmoothly(float headingDegrees,float pitchDegrees,float rollDegrees)
{
    // This method applies a scaling factor to the rotation angles prior to
    // using these rotation angles to rotate the camera. This method is usually
    // called when the camera is being rotated using an input device (such as a
    // mouse or a joystick). 

    headingDegrees *= rotationSpeed;
    pitchDegrees *= rotationSpeed;
    rollDegrees *= rotationSpeed;

    rotate(headingDegrees, pitchDegrees, rollDegrees);
}

/**
 * Method used to move the camera using Newton's second law of motion.
 * @param   direction is move direction vector.
 * @param   elapsedTime is time between frames in seconds.
 */
void Camera::updatePosition(const Vector3D& direction,const float elapsedTime)
{
    if (currentVelocity.magnitudeSq() != 0.0f)
	{
        Vector3D displacement = (currentVelocity * elapsedTime) +
            (0.5f * acceleration * elapsedTime * elapsedTime);

        if (direction.x == 0.0f && currentVelocity.x == 0.0f)
            displacement.x = 0.0f;

        if (direction.y == 0.0f && currentVelocity.y == 0.0f)
            displacement.y = 0.0f;

        if (direction.z == 0.0f && currentVelocity.z == 0.0f)
            displacement.z = 0.0f;

        move(displacement.x, displacement.y, displacement.z);
    }

    updateVelocity(direction, elapsedTime);
}

/**
 * Method is used to rotate flight camera by euler angles.
 * @param   headingDegrees is zAxis angle
 * @param   pitchDegrees is yAxis angle.
 * @param   rollDegrees is xAxis angle
 */
void Camera::rotateFlight(const float headingDegrees,const float pitchDegrees,const float rollDegrees)
{
    accumPitchDegrees += pitchDegrees;

    if (accumPitchDegrees > 360.0f)
        accumPitchDegrees -= 360.0f;

    if (accumPitchDegrees < -360.0f)
        accumPitchDegrees += 360.0f;
   
    Quaternion rotation;

    rotation.fromHeadPitchRoll(headingDegrees, pitchDegrees, rollDegrees);
    orientation *= rotation;
}

/**
 * Method is used to update current velocity from actual move direction and elapsedTime
 * @param   direction is current moving direction vector.
 * @param   elapsedTimeSec is time between frames in second.
 */
void Camera::updateVelocity(const Vector3D& direction,const float elapsedTime)
{
    if (direction.x != 0.0f)
    {
        // Camera is moving along the x axis.
        // Linearly accelerate up to the camera's max speed.

        currentVelocity.x += direction.x * acceleration.x * elapsedTime;

        if (currentVelocity.x > velocity.x)
            currentVelocity.x = velocity.x;
        else if (currentVelocity.x < -velocity.x)
            currentVelocity.x = -velocity.x;
    }
    else
    {
        // Camera is no longer moving along the x axis.
        // Linearly decelerate back to stationary state.

        if (currentVelocity.x > 0.0f)
        {
            if ((currentVelocity.x -= acceleration.x * elapsedTime) < 0.0f)
                currentVelocity.x = 0.0f;
        }
        else
        {
            if ((currentVelocity.x += acceleration.x * elapsedTime) > 0.0f)
                currentVelocity.x = 0.0f;
        }
    }

    if (direction.y != 0.0f)
    {
        // Camera is moving along the y axis.
        // Linearly accelerate up to the camera's max speed.

        currentVelocity.y += direction.y * acceleration.y * elapsedTime;
        
        if (currentVelocity.y > velocity.y)
            currentVelocity.y = velocity.y;
        else if (currentVelocity.y < -velocity.y)
            currentVelocity.y = -velocity.y;
    }
    else
    {
        // Camera is no longer moving along the y axis.
        // Linearly decelerate back to stationary state.

        if (currentVelocity.y > 0.0f)
        {
            if ((currentVelocity.y -= acceleration.y * elapsedTime) < 0.0f)
                currentVelocity.y = 0.0f;
        }
        else
        {
            if ((currentVelocity.y += acceleration.y * elapsedTime) > 0.0f)
                currentVelocity.y = 0.0f;
        }
    }

    if (direction.z != 0.0f)
    {
        // Camera is moving along the z axis.
        // Linearly accelerate up to the camera's max speed.

        currentVelocity.z += direction.z * acceleration.z * elapsedTime;

        if (currentVelocity.z > velocity.z)
            currentVelocity.z = velocity.z;
        else if (currentVelocity.z < -velocity.z)
            currentVelocity.z = -velocity.z;
    }
    else
    {
        // Camera is no longer moving along the z axis.
        // Linearly decelerate back to stationary state.

        if (currentVelocity.z > 0.0f)
        {
            if ((currentVelocity.z -= acceleration.z * elapsedTime) < 0.0f)
                currentVelocity.z = 0.0f;
        }
        else
        {
            if ((currentVelocity.z += acceleration.z * elapsedTime) > 0.0f)
                currentVelocity.z = 0.0f;
        }
    }
}

/**
 * Method is used to reconstruct and update camera view matrix.
 */
void Camera::updateViewMatrix()
{
    viewMatrix = orientation.toMatrix4();

    xAxis.set(viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
    yAxis.set(viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);
    zAxis.set(viewMatrix[0][2], viewMatrix[1][2], viewMatrix[2][2]);
    viewDirection = -zAxis;

    viewMatrix[3][0] = -Vector3D::dot(xAxis, position);
    viewMatrix[3][1] = -Vector3D::dot(yAxis, position);
    viewMatrix[3][2] = -Vector3D::dot(zAxis, position);
}

/**
 * Method is used to set camera acceleration.
 * @param   acceleration is new camera acceleration vector.
 */
void Camera::setAcceleration(const Vector3D& acceleration)
{
    this->acceleration = acceleration;
}

/**
 * Method is used to set camera current velocity vector.
 * @param   currentVelocity is new camera velocity vector.
 */
void Camera::setCurrentVelocity(const Vector3D& currentVelocity)
{
    this->currentVelocity = currentVelocity;
}

/**
 * Method is used to set camera current velocity
 * @param   x is new velocity xAxis value.
 * @param   y is new velocity yAxis value.
 * @param   z is new velocity zAxis value.
 */
void Camera::setCurrentVelocity(const float x,const float y, const float z)
{
    currentVelocity.set(x, y, z);
}

/**
 * Methos is used to set camera new position vector and update view matrix.
 * @param   newPosition is camera new position vector.
 */
void Camera::setPosition(const Vector3D& newPosition)
{
    position = newPosition;
    updateViewMatrix();
}

/**
 * Method is used to set camera rotation speed, rhis is just an arbitrary value used to scale rotations
 * when rotateSmoothly() is called.
 * @param   rotationSpeed is new camera rotation speed value.
 */
void Camera::setRotationSpeed(const float rotationSpeed)
{
    this->rotationSpeed = rotationSpeed;
}

/**
 * Method is used to set camera velocity vector.
 * @param  velocity is new camera velocity vector.
 */
void Camera::setVelocity(const Vector3D& velocity)
{
    this->velocity = velocity;
}


/**
 * Method is used to set camera velocity vector.
 * @param   x is new velocity xAxis value.
 * @param   y is new velocity yAxis value.
 * @param   z is new velocity zAxis value.
 */
void Camera::setVelocity(const float x,const float y,const float z)
{
    velocity.set(x, y, z);
}

/**
 * Accesor to acceleration vector.
 * @return	camera acceleration vector.
 */
const Vector3D &Camera::getAcceleration() const
{ 
	return acceleration;
}

/**
 * Accesor to current velocity vector.
 * @return	camera current velocity vector.
 */
const Vector3D &Camera::getCurrentVelocity() const
{
	return currentVelocity;
}

/**
 * Accesor to position vector.
 * @return	camera position vector.
 */
const Vector3D &Camera::getPosition() const
{
	return position;
}

/**
 * Accesor to orientation quaternion
 * @return	camera orientation quaternion
 */
Quaternion& Camera::getOrientation()
{
	return orientation;
}

/**
 * Accesor to rotation speed value.
 * @return	camera rotation speed.
 */
float Camera::getRotationSpeed() const
{
	return rotationSpeed;
}

/**
 * Accesor to projection matrix.
 * @return	projection matrix.
 */
const Matrix4& Camera::getProjectionMatrix() const
{
	return projectionMatrix;
}

/**
 * Accesor to view direction vector.
 * @return	camera velocity vector.
 */
const Vector3D& Camera::getVelocity() const
{
	return velocity;
}

/**
 * Accesor to view direction vector.
 * @return	camera view direction vector.
 */
const Vector3D& Camera::getViewDirection() const
{
	return viewDirection;
}

/**
 * Accesor to view matrix.
 * @return	view matrix.
 */
const Matrix4& Camera::getViewMatrix() const
{
	return viewMatrix;
}

/**
 * Accesor to view-projection matrix.
 * @return	view-projection matrix.
 */
const Matrix4& Camera::getViewProjectionMatrix() const
{
	return viewProjectionMatrix;
}

/**
 * Accesor to xAxis vector.
 * @return	xAxis vector.
 */
const Vector3D& Camera::getXAxis() const
{
	return xAxis;
}

/**
 * Accesor to yAxis vector.
 * @return	yAxis vector.
 */
const Vector3D& Camera::getYAxis() const
{ 
	return yAxis; 
}

/**
 * Accesor to zAxis vector.
 * @return	zAxis vector.
 */
const Vector3D& Camera::getZAxis() const
{
	return zAxis; 
}

}