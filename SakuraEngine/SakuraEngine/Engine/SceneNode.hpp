/**
 * File contains definition of 3D scene basic element - SceneNode class.
 * @file    SceneNode.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0 
 */

#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include <stdio.h>

namespace Engine
{

/**
 * SceneNode class represents node of three dimmension scene tree. All objects of our World are nodes of current
 * level scene tree. It is very usefull for creating scene and render it. Renderer object need only pointer to      * current scene root. Also it's faster solution than dymanic array or vector structure. 
 * @remarks 
 */
class SceneNode
{
public:
     SceneNode *parentNode;
     SceneNode *childNode;
     SceneNode *prevNode;
     SceneNode *nextNode;

	 SceneNode();
	 SceneNode(SceneNode* sceneNode);
	 virtual ~SceneNode();

	 void attachToParentNode(SceneNode* newParent);
	 void attachChildToNode(SceneNode* newChild);
	 void detachNodeFromParent();
	 bool hasParent();
	 bool hasChild();
	 bool isFirstChild();
	 bool isLastChild();
	 int countChildNodes();

};

}
#endif
