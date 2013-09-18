/**
 * File contains class Mesh_test definition.
 * @file    MeshTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-03
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "MeshTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{
/*
 * Test Mesh class.
 */
void Mesh_test::test_Mesh()
{
  /* Test konstruktorów: */
  try
  {
    std::string name = "Mesh";
    std::string filepath = "TestMesh.txt";
    m.push_back(new Mesh(name, filepath));
    m[0].loadResource();

    std::string MeshName = m[0].getName();
    std::string MeshFilepath = m[0].getFilepath();
    BOOST_CHECK_EQUAL(MeshName.compare(name), 0);
    BOOST_CHECK_EQUAL(MeshFilepath.compare(filepath), 0);
  } catch(std::bad_alloc) {
    std::cout << "Class Mesh test: constructor with initialization values does not work properly:\n";
    std::cout << "std::bad_alloc\n";
  }
  m.clear();
}

}