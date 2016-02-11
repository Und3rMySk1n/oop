#pragma once

template <typename T>
class CMyArray
{
public:
	CMyArray()
	{
		m_begin = (T*)malloc((sizeof(T)));
	}

	size_t GetSize() const
	{
		return m_size;
	}

	T GetElement(size_t numOfElement) const;
	
	bool AddElement(T element)
	{
		T* newBegin = NULL;
		size_t elementPosition = GetSize();
		newBegin = (T*)realloc(m_begin, sizeof(T) * (elementPosition + 1));

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

	bool Clear()
	{
		free(m_begin);
		m_begin = (T*)malloc((sizeof(T)));
		m_size = 0;

		return true;
	}

	T& operator[](size_t position)
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range.");
		}

		return m_begin[position];
	}

	~CMyArray()
	{
		free(m_begin);
	}
private:
	size_t m_size = 0;
	T *m_begin;
};
