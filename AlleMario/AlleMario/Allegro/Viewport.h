/**
 * Viewport.h
 *
 * Viewport class represents visible space of game map that is drawn
 * on screen - game camera.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <allegro5/allegro5.h>

#include "Vector2D.h"

class Viewport
{
private:
	/* size of viewport in pixels */
	// rozmiar ekranu na ktorym rysuje
	float viewportWidth;
	float viewportHeight;

	/* position of top-left corner of viewport in the world */
	// pocztakowo (0,0) potem przesuwa siê X w prawo/lewo
	float worldX;
	float worldY;

	/* position of top-left corner of viewport in the screen */

	// zawsze (0,0) nie zmienia siê
	float screenX;
	float screenY;

	Vector2D velocity;
	bool viewportBlocked;


public:
	Viewport();
	~Viewport();
	
	void updateViewport(float dt, ALLEGRO_KEYBOARD_STATE key_state);

	void setViewportWidth(float viewportWidth);
	void setViewportHeight(float viewportHeight);
	void setWorldX(float worldX);
	void setWorldY(float worldY);
	void setScreenX(float screenX);
	void setScreenY(float screenY);

	float getViewportWidth();
	float getViewportHeight();
	float getWorldX();
	float getWorldY();
	float getScreenX();
	float getScreenY();

	void setViewportVelocity(Vector2D newVelocity);

};
#endif