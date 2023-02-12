#include <bits/stdc++.h>
using namespace std;

int partition(double a[], int low, int high) {
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

void quick_Sort(double a[], int low, int high) {
    int pi = partition(a, low, high);

    if(low<pi-1) {
        quick_Sort(a, low, pi-1);
    }
    if(pi<high) {
        quick_Sort(a, pi, high);
    }
}

void find_Key(double a[], int size, int index) {
    int i;
    double temp, temp2;
    double x[size];
    for(i=0; i<size; i++) {
        temp=a[i];
        x[i]=temp;
    }
    temp2=x[index];
    quick_Sort(a, 0, size-1);
    for(i=0; i<size; i++) {
        if(temp2==a[i]) {
            cout << endl;
            cout << endl;
            cout << i;
        }
    }
}

int main() {
    int item;
    cin >> item;
    double a[item];

    for(int i = 0; i<item; i++) {
        cin >> a[i];
    }
    int index;
    cin >> index;
    int n = sizeof(a)/sizeof(a[0]);
    find_Key(a, n, index);

    return 0;
}

