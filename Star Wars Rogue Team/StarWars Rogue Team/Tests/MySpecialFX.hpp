/**
 * File contains classes MySpecialFX definition.
 * @file    MySpecialFX.h
 * @author  Katarzyna Na³êcz
 * @date    2010-12-04
 * @version 1.0
 */

#ifndef MY_SPECIAL_FX_H
#define MY_SPECIAL_FX_H

#include "../SpecialFX.hpp"

namespace test
{

/**
 * Class represents a stub for SpecialFX test class.
 */
class MySpecialFX : public SpecialFX
{
  public:
    bool rendered;
    int initialized;
    float updated;

    MySpecialFX() : rendered(false), initialized(0), updated(0.0) {}
    ~MySpecialFX() {}
    void initializeEffect() {initialized++; }
    void updateEffect(const float elapsedTime) { updated = elapsedTime; };
    void renderEffect() { rendered = true; };
    void reset() {rendered = false; initialized = 0; updated = 0.0;}
};

}
#endif