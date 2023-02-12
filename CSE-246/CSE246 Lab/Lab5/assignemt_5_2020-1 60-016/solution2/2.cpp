#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void occurrences(char T[], char P[], int M) {
    int x=strlen(P), y=strlen(T);
    int i,j,p=0,t=0,b=2,h=1;

    for(i=0; i<x-1; i++) {
        h=(h*b)%M;
    }

    for(i=0; i<x; i++){
        p=(b*p+P[i])%M;
        t=(b*t+T[i])%M;
    }

    for(i=0; i<=y-x; i++){
        if(p==t){
            for(j=0; j<x; j++){
                if (T[i+j]!=P[j])
                break;
            }
            if (j==x) {
                cout << i << " ";
                cout << i+x-1 << " ";
                cout << endl;
            }
        }
        if (i<y-x){
            t=(b*(t-T[i]*h)+T[i+x])%M;
            if (t<0) {
                t=(t+M);
            }
        }
    }
}

int main() {
    while (1) {
        int min = 7;
        char T[1000000], P[1000];
        cin >> T;
        cin >> P;
        cout << endl;

        occurrences(T,P,min);
        cout << endl;
        cout << endl;
    }
}

