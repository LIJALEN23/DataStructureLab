#pragma once
#include "myint.hpp"
#include <iostream>

namespace arraylist
{
	constexpr u32 DEFAULT_CAPACIY = 10;

	template <typename T>
	class ArrayList
	{
	public :
		ArrayList();
		ArrayList(u32 capacity);
		~ArrayList()
		{	if (!isEmpty())
			{
				delete[] data_;
			}
		}

		void addFirst(const T& data);
		T removeFirst();
		void addLast(const T& data);
		T removeLast();
		T& get(u32 index);
		const T& get(u32 index) const;
		bool isEmpty() { return size_ == 0; }
		u32 size() const { return size_; };
		//void printArr() const;
		//friend std::ostream& operator<<(std::ostream& os, ArrayList<T> list);

	private:
		T* data_;
		u32 capacity_;
		u32 size_;

		void resize(u32 new_capacity);
	};
}