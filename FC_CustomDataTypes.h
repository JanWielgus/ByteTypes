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
	virtual ~ByteType()
	{
	}
	
	virtual uint8_t* byteArr() = 0;
};



class floatByte : public ByteType
{
public:
	static const uint8_t AmtOfBytes = 4;
	
private:
	union
	{
		float value;
		uint8_t byte[AmtOfBytes];
	}data;

public:
	floatByte(float v=0)
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
	static const uint8_t AmtOfBytes = 4;
	
private:
	union
	{
		uint32_t value;
		uint8_t byte[AmtOfBytes];
	}data;

public:
	uint32Byte(uint32_t v=0)
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
	static const uint8_t AmtOfBytes = 4;
	
private:
	union
	{
		int32_t value;
		uint8_t byte[AmtOfBytes];
	}data;

public:
	int32Byte(int32_t v=0)
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
	static const uint8_t AmtOfBytes = 2;
	
private:
	union
	{
		uint16_t value;
		uint8_t byte[AmtOfBytes];
	}data;

public:
	uint16Byte(uint16_t v=0)
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
	static const uint8_t AmtOfBytes = 2;
	
private:
	union
	{
		int16_t value;
		uint8_t byte[AmtOfBytes];
	}data;

public:
	int16Byte(int16_t v=0)
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



union bitByte
{
	bool value[8];
	uint8_t byte;
};





#endif

