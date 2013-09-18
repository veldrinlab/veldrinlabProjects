/**
 * File contains declarations of classes BoundingBox_test and BoundingBox_test_suite.
 * @file    BoundingBoxTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-01-03
 * @version 1.0
 */

#ifndef BoundingBox_TEST_H
#define BoundingBox_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../BoundingBox.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace engine;

namespace test
{
/**
 * Class represents BoundingBox test class.
 */
class BoundingBox_test
{
  public:
    BoundingBox_test() {}

    void test_BoundingBox();

  private:
    bool compare(Vector3D& vec1, Vector3D& vec2);
};

/**
 * Class represents BoundingBox test suite.
 */
class BoundingBox_test_suite : public test_suite
{
   public:

   BoundingBox_test_suite() : test_suite("BoundingBox_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<BoundingBox_test> instance(new BoundingBox_test());

      // create the test cases
      test_case* test_BoundingBox_test_case = BOOST_CLASS_TEST_CASE(
                              &BoundingBox_test::test_BoundingBox, instance );

      // add the test cases to the test suite
      add(test_BoundingBox_test_case);
   }
};

}
#endif