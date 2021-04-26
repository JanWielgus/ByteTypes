/**
 * @file bitByte.h
 * @author Jan Wielgus (jan.wielgus12@gmail.com)
 * @brief 
 * @date 2021-04-26
 * 
 */

#ifndef BITBYTE_H
#define BITBYTE_H

#include <IByteType.h>


class bitByte : public IByteType
{
	union
	{
		bool bits[8];
		uint8_t byte;
	} data;


public:
	bitByte()
	{
	}

	bitByte(const bitByte& other)
	{
		data.byte = other.data.byte;
	}

	bitByte& operator=(const bitByte& other)
	{
		data.byte = other.data.byte; // don't need to check if this != &other
		return *this;
	}

	uint8_t* byteArray() override
	{
		return &data.byte;
	}

	const uint8_t* byteArray() const override
	{
		return &data.byte;
	}

	uint8_t byteSize() const override
	{
		return 1;
	}

	bool* bitArray()
	{
		return data.bits;
	}

	const bool* bitArray() const
	{
		return data.bits;
	}
};


#endif
