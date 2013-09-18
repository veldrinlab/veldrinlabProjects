/**
 * File contains Matrix4Test class definition.
 * @file    Matrix4Test.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-11-11
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "Matrix4Test.hpp"
#include <iostream>

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;


namespace test
{

void Matrix4_test::test_operators()
{
  m.push_back(new Matrix4( 2.0f,  3.3f,  4.5f,  6.34f,
                          23.4f, 65.0f, 32.3f,  3.1f,
                          10.5f, 53.7f, 12.7f, 23.5f,
                          23.4f, 53.7f, 13.3f, 63.5f));
  m.push_back(new Matrix4( 2.0f,  3.3f,  4.5f,  6.34f,
                          23.4f, 65.0f, 32.3f,  3.1f,
                          10.5f, 53.7f, 12.7f, 23.5f,
                          23.4f, 53.7f, 13.3f, 63.5f));
  m.push_back(new Matrix4( -2.0f,  -3.3f,  -4.5f,  -6.34f,
                          -23.4f, -65.0f, -32.3f,  -3.1f,
                          -10.5f, -53.7f, -12.7f, -23.5f,
                          -23.4f, -53.7f, -13.3f, -63.5f));

  /* test operator * (float) */
  Matrix4 matrix = m[1] * -29.3f;

  float tab[4][4] = { -58.6f,    -96.689f, -131.84f,  -185.76f,
                     -685.62f, -1904.5f,   -946.38f,   -90.829f,
                     -307.65f, -1573.4f,   -372.11f,  -688.55f,
                     -685.62f, -1573.4f,   -389.69f, -1860.5f};
  BOOST_CHECK_EQUAL(compare(matrix, tab), true);
  /* test operator [] */
  matrix = m[1];
  float* row = matrix[2];
  BOOST_CHECK_CLOSE(row[0], 10.5, 1e-4);
  BOOST_CHECK_CLOSE(row[1], 53.7, 1e-4);
  BOOST_CHECK_CLOSE(row[2], 12.7, 1e-4);
  BOOST_CHECK_CLOSE(row[3], 23.5, 1e-4);
  const float* row2 = matrix[3];
  BOOST_CHECK_CLOSE(row2[0], 23.4, 1e-4);
  BOOST_CHECK_CLOSE(row2[1], 53.7, 1e-4);
  BOOST_CHECK_CLOSE(row2[2], 13.3, 1e-4);
  BOOST_CHECK_CLOSE(row2[3], 63.5, 1e-4);
  /* test operator == */
  BOOST_CHECK_EQUAL((m[1] == m[1]), true);
  /* test operator != */
  BOOST_CHECK_EQUAL((m[0] != m[2]), true);
  BOOST_CHECK_EQUAL((m[1] != m[1]), false);
  /* test operator += */
  matrix = m[2];
  matrix += m[1];
  float tab2[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  BOOST_CHECK_EQUAL(compare(matrix, tab2), true);
  /* test operator -= */
  m[1] -= m[1];
  BOOST_CHECK_EQUAL(compare(matrix, tab2), true);
  /* test operator *= (matrix) */
  m.clear();
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  m.push_back(new Matrix4(1.31f, 2.2f,  3.3f,   4.54f,
                          -5.5f, 6.6f,  7.7f,   8.8f,
                           9.29f,1.2f, -1.3f,  10.4f,
                           1.5f, 1.6f, 15.7f, -1.8f));
  float tab3[4][4] = { 53.021f, 28.626f, 33.271f, 37.916f,
                      119.68f,  54.78f,  57.64f,  60.5f,
                       19.549f, 43.438f, 55.887f, 68.336f,
                      163.18f,  29.82f,  34.62f,  39.42f};
  m[1] *= m[0];
  BOOST_CHECK_EQUAL(compare(m[1], tab3), true);
  /* test operator *= (float) */
  m[1] *= 0;
  BOOST_CHECK_EQUAL(compare(m[1], tab2), true);
  /* test operator /= (float) */
  m.clear();
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  m[0] /= 2.0f;
  float tab4[4][4] = {0.55f, 1.1f, 1.65f, 2.2f,
                      2.75f, 3.3f, 3.85f, 4.4f,
                      4.95f, 0.6f, 0.65f, 0.7f,
                      0.75f, 0.8f, 0.85f, 0.9f};
  BOOST_CHECK_EQUAL(compare(m[0], tab4), true);
  /* test operator + */
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  m.push_back(new Matrix4(-1.1f, -2.2f, -3.3f, -4.4f,
                          -5.5f, -6.6f, -7.7f, -8.8f,
                          -9.9f, -1.2f, -1.3f, -1.4f,
                          -1.5f, -1.6f, -1.7f, -1.8f));
  matrix = m[1] + m[2];
  BOOST_CHECK_EQUAL(compare(matrix, tab2), true);
  /* test operator - */
  m.clear();
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  m.push_back(new Matrix4(1.0, 1.0, 1.0, 1.0,
                          1.0, 1.0, 1.0, 1.0,
                          1.0, 1.0, 1.0, 1.0,
                          1.0, 1.0, 1.0, 1.0));
  matrix = m[0] - m[1]; 
  float tab5 [4][4] = {0.1f, 1.2f, 2.3f, 3.4f,
                       4.5f, 5.6f, 6.7f, 7.8f,
                       8.9f, 0.2f, 0.3f, 0.4f,
                       0.5f, 0.6f, 0.7f, 0.8f};
  BOOST_CHECK_EQUAL(compare(matrix, tab5), true);
  /* test operator * (matrix) */
  m.push_back(new Matrix4(1.0, 0.0, 0.0, 0.0,
                          0.0, 1.0, 0.0, 0.0,
                          0.0, 0.0, 1.0, 0.0,
                          0.0, 0.0, 0.0, 1.0));
  matrix = m[0] * m[2];
  float tab6[4][4] = {1.1f, 2.2f, 3.3f, 4.4f,
                      5.5f, 6.6f, 7.7f, 8.8f,
                      9.9f, 1.2f, 1.3f, 1.4f,
                      1.5f, 1.6f, 1.7f, 1.8f};
  BOOST_CHECK_EQUAL(compare(matrix, tab6), true);
  /* test operator * (float) */
  matrix = m[2]*2;
  float tab7[4][4] = {2.0f, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0};
  BOOST_CHECK_EQUAL(compare(matrix, tab7), true);
  /* test operator / (float) */
  matrix = m[2]/2;
  float tab8[4][4] = {0.5f, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5};
  BOOST_CHECK_EQUAL(compare(matrix, tab8), true);

  m.clear();
}

