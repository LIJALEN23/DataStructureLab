#include "linkedlist.hpp"
#include "term.hpp"
#include "hashmap.hpp"
#include "pair.hpp"
#include <iostream>
#include <stdexcept>

namespace linkedlist
{
	/**
	 * @brief ������ͷ����һ���ڵ�
	 * 
	 * ����ʱ��Ҫע�⵱ǰ�����Ƿ�Ϊ��
	 * 
	 * @param val ��Ҫ�����ֵ
	 */
	template <typename T>
	void LinkedList<T>::addFirst(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

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
	 * @brief �������ͷ�ڵ�ɾ��
	 * 
	 * ɾ������֮ǰ��Ҫ��������Ƿ�Ϊ��
	 * ɾ���ڵ����Ҫע���������Ƿ��нڵ�
	 * 
	 * @return T ��ɾ���ڵ��ֵ
	 */
	template <typename T>
	T LinkedList<T>::removeFirst()
	{
		if (isEmpty())
		{
			//����Ϊ���׳��쳣
			throw std::runtime_error("[removeFirst()] : The linkedlist is empty!");
		}

		Node<T>* temp = head_;
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
		Node<T>* newNode = new Node<T>(data);

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

		Node<T>* temp = tail_;
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
	T LinkedList<T>::remove(u32 index)
	{
		Node<T>* current = head_;
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
	Node<T>* LinkedList<T>::getHead() const
	{
		return head_;
	}

	template<typename T>
	Node<T>* LinkedList<T>::getTail() const
	{
		return tail_;
	}

	template<typename T>
	void LinkedList<T>::setHead(Node<T>* node)
	{
		head_ = node;
	}

	template<typename T>
	void LinkedList<T>::setTail(Node<T>* node)
	{
		tail_ = node;
	}

	
	//template<typename T>
	//T LinkedList<T>::get(u32 index) const
	//{



	//}

	//template<typename T>
	//void LinkedList<T>::addAll(const LinkedList<T>& list)
	//{
	//}

	//template<typename T>
	//LinkedList<T> LinkedList<T>::subList(u32 start, u32 end) const
	//{

	//}

	template<typename T>
	void LinkedList<T>::clear()
	{

		while (head_ != nullptr)
		{
			Node<T>* temp = head_;
			head_ = head_->next_;
			delete temp;
		}

		tail_ = nullptr;
		size_ = 0;
	}

	//template<typename T>
	//std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
	//{
	//	Node<T>* current = list.head_;
	//	while (current != nullptr)
	//	{
	//		os << current->data_ << " <-> ";
	//		current = current->next_;
	//	}
	//	os << "nullptr";

	//	return os;
	//}

	template class linkedlist::LinkedList<u32>;
	template class linkedlist::LinkedList<struct lab01::Term>;
	template class linkedlist::LinkedList<struct hashmap::Pair<u32, u32>>;
	template class linkedlist::LinkedList<struct hashmap::Pair<u32, double>>;
	//template std::ostream& operator<<(std::ostream& os, const linkedlist::LinkedList<int>& list);
}