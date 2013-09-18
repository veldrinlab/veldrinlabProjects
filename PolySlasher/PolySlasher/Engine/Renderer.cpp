/**
 * File contains Renderer class definition.
 * @file    Renderer.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-16
 * @version 1.0
 */

#include "Renderer.hpp"

using namespace std;
using namespace boost;

namespace Engine
{

/** 
 * Class constructor, get pointer to SceneManger to get actual scene tree to render.
 * @param sceneManager is pointer to current sceneManager.
 */
Renderer::Renderer(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
	glAccum(GL_LOAD, 1);

	motionBlurOn = false; 
	nightVisionOn = false;
}

/**
 * Destructor, noting to do, no memory to deallocate.
 */
Renderer::~Renderer()
{

}

/**
 * Main game engine drawing method, used to render scene. Use double-buffering. Clear current buffer,
 * render all entities from current scene and apply special effects.
 */
void Renderer::renderScene()
{
	//na razie chrzanic uk³ad sceny/shadery itp. samo wyœwietlanie.
	glClearColor (1.0f,1.0f,1.0f,0.0f);
	glClearAccum(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	sceneManager->getWorld()->renderEntity();
	sceneManager->getPlayer()->getSword()->renderEntity();
	sceneManager->getPlayer()->renderEntity();

	if(sceneManager->getPlayer()->isRage())
		motionBlurOn = true;
	else
		motionBlurOn = false;

	vector< boost::shared_ptr<SceneEntity> >* scene = sceneManager->getWorldScene();
	for(vector< boost::shared_ptr<SceneEntity> >::const_iterator i = scene->begin(); i != scene->end(); ++i)
		if((*i)->isVisible)
			(*i)->renderEntity();


	sceneManager->getGameHud()->renderGameHud();

	if(nightVisionOn)
		glColor3f(0.5f,0.5f,1.0f);

	if(motionBlurOn)
	{
		glAccum(GL_MULT, 0.9f);
		glAccum(GL_ACCUM, 0.1f);
		glAccum(GL_RETURN, 1);

	}
	SDL_GL_SwapBuffers();
}
}
