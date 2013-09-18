/**
 * Declaration of FontException class.
 * @file    TextCreationException.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef FONTEXC_H
#define FONTEXC_H

#include <typeinfo>

namespace menu
{

/**
 * TextCreationException is an exception which is thrown when it's impossible to find a font.
 */
class FontException : public std::exception
{

};

}
#endif