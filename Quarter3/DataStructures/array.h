#pragma once
#include <initializer_list>

namespace dc
{
	template<typename T, size_t TSize>
	class array
	{
	public:
		array() {}
		array(const std::initializer_list<T>& ilist)
		{
			size_t i = 0;
			for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
			{
				_elements[i] = *iter;
				i++;
			}
		}
		T& operator [] (size_t position)
		{
			return _elements[position];
		}

		T& at(size_t position)
		{
			return _elements[position];
		}

		const T& operator [] (size_t position) const
		{
			return _elements[position];
		}

		const T& at(size_t position) const
		{
			return _elements[position];
		}

		T& front();
		T& back();

		void fill(const T& value)
		{
			for (size_t i = 0; i < TSize; i++)
			{
				_elements[i] = value;
			}
		}

		void swap(array& other)
		{
			for (size_t i = 0; i < TSize; i++)
			{
				T temp = _elements[i];
				_elements[i] = other[i];
				other[i] = temp;
			}
		}

		T* data() { return _elements; }

		size_t size() const { return TSize; }
		size_t max_size() const { return TSize; }
		bool empty() const { return false; }

	private:
		T _elements[TSize]{};
	};

	template<typename T, size_t TSize>
	T& array<T, TSize>::front()
	{
		return _elements[0];
	}

	template<typename T, size_t TSize>
	T& array<T, TSize>::back()
	{
		return _elements[TSize - 1];
	}
}


