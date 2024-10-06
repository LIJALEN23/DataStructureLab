#include "hashmap.hpp"

namespace hashmap
{
	template<typename K, typename V>
	HashMap<K, V>::HashMap()
	{
		capacity_ = DEFAULT_CAPACITY;
		size_ = 0;
		//bucket_ = ArrayList<LinkedList<Pair<K, V>>>(DEFAULT_CAPACITY);
		//for (u32 i = 0; i < capacity_; i++)
		//{
		//	LinkedList<Pair<K, V>>& list = bucket_.get(i);
		//	list = LinkedList<Pair<K, V>>();
		//}
	}

	template<typename K, typename V>
	HashMap<K, V>::HashMap(u32 capacity)
	{
		capacity_ = capacity;
		size_ = 0;
		//bucket_ = ArrayList<LinkedList<Pair<K, V>>>(capacity);
		//for (u32 i = 0; i < capacity_; i++)
		//{
		//	LinkedList<Pair<K, V>>& list = bucket_.get(i);
		//	list = LinkedList<Pair<K, V>>();
		//}
	}

	template<typename K, typename V>
	HashMap<K, V>::~HashMap()
	{
		for (u32 i = 0; i < capacity_; i++)
		{
			LinkedList<Pair<K, V>>& list = bucket_.get(i);
			list.clear();
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
				
				if (current == list.getHead())
				{
					list.setHead(current->next_);
				}

				if (current == list.getTail())
				{
					list.setTail(current->pre_);
				}

				if (current->pre_ != nullptr)
				{
					current->pre_->next_ = current->next_;
				}
				if (current->next_ != nullptr)
				{
					current->next_->pre_ = current->pre_;
				}

				delete current;
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
		for (u32 i = 0; i < capacity_; i++)
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
		ArrayList<LinkedList<Pair<K, V>>> new_bucket(new_capacity);

		for (u32 i = 0; i < capacity_; i++)
		{
			LinkedList<Pair<K, V>>& list = bucket_.get(i);

			for (Node<Pair<K, V>>* current = list.getHead(); current != nullptr; current = current->next_)
			{
				Pair<K, V> pair = current->data_;
				u32 new_index = hash(pair.key_);
				auto& new_list = new_bucket.get(new_index);
				new_list.addLast(pair);
			}
		}

		bucket_ = new_bucket;
		capacity_ = new_capacity;

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