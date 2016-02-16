#pragma once

template <typename T>
class CMyArray
{
public:
	CMyArray()
	{
	}

	size_t GetSize() const
	{
		return m_size;
	}
	
	void AddElement(T const &element)
	{
		size_t currentSize = GetSize();

		T* newBegin = nullptr;
		
		// такой способ не подходит, нельзя копировать объект побитово
		newBegin = reinterpret_cast<T*>(realloc(m_begin, sizeof(T) * (currentSize + 1)));

		if (newBegin != nullptr) 
		{
			m_begin = newBegin;			
		}
		else 
		{
			throw std::bad_alloc();
		}

		T *newElementPtr = new (m_begin + currentSize) T(element);
		m_size++;
	}

	void Clear()
	{
		if (GetSize() != 0)
		{
			for (size_t i = GetSize(); i-- != 0;)
			{
				m_begin[i].~T();
			}

			
			m_size = 0;
		}
		
	}	

	T& operator[](size_t position)
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range.");
		}

		return m_begin[position];
	}

	T& operator[](size_t position) const
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range.");
		}

		return m_begin[position];
	}

	~CMyArray()
	{
		if (GetSize() != 0)
		{
			for (size_t i = GetSize(); i-- != 0;)
			{
				m_begin[i].~T();
			}
		}
		
		free(m_begin);
	}
private:
	size_t m_size = 0;
	T *m_begin = nullptr;
};