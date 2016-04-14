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
 *  �H�Y�`�I���ڶi���n��(heapify) 
 *  T *arr : ���i��heapify���}�C 
 *  int cmpNode : ���i��heapify���ڸ`�I���� 
 *  int len : heap tree�j�p 
 *  bool (*compare)(T a, T b) : ����j�p����ƫ��w�A�ΨӨM�w����n��Max Heap��Min Heap 
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
	}while(((cmpNode*2)+1) < len); // �Y���l�`�I�h�~��heapify 
}


/*  
 *  �غc��n�� 
 *  T *arr : ���i��heapify���}�C 
 *  int len : heap tree�j�p 
 *  bool (*compare)(T a, T b) : ����j�p����ƫ��w�A�ΨӨM�w����n��Max Heap��Min Heap 
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
 *  �Ƨǰ�n�� 
 *  T *arr : ���i��ƧǪ��}�C 
 *  int len : heap tree�j�p
 *  bool (*Compare)(int a, int b) : ����j�p����ƫ��w�A�ΨӨM�w����n��Max Heap��Min Heap 
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
        cout<<"         �� �n �� �� �k"<<endl;
        cout<<"================================"<<endl;
        cout<<"�Ƨǫe�}�C:"<<endl;
        printArray(arr);
        cout<<"================================"<<endl;
        cout<<"�п��Heap Type:"<<endl;
        cout<<"1) Max Heap"<<endl;
        cout<<"2) Min Heap"<<endl;
        cout<<"3) Exit Program"<<endl;
        cin>>in;
        
        switch(in)
        {
		case '1':
			cout<<"�إ�Max Heap (Heapify)"<<endl;
			start=clock();
			buildHeapTree(arr, ARR_LEN, ascending);
			printArray(arr); // �L�Xheapify�᪺array
			cout<<"�}�l�Ƨ�"<<endl;
			heapSort(arr, ARR_LEN, ascending);
			break;
		case '2':
			cout<<"�إ�Min Heap (Heapify)"<<endl;
			start=clock();
			buildHeapTree(arr, ARR_LEN, descending);
			printArray(arr); // �L�Xheapify�᪺array
			cout<<"�}�l�Ƨ�"<<endl;
			heapSort(arr, ARR_LEN, descending);
			break;
		case '3':
			return 0;
		default:
			system("cls");
			continue;
		}
		end=clock();
		cout<<"�Ƨǵ��G"<<endl;
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
