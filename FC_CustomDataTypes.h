// FC_CustomDataTypes.h
/*
	Created:	03/06/2019
	Author:     Jan Wielgus
*/

#ifndef _FC_CUSTOMDATATYPES_h
#define _FC_CUSTOMDATATYPES_h

#include "arduino.h"


class ByteType
{
public:
	uint8_t AmtOfBytes;

	ByteType(uint8_t amtOfBytes)
		: AmtOfBytes(amtOfBytes)
	{}

	virtual ~ByteType()
	{
	}
	
	virtual uint8_t* byteArr() = 0;
};



class floatByte : public ByteType
{
public:
	static const uint8_t FloatByteSize = 4;

private:
	union
	{
		float value;
		uint8_t byte[FloatByteSize];
	}data;

public:
	floatByte(float v = 0)
		: ByteType(FloatByteSize)
	{
		data.value = v;
	}

	operator float() const
	{
		return data.value;
	}

	uint8_t* byteArr() override
	{
		return data.byte;
	}

};



class uint32Byte : public ByteType
{
public:
	static const uint8_t Uint32ByteSize = 4;
	
private:
	union
	{
		uint32_t value;
		//uint8_t byte[AmtOfBytes];
		uint8_t* byte = new uint8_t[Uint32ByteSize];
	}data;

public:
	uint32Byte(uint32_t v=0)
		:ByteType(Uint32ByteSize)
	{
		data.value = v;
	}

	operator uint32_t() const
	{
		return data.value;
	}

	uint8_t* byteArr() override
	{
		return data.byte;
	}

};



class int32Byte : public ByteType
{
public:
	static const uint8_t Int32ByteSize = 4;
	
private:
	union
	{
		int32_t value;
		uint8_t byte[Int32ByteSize];
	}data;

public:
	int32Byte(int32_t v=0)
		:ByteType(Int32ByteSize)
	{
		data.value = v;
	}

	operator int32_t() const
	{
		return data.value;
	}

	uint8_t* byteArr() override
	{
		return data.byte;
	}

};



class uint16Byte : public ByteType
{
public:
	static const uint8_t Uint16ByteSize = 2;
	
private:
	union
	{
		uint16_t value;
		uint8_t byte[Uint16ByteSize];
	}data;

public:
	uint16Byte(uint16_t v=0)
		:ByteType(Uint16ByteSize)
	{
		data.value = v;
	}

	operator uint16_t() const
	{
		return data.value;
	}

	uint8_t* byteArr() override
	{
		return data.byte;
	}
};



class int16Byte : public ByteType
{
public:
	static const uint8_t Int16ByteSize = 2;
	
private:
	union
	{
		int16_t value;
		uint8_t byte[Int16ByteSize];
	}data;

public:
	int16Byte(int16_t v=0)
		:ByteType(Int16ByteSize)
	{
		data.value = v;
	}

	operator int16_t() const
	{
		return data.value;
	}

	uint8_t* byteArr() override
	{
		return data.byte;
	}
};



class bitByte : public ByteType
{
public:
	static const uint8_t BitByteByteSize = 2;
	
private:
	union
	{
		bool value[8];
		uint8_t byte[BitByteByteSize];
	}data;
	
public:
	bitByte()
		:ByteType(BitByteByteSize)
	{
	}

	bool& operator[](uint8_t index)
	{
		return data.value[index];
	}
	
	uint8_t* byteArr() override
	{
		return data.byte;
	}
};




#endif

