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


void display_Array(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void min_Difference(int a[], int size) {
    int i,j=0,temp;
    int x[size-1];
    for(i=0; i<size; i++) {
        j++;
        temp=a[i]-a[j];
        x[i]=-temp;
    }
    int n = sizeof(x)/sizeof(x[0]);
    quick_Sort(x, 0, n-1);
    cout << x[0];
}

int main() {
    int item;
    cin >> item;
    int a[item];

    for(int i = 0; i<item; i++) {
        cin >> a[i];
    }
    int n = sizeof(a)/sizeof(a[0]);
    quick_Sort(a, 0, n-1);
    cout << endl;
    cout << endl;
    min_Difference(a, n);

    return 0;
}

