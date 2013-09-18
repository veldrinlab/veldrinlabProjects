#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SDL.h>
#include <SDL_opengl.h> 
#include <GL/gl.h>
#include <GL/glu.h>

#include "../Utils/Random.hpp"
#include "../ResourceManager/Texture.hpp"
#include "../Math/Vector3D.hpp"


#define FRAND ((float)(rand()-rand())/RAND_MAX)

namespace Engine
{

/**
 * Class represents basic part of ParticleSystem - Particle which represents particle state.
 * @remarks	maybe add ParticleState class, or just change class name.
 */
class Particle
{
public:
	Particle *next;

	Math::Vector3D position;
	Math::Vector3D velocity;
	Math::Vector3D accelration;
	Math::Vector3D rotation;
	Utils::Color color;
	float lifeTime;
	float size;
	bool isDied;

	Particle();
	~Particle();

};

/**
 * Class represents ParticleSystem which is abstract base class of all particle effects emiters.
 * @remarks	maybe make something like System and Emitters.
 */
class ParticleSystem
{
protected:
	Particle *firstParticle;
	bool isDead;
	
	virtual void onInitialize(Particle *p) = 0;
	virtual void onUpdate(Particle *p, const float elapsedTime) = 0;

public:
	ParticleSystem(const int numParticles);
	virtual ~ParticleSystem();

	void initialize();
	void update(const float elapsedTime);
	virtual void renderEffect() = 0;

	bool isEnd()
	{
		return isDead;
	}
};

}
#endif