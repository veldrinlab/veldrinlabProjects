/**
 * File contains class Quaternion_test definition.
 * @file    QuaternionTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-11-13
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "QuaternionTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

void Quaternion_test::test_operators()
{
  /* test operator== */
  q.push_back(new Quaternion(-5.44f, -42.5f,  55.4f,  232.4f));
  q.push_back(new Quaternion(-5.44f, -42.5f,  55.4f,  232.4f));
  q.push_back(new Quaternion( 5.44f, -42.5f,  55.4f,  232.4f));
  q.push_back(new Quaternion( 5.44f,  42.5f, -55.4f, -232.4f));
  q.push_back(new Quaternion( 5.44f,  42.5f, -55.4f, -232.4f));

  bool res = (q[0] == q[1]);
  BOOST_CHECK_EQUAL(res, true);
  res = (q[0] == q[2]);
  BOOST_CHECK_EQUAL(res, false);
  /* test operator!= */
  res = (q[0] != q[2]);
  BOOST_CHECK_EQUAL(res, true);
  /* test operator+= */
  q[0] += q[3];
  float tab[4] = {0.0f, 0.0f, 0.0f, 0.0f};
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  /* test operator-= */
  q[4] -= q[3];
  BOOST_CHECK_EQUAL(compare(q[4], tab), true);
  /* test operator*=(quaternion) */
  q.clear();
  q.push_back(new Quaternion( 3.0f,  -4.0f, 6.0f, -9.2f));
  q.push_back(new Quaternion( -2.2f, 3.0f, 5.23f, 13.0f));
  q[0] *= q[1];
  float tab1[4] = {93.619f, 143.916f, 26.889f, 20.319f};
  BOOST_CHECK_EQUAL(compare(q[0], tab1), false);

  /* test operator*=(float) */
  q.push_back(new Quaternion( 2.33f, -4.6f, -64.5f, 2.4f));
  q[2] *= 7.3f;
  float tab2[4] = {17.009f, -33.58f, -470.85f, 17.52f};
  BOOST_CHECK_EQUAL(compare(q[2], tab2), true);

  /* test operator/=(float) */
  q[2] /= 4.23f;
  float tab3[4] = {4.021f, -7.9385f, -111.312f, 4.1418f};
  BOOST_CHECK_EQUAL(compare(q[2], tab3), true);

  /* test operator+ */
  q.push_back(new Quaternion(3.24f, 4.9f, -3.55f, -7.0f));
  q.push_back(new Quaternion(2.31f, -4.5f, -1.1f, 32.3f));
  Quaternion qt = q[3] + q[4];
  float tab4[4] = {5.55f, 0.4f, -4.65f, 25.3f};
  BOOST_CHECK_EQUAL(compare(qt, tab4), true);

  /* test operator- */
  q.push_back(new Quaternion(5.55f, 0.4f, -4.65f, 25.3f));
  Quaternion qt1 = q[5] - q[3];
  float tab5[4] = {2.31f, -4.5f, -1.1f, 32.3f};
  BOOST_CHECK_EQUAL(compare(qt1, tab5), true);

  /* test operator*(quaternion) */
  q.clear();
  q.push_back(new Quaternion(3.44f, 9.5f, 23.4f, -7.6f));
  q.push_back(new Quaternion(2.33f, -3.4f, 222.3f, -3.3f));
  Quaternion qt2 = q[0] * q[1];
  float tab6[4] = {-5186.5848f, 1622.699f, 876.424f, 2162.35f};
  BOOST_CHECK_EQUAL(compare(qt2, tab6), false);

  /* test operator*(float) */
  Quaternion qt3 = q[0] * 0.1f;
  float tab7[4] = {0.344f, 0.95f, 2.34f, -0.76f};
  BOOST_CHECK_EQUAL(compare(qt3, tab7), true);

  /* test operator/ */
  Quaternion qt4 = q[1] / 2.3f;
  float tab8[4] = {1.013f, -1.478f, 96.652f, -1.4347f};
  BOOST_CHECK_EQUAL(compare(qt4, tab8), true);

  q.clear();
}

void Quaternion_test::test_conjugate()
{
  q.push_back(new Quaternion(2.3f, -3.4f, -2.33f, 4.6f));
  Quaternion qt = q[0].conjugate();
  float tab[4] = {2.3f, 3.4f, 2.33f, -4.6f};
  BOOST_CHECK_EQUAL(compare(qt, tab), true);
  q.clear();
}

void Quaternion_test::test_fromAxisAngle()
{
  q.push_back(new Quaternion(0.0, 0.0, 0.0, 0.0));
  Vector3D v = Vector3D(3.4f, 2.33f, 41.2f);
  q[0].fromAxisAngle(v, 55.4f);
  float tab[4] = {0.885394f, 1.580463f, 1.083083f, 19.142553f};
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  q.clear();
}

void Quaternion_test::test_fromHeadPitchRoll()
{
  q.push_back(new Quaternion());
  q[0].fromHeadPitchRoll(20, 30, 88);
  float tab[4] = {0.65338844f, 0.066916645f, 0.29754794f, 0.69287151f};
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  q.clear();
}

