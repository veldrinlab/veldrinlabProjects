/**
 * File contains class Color_test definition.
 * @file    ColorTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-12
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "ColorTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

/**
 * Test Color class.
 */
void Color_test::test_Color()
{
  /* test constructors */
  col.push_back(new Color());
  float tab1[4] = {0.0, 0.0, 0.0, 0.0};
  BOOST_CHECK_EQUAL(compare(&col[0], tab1), true);
  col.push_back(new Color(1.1f, 2.2f, 3.3f, 4.4f));
  float tab2[4] = {1.1f, 2.2f, 3.3f, 4.4f};
  BOOST_CHECK_EQUAL(compare(&col[1], tab2), true);
  col.push_back(new Color(col[1]));
  BOOST_CHECK_EQUAL(compare(&col[2], tab2), true);

  /* test operators */
  Color c1 = col[2];
  BOOST_CHECK_EQUAL(compare(&c1, tab2), true);
  col.push_back(new Color(-1.1f, -2.2f, -3.3f, -4.4f));
  col[3] += col[1];
  BOOST_CHECK_EQUAL(compare(&col[3], tab1), true);
  col[1] -= col[2];
  BOOST_CHECK_EQUAL(compare(&col[1], tab1), true);

  col.clear();
  col.push_back(new Color(1.1f, 2.2f, 3.3f, 4.4f));
  col[0] *= 10;
  float tab3[4] = {11.0f, 22.0f, 33.0f, 44.0f};
  BOOST_CHECK_EQUAL(compare(&col[0], tab3), true);

  col.push_back(new Color(2.2f, 4.4f, 6.6f, 8.8f));
  col[1] /= 2.2f;
  float tab4[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  BOOST_CHECK_EQUAL(compare(&col[1], tab4), true);

  Color c2 = col[0] + col[1];
  float tab5[4] = {12.0f, 24.0f, 36.0f, 48.0f};
  BOOST_CHECK_EQUAL(compare(&c2, tab5), true);

  Color c3 = col[0] - col[1];
  float tab6[4] = {10.0f, 20.0f, 30.0f, 40.0f};
  BOOST_CHECK_EQUAL(compare(&c3, tab6), true);

  col.clear();
  col.push_back(new Color(2.2f, 4.4f, 6.6f, 8.8f));
  Color c4 = col[0] * 2.0;
  float tab7[4] = {4.4f, 8.8f, 13.2f, 17.6f};
  BOOST_CHECK_EQUAL(compare(&c4, tab7), true);

  Color c5 = col[0] / 2.2f;
  float tab8[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  BOOST_CHECK_EQUAL(compare(&c5, tab8), true);
}

/**
 * Test changeStateDown() method.
 * @param c color
 * @param tab table to compare
 */
bool Color_test::compare(Color* c, float* tab)
{
  float epsilon = 0.01f;
  if(abs(c->r - tab[0]) > epsilon)
    return false;

  if(abs(c->g - tab[1]) > epsilon)
    return false;

  if(abs(c->b - tab[2]) > epsilon)
    return false;

  if(abs(c->a - tab[3]) > epsilon)
    return false;

  return true;
}

}