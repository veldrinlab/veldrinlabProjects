/**
 * File contains class BoundingBox_test definition.
 * @file    BoundingBoxTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-02
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "BoundingBoxTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{
void BoundingBox_test::test_BoundingBox()
{
  Vertex verts[3];
  verts[0].x = 1.1f; verts[0].y = 1.2f; verts[0].z = 1.3f;
  verts[1].x = 2.1f; verts[1].y = 2.2f; verts[1].z = 2.3f;
  verts[2].x = 3.1f; verts[2].y = 3.2f; verts[2].z = 3.3f;

  BoundingBox bb(verts, 3);
  Vector3D min = bb.min;
  Vector3D max = bb.max;
  Vector3D res_min(1.1f, 1.2f, 1.3f);
  Vector3D res_max(3.1f, 3.2f, 3.3f);
  BOOST_CHECK_EQUAL(compare(min, res_min), true);
  BOOST_CHECK_EQUAL(compare(max, res_max), true);
}

bool BoundingBox_test::compare(Vector3D& vec1, Vector3D& vec2)
{
  float epsilon = 0.01;
  if((abs(vec1.x - vec2.x) < epsilon) && (abs(vec1.y - vec2.y) < epsilon)
      && (abs(vec1.z - vec2.z) < epsilon))
    return true;
  return false;
}

}