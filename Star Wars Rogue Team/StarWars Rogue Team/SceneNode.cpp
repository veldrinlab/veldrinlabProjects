/**
 * File contains definition of SceneNode class.
 * @file    SceneNode.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-19
 * @version 1.0
 */

#include "SceneNode.hpp"

namespace engine
{

/**
 * Default node constructor.
 */
SceneNode::SceneNode()
{
	parentNode = childNode = NULL;
    prevNode = nextNode = this;
}

/**
 * Constructor, initializes object by given parent Node.
 * @param	sceneNode is new Node parent
 */
SceneNode::SceneNode(SceneNode *sceneNode)
{
	parentNode = childNode = NULL;
    prevNode = nextNode = this;
    attachToParentNode(sceneNode);
}

/**
 * Destrcutor, detaches from parent and deletes all children.
 */
SceneNode::~SceneNode()
{
	detachNodeFromParent();
	
	while(childNode)
		delete childNode;
}

/**
 * Method is used to check if node has parent.
 * @return	true if node has parent.
 */
bool SceneNode::hasParent()
{
	return (parentNode != NULL);
}

/**
 * Method is used to check if node has children.
 * @return	true if node has children.
 */
bool SceneNode::hasChild()
{
	return (childNode != NULL);
}

/**
 * Method is used to check if node is a first child. First checks if node has parent.
 * @return	true if node is first child of his parent.
 */
bool SceneNode::isFirstChild()
{
	if (parentNode)
		return (parentNode->childNode == this);
    else
		return false;
}

/**
 * Method is used to check if node is a last child. First checks if node has parent.
 * @return	true if node is the last child of his parent.
 */
bool SceneNode::isLastChild()
{
	if (parentNode)
		return (parentNode->childNode->prevNode == this);
    else
		return false;
}

/**
 * Method used to attach a new node to the parent. If a node has a parent, detach from old parent and attach to the new one.
 * @param	newParent is node new parent node.
 */
void SceneNode::attachToParentNode(SceneNode* newParent)
{
	if (parentNode)
		detachNodeFromParent();

    parentNode = newParent;

	if (parentNode->childNode)
	{
		prevNode = parentNode->childNode->prevNode;
        nextNode = parentNode->childNode;
        parentNode->childNode->prevNode->nextNode = this;
        parentNode->childNode->prevNode = this;
    }
    else
		parentNode->childNode = this;
}

/**
 * Method used to attach a new child to the node. If a new child's node has a parent, detach from old parent.
 * @param	newChild is node new children node.
 */
void SceneNode::attachChildToNode(SceneNode* newChild)
{
	if (newChild->hasParent())
		newChild->detachNodeFromParent();

    newChild->parentNode = this;

    if (childNode)
	{
		newChild->prevNode = childNode->prevNode;
        newChild->nextNode = childNode;
        childNode->prevNode->nextNode = newChild;
        childNode->prevNode = newChild;
     }
     else
		 childNode = newChild;
}

/**
 * Method used to detach a node from parent.
 */
void SceneNode::detachNodeFromParent()
{
	if (parentNode && parentNode->childNode == this)
    {
		if (nextNode != this)
			parentNode->childNode = nextNode;
        else
            parentNode->childNode = NULL;
    }
    
	prevNode->nextNode = nextNode;
    nextNode->prevNode = prevNode;
	prevNode = this;
    nextNode = this;
}

/**
 * Method used to count current node children.
 * @return	current node children number.
 */
int SceneNode::countChildNodes()
{
	if (childNode)
		return childNode->countChildNodes() + 1;
    else
		return 0;
}

}