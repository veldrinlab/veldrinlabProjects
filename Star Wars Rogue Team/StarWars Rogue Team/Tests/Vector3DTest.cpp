/**
 * File contains Vector3DTest class definition.
 * @file    Vector3DTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-11-9
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "Vector3DTest.hpp"
#include <iostream>

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

#define CHECK_IS_CLOSE_WEAK(x, y, t) boost::test_tools::check_is_close((x),(y), \
  boost::test_tools::percent_tolerance(t), boost::test_tools::FPC_WEAK)

/**
 * Test cross() method.
 */
void Vector3D_test::test_cross()
{
  v.push_back(new Vector3D(15.0, 16.0, 17.0));
  v.push_back(new Vector3D(30.0, 32.0, 34.0));
  const Vector3D& v1 = v[0];
  const Vector3D& v2 = v[1];
  Vector3D tmp;
  tmp = v[0].cross(v1, v2);
  BOOST_CHECK_CLOSE(tmp.x, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp.y, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp.z, 0.0, 1e-6);
  v.clear();
}

/**
 * Test distance() method.
 */
void Vector3D_test::test_distance()
{
  v.push_back(new Vector3D(3.0, 5.0, 17.0));
  v.push_back(new Vector3D(3.0, 5.0, 16.0));
  v.push_back(new Vector3D(3.0, 5.0, 18.0));
  v.push_back(new Vector3D(3.0, 6.0, 17.0));
  v.push_back(new Vector3D(2.0, 5.0, 17.0));
  v.push_back(new Vector3D(300.0, -32.0, 374.9f));

  BOOST_CHECK_CLOSE(v[0].distanceSq(v[0], v[0]), 0.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[0],   v[0]), 0.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[0],   v[1]), 1.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distanceSq(v[0], v[1]), 1.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[2],   v[0]), 1.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[0],   v[3]), 1.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[0],   v[4]), 1.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].distance(v[4],   v[5]), 467.189, 1e-2);
  v.clear();
}

/**
 * Test dot() method.
 */
void Vector3D_test::test_dot()
{
  v.push_back(new Vector3D(33.4f, 209.43f, 11327.06f));
  v.push_back(new Vector3D(0.0, 0.0, 0.0));
  v.push_back(new Vector3D(1.0, 1.0, 1.0));
  v.push_back(new Vector3D(3.0, 2.0, 6.0));
  v.push_back(new Vector3D(0.0001f, 0.0001f, 0.0001f));

  BOOST_CHECK_CLOSE(v[0].dot(v[0], v[1]), 0.0, 1e-6);
  BOOST_CHECK_CLOSE(v[0].dot(v[0], v[2]), (33.4 + 209.43 + 11327.06), 1e-2);
  BOOST_CHECK_CLOSE(v[0].dot(v[3], v[4]), 0.0011, 1e-4);
  v.clear();
}

/**
 * Test operators.
 */
