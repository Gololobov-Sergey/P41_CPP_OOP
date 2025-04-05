#pragma once
#include <iostream>
#include "String.h"


using namespace std;


enum class ReservoirType
{
	OCEAN, SEA, RIVER, LAKE, POND, PUDDLE, UNDEFINED = -1
};

const char* getReservoirType(ReservoirType type)
{
	switch (type)
	{
	case ReservoirType::OCEAN:  return "Ocean";
	case ReservoirType::SEA:    return "Sea";
	case ReservoirType::RIVER:  return "River";
	case ReservoirType::LAKE:   return "Lake";
	case ReservoirType::POND:   return "Pond";
	case ReservoirType::PUDDLE: return "Puddle";
	default:            		return "Undefined";
	}
}

class Reservoir
{
	ReservoirType type;
	String name;
	double width;
	double length;
	double depth;

public:
	Reservoir(ReservoirType type, String name, double width, double length, double depth)
	{
		this->type = type;
		this->name = name;
		this->width = width;
		this->length = length;
		this->depth = depth;
	}

	void print() const
	{
		cout << "Type   : " << getReservoirType(type) << endl;
		cout << "Name   : " << name.get() << endl;
		cout << "Width  : " << width << endl;
		cout << "Length : " << length << endl;
		cout << "Depth  : " << depth << endl;
	}
};

