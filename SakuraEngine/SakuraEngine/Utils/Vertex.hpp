/**
 * File contains declaration of Vertex class.
 * @file    Vertex.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-24
 * @version 1.0
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

namespace Utils
{

/**
 * Class represents basic part of model geometry - Vertex, represented by XYZ system.
 */
class Vertex
{
public:
	float x;
	float y;
	float z;

	Vertex() { x = 0; y = 0; z = 0; }
};

}
#endif
