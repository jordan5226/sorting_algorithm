/*
Selection Sort
*/

#include <iostream>
using namespace std;
#define NUM_ARR 10
#define SWAP(x,y) {int tmp; tmp=x; x=y; y=tmp;} // �洫��Ƽg�k3

// �洫��Ƽg�k1 
void Swap(int *a, int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

/*
// �洫��Ƽg�k2
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
    cout<<"         �� �� �� �� �k"<<endl;
    cout<<"================================"<<endl;
    cout<<"�Ƨǫe�}�C:"<<endl;
    Print_Array(arr);
    cout<<"================================"<<endl;
    cout<<"�}�l�Ƨ�:"<<endl;
    // �Ѥj�ƨ�p
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
            Swap(&arr[i], &arr[max_index]); //�D�ʶǧ}: �洫���1  �Υi�g�� Swap(arr+i, arr+max_index);
            //Swap(arr[i], arr[max_index]); //�ǰѦ�: �洫���2  �Υi�g�� Swap(*(arr+i), *(arr+max_index));
            //SWAP(arr[i], arr[max_index]); // define��� 
        }
        Print_Array(arr);
    }
    time_t end=clock();
    printf("Times: %dms\n", end-start);
    system("pause");
    return 0;
}

