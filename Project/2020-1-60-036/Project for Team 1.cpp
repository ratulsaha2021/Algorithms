#include <bits/stdc++.h>
using namespace std;
void maxSumInterval(int sizeofArray, vector<int> array)
{

    int max_sum = array[0]; //stores maximum sum contiguous sum
    int curr_sum = array[0]; //stores current maximum sum ending here

    for (int i = 1; i < sizeofArray; i++)//iterates over the array and add the value of the current element to curr_sum and check
    {
        if((curr_sum + array[i]) > array[i])
        {

            curr_sum = curr_sum + array[i]; // if array element is smaller than sum the of array element and curr_sum, update curr_sum
        }
        else
        {
            curr_sum = array[i]; // if array element is greater than the sum of array element and currentSum, updates currentSum
        }
        if( curr_sum > max_sum)
        {
            max_sum = curr_sum; //if sum is greater than max_sum, updates max_sum equals to curr_sum
        }

    }
    cout<<max_sum; //prints the value of maximum sum
}


int main()
{
    int sizeofArray; //takes input of the size of the array given by the user
    cin>>sizeofArray;

    if(sizeofArray == 0) //checks if the array is empty
    {
        cout<<"Invalid \n";
    }
    else
    {
        vector<int> arr;
        int element;
        for(int i = 0; i<sizeofArray; i++)
        {
            cin>>element;
            arr.push_back(element);//takes inputs of the array elements
        }

        cout<<endl;
        maxSumInterval(sizeofArray, arr);//calls the function to print maximum sub-array sum
        cout<<endl;
    }
    return 0;
}

