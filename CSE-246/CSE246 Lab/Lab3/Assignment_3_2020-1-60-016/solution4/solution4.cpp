#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void LCS( char *M, char *N, int i, int j) {
    int x,y;
    int arr[i+1][j+1];

    for (x=0; x<=i; x++) {
        for (int y=0; y<=j; y++) {
            if (x==0||y==0) {
                arr[x][y]=0;
            }
            else if (M[x-1]==N[y-1]) {
                arr[x][y]=arr[x-1][y-1]+1;
            }
            else {
                arr[x][y]=max(arr[x-1][y],arr[x][y-1]);
            }
        }
    }

    int count=0;
    int index=arr[i][j];
    char LCS[index+1];
    LCS[index]='\0';

    int p=i;
    int q=j;

    while (p>0 && q>0) {
        if (M[p-1] == N[q-1]) {
        LCS[index-1]=M[p-1];
        p--;
        q--;
        index--;
        count++;
        }
        else if (arr[p-1][q]>arr[p][q-1]) {
        p--;
        }
        else {
        q--;
        }
    }
    cout << count;
    cout << endl;
    cout << LCS;
    cout << endl;
    cout << endl;
}

int main(){
    int i,j;
    char M[40];
    char N[40];

    while(1) {
        cin >> M;
        cin >> N;

        i = strlen(M);
        j = strlen(N);

        LCS(M, N, i, j);
    }
    return 0;
}
