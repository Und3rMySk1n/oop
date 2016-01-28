#include "stdafx.h"
#include "SolidBody.h"

CSolidBody::CSolidBody(const std::string & type, double density)
	: CBody(type, density)
{
}

CSolidBody::~CSolidBody()
{
}

double CSolidBody::GetMass()const
{
	return GetVolume() * GetDensity();
}