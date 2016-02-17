#pragma once

template <typename T>
class CMyArray
{
public:
	CMyArray()
	{
	}

	CMyArray(const CMyArray &myArray)
	{		
		size_t newSize = myArray.m_size;
		T* newBegin = reinterpret_cast<T*>(malloc(sizeof(T) * newSize));

		if (newBegin == nullptr)
		{
			throw std::bad_alloc();
		}

		for (size_t i = 0; i < newSize; i++)
		{
			T *newElementPtr = new (newBegin + i) T(myArray[i]);
		}

		m_size = newSize;
		m_count = newSize;
		m_begin = newBegin;
	}

	size_t GetSize() const
	{
		return m_size;
	}

	size_t GetCount() const
	{
		return m_count;
	}
	
	void AddElement(T const &element)
	{
		size_t currentSize = GetSize();
		size_t currentCount = GetCount();
		if (currentSize == currentCount)
		{
			T* newBegin = reinterpret_cast<T*>(malloc(sizeof(T) * (currentSize + 1)));

			if (newBegin == nullptr)
			{
				throw std::bad_alloc();
			}

			for (size_t i = 0; i < currentSize; i++)
			{
				T *newElementPtr = new (newBegin + i) T(m_begin[i]);
			}

			T *newElementPtr = new (newBegin + currentSize) T(element);

			std::swap(m_begin, newBegin);
			m_size++;
			m_count++;

			for (size_t i = currentSize; i-- != 0;)
			{
				newBegin[i].~T();
			}
			free(newBegin);
		}
		else
		{
			T *newElementPtr = new (m_begin + currentCount) T(element);
			m_count++;
		}
		
	}

	void Resize(size_t newSize)
	{
		size_t currentSize = GetSize();

		if (newSize > currentSize)
		{
			T* newBegin = reinterpret_cast<T*>(malloc(sizeof(T) * newSize));

			if (newBegin == nullptr)
			{
				throw std::bad_alloc();
			}

			for (size_t i = 0; i < currentSize; i++)
			{
				T *newElementPtr = new (newBegin + i) T(m_begin[i]);
			}

			for (size_t i = currentSize; i < newSize; i++)
			{
				T *newElementPtr = new (newBegin + i) T();
			}

			std::swap(m_begin, newBegin);
			m_size = newSize;
			m_count = newSize;

			for (size_t i = currentSize; i-- != 0;)
			{
				newBegin[i].~T();
			}
			free(newBegin);
		}
		else if (newSize < currentSize)
		{
			for (size_t i = currentSize - 1; i >= newSize; i--)
			{
				m_begin[i].~T();
				m_begin[i] = T();
			}
			m_count = newSize;
		}
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
			m_count = 0;
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

	CMyArray& operator = (CMyArray const& other)
	{
		CMyArray newArray(other);

		std::swap(m_size, newArray.m_size);
		std::swap(m_begin, newArray.m_begin);
		std::swap(m_count, newArray.m_count);

		return *this;
	}

	~CMyArray()
	{
		Clear();		
		free(m_begin);
	}
private:
	size_t m_size = 0;
	size_t m_count = 0;
	T *m_begin = nullptr;
};