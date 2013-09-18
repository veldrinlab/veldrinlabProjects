/**
 * File contains declarations of classes SpecialFXManager_test and SpecialFXManager_test_suite.
 * @file    SpecialFXManagerTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-30
 * @version 1.0
 */

#ifndef SpecialFXManager_TEST_H
#define SpecialFXManager_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "../SpecialFXManager.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace specialFx;

namespace test
{

class SpecialFXManager_test
{
  public:
    SpecialFXManager_test() {}

    void test_addSpecialEffect();
    void test_initializeUpdateEffects();
    void test_renderEffects();

  private:
    //boost::shared_ptr<SpecialFXManager> sfm;
};

class SpecialFXManager_test_suite : public test_suite
{
   public:

   SpecialFXManager_test_suite() : test_suite("SpecialFXManager_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<SpecialFXManager_test> instance(new SpecialFXManager_test());

      // create the test cases
      test_case* test_addSpecialEffect_test_case = BOOST_CLASS_TEST_CASE(
                              &SpecialFXManager_test::test_addSpecialEffect, instance );
      test_case* test_initializeUpdateEffects_test_case = BOOST_CLASS_TEST_CASE(
                              &SpecialFXManager_test::test_initializeUpdateEffects, instance );
      test_case* test_renderEffects_test_case = BOOST_CLASS_TEST_CASE(
                              &SpecialFXManager_test::test_renderEffects, instance );

      // add the test cases to the test suite
      add(test_addSpecialEffect_test_case);
      add(test_initializeUpdateEffects_test_case);
      add(test_renderEffects_test_case);
   }
};

}
#endif