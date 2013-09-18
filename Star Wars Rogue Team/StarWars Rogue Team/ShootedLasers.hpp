/**
 * File contains declaration and definition of ShootedLasers class. 
 * @file    ShootedLasers.hpp
 * @author  Adam Sznajder
 * @date    2011-01-08
 * @version 2.0
 */

#ifndef SHOOTED_LASERS_HPP
#define SHOOTED_LASERS_HPP

#include "SceneEntity.hpp"
#include <boost/shared_ptr.hpp>
#include <vector>

using namespace engine;
using namespace std;

namespace game
{

/**
 * ShootedLasers is class which is used to handle shootedLasers vector.
 * Pointer to this vector is often passed as function's arguments and STL vector
 * while relocation changes it's addres and doesn't inform about this event all it's
 * pointers. To sum up: this class was created in order to work with vector in freely way.
 */
class ShootedLasers
{
private:
	vector< boost::shared_ptr<SceneEntity> > shootedLasers;
public:
	vector< boost::shared_ptr<SceneEntity> >* getShootedLasers() { return &shootedLasers; };
};

}
#endif
