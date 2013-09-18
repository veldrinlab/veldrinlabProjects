/**
 * File contains class Texture_test definition.
 * @file    TextureTest.cpp
 * @author  Katarzyna Na³êcz
 * @date    2010-12-03
 * @version 1.0
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <iostream>
#include <fstream>
#include "TextureTest.hpp"

using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

namespace test
{
/*
 * Test Texture class.
 */
void Texture_test::test_Texture()
{
  /* Test konstruktorów: */
  try
  {
    std::string name = "Texture";
    std::string filepath = "tekstura1.bmp";
    t.push_back(new Texture(name, filepath));
    std::string textureName = t[0].getName();
    std::string textureFilepath = t[0].getFilepath();
    BOOST_CHECK_EQUAL(textureName.compare(name), 0);
    BOOST_CHECK_EQUAL(textureFilepath.compare(filepath), 0);
  } catch(std::bad_alloc) {
    std::cout << "Class Texture: constructor with initialization values does not work properly:\n";
    std::cout << "std::bad_alloc\n";
  }

  try
  {
    std::string name1 = "Texture";
    std::string filepath1 = "tekstura1.bmp";
    Texture txt = Texture(name1, filepath1);
    std::string textureName1 = t[0].getName();
    std::string textureFilepath1 = t[0].getFilepath();
    BOOST_CHECK_EQUAL(textureName1.compare(name1), 0);
    BOOST_CHECK_EQUAL(textureFilepath1.compare(filepath1), 0);
  } catch(std::bad_alloc) {
    std::cout << "Class Texture: copy constructor does not work properly:\n";
    std::cout << "std::bad_alloc\n";
  }

  t.clear();
}

}