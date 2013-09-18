/**
 * File contains declarations of classes ResourceManager_test and ResourceManager_test_suite.
 * @file    ResourceManagerTest.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-04
 * @version 1.0
 */

#ifndef RESOURCE_MANAGER_TEST_H
#define RESOURCE_MANAGER_TEST_H

#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "../ResourceManager/ResourceManager.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;
using namespace resMan;

namespace test
{

/**
 * Class represents ResourceManager test class.
 */
class ResourceManager_test
{
  public:
    ResourceManager_test() {}

    void test_ResourceManager();

  private:
    boost::ptr_vector<ResourceManager> rm;
};

/**
 * Class represents ResourceManager test suite.
 */
class ResourceManager_test_suite : public test_suite
{
   public:

   ResourceManager_test_suite() : test_suite("ResourceManager_test_suite")
   {
      // create an instance of the test cases class
      boost::shared_ptr<ResourceManager_test> instance(new ResourceManager_test());

      // create the test cases
      test_case* test_ResourceManager_test_case = BOOST_CLASS_TEST_CASE(
                              &ResourceManager_test::test_ResourceManager, instance );

      // add the test cases to the test suite
      add(test_ResourceManager_test_case);
   }
};

}
#endif
