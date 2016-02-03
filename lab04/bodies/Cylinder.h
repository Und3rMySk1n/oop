#pragma once
#include "SolidBody.h"
class CCylinder :
	public CSolidBody
{
public:
	CCylinder(double density, double radius, double height);

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

	~CCylinder();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_radius;
	double m_height;
};

