#include <bits/stdc++.h>
using namespace std;


void upper_Bound(int A[], int S, int low, int high, int N) {
    int middle = (low+high)/2;

    while(low<=high) {
        if(A[middle]==S) {
            int i,temp;
            if(A[middle]==A[middle+1]) {
                for(i=middle; i<N; i++) {
                    if(A[i]==A[middle]) {
                        temp=i;
                    }
                }
                cout << temp << " ";
            }
            else {
                cout << middle+1 << " ";
            }
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
        int i,temp;
        if(A[low]==A[low+1]) {
            for(i=low; i<N; i++) {
                if(A[i]==A[low]) {
                    temp=i;
                }
            }
            cout << temp << " ";
        }
        else {
            cout << low << " ";
        }
    }
}



void lower_Bound(int A[], int S, int low, int high) {
    int middle = (low+high)/2;

    while(low<=high) {
        if(A[middle]==S) {
            int i;
            if(A[middle]==A[middle-1]) {
                for(i=0; i<high; i++) {
                    if(A[i]==A[middle]) {
                        cout << i << " ";
                        i=middle;
                    }
                }
            }
            else {
                cout << middle << " ";
            }
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
        int i;
        if(A[high]==A[high-1]) {
            for(i=0; i<high; i++) {
                if(A[i]==A[high]) {
                    cout << i << " ";
                    i=high;
                }
            }
        }
        else {
            cout << high << " ";
        }
    }
}


int main() {
    int N,S;
    cin >> N;
    cin >> S;
    int A[N];

    for(int i = 0; i<N; i++) {
        cin >> A[i];
    }
    cout << endl;
    upper_Bound(A, S, 0, N-1, N);
    lower_Bound(A, S, 0, N-1);
}
