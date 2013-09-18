/**
 * File contains class ResourceManager_test definition.
 * @file    ResourceManagerTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-04
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "ResourceManagerTest.hpp"
#include "MyResources.hpp"

#include "../ResourceManager/ResourceType.hpp"
#include "../ResourceManager/TypeNotFoundException.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{

PResource createResourceA(std::string a, std::string b)
{
  return boost::shared_ptr<Resource> (new ResourceA(a, b));
}

PResource createResourceB(std::string a, std::string b)
{
  return boost::shared_ptr<Resource> (new ResourceB(a, b));
}

PResource createResourceC(std::string a, std::string b)
{
  return boost::shared_ptr<Resource> (new ResourceC(a, b));
}

/**
 * Test ResourceManager methods.
 */
void ResourceManager_test::test_ResourceManager()
{
  rm.push_back(ResourceManager::getInstance());
  rm[0].registerResource(MESH, &createResourceA);
  rm[0].registerResource(TEXTURE, &createResourceB);

  BOOST_CHECK_NO_THROW(rm[0].getResource("NewName2", "NewFilepath2", MESH));

  rm[0].registerResource(AUDIO, &createResourceC);

  PResource resA = rm[0].getResource("NameA", "FilepathA", MESH);
  std::string resAFilepath = resA->getFilepath();
  BOOST_CHECK_EQUAL(resAFilepath.compare("FilepathA"), 0);

  PResource resB = rm[0].getResource("NameB", "FilepathB", TEXTURE);
  std::string resBFilepath = resB->getFilepath();
  BOOST_CHECK_EQUAL(resBFilepath.compare("FilepathB"), 0);

  PResource resC = rm[0].getResource("NameC", "FilepathC", AUDIO);
  std::string resCFilepath = resC->getFilepath();
  BOOST_CHECK_EQUAL(resCFilepath.compare("FilepathC"), 0);

  rm.clear();
}

}