/**
 * File contains definition of DestroyEffect class.
 * @file    DestroyEffect.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-02
 * @version 1.0
 */

#include "DestroyEffect.hpp"

namespace specialFx
{

/**
 * Constructor with initialize parameters.
 * @param	origin is effect start position.
 */
DestroyEffect::DestroyEffect(const Vector3D& origin) : ParticleSystem(100)
{
	this->origin = origin;
	this->effectTime = 2.5f;
	this->isDead = false;

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(std::string("Particle"), std::string("Data/particle.png"), TEXTURE);
	initializeEffect();
}

/**
 * Destrcutor, free allocated memory.
 */
DestroyEffect::~DestroyEffect()
{

}

/**
 * Method is used to initialize particle.
 * @param	p is pointer to current initializing particle.
 */
void DestroyEffect::onInitialize(Particle* p)
{
	p->position = origin;
	
	p->size = 2.0f+FRAND/5;

	if(FRAND > 0)
	{
		p->velocity.x = 0;
		p->velocity.y = FRAND;
	}
	else
	{
		p->velocity.x = FRAND;
		p->velocity.y = 0;
	}
	
	p->velocity.z = 0;
	p->color.r = 1.0f;
	p->color.g = 1.0f;
	p->color.b = 1.0f;
	p->color.a = 0.5f + 0.1f*FRAND;
	//p->color.a = 1.0;
}

/**
 * Method is used to update particle.
 * @param	p is pointer to current initializing particle.
 * @param	elapsedTime	is time between frames.
 */
void DestroyEffect::onUpdate(Particle* p, const float elapsedTime)
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
void DestroyEffect::renderEffect()
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

		Texture* tempTexture = static_cast<Texture*>(texture.get());
		glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
		
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

		p = p->next;
		glPopMatrix();	
	}
	glEnable(GL_DEPTH_TEST);
}

}