#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[(low+high)/2];

    while(low<=high) {
        while(a[low]<pivot) {
            low++;
        }
        while(a[high]>pivot) {
            high--;
        }
        if(low<=high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
            low++;
            high--;
        }
    }
    return low;
}

void quick_Sort(int a[], int low, int high) {
    int pi = partition(a, low, high);

    if(low<pi-1) {
        quick_Sort(a, low, pi-1);
    }
    if(pi<high) {
        quick_Sort(a, pi, high);
    }
}


int removeDuplicates(int arr[], int n){
    if (n==0 || n==1) {
        return n;
    }
    int j = 0;

    for (int i=0; i < n-1; i++) {
        if (arr[i] != arr[i+1])arr[j++] = arr[i];
    }

    arr[j++] = arr[n-1];

    return j;
}

int MCM(int n, int p[]) {
    int m[n][n]={0};
    int s[n][n]={0};
    int j,min,q;
    for(int d=1; d<n-1; d++) {
        for(int i=1; i<n-d; i++) {
            j=i+d;
            min=INT_MAX;
            for(int k=1; k<=j-1; k++) {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min) {
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    return m[1][n-1];
}

int main () {
    while(1) {
        int num,x;
        cin >> num;
        int n=2*num;
        int data[n];
        for(int i=0; i<n; i++) {
            cin >> x;
            data[i]=x;
        }
        quick_Sort(data,0,n-1);
        n=removeDuplicates(data,n);
        cout << endl;
        cout << MCM(n,data);
        cout << endl;
    }
    return 0;
}

