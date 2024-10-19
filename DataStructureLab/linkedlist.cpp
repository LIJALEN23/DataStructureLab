/**
* @file linkedlist.cpp
* @brief LinkedList类的实现
* 
* @author [lijalen](https://github.com/LIJALEN23)
* @date 2024-10-19
* @version 2.0
*/

#include "linkedlist.hpp"
#include <iostream>
#include <stdexcept>

/**
* @namespace arraylist
* @brief 与ArrayList有关的都放在该名称空间中中
*/
namespace linkedlist
{
	template<typename T>
	LinkedList<T>::LinkedList(const LinkedList& other)
	{
		head_ = nullptr;
		tail_ = nullptr;
		size_ = 0;

		Node* current = other.head_;
		while (current != nullptr) {
			addLast(current->data_);
			current = current->next_;
		}
	}

	template<typename T>
	LinkedList<T>::LinkedList(LinkedList&& other) noexcept
	{
		head_ = other.head_;
		tail_ = other.tail_;
		size_ = other.size_;

		other.head_ = nullptr;
		other.tail_ = nullptr;
	}

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
	{
		if (this != &other) { // 避免自我赋值
			clear(); // 清空当前链表

			Node* current = other.head_;
			while (current != nullptr) {
				addLast(current->data_); // 使用 addLast 或 addFirst 方法添加节点
				current = current->next_;
			}
		}
		return *this; // 返回当前对象的引用
	}

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept
	{
		if (this != &other) {
			head_ = other.head_;
			tail_ = other.tail_;
			size_ = other.size_;

			other.head_ = nullptr;
			other.tail_ = nullptr;
		}

		return *this;
	}

	/**
	 * @brief 在链表头部插一个节点
	 * 
	 * 插入时需要注意当前链表是否为空
	 * 
	 * @param val 需要插入的值
	 */
	template <typename T>
	void LinkedList<T>::addFirst(const T& data)
	{
		Node* newNode = new Node(data);

		if (isEmpty())
		{
			tail_ = head_ = newNode;
		}
		else
		{
			newNode->next_ = head_;
			head_->pre_ = newNode;
			head_ = newNode;
		}

		size_++;
	}

	/**
	 * @brief 将链表的头节点删除
	 * 
	 * 删除操作之前需要检查链表是否为空
	 * 删除节点后需要注意链表中是否还有节点
	 * 
	 * @return T 被删除节点的值
	 */
	template <typename T>
	T LinkedList<T>::removeFirst()
	{
		if (isEmpty())
		{
			//链表为空抛出异常
			throw std::runtime_error("[removeFirst()] : The linkedlist is empty!");
		}

		Node* temp = head_;
		T data = temp->data_;

		head_ = head_->next_;
		head_->pre_ = nullptr;
		if (head_ == nullptr)
		{
			tail_ = nullptr;
		}

		delete temp;
		size_--;

		return data;
	}

	template <typename T>
	void LinkedList<T>::addLast(const T& data)
	{
		Node* newNode = new Node(data);

		if (isEmpty())
		{
			head_ = tail_ = newNode;
		}
		else
		{
			newNode->pre_ = tail_;
			tail_->next_ = newNode;
			tail_ = newNode;
		}

		size_++;
	}

	template <typename T>
	T LinkedList<T>::removeLast()
	{
		if (isEmpty())
		{
			throw std::runtime_error("[removeLast()] : The linkedlist is empty!");
		}

		Node* temp = tail_;
		T data = temp->data_;

		tail_ = tail_->pre_;
		tail_->next_ = nullptr;
		if (tail_ == nullptr)
		{
			head_ = nullptr;
		}

		delete temp;
		size_--;

		return data;
	}

	template<typename T>
	T LinkedList<T>::remove(size_t index)
	{
		Node* current = head_;
		while (index != 0)
		{
			current = current->next_;
			index--;
		}

		(*current->pre_).next_ = current->next_;
		(*current->next_).pre_ = current->pre_;

		T data = current->data_;
		return data;
	}

	template<typename T>
	T LinkedList<T>::get(size_t index)
	{
		if (index + 1 > size_)
		{
			;
		}

		Node* current = head_;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next_;
		}

		return current->data_;
	}
	
	template<typename T>
	const T& LinkedList<T>::get(size_t index) const
	{
		if (index + 1 > size_)
		{
			;
		}

		Node* current = head_;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next_;
		}

		return current->data_;

	}

	template<typename T>
	const T& LinkedList<T>::operator[](size_t index) const
	{
		if (index + 1 > size_)
		{
			;
		}

		Node* current = head_;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next_;
		}

		return current->data_;

	}

	template<typename T>
	void LinkedList<T>::set(size_t index, const T& data)
	{
	}

	template<typename T>
	void LinkedList<T>::clear()
	{

		while (head_ != nullptr)
		{
			Node* temp = head_;
			head_ = head_->next_;
			delete temp;
		}

		tail_ = nullptr;
		size_ = 0;
	}


	std::ostream& operator<<(std::ostream& os, const LinkedList<u32>& list)
	{
		LinkedList<u32>::Node* current = list.head_;

		while (current != nullptr)
		{ 
			os << current->data_ << " <-> ";
			current = current->next_;
		}

		os << "nullptr";

		return os;
	}

	template class LinkedList<u32>;
	
}