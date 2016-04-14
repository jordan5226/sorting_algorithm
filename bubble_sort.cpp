/*
Bubble Sort
*/

#include <iostream>
#include <time.h>
using namespace std;
#define NUM_ARR 10
#define SWAP(x,y) {int tmp; tmp=x; x=y; y=tmp;}

void Print_Array(int *arr)
{
    cout<<"Array: ";
    for(int i=0;i<NUM_ARR;i++)
    {
        printf("%2d ",arr[i]);
    }
    cout<<endl;
}

int main()
{
    int arr[NUM_ARR]={3,8,26,15,42,26,51,21,39,35};
    int i=0,j=0;
    bool isSwapped=false;
    
    cout<<"================================"<<endl;
    cout<<"         Bubble Sort"<<endl;
    cout<<"         泡 沫 排 序 法"<<endl;
    cout<<"================================"<<endl;
    cout<<"排序前陣列:"<<endl;
    Print_Array(arr);
    cout<<"================================"<<endl;
    cout<<"開始排序:"<<endl;
    // 由大排到小
    time_t start=clock();
    for(i=0;i<NUM_ARR-1;i++)
    {
		isSwapped=false;
        for(j=0;j<NUM_ARR-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                SWAP(arr[j], arr[j+1]);
                isSwapped=true;
            }
        }
        Print_Array(arr);
        if(!isSwapped)
        	break;
    }
    time_t end=clock();
    printf("Times: %dms\n", end-start);
    system("pause");
    return 0;
}

