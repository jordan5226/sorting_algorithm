/*
Insertion Sort
*/

#include <iostream>
#include <windows.h>
using namespace std;
#define LENGTH_ARR 10

template <typename T>
void PrintArr(T* arr, int length)
{
	for(int i=0;i<length;i++)
		cout<<arr[i]<<" ";
}

template <typename T>
void InsertionSort(T* arr, int length)
{
	int lastSortedIdx=0; // mark first element as sorted
	int extractedElement=-1;
	int currentSortedIdx=0;
	for(int unsortedIdx=lastSortedIdx+1 ; unsortedIdx < length ; unsortedIdx++, lastSortedIdx++) // for each unsorted element
	{
		extractedElement=arr[unsortedIdx]; // 'extract' the element
		for(currentSortedIdx=lastSortedIdx;
				currentSortedIdx>=0 ;currentSortedIdx--) // for i = lastSortedIndex to 0
		{
			if(arr[currentSortedIdx] > extractedElement) // if currentSortedElement > extractedElement
			// (this condition can move to for loop condition, and else is not nessecary)
				arr[currentSortedIdx+1]=arr[currentSortedIdx]; // move sorted element to the right by 1
			else
				break;
		}
		arr[currentSortedIdx+1]=extractedElement; // else: insert extracted element
		printf("Step %d: ", unsortedIdx);
		PrintArr(arr, LENGTH_ARR);
		printf("\n");
	}
}

int main()
{
	int arr[LENGTH_ARR]={3,8,26,15,42,26,51,21,39,35};
	
	printf("Before: ");
	PrintArr(arr, LENGTH_ARR);
	printf("\n");
	time_t start=clock();
	InsertionSort(arr, LENGTH_ARR);
	time_t end=clock();
	printf("Final: ");
	PrintArr(arr, LENGTH_ARR);
	printf("\n");
	printf("Times: %dms\n", end-start);
	
	system("pause");
	return 0;
}
