/**
 * File contains declarations of classes SceneNodeTest and SceneNode_test_suite.
 * @file    SceneNodeTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-11-29
 * @version 1.0
 */

#ifndef SCENE_NODE_TEST_H
#define SCENE_NODE_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../SceneNode.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace engine;

namespace test
{

/**
 * Class represents SceneNode test class.
 */
class SceneNode_test
{
  public:
    SceneNode_test() {}

    void test_attachToParentNode();
    void test_attachChildToNode();
    void test_detachNodeFromParent();
    void test_hasParent();
    void test_hasChild();
    void test_isFirstChild();
    void test_isLastChild();
    void test_countChildNodes();

  private:
    boost::ptr_vector<SceneNode> sn;
};

/**
 * Class represents SceneNode test suite.
 */
class SceneNode_test_suite : public test_suite
{
   public:

   SceneNode_test_suite() : test_suite("SceneNode_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<SceneNode_test> instance(new SceneNode_test());

      // create the test cases
      test_case* attachToParentNode_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_attachToParentNode, instance );
      test_case* attachChildToNode_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_attachChildToNode, instance );
      test_case* detachNodeFromParent_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_detachNodeFromParent, instance );
      test_case* hasParent_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_hasParent, instance );
      test_case* hasChild_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_hasChild, instance );
      test_case* isFirstChild_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_isFirstChild, instance );
      test_case* isLastChild_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_isLastChild, instance );
      test_case* countChildNodes_test_case = BOOST_CLASS_TEST_CASE(
                              &SceneNode_test::test_countChildNodes, instance );

      // add the test cases to the test suite
      add(attachToParentNode_test_case);
      add(attachChildToNode_test_case);
      add(detachNodeFromParent_test_case);
      add(hasParent_test_case);
      add(hasChild_test_case);
      add(isFirstChild_test_case);
      add(isLastChild_test_case);
      add(countChildNodes_test_case);
   }
};

}
#endif
