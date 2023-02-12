#include <bits/stdc++.h>
using namespace std;

struct Element {
    int val, w;
};

struct Car {
    int car1, car2;
};

int divide(Element item[], int m[], int low, int high)
{
    Car c;
    int temp;
    int pivot = m[(low+high)/2];

    while(low<=high)
        {
        while(m[low]>pivot)
        {
            low++;
        }
        while(m[high]<pivot)
        {
            high--;
        }
        if(low<=high)
        {
            temp = m[low];
            c.car1 = item[low].val;
            c.car2 = item[low].w;
            m[low] = m[high];
            item[low].val = item[high].val;
            item[low].w = item[high].w;
            m[high] = temp;
            item[high].val = c.car1;
            item[high].w = c.car2;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(Element item[], int m[], int low, int high)
{
    int mid = divide(item, m, low, high);

    if(low<mid-1)
    {
        quick_Sort(item, m, low, mid-1);
    }
    if(mid<high)
    {
        quick_Sort(item, m, mid, high);
    }
}

int main() {
    int N,i,j;
    double W,car_w=0,car_val=0;


        cin >> N;
        cin >> W;
        int m[N];
        Element item[N];

        for(i=0; i<N; i++)
        {
            cin >> m[i];
        }

        for(i=0; i<N; i++)
        {
            cin >> item[i].w;
            item[i].val = m[i]*item[i].w;
        }

        quick_Sort(item, m, 0, N-1);

        for(i=0; i<N-1; i++)
        {
            if(W>item[i].w)
            {
                car_w = car_w+item[i].w;
                W = W-item[i].w;
                car_val = car_val+item[i].val;
            }
            else
            {
                car_w = car_w+W;
                car_val = car_val+m[i]*W;
                i=N;
            }
        }
        cout <<car_val;

    return 0;
}
