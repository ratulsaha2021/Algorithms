#include <bits/stdc++.h>
using namespace std;

int upper_Binary_Search(int A[], int S, int low, int high) {
    int middle = (low+high)/2;
    int num=high;
    int i, temp=1;

    while(low<=high) {
        if(A[middle]==S) {
            for(i=0; i<num-middle; i++) {
                if(A[middle+i]==A[middle+i+1]) {
                    temp=i+1;
                }
            }
            return middle+temp;
            break;
        }
        else if(A[middle]<S) {
            low = middle+1;
        }
        else if(A[middle]>S) {
            high = middle-1;
        }
        middle = (low+high)/2;
    }
    if(low>high) {
        int j, tempp;
        for(j=0; j<num; j++) {
            if(A[low]==A[low+j]) {
                tempp=j;
            }
        }
        return low+tempp;
    }

}


int lower_Binary_Search(int A[], int S, int low, int high) {
    int middle = (low+high)/2;
    int i, temp;

    while(low<=high) {
        if(A[middle]==S) {
            for(i=0; i<middle; i++) {
                if(A[middle]==A[middle-i]) {
                    temp=i;
                }
            }
            return middle-temp;
            break;
        }
        else if(A[middle]<S) {
            low = middle+1;
        }
        else if(A[middle]>S) {
            high = middle-1;
        }
        middle = (low+high)/2;
    }
    if(low>high) {
        int j, tempp;
        for(j=1; j<low; j++) {
            if(A[low-1]==A[low-j]) {
                tempp=j;
            }
        }
        return low-tempp;
    }
}


void upper_Bound(int A[], int S, int N) {
    int x = upper_Binary_Search(A, S, 0, N-1);
    cout << x << " ";
}

void lower_Bound(int A[], int S, int N) {
    int y = lower_Binary_Search(A, S, 0, N-1);
    cout << y << " ";
}


int main() {
    int N,S;
    cin >> N;
    cin >> S;
    cout << endl;
    int A[N];

    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    cout << endl;
    upper_Bound(A, S, N);
    lower_Bound(A, S, N);
}
