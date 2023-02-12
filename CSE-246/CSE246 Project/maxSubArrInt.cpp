#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void maxSubArraySum( int arraySize, vector<int> array)
{

    int maximumSum = array[0];
    int currentSum = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        if((currentSum + array[i]) > array[i])
        {

            currentSum = currentSum + array[i]; // if array element is smaller than sum the of array element and currentSum, update currentSum equals to (current sum + that element )
        }
        else
        {
            currentSum = array[i]; // if array element is greater than the sum of array element and currentSum, updates currentSum equals to that element
        }
        if( currentSum > maximumSum)
        {
            maximumSum = currentSum; //sum is greater than maximumSum, updates maximumSum equals to currentSum
        }

    }
    cout<<maximumSum; //prints the value of maximumsum

}


int main()
{
    int arraySize; // takes input of the size of the array given by the user
    cin>>arraySize;

    if(arraySize == 0) //checks if the array is empty
    {
        cout<<"Invalid \n";
    }
    else
    {
        vector<int> arr;
        int element;
        for(int i = 0; i<arraySize; i++)
        {
            cin>>element;
            arr.push_back(element);//takes inputs of the array elements
        }

        cout<<endl;
        maxSubArraySum(arraySize, arr);//calls the function to print maximum sub-array sum
        cout<<endl;
    }
    return 0;
}
