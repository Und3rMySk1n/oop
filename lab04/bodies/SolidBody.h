#pragma once
#include "Body.h"

class CSolidBody :
	public CBody
{
public:
	CSolidBody(const std::string & type, double density);

	double GetMass() const override;

	virtual ~CSolidBody();
};

