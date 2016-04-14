/*
Selection Sort
*/

#include <iostream>
using namespace std;
#define NUM_ARR 10
#define SWAP(x,y) {int tmp; tmp=x; x=y; y=tmp;} // ユ传ㄧ计糶猭3

// ユ传ㄧ计糶猭1 
void Swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

/*
// ユ传ㄧ计糶猭2
void Swap(int &a, int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
*/

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
    int arr[NUM_ARR]={3,8,26,15,42,17,51,21,39,35};
    int i=0,j=0,max_index=0;
    cout<<"================================"<<endl;
    cout<<"         Selection Sort"<<endl;
    cout<<"         匡 拒 逼  猭"<<endl;
    cout<<"================================"<<endl;
    cout<<"逼玡皚:"<<endl;
    Print_Array(arr);
    cout<<"================================"<<endl;
    cout<<"秨﹍逼:"<<endl;
    // パ逼
    time_t start=clock();
    for(i=0;i<NUM_ARR-1;i++)
    {
        max_index=i;
        for(j=i+1;j<NUM_ARR;j++)
        {
            if(arr[j]>arr[max_index])
            {
                max_index=j;
            }
        }
        if(max_index!=i)
        {
            Swap(&arr[i], &arr[max_index]); //笆肚: ユ传ㄧ计1  ┪糶Θ Swap(arr+i, arr+max_index);
            //Swap(arr[i], arr[max_index]); //肚把σ: ユ传ㄧ计2  ┪糶Θ Swap(*(arr+i), *(arr+max_index));
            //SWAP(arr[i], arr[max_index]); // defineㄧ计 
        }
        Print_Array(arr);
    }
    time_t end=clock();
    printf("Times: %dms\n", end-start);
    system("pause");
    return 0;
}

