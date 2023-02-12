#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void occurrences(char Patt[],char Pref[], int M)
{
    int x=strlen(Patt), y=strlen(Pref);
    int i,j,p=0,t=0,b=2,h=1;

    for(i=0; i<x-1; i++)
    {
        h=(h*b)%M;
    }

    for(i=0; i<x; i++)
    {
        p=(b*p+Patt[i])%M;
        t=(b*t+Pref[i])%M;
    }

    for(i=0; i<=y-x; i++)
    {
        if(p==t)
        {
            for(j=0; j<x; j++)
            {
                if (Pref[i+j]!=Patt[j])
                break;
            }
            if (j==x)
            {
                cout << i << " ";
                cout << i+x-1 << " ";
                cout << endl;
            }
        }
        if (i<y-x)
        {
            t=(b*(t-Pref[i]*h)+Pref[i+x])%M;
            if (t<0)
            {
                t=(t+M);
            }
        }
    }
}

int main()
{
        int min = 7;
        char Pref[1000000], Patt[1000];
        cin >> Pref;
        cin >> Patt;
        cout << endl;

        occurrences(Patt,Pref,min);

}