void Vector3D_test::test_operators()
{
  /* test operator*(float, Vector3D) */
  v.push_back(new Vector3D(-3.9f, -4.8f, -7.2f));
  v.push_back(new Vector3D(1.0, 1.0, 1.0));
  Vector3D tmp1 = v[0] * 19.23f;
  Vector3D tmp2 = v[1] * 0.00001f;

  BOOST_CHECK_CLOSE(tmp1.x, -74.997, 1e-3);
  BOOST_CHECK_CLOSE(tmp1.y, -92.304, 1e-3);
  BOOST_CHECK_CLOSE(tmp1.z, -138.456, 1e-3);
  BOOST_CHECK_CLOSE(tmp2.x, 0.00001, 1e-5);
  BOOST_CHECK_CLOSE(tmp2.y, 0.00001, 1e-5);
  BOOST_CHECK_CLOSE(tmp2.z, 0.00001, 1e-5);
  BOOST_CHECK_CLOSE(v[0].x, -3.9, 1e-5); // check if not changed

  /* test operator- (-vector) */
  Vector3D tmp3 = -v[0];
  BOOST_CHECK_CLOSE(tmp3.x, 3.9, 1e-2);
  BOOST_CHECK_CLOSE(tmp3.y, 4.8, 1e-2);
  BOOST_CHECK_CLOSE(tmp3.z, 7.2, 1e-2);

  /* test operator += */
  tmp3 += v[0];
  BOOST_CHECK_CLOSE(tmp3.x, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp3.y, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp3.z, 0.0, 1e-6);

  /* test operator == */
  v.clear();
  v.push_back(new Vector3D(3.3f, 2.7f, -291.0f));
  v.push_back(new Vector3D(3.3f, 2.7f, -291.0f));
  v.push_back(new Vector3D(3.3f, 2.7f, 291.0f));
  BOOST_CHECK_EQUAL((v[0] == v[1]), true);
  BOOST_CHECK_EQUAL((v[0] == v[2]), false);

  /* test operator != */
  BOOST_CHECK_EQUAL((v[0] != v[2]), true);
  BOOST_CHECK_EQUAL((v[0] != v[1]), false);

  /* test operator -= */
  tmp1 = v[0];
  tmp2 = v[0];
  tmp1 -= tmp2;
  BOOST_CHECK_CLOSE(tmp1.x, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.y, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.z, 0.0, 1e-6);

  /* test operator *= (float) */
  v.push_back(new Vector3D(-5.0f, 3.0f, 232.0f));
  tmp1 = v[3];
  tmp1 *= 2.1f;
  BOOST_CHECK_CLOSE(tmp1.x, -10.5, 1e-3);
  BOOST_CHECK_CLOSE(tmp1.y,   6.3, 1e-3);
  BOOST_CHECK_CLOSE(tmp1.z, 487.2, 1e-3);

  /* test operator /= (float) */
  v.push_back(new Vector3D(-44.4f, 222.2f, -8888.8f));
  tmp1 = v[4];
  tmp1 /= 2.2f;
  BOOST_CHECK_CLOSE(tmp1.x,  -20.18181818 , 1e-3);
  BOOST_CHECK_CLOSE(tmp1.y,   101.0       , 1e-3);
  BOOST_CHECK_CLOSE(tmp1.z, -4040.36363636, 1e-3);

  /* test operator + */
  v.push_back(new Vector3D(0.001f, 0.001f, -0.001f));
  v.push_back(new Vector3D(0.999f, 0.999f, 1.001f));
  tmp1 = v[5] + v[6];
  BOOST_CHECK_CLOSE(tmp1.x, 1.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.y, 1.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.z, 1.0, 1e-6);

  /* test operator - (vector1 - vector2) */
  v.push_back(new Vector3D(0.999f, 0.999f, 1.001f));
  tmp1 = v[7] - v[6];
  BOOST_CHECK_CLOSE(tmp1.x, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.y, 0.0, 1e-6);
  BOOST_CHECK_CLOSE(tmp1.z, 0.0, 1e-6);
  /* test operator * (float) */
  v.push_back(new Vector3D(1.3f, -4.33f, 6545.1f));
  tmp1 = v[8] * 0.01f;
  BOOST_CHECK_CLOSE(tmp1.x,   0.013 , 1e-3);
  BOOST_CHECK_CLOSE(tmp1.y,  -0.0433, 1e-3);
  BOOST_CHECK_CLOSE(tmp1.z,  65.451 , 1e-3);

  /* test operator / (float) */
  tmp1 = v[8] / 0.1f;
  BOOST_CHECK_CLOSE(tmp1.x,    13.0, 1e-2);
  BOOST_CHECK_CLOSE(tmp1.y,   -43.3, 1e-2);
  BOOST_CHECK_CLOSE(tmp1.z, 65451.0, 1e-2);

  v.clear();
}

/**
 * Test lerp method.
 */
void Vector3D_test::test_lerp()
{
  v.push_back(new Vector3D(3.0f, 4.0f, 2.0f));
  v.push_back(new Vector3D(5.0f, -8.0f, 1.0f));
  Vector3D tmp = v[0].lerp(v[0], v[1], 0.1f);
  BOOST_CHECK_CLOSE(tmp.x, 3.2, 1e-3);
  BOOST_CHECK_CLOSE(tmp.y, 2.8, 1e-3);
  BOOST_CHECK_CLOSE(tmp.z, 1.9, 1e-3);
  v.clear();
}

/**
 * Test magnitude method().
 */
void Vector3D_test::test_magnitude()
{
  v.push_back(new Vector3D(-3.02f, 4.10f, -2.12f));
  v.push_back(new Vector3D(-1.0, -1.0, -1.0));

  float res0 = v[0].magnitudeSq();
  float res1 = v[1].magnitudeSq();
  float res3 = v[0].magnitude();

  BOOST_CHECK_CLOSE(res0, 30.4248, 1e-4);
  BOOST_CHECK_CLOSE(res1, 3.0    , 1e-4);
  BOOST_CHECK_CLOSE(res3, 5.51587, 1e-4);

  v.clear();
}

