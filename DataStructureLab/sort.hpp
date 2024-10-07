#pragma once
#include "myint.hpp"

namespace sort
{
	template<typename T>
	void swap(T* arr, u32 first_index, u32 second_index);

	template<typename T>
	void bubbleSort(T* arr, u32 size);
	
	template<typename T>
	void mergeSort(T* arr, u32 size);

	template<typename T>
	void selectSort(T* arr, u32 size);
	
	template<typename T>
	void shellSort(T* arr, u32 size);

	template<typename T>
	void quickSort(T* arr, u32 size);

	template<typename T>
	void insertSort(T* arr, u32 size);
}