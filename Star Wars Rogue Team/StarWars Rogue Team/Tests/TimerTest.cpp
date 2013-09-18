/**
 * File contains class Timer_test definition.
 * @file    TimerTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-02
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

#include "TimerTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;


namespace test
{

/**
 * Test Timer class methods.
 */
void Timer_test::test_Timer()
{
  Timer tm = Timer();
  tm.updateTimerData();
  tm.updateFramesData();
#ifdef _WIN32
  Sleep(1000);
#else
  sleep(1);
#endif

  tm.updateTimerData();
  tm.updateFramesData();
  BOOST_CHECK(tm.getElapsedTime() >= 1);
  BOOST_CHECK(tm.isSecondElapsed());

  tm.resetFrameData();
  tm.updateFpsData();
  float res = tm.getFramesPerSecond();
  BOOST_CHECK(res == 0);
}

}