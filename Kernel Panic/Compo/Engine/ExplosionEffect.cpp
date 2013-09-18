/**
 * File contains definition of ExplotionEffect class.
 * @file    ExplosionEffect.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-02
 * @version 1.0
 */

#include "ExplosionEffect.hpp"

using namespace std;
using namespace Math;
using namespace Resource;

namespace Engine
{

/**
 * Constructor with initialize parameters.
 * @param	origin is effect start position.
 */
ExplosionEffect::ExplosionEffect(const Vector3D& origin) : ParticleSystem(100)
{
	this->origin = origin;
	this->effectTime = 2.5f;
	this->isDead = false;

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("Particle"), string("Data/particle.png"), TEXTURE);

	initialize();
}

/**
 * Destrcutor, free allocated memory.
 */
ExplosionEffect::~ExplosionEffect()
{
	
}

/**
 * Method is used to initialize particle.
 * @param	p is pointer to current initializing particle.
 */
void ExplosionEffect::onInitialize(Particle* p)
{
	p->position = origin;
	
	p->size = 2.0f+FRAND/5;

	p->velocity.x = FRAND;
	p->velocity.y = FRAND;
	p->velocity.z = 0;

	p->color.r = 1.0f;
	p->color.g = 0.0f;
	p->color.b = 1.0f;
	p->color.a = 0.2f + 0.1f*FRAND;
	//p->color.a = 1.0;
	
}

/**
 * Method is used to update particle.
 * @param p    is pointer to current initializing particle.
 * @param elapsedTime	is time between frames.
 */
void ExplosionEffect::onUpdate(Particle* p, const float elapsedTime)
{
	p->color.a = p->color.a - 0.1f * elapsedTime;
	p->size += 0.1f * elapsedTime;
	p->velocity += p->velocity * elapsedTime * 0.2f;
	p->position += p->velocity * elapsedTime * 5;

	effectTime -= elapsedTime/100;
	if(effectTime <= 0.0f)
		isDead = true;
}

/**
 * Method is used to render special effect.
 */
void ExplosionEffect::renderEffect()
{
	Particle *p = firstParticle;
	glDisable(GL_DEPTH_TEST);
	while(p)
	{
		glPushMatrix();
		GLfloat size = p->size/2;
		Vector3D pos = p->position;

		glTranslatef(pos.x,pos.y,pos.z);

		float modelview[16];
		glGetFloatv(GL_MODELVIEW_MATRIX , modelview);

		for(int i=0; i<3; ++i ) 
			for(int j=0; j<3; ++j )
			{
				if ( i==j )
					modelview[i*4+j] = 1.0;
				else
					modelview[i*4+j] = 0.0;
			}

		glLoadMatrixf(modelview);

		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(p->color.r, p->color.g, p->color.b, p->color.a);
		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 0.0f, 0.0f, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f( 3.0f, 0.0f, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f(3.0F,3.0f, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 0.0f, 3.0f, 0 );
		glEnd();
		glColor4f(1.0f,1.0f,1.0f,1.0f);

		p = p->next;
		glPopMatrix();	
	}
	glEnable(GL_DEPTH_TEST);
}

}