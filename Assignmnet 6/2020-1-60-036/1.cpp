#include <bits/stdc++.h>
using namespace std;

int lIS(int arr[], int n)
{
    int lIS[n];

    lIS[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lIS[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lIS[i] < lIS[j] + 1)
            {
                lIS[i] = lIS[j] + 1;
            }

        }

    }

    return *max_element(lIS, lIS + n);
}

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<lIS(arr, n);

    return 0;
}
