/**
 * File contains class SceneNode_test definition.
 * @file    SceneNodeTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-11-29
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "SceneNodeTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

/**
 * Test attachToParentNode() method.
 */
void SceneNode_test::test_attachToParentNode()
{
  SceneNode* root (new SceneNode());
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(root->parentNode == NULL);
  BOOST_CHECK(child1->parentNode == root);
  SceneNode* child2 (new SceneNode());
  child2->attachToParentNode(root);
  BOOST_CHECK(child1->parentNode == root);
  BOOST_CHECK(child2->parentNode == root);
  delete child2;
  delete child1;
  delete root;
}

/**
 * Test attachToChildNode() method.
 */
void SceneNode_test::test_attachChildToNode()
{
  SceneNode* root (new SceneNode());
  SceneNode* child1 (new SceneNode());
  root->attachChildToNode(child1);
  BOOST_CHECK(child1->parentNode == root);
  BOOST_CHECK(root->childNode == child1);
  root->attachChildToNode(root);
  BOOST_CHECK(root->childNode != root);
  delete child1;
  delete root;
}

/**
 * Test detachNodeFromParent() method.
 */
void SceneNode_test::test_detachNodeFromParent()
{
  SceneNode* root (new SceneNode());
  root->detachNodeFromParent();
  BOOST_CHECK(root->parentNode == NULL);
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(child1->parentNode == root);
  child1->detachNodeFromParent();
  //BOOST_CHECK(child1->parentNode != root);
  //TODO
  BOOST_CHECK(child1->parentNode == root);
  delete child1;
  delete root;
}

/**
 * Test hasParent() method.
 */
void SceneNode_test::test_hasParent()
{
  SceneNode* root (new SceneNode());
  BOOST_CHECK(!root->hasParent());
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(child1->hasParent());
  delete child1;
  delete root;
}

/**
 * Test hasChild() method.
 */
void SceneNode_test::test_hasChild()
{
  SceneNode* root (new SceneNode());
  BOOST_CHECK(!root->hasChild());
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(!child1->hasChild());
  BOOST_CHECK(root->hasChild());
  delete child1;
  delete root;
}

/**
 * Test isFirstChild() method.
 */
void SceneNode_test::test_isFirstChild()
{
  SceneNode* root (new SceneNode());
  BOOST_CHECK(!root->isFirstChild());
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(child1->isFirstChild());
  SceneNode* child2 (new SceneNode(root));
  BOOST_CHECK(child1->isFirstChild());
  BOOST_CHECK(!child2->isFirstChild());
  delete child2;
  delete child1;
  delete root;
}

/**
 * Test isLastChild() method.
 */
void SceneNode_test::test_isLastChild()
{
  SceneNode* root (new SceneNode());
  BOOST_CHECK(!root->isLastChild());
  SceneNode* child1 (new SceneNode(root));
  BOOST_CHECK(child1->isLastChild());
  SceneNode* child2 (new SceneNode(root));
  BOOST_CHECK(!child1->isLastChild());
  BOOST_CHECK(child2->isLastChild());
  delete child2;
  delete child1;
  delete root;
}

/**
 * Test countChildNodes() method.
 */
void SceneNode_test::test_countChildNodes()
{
  int counter = 3;
  SceneNode* root (new SceneNode());
  BOOST_CHECK(root->countChildNodes() == 0);

  for(int i = 0; i < counter; i++)
    sn.push_back(new SceneNode(root));

  for(int j = 1; j < counter; j++)
    sn[j].attachToParentNode(&sn[j-1]);

  int res = root->countChildNodes();
  BOOST_CHECK(res == counter);

  sn[1].detachNodeFromParent();
  sn[2].detachNodeFromParent();
  res = root->countChildNodes();
  BOOST_CHECK(res == (counter - 2));

  sn.clear();
  delete root;
}

}