#include "HealthBar.hpp"

using namespace std;
using namespace Engine;
using namespace Resource;
using namespace Math;

namespace Game
{
	HealthBar::HealthBar(SceneEntity* entity)
	{
		this->entity = entity;
		maxValue = entity->healthPoints;

	}

	HealthBar::~HealthBar()
	{

	}

	void HealthBar::renderHealthBar()
	{
		if(entity->healthPoints != maxValue)
		{
			glPushMatrix();
			glTranslatef(entity->position.x - entity->width/3, entity->position.y + entity->height/2+5,entity->position.z);

			glBegin(GL_QUADS);
				glTexCoord2i(0,0);
				glVertex2f(0.0f, 0.0f);
				glTexCoord2i(1,0);
				glVertex2f( 1.0f * entity->healthPoints, 0.0f);
				glTexCoord2i(1,1);
				glVertex2f( 1.0f * entity->healthPoints, 5.0f);
				glTexCoord2i(0,1);
				glVertex2f(0.0f,5.0f);
			glEnd();
			glPopMatrix();
		}
	}
}