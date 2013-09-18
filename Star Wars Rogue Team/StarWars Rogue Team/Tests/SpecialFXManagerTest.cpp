/**
 * File contains class SpecialFXManager_test definition.
 * @file    SpecialFXManagerTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-30
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "SpecialFXManagerTest.hpp"
#include "MySpecialFX.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{
/**
 * Test addSpecialEffect() method.
 */
void SpecialFXManager_test::test_addSpecialEffect()
{
  MySpecialFX* sf1 = new MySpecialFX;
  SpecialFXManager* sfm = new SpecialFXManager;
  sfm->addSpecialEffect(sf1);
  BOOST_CHECK(sf1->initialized == 1);
  delete sfm;
}

/**
 * Test initialize() and update() methods.
 */
void SpecialFXManager_test::test_initializeUpdateEffects()
{
  SpecialFXManager* sfm = new SpecialFXManager;

  MySpecialFX* sf1 = new MySpecialFX;
  MySpecialFX* sf2 = new MySpecialFX;
  MySpecialFX* sf3 = new MySpecialFX;

  sfm->addSpecialEffect(sf1);
  sfm->addSpecialEffect(sf2);
  sfm->addSpecialEffect(sf3);

  sfm->initializeEffects();
  BOOST_CHECK(sf1->initialized == 2);
  BOOST_CHECK(sf2->initialized == 2);
  BOOST_CHECK(sf3->initialized == 2);

  sfm->updateEffects(0.1);
  BOOST_CHECK(sf1->initialized == 2);
  BOOST_CHECK(sf2->initialized == 2);
  BOOST_CHECK(sf3->initialized == 2);
  BOOST_CHECK_CLOSE(sf1->updated, 0.1, 1e-3);
  BOOST_CHECK_CLOSE(sf2->updated, 0.1, 1e-3);
  BOOST_CHECK_CLOSE(sf3->updated, 0.1, 1e-3);

  delete sfm;
}

/**
 * Test renderEffect() method.
 */
void SpecialFXManager_test::test_renderEffects()
{
  SpecialFXManager* sfm = new SpecialFXManager;

  MySpecialFX* sf1 = new MySpecialFX;
  MySpecialFX* sf2 = new MySpecialFX;
  MySpecialFX* sf3 = new MySpecialFX;
  MySpecialFX* sf4 = new MySpecialFX;

  sfm->addSpecialEffect(sf1);
  sfm->addSpecialEffect(sf2);
  sfm->addSpecialEffect(sf3);
  sfm->addSpecialEffect(sf4);

  sfm->renderEffects();

  BOOST_CHECK(sf1->rendered == true);
  BOOST_CHECK(sf2->rendered == true);
  BOOST_CHECK(sf3->rendered == true);
  BOOST_CHECK(sf4->rendered == true);

  delete sfm;
}

}