void Matrix4_test::test_fromAxes()
{
  m.push_back(new Matrix4());
  Vector3D* v1 = new Vector3D(1.2f, 4.5f, -77.7f);
  Vector3D* v2 = new Vector3D(33.2f, 7.25f, 2.7f);
  Vector3D* v3 = new Vector3D(-0.2f, 24.5f, -9.7f);
  m[0].fromAxes(*v1, *v2, *v3);
  float tab[4][4] = {1.2f, 4.5f, -77.7f, 0.0f, 33.2f, 7.2f, 2.7f, 0.0f, -0.2f, 24.5f, -9.7f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  delete v1; delete v2; delete v3;
  m.clear();
}

void Matrix4_test::test_fromAxesTransposed()
{
  m.push_back(new Matrix4());
  Vector3D* v1 = new Vector3D(1.2f, 4.5f, -77.7f);
  Vector3D* v2 = new Vector3D(33.2f, 7.25f, 2.7f);
  Vector3D* v3 = new Vector3D(-0.2f, 24.5f, -9.7f);
  m[0].fromAxesTransposed(*v1, *v2, *v3);
  float tab[4][4] = {1.2f, 33.2f, -0.2f, 0.0f, 4.5f, 7.2f, 24.5f, 0.0f, -77.7f, 2.7f, -9.7f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  delete v1; delete v2; delete v3;
  m.clear();
}

void Matrix4_test::test_identity()
{
  m.push_back(new Matrix4());
  m[0].identity();
  float tab[4][4] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  m.clear();
}

void Matrix4_test::test_toAxes()
{
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  Vector3D* v1 = new Vector3D();
  Vector3D* v2 = new Vector3D();
  Vector3D* v3 = new Vector3D();
  m[0].toAxes(*v1, *v2, *v3);
  float tab1[3] = {1.1f, 2.2f, 3.3f};
  float tab2[3] = {5.5f, 6.6f, 7.7f};
  float tab3[3] = {9.9f, 1.2f, 1.3f};
  BOOST_CHECK_EQUAL(compare(*v1, tab1), true);
  BOOST_CHECK_EQUAL(compare(*v2, tab2), true);
  BOOST_CHECK_EQUAL(compare(*v3, tab3), true);
  delete v1; delete v2; delete v3;
  m.clear();
}

void Matrix4_test::test_toAxesTransposed()
{
  m.push_back(new Matrix4(1.1f, 2.2f, 3.3f, 4.4f,
                          5.5f, 6.6f, 7.7f, 8.8f,
                          9.9f, 1.2f, 1.3f, 1.4f,
                          1.5f, 1.6f, 1.7f, 1.8f));
  Vector3D* v1 = new Vector3D();
  Vector3D* v2 = new Vector3D();
  Vector3D* v3 = new Vector3D();
  m[0].toAxesTransposed(*v1, *v2, *v3);
  float tab1[3] = {1.1f, 5.5f, 9.9f};
  float tab2[3] = {2.2f, 6.6f, 1.2f};
  float tab3[3] = {3.3f, 7.7f, 1.3f};
  BOOST_CHECK_EQUAL(compare(*v1, tab1), true);
  BOOST_CHECK_EQUAL(compare(*v2, tab2), true);
  BOOST_CHECK_EQUAL(compare(*v3, tab3), true);
  delete v1; delete v2; delete v3;
  m.clear();
}

void Matrix4_test::test_fromHeadPitchRoll()
{
  m.push_back(new Matrix4());
  m[0].fromHeadPitchRoll(45, 30, 90);
  float tab[4][4] = {-0.35355f, 0.70711f, -0.612372f, 0.0f, -0.866025f, 0.0f, 0.5f, 0.0f,
  0.35355f, 0.707107f, 0.612372f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  m.clear();
}

/*
void Matrix4_test::test_orient()
{
  //TODO ???
  m.push_back(new Matrix4());
  Vector3D* v1 = new Vector3D(0.6f, 0.25f, 0.759934f);
  Vector3D* v2 = new Vector3D(0.3946f, 0.5215f, 0.759934f);
  m[0].orient(*v1, *v2);
  float tab[4][4] = {0.866f, -0.5f, 0.0f, 0.0f, 0.5f, 0.866f, 0.0f, 0.0f,
                     0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  delete v1; delete v2;
  m.clear();
}
*/

void Matrix4_test::test_rotate()
{
  m.push_back(new Matrix4());
  m.push_back(new Matrix4());
  m.push_back(new Matrix4());
  Vector3D* vec = new Vector3D(0.0f, 0.0f, 1.0f);
  m[0].rotate(*vec, 90);
  float tab[4][4] = {0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                     0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  delete vec;
  /*****************************************************************/
  vec = new Vector3D(1.0f, 0.0f, 0.0f);
  m[1].rotate(*vec, 90);
  float tab1[4][4] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
                     0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[1], tab1), true);
  delete vec;
  /*****************************************************************/
  vec = new Vector3D(0.0f, 1.0f, 0.0f);
  m[2].rotate(*vec, 90);
  float tab2[4][4] = {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                     -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[2], tab2), true);
  delete vec;

  m.clear();
}

void Matrix4_test::test_scale()
{
  m.push_back(new Matrix4());
  m[0].scale(1.33f, 4.3f, 3.2f);
  float tab[4][4] = {1.33f, 0.0f, 0.0f, 0.0f, 0.0f, 4.3f, 0.0f, 0.0f,
                     0.0f, 0.0f, 3.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  m.clear();
}

void Matrix4_test::test_toHeadPitchRoll()
{
  m.push_back(new Matrix4(-0.35355f,  0.70711f, -0.612372f, 0.0f,
                          -0.866025f, 0.0f,      0.5f,      0.0f,
                           0.35355f,  0.707107f, 0.612372f, 0.0f,
                           0.0f,      0.0f,      0.0f,      1.0f));
  float headDegrees = 0;
  float pitchDegrees = 0;
  float rollDegrees = 0;
  m[0].toHeadPitchRoll(headDegrees, pitchDegrees, rollDegrees);
  BOOST_CHECK_CLOSE(headDegrees,  45.0, 1e-1);
  BOOST_CHECK_CLOSE(pitchDegrees, 30.0, 1e-1);
  BOOST_CHECK_CLOSE(rollDegrees,  90.0, 1e-1);
  m.clear();
}

void Matrix4_test::test_translate()
{
  m.push_back(new Matrix4());
  m[0].translate(1.33f, 4.3f, 3.2f);
  float tab[4][4] = {1.0f, 0.0f, 0.0f, 1.33f, 0.0f, 1.0f, 0.0f, 4.3f,
                     0.0f, 0.0f, 1.0f, 3.2f, 0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m[0], tab), true);
  m.clear();
}

/*****************************************************************************/
bool Matrix4_test::compare(Matrix4 matrix, float tab[4][4])
{
  float epsilon = 0.1f;
  for(int i = 0; i < 4; i++)
  {
    float* row = matrix[i];
    for(int j = 0; j < 4; j++)
    {
      if(abs((row[j]) - tab[i][j])
    > epsilon)
        return false;
    }
  }
  return true;
}

bool Matrix4_test::compare(Vector3D& vec, float tab[3])
{
  if((vec.x == tab[0]) && (vec.y == tab[1]) && (vec.z == tab[2]))
    return true;
  return false;
}

}