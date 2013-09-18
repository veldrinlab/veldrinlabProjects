/**
 * File contains declarations of classes Mesh_test and Mesh_test_suite.
 * @file    MeshTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-03
 * @version 1.0
 */

#ifndef MESH_TEST_H
#define MESH_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../ResourceManager/Mesh.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace resMan;

namespace test
{

/**
 * Class represents Mesh test class.
 */
class Mesh_test
{
  public:
    Mesh_test() {}

    void test_Mesh();

  private:
    boost::ptr_vector<Mesh> m;
};

/**
 * Class represents Mesh test suite.
 */
class Mesh_test_suite : public test_suite
{
   public:

   Mesh_test_suite() : test_suite("Mesh_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Mesh_test> instance(new Mesh_test());

      // create the test cases
      test_case* test_Mesh_test_case = BOOST_CLASS_TEST_CASE(
                              &Mesh_test::test_Mesh, instance );

      // add the test cases to the test suite
      add(test_Mesh_test_case);
   }
};

}
#endif
