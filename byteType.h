/**
 * @file byteType.h
 * @author Jan Wielgus (jan.wielgus12@gmail.com)
 * @brief 
 * @date 2019-06-03
 * @date 2020-07-30
 * @date 2021-04-26
 * 
 */

#ifndef BYTETYPES_H
#define BYTETYPES_H

#include <IByteType.h>


template <class T, const uint8_t SizeInBytes = sizeof(T)>
class byteType : public IByteType
{
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

	byteType(const byteType<T, SizeInBytes>& other)
	{
		data.value = other.data.value;
	}

	byteType<T, SizeInBytes>& operator=(const byteType<T, SizeInBytes>& other)
	{
		if (this != &other)
		{
			data.value = other.data.value;
		}

		return *this;
	}

	uint8_t* byteArray() override
	{
		return data.bytes;
	}

	const uint8_t* byteArray() const override
	{
		return data.bytes;
	}

	uint8_t byteSize() const override
	{
		return SizeInBytes;
	}

	operator T() const
	{
		return data.value;
	}

	bool operator==(const byteType<T, SizeInBytes>& other) const
	{
		return data.value == other.data.value;
	}

	bool operator!=(const byteType<T, SizeInBytes>& other) const
	{
		return data.value != other.data.value;
	}
};


typedef byteType<uint8_t> uint8Byte;
typedef byteType<uint16_t> uint16Byte;
typedef byteType<uint32_t> uint32Byte;

typedef byteType<int8_t> int8Byte;
typedef byteType<int16_t> int16Byte;
typedef byteType<int32_t> int32Byte;

typedef byteType<float> floatByte;


#endif

