/**
* @file arraylist.hpp
* @brief ArrayList类的头文件
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-16
* @version 2.0
*/
#pragma once
#include "myint.hpp"
#include <iostream>

/**
* @namespace arraylist
* @brief 与ArrayList有关的都放在该名称空间中中
*/
namespace arraylist
{
	constexpr size_t DEFAULT_CAPACIY = 10;	//默认数组大小

	/**
	* @brief ArrayList类的头文件声明
	* 
	* @details 一个泛型的ArrayList类，包括基本的增删查改
	*/
	template<typename T>
	class ArrayList
	{
	public:
		ArrayList();					 //默认构造函数

		ArrayList(size_t capacity);		 //给定初始空间的构造函数
			
		/**
		* @brief ArrayList的析构函数，当data_不为空时，需要释放其开辟的内存
		*/
		~ArrayList()
		{	if (!isEmpty())
			{
				delete[] data_;
			}
		}

		ArrayList(const ArrayList& other);						//复制构造函数

		ArrayList(ArrayList&& other) noexcept;					//移动构造函数

		ArrayList& operator=(const ArrayList& other);			//赋值运算符

		ArrayList& operator=(ArrayList&& other) noexcept;		//移动赋值运算符

		

		void addFirst(const T& data);				//在列表第一个位置插入新数据

		T removeFirst();							//将列表第一个位置的数据删除

		void addLast(const T& data);				//在列表最后一个位置插入新数据

		T removeLast();								//将列表最后一个位置的数据删除

		T get(size_t index);						//获得下标index处的数据

		const T& get(size_t index) const;			//获得下标index处的数据的常量引用

		const T& operator[](size_t index) const;	//重载[]以实现用数组方式获得下标index处的常量引用

		T remove(size_t index);						//删除下标index处的数据

		void set(size_t index, const T& data);		//在下标index出的元素重新设置成data
			
		bool isEmpty() { return size_ == 0; }		//判断列表是否为空	
			
		size_t size() const { return size_; };			//获得列表中元素的数量

		friend std::ostream& operator<<(std::ostream& os, const ArrayList& list);	//重载<<以实现输出列表中元素，需要显式具体化

	private:
		T* data_;			//存放数据的数组
			
		size_t capacity_;	//该列表的容量大小

		size_t size_;		//该列表现在使用的数量


		void resize(size_t new_capacity);	//当列表中元素数量到达一定值时，需要进行扩容等
	};

}