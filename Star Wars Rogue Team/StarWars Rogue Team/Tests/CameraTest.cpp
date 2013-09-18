/**
 * File contains class Camera_test definition.
 * @file    CameraTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-02
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "CameraTest.hpp"

#include <SDL.h>

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace engine;

namespace test
{
void Camera_test::test_KeysPressed()
{
  Camera c = Camera();
  Vector3D d = c.direction;
  c.wKeyPressed();
  c.dKeyPressed();
  c.eKeyPressed();
  BOOST_CHECK(c.direction.z > d.z);
  BOOST_CHECK(c.direction.y > d.y);
  BOOST_CHECK(c.direction.x > d.x);

  Camera c1 = Camera();
  Vector3D d1 = c.direction;
  c.sKeyPressed();
  c.aKeyPressed();
  c.qKeyPressed();
  BOOST_CHECK(c1.direction.z < d1.z);
  BOOST_CHECK(c1.direction.y < d1.y);
  BOOST_CHECK(c1.direction.x < d1.x);
}

void Camera_test::test_mouseMoved()
{
  Camera c = Camera();
  float dx = c.dx;
  float dy = c.dy;
  float dz = c.dz;
  c.mouseMoved();
  BOOST_CHECK(!((dx == c.dx) && (dy == c.dy) && (dz == c.dz)));
}

void Camera_test::test_initCamera()
{
  Camera c = Camera();
  c.initCamera();
  Matrix4 pm = c.getProjectionMatrix();
  float tab[4][4] = {1.33439f, 0.0f, 0.0f, 0.0f,
                     0.0f, 1.7791938f, 0.0f, 0.0f,
                     0.0f, 0.0f, -1.0f, -1.0f,
                     0.0f, 0.0f, -0.2f, 0.0f};
  BOOST_CHECK_EQUAL(compare(pm, tab), true);
  Matrix4 vm = c.getViewProjectionMatrix();
  BOOST_CHECK(pm == vm);
}

void Camera_test::test_updateEntity()
{
  Camera c = Camera();
  c.setRotationSpeed(0.0);
  c.updateEntity(0.0);
  BOOST_CHECK_CLOSE(c.direction.x, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.direction.y, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.direction.z, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dx, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dy, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dz, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.getRotationSpeed(), 0.0, 1e-3);

  Camera c1 = Camera();
  c1.setRotationSpeed(1.0);
  c1.direction.x = 1.0;
  c1.dy = 90.0;
  c1.dz = 90.0;
  c1.updateEntity(5.0);

  Quaternion q = c1.getOrientation();
  BOOST_CHECK_CLOSE(q.w, 0.2425161, 1e-2);
  BOOST_CHECK_CLOSE(q.x, -0.66440755, 1e-2);
  BOOST_CHECK_CLOSE(q.y, 0.664215, 1e-2);
  BOOST_CHECK_CLOSE(q.z, -0.24199104, 1e-2);
  BOOST_CHECK_CLOSE(c.direction.x, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.direction.y, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.direction.z, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dx, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dy, 0.0, 1e-3);
  BOOST_CHECK_CLOSE(c.dz, 0.0, 1e-3);
}

/******************************************************************/
bool Camera_test::compare(Matrix4 matrix, float tab[4][4])
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