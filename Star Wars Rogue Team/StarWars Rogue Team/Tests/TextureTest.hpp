/**
 * File contains declarations of classes Texture_test and Texture_test_suite.
 * @file    TextureTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-03
 * @version 1.0
 */

#ifndef TEXTURE_TEST_H
#define TEXTURE_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../ResourceManager/Texture.hpp"
#include "../ResourceManager/Resource.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace resMan;

namespace test
{

/**
 * Class represents Texture test class.
 */
class Texture_test
{
  public:
    Texture_test() {}

    void test_Texture();

  private:
    boost::ptr_vector<Texture> t;
};

/**
 * Class represents Texture class test suite.
 */
class Texture_test_suite : public test_suite
{
   public:

   Texture_test_suite() : test_suite("Texture_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Texture_test> instance(new Texture_test());

      // create the test cases
      test_case* test_Texture_test_case = BOOST_CLASS_TEST_CASE(
                              &Texture_test::test_Texture, instance );

      // add the test cases to the test suite
      add(test_Texture_test_case);
   }
};

}
#endif
