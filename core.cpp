#include "i2cclass.h"
#include "ErrorNo.h"


int i2cclas::writeCommand_(uint8_t reg, uint8_t value)
{
    uint8_t command[2];
    command[0] = reg;
    command[1] = value;

    return i2c.write((uint8_t)0xED, (const char *)command, 2);
}

int i2cclas::readCommand_(uint8_t reg, uint8_t* buffer, int length)
{
    int result;

    if (buffer == NULL || length <= 0 )
        return MICROBIT_INVALID_PARAMETER;

    result = i2c.write((uint8_t)0xED, (const char *)&reg, 1);
    if (result !=0)
        return MICROBIT_I2C_ERROR;

    result = i2c.read((uint8_t)0xED, (char *)buffer, length);
    if (result !=0)
        return MICROBIT_I2C_ERROR;

    return MICROBIT_OK;
}

int i2cclas::getid()
{
    uint8_t data;
    int result;

    result = readCommand_((uint8_t)0xD0, &data, 1);
    if (result !=0)
        return MICROBIT_I2C_ERROR;

    return (int)data;
}
