#pragma once
#include "myint.hpp"
#include "pair.hpp"
#include "arraylist.hpp"
#include "linkedlist.hpp"

namespace hashmap
{
	using arraylist::ArrayList;
	using linkedlist::LinkedList;
	using linkedlist::Node;

	constexpr u32 DEFAULT_CAPACITY = 8;
	constexpr float LOAD_FACTOR = 0.75f;

	template<typename K, typename V>
	class HashMap
	{
	public:
		HashMap();
		HashMap(u32 capacity);
		~HashMap();

		HashMap(const HashMap& other);
		HashMap(HashMap&& other) noexcept;
		HashMap& operator=(const HashMap& other);
		HashMap& operator=(HashMap&& other) noexcept;


		void put(const K& key, const V& val);
		const V& get(const K& key) const;
		V& get(const K& key);
		V remove(const K& key);
		bool containsKey (const K& key) const;
		bool containsVal (const V& val) const;
		u32 size() const { return size_; };
		bool isEmpty() const { return size_ == 0; }
		Pair<K, V>* toArray() const;

	private:
		void resize(u32 new_capacity);
		//Ĭ��Ϊ����
		u32 hash(const K& key) const { return key % capacity_; }
		void ensureCapacity();

		ArrayList<LinkedList<Pair<K, V>>> bucket_;
		u32 capacity_;
		u32 size_;
	};
}