void Quaternion_test::test_fromMatrix()
{
  Matrix4 m = Matrix4(-38.8402f, -28.806f, 63.444f, 0.0f,
                      33.594f, -7.18f, 11.28f, 0.0f,
                      -61.044f, 20.64f, -31.0202f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f);
  q.push_back(new Quaternion());
  q[0].fromMatrix(m);
  float tab[4] = {7.8f, -0.3f, -3.99f, -2.0f};
  BOOST_CHECK_EQUAL(compare(q[0], tab), false);
  q.clear();
}

void Quaternion_test::test_identity()
{
  q.push_back(new Quaternion(2.3f, -3.4f, -2.33f, 4.6f));
  float tab[4] = {1.0f, 0.0f, 0.0f, 0.0f};
  q[0].identity();
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  q.clear();
}

void Quaternion_test::test_magnitude()
{
  q.push_back(new Quaternion(2.0f, 4.0f, 0.125f, 0.33333333f));
  float n = q[0].magnitude();
  BOOST_CHECK_CLOSE(q[0].magnitude(), 4.48628, 1e-3);
  q.clear();
}

void Quaternion_test::test_inverse()
{
  q.push_back(new Quaternion(2.0f, 4.0f, 0.125f, 0.33333333f));
  float tab[4] = {0.4458f, -0.89161f, -0.02786f, -0.0743f};
  Quaternion qt = q[0].inverse();
  BOOST_CHECK_EQUAL(compare(qt, tab), true);
  q.clear();
}
void Quaternion_test::test_normalize()
{
  q.push_back(new Quaternion(2.0f, 4.0f, 0.125f, 0.33333333f));
  float tab[4] = {0.4458f, 0.8916f, 0.02786f, 0.0743f};
  q[0].normalize();
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  q.clear();
}

void Quaternion_test::test_set()
{
  q.push_back(new Quaternion(0.0f, 0.0f, 0.0f, 0.0f));
  q[0].set(-3.4f, 5.65f, -4.6f, 33.4f);
  float tab[4] = {-3.4f, 5.65f, -4.6f, 33.4f};
  BOOST_CHECK_EQUAL(compare(q[0], tab), true);
  q.clear();
}

void Quaternion_test::test_toAxesAngle()
{
  q.push_back(new Quaternion(0.923879564f, 1.339391749f,
                             0.765366714f, 1.626404267f));
  Vector3D v = Vector3D(0.0, 0.0, 0.0);
  float degrees = 0.0f;
  q[0].toAxisAngle(v, degrees);
  BOOST_CHECK_CLOSE(degrees, 45.0, 1e-1);
  BOOST_CHECK_CLOSE(v.x, 3.5,  1e-2);
  BOOST_CHECK_CLOSE(v.y, 2.0,  1e-2);
  BOOST_CHECK_CLOSE(v.z, 4.25, 1e-2);
  q.clear();
}

void Quaternion_test::test_toHeadPitchRoll()
{
  q.push_back(new Quaternion(0.62469983f, 0.086263292f, 0.33177754f, 0.70159280f));
  float h = 0.0f, p = 0.0f, r = 0.0f;
  q[0].toHeadPitchRoll(h, p, r);
  BOOST_CHECK_CLOSE(h, 21.0, 1e-2);
  BOOST_CHECK_CLOSE(p, 35.0, 1e-2);
  BOOST_CHECK_CLOSE(r, 90.0, 1e-2);
  q.clear();
}

void Quaternion_test::test_toMatrix()
{
  q.push_back(new Quaternion(3.42f, -382.3f, -3.99f, -2.034f));
  Matrix4 m = q[0].toMatrix4();
  float tab[4][4] = {-39.1145f, 3036.8414f, 1582.488f, 0.0f,
                     3064.66656f, -292313.8543f, -2598.70068f, 0.0f,
                     1527.9048f, 2631.16332f, -292337.41f, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m, tab), true);
  q.clear();

  q.push_back(new Quaternion(7.8f, -0.3f, -3.99f, -2.0f));
  Matrix4 m1 = q[0].toMatrix4();
  float tab1[4][4] = {-38.8402f, -28.806f, 63.444f, 0.0f,
                      33.594f, -7.18f, 11.28f, 0.0f,
                      -61.044f, 20.64f, -31.0202f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f};
  BOOST_CHECK_EQUAL(compare(m1, tab1), true);
  q.clear();
}

/***********************************************************************************8*/
bool Quaternion_test::compare(Quaternion& q, float tab[4])
{
  float epsilon = 0.001f;
  bool res1 = (abs(q.w - tab[0]) < epsilon);
  bool res2 = (abs(q.x - tab[1]) < epsilon);
  bool res3 = (abs(q.y - tab[2]) < epsilon);
  bool res4 = (abs(q.z - tab[3]) < epsilon);
  return (res1 && res2 && res3 && res4);
}

bool Quaternion_test::compare(Matrix4 matrix, float tab[4][4])
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

}