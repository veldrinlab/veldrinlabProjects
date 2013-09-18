/**
 * File contains declarations of classes Matrix4Test and Matrix4_test_suite.
 * @file    Matrix4Test.h
 * @author  Katarzyna Na³êcz
 * @date    2010-11-11
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Matrix4.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace math;

namespace test
{

/**
 * Class represents Matrix4 test class.
 */
class Matrix4_test
{
   public:
     Matrix4_test() {}

     void test_operators();
     void test_fromAxes();
     void test_fromAxesTransposed();
     void test_identity();
     void test_toAxes();
     void test_toAxesTransposed();
     void test_fromHeadPitchRoll();
     void test_orient(){}
     void test_rotate();
     void test_scale();
     void test_toHeadPitchRoll();
     void test_translate();

   private:
    boost::ptr_vector<Matrix4> m;

    bool compare(Matrix4 matrix, float tab[4][4]);
    bool Matrix4_test::compare(Vector3D& vec, float tab[3]);
};

/**
 * Class represents Matrix4 test suite.
 */
class Matrix4_test_suite : public test_suite
{
   public:

   Matrix4_test_suite() : test_suite("Matrix4_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Matrix4_test> instance(new Matrix4_test());

      // create the test cases
      test_case* operators_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_operators, instance );
      test_case* fromAxes_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_fromAxes, instance );
      test_case* fromAxesTransposed_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_fromAxesTransposed, instance );
      test_case* identity_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_identity, instance );
      test_case* toAxes_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_toAxes, instance );
      test_case* toAxesTransposed_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_toAxesTransposed, instance );
      test_case* fromHeadPitchRoll_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_fromHeadPitchRoll, instance );
      test_case* orient_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_orient, instance );
      test_case* rotate_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_rotate, instance );
      test_case* scale_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_scale, instance );
      test_case* toHeadPitchRoll_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_toHeadPitchRoll, instance );
      test_case* translate_test_case = BOOST_CLASS_TEST_CASE(
                              &Matrix4_test::test_translate, instance );

      // add the test cases to the test suite
      add(operators_test_case);
      add(fromAxes_test_case);
      add(fromAxesTransposed_test_case);
      add(identity_test_case);
      add(toAxes_test_case);
      add(toAxesTransposed_test_case);
      add(fromHeadPitchRoll_test_case);
      add(orient_test_case);
      add(rotate_test_case);
      add(scale_test_case);
      add(toHeadPitchRoll_test_case);
      add(translate_test_case);
   }
};

}