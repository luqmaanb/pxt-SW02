#ifndef CORE_H
#define CORE_H

#include "MicroBitI2C.h"

class i2cclas
{
    MicroBitI2C&    i2c;                // The I2C interface to use.
public:
    i2cclas(MicroBitI2C &_i2c):i2c(_i2c){}
    int getid();
private:
    int writeCommand_(uint8_t reg, uint8_t value);
    int readCommand_(uint8_t reg, uint8_t* buffer, int length);
};
#endif
