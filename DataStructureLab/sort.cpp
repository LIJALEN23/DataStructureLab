#include "sort.hpp"
#include "term.hpp"

namespace sort
{
	template<typename T>
	void swap(T* arr, u32 first_index, u32 second_index)
	{
		T temp = *(arr + first_index);
		*(arr + first_index) = *(arr + second_index);
		*(arr + second_index) = temp;
	}

	template<typename T>
	void bubbleSort(T* arr, u32 size)
	{
		bool swap_flag = false;

		for (u32 i = 0; i < size; i++)
		{
			for (u32 j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr, j, j + 1);
					swap_flag = true;
				}
			}

			if (!swap_flag)
			{
				return;
			}
		}
	}

	template<typename T>
	void mergeSort(T* arr, u32 size)
	{
	}

	template<typename T>
	void selectSort(T* arr, u32 size)
	{
	}

	template<typename T>
	void shellSort(T* arr, u32 size)
	{
	}

	template<typename T>
	void quickSort(T* arr, u32 size)
	{
	}

	template<typename T>
	void insertSort(T* arr, u32 size)
	{
	}


	template void sort::swap<u32>(u32*, u32, u32);
	template void sort::swap<lab01::Term>(lab01::Term*, u32, u32);


	template void sort::bubbleSort<u32>(u32*, u32);
	template void sort::bubbleSort<lab01::Term>(lab01::Term*, u32);
}