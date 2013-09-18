/**
 * File contains declarations of classes Timer_test and Timer_test_suite.
 * @file    TimerTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-02
 * @version 1.0
 */

#ifndef TIMER_TEST_H
#define TIMER_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Timer.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace engine;

namespace test
{
/**
 * Class represents Timer test class.
 */
class Timer_test
{
  public:
    Timer_test() {}

    void test_Timer();

  private:
    boost::ptr_vector<Timer> t;
};

/**
 * Class represents Timer test suite.
 */
class Timer_test_suite : public test_suite
{
   public:

   Timer_test_suite() : test_suite("Timer_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Timer_test> instance(new Timer_test());

      // create the test cases
      test_case* test_Timer_test_case = BOOST_CLASS_TEST_CASE(
                              &Timer_test::test_Timer, instance );

      // add the test cases to the test suite
      add(test_Timer_test_case);
   }
};

}
#endif
