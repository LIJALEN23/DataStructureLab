#pragma once
#include "node.hpp"
#include "myint.hpp"
#include <ostream>

namespace linkedlist
{
	template <typename T>
	class LinkedList
	{
	private:
		Node<T>* head_;
		Node<T>* tail_;
		u32 size_;

	public:
		LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
		~LinkedList()
		{
			if (!isEmpty())
			{
				clear();
			}
		}

		LinkedList(const LinkedList& other);
		LinkedList(LinkedList&& other) noexcept;
		LinkedList& operator=(const LinkedList& other);
		LinkedList& operator=(LinkedList&& other) noexcept;



		void addFirst(const T& data);
		T removeFirst();
		void addLast(const T& data);
		T removeLast();
		T remove(u32 index);

		//T get(u32 index) const;
		Node<T>* getHead() const;
		Node<T>* getTail() const;
		void setHead(Node<T>* node);
		void setTail(Node<T>* node);
		//void addAll(const LinkedList<T>& list);
		//LinkedList<T> subList(u32 start, u32 end) const;
		bool isEmpty() const { return size_ == 0; };
		u32 getSize() const { return size_; };
		void clear();
		//friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
	};

}