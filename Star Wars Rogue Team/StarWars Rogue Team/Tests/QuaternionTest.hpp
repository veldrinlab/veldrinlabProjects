/**
 * File contains declarations of classes Quaternion_test and Quaternion_test_suite.
 * @file    QuaternionTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef QUATERNION_TEST_H
#define QUATERNION_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../Quaternion.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace math;

namespace test
{

/**
 * Class represents Quaternion test class.
 */
class Quaternion_test
{
   public:
     Quaternion_test() {}

     void test_operators();
     void test_conjugate();
     void test_fromAxisAngle();
     void test_fromHeadPitchRoll();
     void test_fromMatrix();
     void test_identity();
     void test_inverse();
     void test_magnitude();
     void test_normalize();
     void test_set();
     void test_toAxesAngle();
     void test_toHeadPitchRoll();
     void test_toMatrix();

   private:
    boost::ptr_vector<Quaternion> q;
    bool compare(Quaternion& q, float tab[4]);
    bool Quaternion_test::compare(Matrix4 matrix, float tab[4][4]);
};

/**
 * Class represents Quaternion test class.
 */
class Quaternion_test_suite : public test_suite
{
   public:

   Quaternion_test_suite() : test_suite("Quaternion_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<Quaternion_test> instance(new Quaternion_test());

      // create the test cases
      test_case* operators_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_operators, instance );
      test_case* conjugate_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_conjugate, instance );
      test_case* fromAxisAngle_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_fromAxisAngle, instance );
      test_case* fromHeadPitchRoll_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_fromHeadPitchRoll, instance );
      test_case* fromMatrix_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_fromMatrix, instance );
      test_case* identity_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_identity, instance );
      test_case* inverse_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_inverse, instance );
      test_case* magnitude_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_magnitude, instance );
      test_case* normalize_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_normalize, instance );
      test_case* set_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_set, instance );
      test_case* toAxesAngle_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_toAxesAngle, instance );
      test_case* toHeadPitchRoll_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_toHeadPitchRoll, instance );
      test_case* toMatrix_test_case = BOOST_CLASS_TEST_CASE(
                              &Quaternion_test::test_toMatrix, instance );

      // add the test cases to the test suite
      add(operators_test_case);
      add(conjugate_test_case);
      add(fromAxisAngle_test_case);
      add(fromHeadPitchRoll_test_case);
      add(fromMatrix_test_case);
      add(identity_test_case);
      add(inverse_test_case);
      add(magnitude_test_case);
      add(normalize_test_case);
      add(set_test_case);
      add(toAxesAngle_test_case);
      add(toHeadPitchRoll_test_case);
      add(toMatrix_test_case);
   }
};

}
#endif
