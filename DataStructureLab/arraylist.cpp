/**
* @file arraylist.cpp
* @brief ArrayList类的实现
*
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-16
* @version 2.0
*/
#include "myint.hpp"
#include "arraylist.hpp"
#include <stdexcept>
#include <iostream>

/**
* @namespace arraylist
* @brief 与ArrayList有关的都放在该名称空间中中
*/
namespace arraylist {

	/**
	* @brief ArrayList的构造函数，初始化data_数组(分配默认的空间)
	*/
	template<typename T>
	ArrayList<T>::ArrayList()
	{
		data_ = new T[DEFAULT_CAPACIY];
		capacity_ = DEFAULT_CAPACIY;

		//初始化data_
		for (size_t i = 0; i < capacity_; i++)
		{
			new (data_ + i) T();
		}

		size_ = 0;
	}

	/**
	* @brief 构造函数，用于创建具有指定容量的 ArrayList 对象。
	*
	* @param capacity 指定数组的初始容量。如果容量小于或等于零，则抛出异常。
	*
	* @throws std::invalid_argument 如果提供的容量值是非正数，则抛出此异常。
	*/
	template<typename T>
	ArrayList<T>::ArrayList(size_t capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("Capacity must be positive.");
		}

		data_ = new T[capacity];
		capacity_ = capacity;

		//初始化data_
		for (size_t i = 0; i < capacity_; i++)
		{
			new (data_ + i) T();
		}

		size_ = 0;
	}

	/**
	* @brief 拷贝构造函数，用于创建一个与已有 ArrayList 对象完全相同的副本
	* 
	* @param other 要拷贝的 ArrayList 对象。
	*/
	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;

		data_ = new T[capacity_];

		//将other.data_的每个数据复制到data_中
		for (size_t i = 0; i < capacity_; i++)
		{
			new (data_ + i) T(other.data_[i]);
		}
	}

	/**
	* 移动复制构造函数*/
	template<typename T>
	ArrayList<T>::ArrayList(ArrayList&& other) noexcept
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		data_ = other.data_;

		//将原来的data设置成nullptr
		other.data_ = nullptr;
	}

	/**
	* 重载赋值运算符*/
	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other)
	{
		if (this != &other)
		{
			//先释放原来的内存
			delete[] data_;

			capacity_ = other.capacity_;
			size_ = other.size_;

			data_ = new T[capacity_];
			std::uninitialized_copy(other.data_, other.data_ + size_, data_);
		}

		return *this;
	}

	/**
	* 重载移动赋值运算符*/
	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(ArrayList&& other) noexcept
	{
		if (this != &other)
		{
			capacity_ = other.capacity_;
			size_ = other.size_;
			data_ = other.data_;

			//将原来的data设置成nullptr
			other.data_ = nullptr;
		}

		return *this;
	}

	template<typename T>
	void ArrayList<T>::addFirst(const T& data)
	{
		//判断是否需要扩容
		if (capacity_ == size_)
		{
			resize(capacity_ * 2);
		}

		std::memmove(data_ + 1, data_, sizeof(T) * size_);

		new (&data_[0]) T(data);
		size_++;
	}

	template<typename T>
	T ArrayList<T>::removeFirst()
	{
		if (isEmpty())
		{
			throw std::out_of_range("Cannot remove from an empty list!");
		}

		T data = std::move(data_[0]);

		std::memmove(data_, &data_[1], sizeof(T) * (size_ - 1));
		
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

		new (&data_[size_++]) T(data);
	}

	template<typename T>
	T ArrayList<T>::removeLast()
	{
		if (isEmpty())
		{
			throw std::out_of_range("Cannot remove from an empty list!");
		}

		T data = std::move(data_[--size_]);
		//将最后一个元素手动析构
		data_[size_].~T();

		if (size_ < capacity_ / 4)
		{
			resize(capacity_ / 2);
		}

		return data;
	}

	template<typename T>
	T ArrayList<T>::get(size_t index)
	{
		if (index >= size_)
		{
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	template<typename T>
	const T& ArrayList<T>::get(size_t index) const
	{
		if (index >= size_)
		{
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	template<typename T>
	const T& ArrayList<T>::operator[](size_t index) const{
		if (index >= size_)
		{
			throw std::out_of_range("Index out of range");
		}

		return data_[index];
	}

	template<typename T>
	void ArrayList<T>::set(size_t index, const T& data)
	{
		if (index >= size_)
		{
			throw std::out_of_range("Index out of range");
		}

		data_[index] = data;
	}

	template<typename T>
	void ArrayList<T>::resize(size_t new_capacity)
	{
		T* temp = new T[new_capacity];
		std::uninitialized_copy_n(data_, size_, temp);

		delete[] data_;

		data_ = temp;
		capacity_ = new_capacity;
	}

	std::ostream& operator<<(std::ostream& os, const ArrayList<u32>& list)
	{
		os << "[";

		for (size_t i = 0; i < list.size() - 1; i++)	
		{ 
			os << list.get(i) << " ";
		}
			
		return os << list.get(list.size() - 1) << "]";
	}

	template class ArrayList<u32>;
}