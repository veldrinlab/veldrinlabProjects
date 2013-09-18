/**
 * File contains class MenuStates_test definition.
 * @file    MenuStatesTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-12
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "MenuStatesTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

/*
 * Test MenuStates classes methods.
 */
void MenuStates_test::test_MenuStates()
{
  
  boost::ptr_vector<BackMenuState> bms;
  boost::ptr_vector<ColorDepthMenuState> cdms;
  boost::ptr_vector<CreditsMenuState> cms;
  boost::ptr_vector<GameMenuState> gms;
  boost::ptr_vector<OptionsMenuState> oms;
  boost::ptr_vector<QuitMenuState> qms;
  boost::ptr_vector<ResolutionMenuState> rmms;
  boost::ptr_vector<ShowCreditsMenuState> scms;
  boost::ptr_vector<ShowOptionsMenuState> soms;

  for(int i = 0; i < 3; i++)
  {
    bms.push_back(new BackMenuState());
    cdms.push_back(new ColorDepthMenuState);
    cms.push_back(new CreditsMenuState);
    gms.push_back(new GameMenuState);
    oms.push_back(new OptionsMenuState);
    qms.push_back(new QuitMenuState);
    rmms.push_back(new ResolutionMenuState);
    scms.push_back(new ShowCreditsMenuState);
    soms.push_back(new ShowOptionsMenuState);
  }

  checkChangeStateDown(&bms[0],  SHOW_OPTIONS_MS);
  checkChangeStateDown(&cdms[0], BACK_MS);
  checkChangeStateDown(&cms[0],  QUIT_MS);
  checkChangeStateDown(&gms[0],  OPTIONS_MS);
  checkChangeStateDown(&oms[0],  CREDITS_MS);
  checkChangeStateDown(&qms[0],  GAME_MS);
  checkChangeStateDown(&rmms[0], COLOR_DEPTH_MS);
  checkChangeStateDown(&scms[0], SHOW_CREDITS_MS);
  checkChangeStateDown(&soms[0], RESOLUTION_MS);
  
  checkChangeStateUp(&bms[1],  COLOR_DEPTH_MS);
  checkChangeStateUp(&cdms[1], RESOLUTION_MS);
  checkChangeStateUp(&cms[1],  OPTIONS_MS);
  checkChangeStateUp(&gms[1],  QUIT_MS);
  checkChangeStateUp(&oms[1],  GAME_MS);
  checkChangeStateUp(&qms[1],  CREDITS_MS);
  checkChangeStateUp(&rmms[1], SHOW_OPTIONS_MS);
  checkChangeStateUp(&scms[1], SHOW_CREDITS_MS);
  checkChangeStateUp(&soms[1], BACK_MS);

  checkPerformAction(&bms[2],  OPTIONS_MS);
  checkPerformAction(&cms[2],  SHOW_CREDITS_MS);
  checkPerformAction(&gms[2],  CHOOSE_LEVEL_MS);
  checkPerformAction(&oms[2],  SHOW_OPTIONS_MS);
  checkPerformAction(&qms[2],  NO_MS); ///
  checkPerformAction(&scms[2], CREDITS_MS);
}

/**
 * Test changeStateDown() method.
 * @param ms menu state
 * @type type of menu state
 */
