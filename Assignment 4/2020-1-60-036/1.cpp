#include <iostream>
using namespace std;

int main()
{
  int T, i,j, count=0;
  cin >> T;
  long long int t[T];

  for(i=0;i<T;i++)
  {
      cin>>t[i];
  }
    for(i=0;i<T;i++)
    {
      count =0;
    for(j=2;j<=t[i];j++)
    {
        if(t[i] % j == 0)
      {
          count++;
      }
    }

        if (count==1)
        {
            cout << "Prime.\n";
        }
  else
  {
     cout<<"Not Prime";
  }
}


  return 0;
}


