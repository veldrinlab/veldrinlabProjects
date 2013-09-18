/**
 * File contains declarations of classes Vector3DTest and Vector3D_test_suite.
 * @file    Vector3DTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-11-9
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Vector3D.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace math;

namespace test
{
/**
 * Class represents Vector3D test class.
 */
class Vector3D_test
{
  public:
    Vector3D_test() {}

    void test_cross();
    void test_distance();
    void test_dot();
    void test_operators();
    void test_lerp();
    void test_magnitude();
    void test_proj();
    void test_normalize();
    void test_orthogonalize();
    void test_perp();
    void test_reflect();
    void test_inverse();
    void test_set();

  private:
    boost::ptr_vector<Vector3D> v;
};

/**
 * Class represents Vector3D test suite.
 */
class Vector3D_test_suite : public test_suite
{
   public:

   Vector3D_test_suite() : test_suite("Vector3D_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Vector3D_test> instance(new Vector3D_test());

      // create the test cases
      test_case* cross_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_cross, instance );
      test_case* distance_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_distance, instance );
      test_case* dot_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_dot, instance );
      test_case* operators_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_operators, instance );
      test_case* lerp_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_lerp, instance );
      test_case* orthogonalize_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_orthogonalize, instance );

      test_case* proj_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_proj, instance );
      test_case* perp_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_perp, instance );
      test_case* reflect_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_reflect, instance );
      test_case* magnitude_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_magnitude, instance );
      test_case* inverse_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_inverse, instance );

      test_case* normalize_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_normalize, instance );
      test_case* set_test_case = BOOST_CLASS_TEST_CASE(
                              &Vector3D_test::test_set, instance );

      // add the test cases to the test suite
      add(cross_test_case);
      add(distance_test_case);
      add(dot_test_case);
      add(operators_test_case);
      add(lerp_test_case);
      add(orthogonalize_test_case);
      add(proj_test_case);
      add(perp_test_case);
      add(reflect_test_case);
      add(magnitude_test_case);
      add(inverse_test_case);
      add(normalize_test_case);
      add(set_test_case);
   }
};

}