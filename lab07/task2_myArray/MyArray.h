#pragma once

class CMyArray
{
public:
	CMyArray();

	size_t GetSize() const;
	int GetElement(size_t numOfElement) const;
	
	bool AddElement(int element);
	bool Clear();

	int& operator[](size_t position);

	~CMyArray();
private:
	size_t m_size = 0;
	int *m_begin;
};