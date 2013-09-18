/**
 * Declaration of TextCreationException class.
 * @file    TextCreationException.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef TEXTCREATEXC_H
#define TEXTCREATEXC_H

#include <typeinfo>

namespace menu
{

/**
 * TextCreationException is an exception which is thrown when it's impossible to create a TTF based text
 * and display it on the screen.
 */
class TextCreationException : public std::exception
{

};

}
#endif