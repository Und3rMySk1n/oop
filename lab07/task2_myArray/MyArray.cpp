#include "stdafx.h"
#include "MyArray.h"

using namespace std;
const size_t DEFAULT_SIZE = 100;

CMyArray::CMyArray()
{
	m_begin = (int*)malloc((sizeof(int)));
}

CMyArray::~CMyArray()
{
	free(m_begin);
}

size_t CMyArray::GetSize() const
{
	return m_size;
}

bool CMyArray::AddElement(int element)
{
	int* newBegin = NULL;
	size_t elementPosition = GetSize();
	newBegin = (int*)realloc(m_begin, sizeof(int) * (elementPosition + 1));

	if (newBegin != NULL) {
		m_begin = newBegin;
	}
	else {
		free(m_begin);
		return false;
	}		

	m_begin[elementPosition] = element;
	m_size++;

	return true;
}

bool CMyArray::Clear()
{
	free(m_begin);
	m_begin = (int*)malloc((sizeof(int)));
	m_size = 0;

	return true;
}

int& CMyArray::operator[](size_t position)
{
	if (position >= GetSize())
	{
		throw std::out_of_range("Element is out of range.");
	}

	return m_begin[position];
}