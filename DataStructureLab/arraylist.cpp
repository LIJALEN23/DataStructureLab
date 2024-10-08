#include "arraylist.hpp"
#include "linkedlist.hpp"
#include "hashmap.hpp"
#include "pair.hpp"
#include "polynomial.hpp"
#include <stdexcept>
#include <iostream>

namespace arraylist {

	template<typename T>
	ArrayList<T>::ArrayList()
	{
		data_ = new T[DEFAULT_CAPACIY];
		capacity_ = DEFAULT_CAPACIY;
		for (u32 i = 0; i < capacity_; i++)
		{
			new (data_ + i) T();
		}
		size_ = 0;
	}

	template<typename T>
	ArrayList<T>::ArrayList(u32 capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("Capacity must be positive.");
		}

		data_ = new T[capacity];
		capacity_ = capacity;
		for (u32 i = 0; i < capacity_; i++)
		{
			new (data_ + i) T();
		}
		size_ = 0;
	}

	template<typename T>
	void ArrayList<T>::addFirst(const T& data)
	{
		if (capacity_ == size_)
		{
			resize(capacity_ * 2);
		}

		for (u32 i = size_; i > 0; i--)
		{
			data_[i] = data_[i - 1];
		}

		data_[0] = data;
		size_++;
	}

	template<typename T>
	T ArrayList<T>::removeFirst()
	{
		if (isEmpty())
		{
			throw std::out_of_range("Cannot remove from an empty list!");
		}

		T data = data_[0];
		for (u32 i = 0; i < size_ - 1; i++)
		{
			data_[i] = data_[i + 1];
		}
		
		size_--;
		if (size_ < capacity_ / 4)
		{
			resize(capacity_ / 2);
		}

		return data;
	}

	template<typename T>
	void ArrayList<T>::addLast(const T& data)
	{
		if (capacity_ == size_)
		{
			resize(capacity_ * 2);
		}

		data_[size_++] = data;
	}

	template<typename T>
	T ArrayList<T>::removeLast()
	{
		if (isEmpty())
		{
			throw std::out_of_range("Cannot remove from an empty list!");
		}
		T data = data_[--size_];

		if (size_ < capacity_ / 4)
		{
			resize(capacity_ / 2);
		}

		return data;
	}

	template<typename T>
	T& ArrayList<T>::get(u32 index)
	{
		if (index >= capacity_)
		{
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	template<typename T>
	const T& ArrayList<T>::get(u32 index) const
	{
		if (index >= capacity_)
		{
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	template<typename T>
	void ArrayList<T>::resize(u32 new_capacity)
	{
		T* temp = new T[new_capacity];
		for (u32 i = 0; i < new_capacity; i++)
		{
			temp[i] = data_[i];
		}

		delete[] data_;
		data_ = temp;
		capacity_ = new_capacity;
	}

	//template<typename T>
	//void ArrayList<T>::printArr() const
	//{
	//	std::cout << "[ ";
	//	for (u32 i = 0; i < size_; i++)
	//	{
	//		std::cout << data_[i] << " ";
	//	}
	//	std::cout << "]" << std::endl;
	//}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, ArrayList<T> list)
	{
		os << "[ ";

		for (u32 i = 0; i < list.size(); i++)
		{
			os << list.get(i) << " ";
		}

		return os << "]";
	}


	template class arraylist::ArrayList<u32>;
	template class arraylist::ArrayList<class linkedlist::LinkedList<struct hashmap::Pair<u32, u32>>>;
	template class arraylist::ArrayList<class linkedlist::LinkedList<struct hashmap::Pair<u32, double>>>;
	template class arraylist::ArrayList<lab01::Polynomial>;
	//template std::ostream& operator<<(std::ostream& os, ArrayList<int> list);
}