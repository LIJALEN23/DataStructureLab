/**
* @file linkedlist.hpp
* @brief LinkedList类的头文件
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-19
* @version 2.0
*/
#pragma o
#pragma once
#include "myint.hpp"
#include <ostream>

/**
* @namespace linkedlist
* @brief 与LinkedList有关的都放在该名称空间中中
*/
namespace linkedlist
{

	/**
	* @brief LinkedList类的头文件声明
	*
	* @details 一个泛型的LinkedList类，包括基本的增删查改
	*/
	template <typename T>
	class LinkedList
	{
	public:
		LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}		//默认无参构造函数

		/**
		* @brief LinkedList的析构函数，当链表不为空时，需要释放其开辟的内存
		*/
		~LinkedList()						
		{
			if (!isEmpty())
			{
				clear();
			}
		}

		LinkedList(const LinkedList& other);					//复制构造函数

		LinkedList(LinkedList&& other) noexcept;				//移动复制构造函数

		LinkedList& operator=(const LinkedList& other);			//赋值运算符

		LinkedList& operator=(LinkedList&& other) noexcept;		//移动赋值运算符



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
			
		size_t size() const { return size_; };		//获得列表中元素的数量

		void clear();								//清空链表

		friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);	//重载<<以实现输出列表中元素，需要显式具体化

	private:
		/**
		* @brief Node，链表的节点 
		*/
		struct Node	
		{
			T data_;		//节点存储的数据
			Node* pre_;		//指向前一个节点的指针
			Node* next_;	//指向下一个节点的指针

			Node(const T& data, Node* pre = nullptr, Node* next = nullptr) : data_(data), pre_(pre), next_(next) {} //构造函数
		};

		Node* head_;		//链表的头节点
		Node* tail_;		//链表的根节点
		size_t size_;		//链表的数量
	};

}