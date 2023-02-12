#include<bits/stdc++.h>
using namespace std;

void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}


	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
 int repeated_element(int arr[], int n)
 {
     int maxc=0;
     int temp = -1;
     for(int i=0; i<n-1; i++)
     {
         int c = 0;
         for(int j=1;j<n; j++)
         {
             if(arr[i] == arr[j])
                c++;
         }
         if(c>maxc)
         {
             maxc = c;
             temp =i;
         }
     }
     cout<< "\n"<< arr[temp];
 }

int main()
{
	int n, i;
	cout<<"\nEnter the number of element: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
	MergeSort(arr, 0, n-1);

	cout<<"\nSorted Data: ";
	for (i = 0; i < n; i++)
    {
        cout<<" "<<arr[i];
    }
    repeated_element(arr,n);
}
