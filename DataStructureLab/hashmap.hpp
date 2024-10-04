#pragma once
#include "myint.hpp"

namespace hashmap
{
	const u32 DEFAULT_CAPACITY = 8;

	template<typename K, typename V>
	class HashMap
	{
	public:
		HashMap();
		~HashMap() { delete[] data_; }
		void put(const K& key, const V& val);
		V get(const K& key) const;
		V remove(const K& key);
		bool containsKey (const K& key) const;
		bool constainsVal (const V& val) const;
		u32 size() const { return size_; };
		bool isEmpty() const { return size_ == 0; }

	private:
		V* data_;
		u32 capacity_;
		u32 size_;

		u32 hash(const K& key) const { return key() % capacity_; }
	};
}