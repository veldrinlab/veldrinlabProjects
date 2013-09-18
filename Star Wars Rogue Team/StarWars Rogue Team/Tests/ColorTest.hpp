/**
 * File contains declarations of classes Color_test and Color_test_suite.
 * @file    ColorTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-12
 * @version 1.0
 */

#ifndef COLOR_TEST_H
#define COLOR_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Color.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace engine;

namespace test
{

/**
 * Class represents Color test class.
 */
class Color_test
{
  public:
    Color_test() {}

    void test_Color();

  private:
    boost::ptr_vector<Color> col;
    bool compare(Color* c, float* tab);
};

/**
 * Class represents Color test suite.
 */
class Color_test_suite : public test_suite
{
   public:

   Color_test_suite() : test_suite("Color_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Color_test> instance(new Color_test());

      // create the test cases
      test_case* test_Color_test_case = BOOST_CLASS_TEST_CASE(
                              &Color_test::test_Color, instance );

      // add the test cases to the test suite
      add(test_Color_test_case);
   }
};

}
#endif