/*
Heap Sort
*/

#include <iostream>
#include <windows.h>
using namespace std;

#define ARR_LEN 10


template <class T>
void swapNode(T& a, T& b)
{
	T tmp(a);
	a=b;
	b=tmp;
}


template <class T>
bool ascending(T a, T b)
{
	if(a > b)
		return true;
	return false;
}


template <class T>
bool descending(T a, T b)
{
	if(a < b)
		return true;
	return false;
}

template <class T>
void printArray(T *arr)
{
	cout<<"Array: ";
	for(int i=0;i<ARR_LEN;++i)
	{
		printf("%2d ", arr[i]);
	}
	cout<<endl;
}


/*  
 *  以某節點為根進行堆積化(heapify) 
 *  T *arr : 欲進行heapify的陣列 
 *  int cmpNode : 欲進行heapify的根節點索引 
 *  int len : heap tree大小 
 *  bool (*compare)(T a, T b) : 比較大小之函數指針，用來決定此堆積樹為Max Heap或Min Heap 
 */
template <class T>
void heapifyRoot(T *arr, int cmpNode, int len, bool (*comp)(T, T))
{
	int root;
	do {
		root = cmpNode;
		for(int i=(root*2)+1;(i<len)&&(i<=(root*2)+2);++i)
		{
			if(comp(arr[i], arr[cmpNode]))
				cmpNode = i;
		}
		if(cmpNode != root)
			swapNode(arr[root], arr[cmpNode]);
		else
			break;
	}while(((cmpNode*2)+1) < len); // 若有子節點則繼續heapify 
}


/*  
 *  建構堆積樹 
 *  T *arr : 欲進行heapify的陣列 
 *  int len : heap tree大小 
 *  bool (*compare)(T a, T b) : 比較大小之函數指針，用來決定此堆積樹為Max Heap或Min Heap 
 */
template <class T>
void buildHeapTree(T *arr, int len, bool (*comp)(T, T))
{
	for(int i=(len/2)-1;i>=0;--i)
	{
		heapifyRoot(arr, i, len, comp);
	}
}


/*  
 *  排序堆積樹 
 *  T *arr : 欲進行排序的陣列 
 *  int len : heap tree大小
 *  bool (*Compare)(int a, int b) : 比較大小之函數指針，用來決定此堆積樹為Max Heap或Min Heap 
 */
template <class T>
void heapSort(T *arr, int len, bool (*comp)(T, T))
{
	while(len>1)
	{
		swapNode(arr[0], arr[len-1]);
		--len;
		heapifyRoot(arr, 0, len, comp);
	}
}


int main()
{
	int arr[]={3,8,26,15,42,26,51,21,39,35};
	char in;
	time_t start,end;
	
	while(1)
	{
		cout<<"================================"<<endl;
        cout<<"         Heap Sort"<<endl;
        cout<<"         堆 積 排 序 法"<<endl;
        cout<<"================================"<<endl;
        cout<<"排序前陣列:"<<endl;
        printArray(arr);
        cout<<"================================"<<endl;
        cout<<"請選擇Heap Type:"<<endl;
        cout<<"1) Max Heap"<<endl;
        cout<<"2) Min Heap"<<endl;
        cout<<"3) Exit Program"<<endl;
        cin>>in;
        
        switch(in)
        {
		case '1':
			cout<<"建立Max Heap (Heapify)"<<endl;
			start=clock();
			buildHeapTree(arr, ARR_LEN, ascending);
			printArray(arr); // 印出heapify後的array
			cout<<"開始排序"<<endl;
			heapSort(arr, ARR_LEN, ascending);
			break;
		case '2':
			cout<<"建立Min Heap (Heapify)"<<endl;
			start=clock();
			buildHeapTree(arr, ARR_LEN, descending);
			printArray(arr); // 印出heapify後的array
			cout<<"開始排序"<<endl;
			heapSort(arr, ARR_LEN, descending);
			break;
		case '3':
			return 0;
		default:
			system("cls");
			continue;
		}
		end=clock();
		cout<<"排序結果"<<endl;
		cout<<"Array: ";
		for(int i=ARR_LEN-1;i>=0;--i)
		{
			printf("%2d ", arr[i]);
		}
		cout<<endl;
		printf("Times: %dms\n", end-start);
		system("pause");
		system("cls");
	}
	
	return 0;
}
