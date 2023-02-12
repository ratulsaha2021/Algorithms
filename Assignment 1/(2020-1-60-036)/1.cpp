#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int upper_Bound(int A[], int S, int lo, int hi)
{
    int mid = (lo+hi)/2;
    int n =hi,i, car=1;

    while(lo<=hi)
    {
        if(A[mid]==S)
        {
            for(i=0; i<n-mid; i++)
            {
                if(A[mid+i]==A[mid+i+1])
                {
                    car=i+1;
                }
            }
        return mid+car;
        break;
        }
        else if(A[mid]<S)
        {
            lo = mid+1;
        }
        else if(A[mid]>S)
        {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    if(lo>hi)
    {
        int j, c;
        for(j=0; j<n; j++)
         {
            if(A[lo]==A[lo+j])
            {
                c=j;
            }
        }
        return lo+c;
    }

}


int lower_Bound(int A[], int S, int lo, int hi)
 {
    int mid = (lo+hi)/2;
    int i,car;

    while(lo<=hi)
        {
        if(A[mid]==S)
         {
            for(i=0; i<mid; i++)
             {
                if(A[mid]==A[mid-i])
                {
                    car=i;
                }
             }
            return mid-car;
            break;
        }
        else if(A[mid]<S)
        {
            lo = mid+1;
        }
        else if(A[mid]>S)
        {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    if(lo>hi)
    {
        int j, c;
        for(j=1; j<lo; j++)
        {
            if(A[lo-1]==A[lo-j])
            {
                c=j;
            }
        }
        return lo-c;
    }
}


int up_Bound(int A[], int S, int N)
{
    int x = upper_Bound(A, S, 0, N-1);
    cout << x << " ";
}

int lo_Bound(int A[], int S, int N)
{
    int y = lower_Bound(A, S, 0, N-1);
    cout << y << " ";
}


int main()
{
    int N,S;
    cin >> N >> S;
    int A[N];
    for(int i = 0; i<N; i++)
    {
        cin >> A[i];
    }
    up_Bound(A, S, N);
    lo_Bound(A, S, N);
}