void MenuStates_test::checkChangeStateDown(IMenuState* ms, ClassID type)
{
  IMenuState* r;
  switch(type)
  {
    case SHOW_OPTIONS_MS:
      r = dynamic_cast<ShowOptionsMenuState*> (ms->changeStateDown());
      break;
    case BACK_MS:
      r = dynamic_cast<BackMenuState*> (ms->changeStateDown());
      break;
    case COLOR_DEPTH_MS:
      r = dynamic_cast<ColorDepthMenuState*> (ms->changeStateDown());
      break;
    case CREDITS_MS:
      r = dynamic_cast<CreditsMenuState*> (ms->changeStateDown());
      break;
    case GAME_MS:
      r = dynamic_cast<GameMenuState*> (ms->changeStateDown());
      break;
    case OPTIONS_MS:
      r = dynamic_cast<OptionsMenuState*> (ms->changeStateDown());
      break;
    case QUIT_MS:
      r = dynamic_cast<QuitMenuState*> (ms->changeStateDown());
      break;
    case RESOLUTION_MS:
      r = dynamic_cast<ResolutionMenuState*> (ms->changeStateDown());
      break;
    case SHOW_CREDITS_MS:
      r = dynamic_cast<ShowCreditsMenuState*> (ms->changeStateDown());
      break;
  }
  BOOST_CHECK(r != NULL);
  delete r;
}

/**
 * Test changeStateUp() method.
 * @param ms menu state
 * @type type of menu state
 */
void MenuStates_test::checkChangeStateUp(IMenuState* ms, ClassID type)
{
  IMenuState* r;
  switch(type)
  {
    case SHOW_OPTIONS_MS:
      r = dynamic_cast<ShowOptionsMenuState*> (ms->changeStateUp());
      break;
    case BACK_MS:
      r = dynamic_cast<BackMenuState*> (ms->changeStateUp());
      break;
    case COLOR_DEPTH_MS:
      r = dynamic_cast<ColorDepthMenuState*> (ms->changeStateUp());
      break;
    case CREDITS_MS:
      r = dynamic_cast<CreditsMenuState*> (ms->changeStateUp());
      break;
    case GAME_MS:
      r = dynamic_cast<GameMenuState*> (ms->changeStateUp());
      break;
    case OPTIONS_MS:
      r = dynamic_cast<OptionsMenuState*> (ms->changeStateUp());
      break;
    case QUIT_MS:
      r = dynamic_cast<QuitMenuState*> (ms->changeStateUp());
      break;
    case RESOLUTION_MS:
      r = dynamic_cast<ResolutionMenuState*> (ms->changeStateUp());
      break;
    case SHOW_CREDITS_MS:
      r = dynamic_cast<ShowCreditsMenuState*> (ms->changeStateUp());
      break;
  }
  BOOST_CHECK(r != NULL);
  delete r;
}

/**
 * Test performAction() method.
 * @param ms menu state
 * @type type of menu state
 */
void MenuStates_test::checkPerformAction(IMenuState* ms, ClassID type)
{
  IMenuState* r;

  if(type == NO_MS)
  {
    r = ms->performAction();
    BOOST_CHECK(r == NULL);
    return;
  }

  switch(type)
  {
    case SHOW_OPTIONS_MS:
      r = dynamic_cast<ShowOptionsMenuState*> (ms->performAction());
      break;
    case BACK_MS:
      r = dynamic_cast<BackMenuState*> (ms->performAction());
      break;
    case COLOR_DEPTH_MS:
      r = dynamic_cast<ColorDepthMenuState*> (ms->performAction());
      break;
    case CREDITS_MS:
      r = dynamic_cast<CreditsMenuState*> (ms->performAction());
      break;
    case GAME_MS:
      r = dynamic_cast<GameMenuState*> (ms->performAction());
      break;
    case OPTIONS_MS:
      r = dynamic_cast<OptionsMenuState*> (ms->performAction());
      break;
    case QUIT_MS:
      r = dynamic_cast<QuitMenuState*> (ms->performAction());
      break;
    case RESOLUTION_MS:
      r = dynamic_cast<ResolutionMenuState*> (ms->performAction());
      break;
    case SHOW_CREDITS_MS:
      r = dynamic_cast<ShowCreditsMenuState*> (ms->performAction());
      break;
    case CHOOSE_LEVEL_MS:
      r = dynamic_cast<ChooseLevelMenuState*> (ms->performAction());
      break;
  }
  BOOST_CHECK(r != NULL);
  delete r;
}

}