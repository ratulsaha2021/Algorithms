#include <bits/stdc++.h>
using namespace std;

void Prefix(char* String, int m, int* pi)
{
	int j = 0;

	pi[0] = 0;


	int i = 1;
	while (i < m) {
		if (String[i] == String[j]) {
			j++;
			pi[i] = j;
			i++;
		}
		else
		{

			if (j != 0) {
				j = pi[j - 1];


            }
			else
			{
				pi[i] = 0;
				i++;
			}
		}
	}


	for (i =0;i<m;i++)
    {
        cout<<pi[i]<<" ";

    }
}


int main()
{

	char String[100000];

    gets(String);

	int m = strlen(String);
	int pi[m];
	Prefix(String, m, pi);

    return 0;
}
