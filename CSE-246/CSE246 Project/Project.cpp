#include <bits/stdc++.h>
using namespace std;
void maxSubArraySum(int arraySize, vector<int> array)
{

    int max_sum = array[0]; //O(1) memory to store maximum sub array interval, O(1) time for assignment.
    int curr_sum = array[0]; //O(1) memory to store current maximum sum ending here, O(1) time for assignment.

    for (int i = 1; i < arraySize; i++) //O(n) to loop through each element in array
    {
        if((curr_sum + array[i]) > array[i]) //O(1) to compare.
        {

            curr_sum = curr_sum + array[i]; //O(1) to assign new value
        }
        else //O(1) to compare.
        {
            curr_sum = array[i]; //O(1) to assign new value
        }
        if( curr_sum > max_sum)//O(1) to compare.
        {
            max_sum = curr_sum; //O(1) to assign new value
        }

    }
    cout<<max_sum; //O(1) time to print the final result
}


int main()
{
    int arraySize; //O(1) memory to define number of elements in the array
    cin>>arraySize;

    if(arraySize == 0) //O(1) time to compare.
    {
        cout<<"Invalid \n"; //O(1) time to print
    }
    else //O(1) time to compare.
    {
        vector<int> arr; //O(1) memory to define number of elements in the array
        int element;
        for(int i = 0; i<arraySize; i++) //O(n) to loop through take user inputs of the array elements
        {
            cin>>element;
            arr.push_back(element);
        }

        cout<<endl;//O(1) time to print a new line
        maxSubArraySum(arraySize, arr);
        cout<<endl; //O(1) time to print a new line
    }
    return 0;
}
