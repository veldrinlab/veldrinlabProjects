/**
 * File contains main test suite definition.
 * @file    TestRunner.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-11-8
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include "TestClasses.hpp"

using boost::unit_test_framework::test_suite;
using namespace test;

/**
 * Test program entry point.
 */
test_suite* init_unit_test_suite(int argc, char* argv[])
{
  test_suite* top_test_suite = BOOST_TEST_SUITE( "Master test suite" );
  /* adding the test suites */
  top_test_suite->add(new Vector3D_test_suite());
  top_test_suite->add(new Matrix4_test_suite());
  top_test_suite->add(new Quaternion_test_suite());
  top_test_suite->add(new SceneNode_test_suite());
  top_test_suite->add(new Timer_test_suite());
  top_test_suite->add(new Camera_test_suite());
  top_test_suite->add(new Texture_test_suite());
  top_test_suite->add(new Mesh_test_suite());
  top_test_suite->add(new ResourceManager_test_suite());
  top_test_suite->add(new Color_test_suite());

  /* all MenuState classes are tested in one test suite: */
  top_test_suite->add(new MenuStates_test_suite());

  top_test_suite->add(new SpecialFXManager_test_suite());
  top_test_suite->add(new BoundingBox_test_suite());

  return top_test_suite;
}
