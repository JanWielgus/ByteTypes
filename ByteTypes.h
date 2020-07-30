// FC_CustomDataTypes.h
/*
	Created:	03/06/2019
	Modified:	30/07/2020
	Author:     Jan Wielgus
*/

#ifndef BYTETYPES_H
#define BYTETYPES_H

#include "IByteType.h"


template <class T, int SizeInBytes>
class byteType : public IByteType
{
private:
	union
	{
		T value;
		uint8_t bytes[SizeInBytes];
	} data;


public:
	byteType()
	{
	}

	byteType(T value)
	{
		data.value = value;
	}

	~byteType() {}

	uint8_t* byteArray() override
	{
		return data.bytes;
	}

	const uint8_t* byteArray() const override
	{
		return data.bytes;
	}

	uint8_t byteSize() override
	{
		return SizeInBytes;
	}

	operator T() const
	{
		return data.value;
	}

	byteType<T, SizeInBytes>& operator=(const byteType<T, SizeInBytes>& other)
	{
		if (this != &other)
		{
			data.value = other.data.value;
		}

		return *this;
	}
};




class bitByte : public IByteType
{
private:
	union
	{
		bool bits[8];
		uint8_t byte;
	} data;

public:
	uint8_t* byteArray() override
	{
		return &data.byte;
	}

	const uint8_t* byteArray() const override
	{
		return &data.byte;
	}

	uint8_t byteSize() override
	{
		return 1;
	}

	bool& operator[](uint8_t index)
	{
		return data.bits[index];
	}
};



typedef byteType<uint8_t, 1> uint8Byte;
typedef byteType<uint16_t, 2> uint16Byte;
typedef byteType<uint32_t, 4> uint32Byte;

typedef byteType<int8_t, 1> int8Byte;
typedef byteType<int16_t, 2> int16Byte;
typedef byteType<int32_t, 4> int32Byte;

typedef byteType<float, 4> floatByte;


#endif

