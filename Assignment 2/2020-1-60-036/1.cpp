#include<bits/stdc++.h>
using namespace std;

void Merge(float *a, int low, int high, int mid)
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


void MergeSort(float *a, int low, int high)
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

void prev_pos(float arr[], int n, int index)
{
    int i;
    float temp, temp1;
    float x[n];
    for(i=0; i<n; i++)
    {
        temp=arr[i];
        x[i]=temp;
    }
        temp1 = x[index];
    MergeSort(arr, 0, n-1);
    for(i=0; i<n; i++)
    {
        if(temp1==arr[i])
        {
            cout << i;
        }
    }
}
int main()
{
	int n, i,index;
	cout<<"\nEnter the number of element: ";
	cin>>n;

	float arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);

	cout<<"\nSorted Data: ";
	for (i = 0; i < n; i++)
    cout<<" "<<arr[i];
    cout<< "\nGive the Index: ";
    cin>> index;
    prev_pos(arr,n,index);

}