/**
 * Test proj() method.
 */
void Vector3D_test::test_proj()
{
  v.push_back(new Vector3D(2.0, 1.0, 0.0));
  v.push_back(new Vector3D(-3.0, 4.0, 0.0));
  Vector3D tmp = v[0].proj(v[0], v[1]);

  BOOST_CHECK_CLOSE(tmp.x,  0.24, 1e-2);
  BOOST_CHECK_CLOSE(tmp.y, -0.32, 1e-2);
  BOOST_CHECK_CLOSE(tmp.z,  0.0 , 1e-2);
  v.clear();
}

/**
 * Test normalize() method.
 */
void Vector3D_test::test_normalize()
{
  v.push_back(new Vector3D(2.0, 1.0, -100.0));
  v[0].normalize();
  Vector3D tmp = v[0];
  float length = sqrtf(tmp.x*tmp.x + tmp.y*tmp.y + tmp.z*tmp.z);
  BOOST_CHECK_CLOSE(length, 1.0, 1e-2);
  v.clear();
}

/**
 * Test orthogonalize() method.
 */
void Vector3D_test::test_orthogonalize()
{
  v.push_back(new Vector3D(1.0, 2.0, 3.0));
  v.push_back(new Vector3D(-1.0, 2.0, -1.0));
  v.push_back(new Vector3D(2.3f, -382.2f, 3.0f));
  
  v[0].orthogonalize(v[0], v[1]);
  float x = (v[0].x) * (v[1].x);
  float y = (v[0].y) * (v[1].y);
  float z = (v[0].z) * (v[1].z);
  float res = x + y + z;

  CHECK_IS_CLOSE_WEAK(res, 0.0, 1e-4);
  v.clear();

  v.push_back(new Vector3D(11.0f, 2.0f, -3.6f));
  v.push_back(new Vector3D(-1.0f, 22.0f, -1.0f));
  v.push_back(new Vector3D(2.3f, -382.2f, 3.0f));
  v[0].orthogonalize(v[0], v[1], v[2]);
  x = (v[0].x) * (v[1].x) * (v[2].x);
  y = (v[0].y) * (v[1].y) * (v[2].y);
  z = (v[0].z) * (v[1].z) * (v[2].z);
  res = x + y + z;
  CHECK_IS_CLOSE_WEAK(res, 0.0, 1e-4);

  v.clear();
}

/**
 * Test perp() method.
 */
void Vector3D_test::test_perp()
{
  v.push_back(new Vector3D(1.0, 2.0, 3.0));
  v.push_back(new Vector3D(-1.0, 2.0, -1.0));
  Vector3D tmp = v[0].perp(v[0], v[1]);
  float x = (tmp.x) * (v[1].x);
  float y = (tmp.y) * (v[1].y);
  float z = (tmp.z) * (v[1].z);
  float res = x + y + z;

  CHECK_IS_CLOSE_WEAK(res, 0.0, 1e-4);

  v.clear();
}

/**
 * Test reflect() method.
 */
void Vector3D_test::test_reflect()
{
  v.push_back(new Vector3D(11.0f, 12.0f, 13.0f));
  v.push_back(new Vector3D(1.0f, 8.0f, 4.0f));
  Vector3D tmp = v[0].reflect(v[0], v[1]);

  BOOST_CHECK_CLOSE(tmp.x,   7.07408, 1e-3);
  BOOST_CHECK_CLOSE(tmp.y, -19.4074 , 1e-3);
  BOOST_CHECK_CLOSE(tmp.z,  -2.7037 , 1e-3);

  v.clear();
}

/**
 * Test inverse() method.
 */
void Vector3D_test::test_inverse()
{
  v.push_back(new Vector3D(11.0f, 12.0f, 13.0f));
  Vector3D tmp = v[0].inverse();

  BOOST_CHECK_CLOSE(tmp.x + v[0].x, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(tmp.y + v[0].y, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(tmp.z + v[0].z, 0.0, 1e-3);

  v.clear();
}

/**
 * Test set() method.
 */
void Vector3D_test::test_set()
{
  v.push_back(new Vector3D(0.0, 0.0, 0.0));
  v[0].set(-2.2f, 738.3f, 32.9f);

  BOOST_CHECK_CLOSE(v[0].x,  -2.2, 1e-3);
  BOOST_CHECK_CLOSE(v[0].y, 738.3, 1e-3);
  BOOST_CHECK_CLOSE(v[0].z,  32.9, 1e-3);

  v.clear();
}

}