#ifndef MY_RESOURCES_H
#define MY_RESOURCES_H
#include <string>

using namespace resMan;

namespace test
{

/**
 * Class represents Resource stub.
 */
class ResourceA : public Resource
{
  public:
    ResourceA(std::string n, std::string f)
    {
      name = &n;
      filepath = f;
    }
    void loadResource() {}
};

/**
 * Class represents Resource stub.
 */
class ResourceB : public Resource
{
  public:
    ResourceB(std::string n, std::string f)
    {
      name = &n;
      filepath = f;
    }
    void loadResource() {}
};

/**
 * Class represents Resource stub.
 */
class ResourceC : public Resource
{
  public:
    ResourceC(std::string n, std::string f)
    {
      name = &n;
      filepath = f;
    }
    void loadResource() {}
};

}
#endif