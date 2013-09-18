/**
 * File contains declarations of classes Camera_test and Camera_test_suite.
 * @file    CameraTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef CAMERA_TEST_H
#define CAMERA_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Camera.hpp"
#include "../Matrix4.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

/**
 * Class represents Camera test class.
 */
class Camera_test
{
  public:
    Camera_test() {}

    void test_KeysPressed();
  	void test_mouseMoved();
	  void test_initCamera();
	  void test_updateEntity();

  private:
    bool compare(Matrix4 matrix, float tab[4][4]);
};

/**
 * Class represents Camera test suite.
 */
class Camera_test_suite : public test_suite
{
   public:

   Camera_test_suite() : test_suite("Camera_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Camera_test> instance(new Camera_test());

      // create the test cases
      test_case* KeysPressed_test_case = BOOST_CLASS_TEST_CASE(
                              &Camera_test::test_KeysPressed, instance );
      test_case* mouseMoved_test_case = BOOST_CLASS_TEST_CASE(
                              &Camera_test::test_mouseMoved, instance );
      test_case* initCamera_test_case = BOOST_CLASS_TEST_CASE(
                              &Camera_test::test_initCamera, instance );
      test_case* updateEntity_test_case = BOOST_CLASS_TEST_CASE(
                              &Camera_test::test_updateEntity, instance );

      // add the test cases to the test suite
      add(KeysPressed_test_case);
      add(mouseMoved_test_case);
      add(initCamera_test_case);
      add(updateEntity_test_case);
   }
};

}
#endif
