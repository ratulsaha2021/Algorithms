#include <bits/stdc++.h>
using namespace std;

struct Act
{
    int start, finish;
};

struct Temp
{
    int temp1, temp2;
};

int divide(Act arr[], int low, int high)
{
    Temp t;
    int pivot = arr[(low+high)/2].finish;

    while(low<=high)
        {
        while(arr[low].finish<pivot)
        {
            low++;
        }
        while(arr[high].finish>pivot)
        {
            high--;
        }
        if(low<=high)
        {
            t.temp2 = arr[low].finish;
            t.temp1 = arr[low].start;
            arr[low].finish = arr[high].finish;
            arr[low].start = arr[high].start;
            arr[high].finish = t.temp2;
            arr[high].start = t.temp1;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(Act arr[], int low, int high)
{
    int m = divide(arr, low, high);

    if(low<m-1)
    {
        quick_Sort(arr, low, m-1);
    }
    if(m<high)
    {
        quick_Sort(arr, m, high);
    }
}

void max(Act arr[], int N)
{
    int i,j,count;

    i=0;
    count=1;
    for (j=1; j<N; j++)
    {
      if (arr[j].start>arr[i].finish)
      {
        count++;
        i=j;
      }
    }
    cout << count;

}

int main()
{
    int N,i,j;
        cin >> N;
        Act arr[N];

        for(i=0; i<N; i++)
        {
            j=i;
            cin >> arr[i].start;
            cin >> arr[j].finish;
        }

        quick_Sort(arr, 0, N-1);
        max(arr, N);

}
