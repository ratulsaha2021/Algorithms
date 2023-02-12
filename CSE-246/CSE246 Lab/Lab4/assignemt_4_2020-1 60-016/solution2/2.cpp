#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        int M,N;
        cin >> M;
        cin >> N;
        int cell[M][N];
        int i,j;

        for(i=0; i<M; i++) {
            for(j=0; j<N; j++) {
                cin >> cell[i][j];
            }
        }

        int x,y,min;
        x=M+1;
        y=N+2;
        int temp[x][y];

        for(i=0; i<x; i++) {
            for(j=0; j<1; j++) {
                temp[i][j]=INT_MAX;
            }
        }

        for(i=0; i<x; i++) {
            for(j=y-1; j<y; j++) {
                temp[i][j]=INT_MAX;
            }
        }

        for(i=0; i<1; i++) {
            for(j=1; j<y-1; j++) {
                temp[i][j]=0;
            }
        }

        for(i=1; i<x; i++) {
            for(j=1; j<y-1; j++) {
                if(temp[i-1][j-1] <= temp[i-1][j] && temp[i-1][j-1]<=temp[i-1][j+1]) {
                    min=temp[i-1][j-1];
                }
                else if(temp[i-1][j] <= temp[i-1][j-1] && temp[i-1][j]<=temp[i-1][j+1]) {
                    min=temp[i-1][j];
                }
                else {
                    min=temp[i-1][j+1];
                }
                temp[i][j]=cell[i-1][j-1]+min;
            }
        }

        int z = INT_MAX;

        for(i=x-1;i<x;i++) {
            for(j=1;j<y-1;j++) {
                if(z>temp[i][j]) {
                    z=temp[i][j];
                }
            }
        }

        cout << endl;
        cout << z;
        cout << endl;
        cout << endl;
        cout << endl;
    }
}
