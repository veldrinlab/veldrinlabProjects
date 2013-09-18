/**
 * File contains declarations of classes MenuStates_test and MenuStates_test_suite.
 * @file    MenuStatesTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-12
 * @version 1.0
 */

#ifndef MENU_STATES_TEST
#define MENU_STATES_TEST

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "../BackMenuState.hpp"
#include "../ColorDepthMenuState.hpp"
#include "../Menu/CreditsMenuState.hpp"
#include "../GameMenuState.hpp"
#include "../Menu/OptionsMenuState.hpp"
#include "../Menu/QuitMenuState.hpp"
#include "../ResolutionMenuState.hpp"
#include "../Menu/ShowCreditsMenuState.hpp"
#include "../ShowOptionsMenuState.hpp"
#include "../ChooseLevelMenuState.hpp"

#include "MyMenuStates.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace menu;

namespace test
{

/**
 * Class represents MenuStates test class.
 */
class MenuStates_test
{
  public:
    MenuStates_test() {}

    void test_MenuStates();
  private:
    void checkChangeStateDown(IMenuState* ms, ClassID type);
    void checkChangeStateUp(IMenuState* ms, ClassID type);
    void checkPerformAction(IMenuState* ms, ClassID type);
};

/**
 * Class represents MenuStates test suite.
 */
class MenuStates_test_suite : public test_suite
{
   public:

   MenuStates_test_suite() : test_suite("MenuStates_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<MenuStates_test> instance(new MenuStates_test());

      // create the test cases
      test_case* test_MenuStates_test_case = BOOST_CLASS_TEST_CASE(
                              &MenuStates_test::test_MenuStates, instance );

      // add the test cases to the test suite
      add(test_MenuStates_test_case);
   }
};

}
#endif