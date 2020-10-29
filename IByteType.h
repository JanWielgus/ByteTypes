/**
 * @file IByteType.h
 * @author Jan Wielgus
 * @date 2020-07-30
 * 
 */

#ifndef IBYTETYPE_H
#define IBYTETYPE_H

#ifdef ARDUINO
    #include <arduino.h>
#endif


class IByteType
{
public:
    virtual ~IByteType() {}

    virtual uint8_t* byteArray() = 0;
    virtual const uint8_t* byteArray() const = 0;
    virtual uint8_t byteSize() = 0;
};


#endif
