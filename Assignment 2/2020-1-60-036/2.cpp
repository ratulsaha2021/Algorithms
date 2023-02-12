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

int findMinDiff(int arr[], int n)
{
int diff = INT_MAX;

for (int i=0; i<n-1; i++)
{
   for (int j=i+1; j<n; j++)
   {
       if (abs(arr[i] - arr[j]) < diff)
       {
           diff = abs(arr[i] - arr[j]);
       }

   }
}
return diff;
}

int main()
{
	int n, i;
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	MergeSort(arr, 0, n-1);
    cout <<findMinDiff(arr, n);
	return 0;
}
