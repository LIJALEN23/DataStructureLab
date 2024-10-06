#include "hashmap.hpp"

namespace hashmap
{
	template<typename K, typename V>
	HashMap<K, V>::HashMap()
	{
		capacity_ = DEFAULT_CAPACITY;
		size_ = 0;
		bucket_ = ArrayList<LinkedList<Pair<K, V>>>(DEFAULT_CAPACITY);
		for (u32 i = 0; i < capacity_; i++)
		{
			auto& list = bucket_.get(i);
			list = LinkedList<Pair<K, V>>();
		}
	}

	template<typename K, typename V>
	HashMap<K, V>::HashMap(u32 capacity)
	{
		capacity_ = capacity;
		size_ = 0;
		bucket_ = ArrayList<LinkedList<Pair<K, V>>>(capacity);
		for (u32 i = 0; i < capacity_; i++)
		{
			auto& list = bucket_.get(i);
			list = LinkedList<Pair<K, V>>();
		}
	}

	template<typename K, typename V>
	void HashMap<K, V>::put(const K& key, const V& val)
	{
		u32 index = hash(key);
		LinkedList<Pair<K, V>>& list = bucket_.get(index);
		for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
		{
			if (current->data_.key_ == key)
			{
				current->data_.val_ = val;
				return;
			}
		}
		list.addLast(Pair<K, V>(key, val));
		++size_;
		ensureCapacity();
	}

	template<typename K, typename V>
	V HashMap<K, V>::get(const K& key) const
	{
		u32 index = hash(key);
		const LinkedList<Pair<K, V>> list = bucket_.get(index);

		for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
		{
			if (current->data_.key_ == key)
			{
				return current->data_.val_;
			}
		}
		throw std::runtime_error("Key not found.");
	}

	template<typename K, typename V>
	V HashMap<K, V>::remove(const K& key)
	{
		u32 index = hash(key);
		auto& list = bucket_.get(index);
		Node<Pair<K, V>>* current = list.getHead();
		while (current != nullptr)
		{
			if (current->data_.key_ == key)
			{
				V val = current->data_.val_;
				(*current->pre_).next_ = current->next_;
				(*current->next_).pre_ = current->pre_;
				--size_;
				return val;
			}
			current = current->next_;
		}
		throw std::runtime_error("Key not found.");
	}

	template<typename K, typename V>
	bool HashMap<K, V>::containsVal(const V& val) const
	{
		for (u32 i = 0; i < bucket_.size(); ++i)
		{
			const LinkedList<Pair<K, V>>& list = bucket_.get(i);
			for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
			{
				if (current->data_.val_ == val)
				{
					return true;
				}
			}
		}
		return false;
	}

	template<typename K, typename V>
	bool HashMap<K, V>::containsKey(const K& key) const
	{
		u32 index = hash(key);
		const LinkedList<Pair<K, V>>& list = bucket_.get(index);
		for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
		{
			if (current->data_.key_ == key)
			{
				return true;
			}
		}
		return false;	
	}

	template<typename K, typename V>
	void HashMap<K, V>::resize(u32 new_capacity)
	{
		HashMap<K, V> new_map = HashMap(new_capacity);

		for (u32 i = 0; i < capacity_; i++)
		{
			LinkedList<Pair<K, V>>& list = bucket_.get(i);

			for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
			{
				Pair<K, V> pair = current->data_;
				new_map.put(pair.key_, pair.val_);
			}
		}

		bucket_ = new_map.bucket_;
		capacity_ = new_map.capacity_;
	}

	template<typename K, typename V>
	void HashMap<K, V>::ensureCapacity()
	{
		if ((float)(size_ / capacity_) >= LOAD_FACTOR)
		{
			resize(capacity_ * 2);
		}
	}

	template class hashmap::HashMap<u32, u32>;
	template struct hashmap::Pair<u32, u32>;
}