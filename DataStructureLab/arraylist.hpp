#include "myint.hpp"

namespace arraylist
{
	const u32 DEFAULT_CAPACIY = 10;

	template <typename T>
	class ArrayList
	{
	public :
		ArrayList();
		~ArrayList() { delete[] data_; }

		void addFirst(const T& data);
		T removeFirst();
		void addLast(const T& data);
		T removeLast();
		T get(u32 index) const;
		u32 size() const;



	private:
		T* data_;
		u32 capacity;
		u32 size;
	};
}