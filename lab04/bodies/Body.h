#pragma once
class CBody
{
public:
	CBody(const std::string & type, double density);
	
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	std::string ToString() const;

	virtual ~CBody();
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	double m_density;
	std::string m_type;
};
