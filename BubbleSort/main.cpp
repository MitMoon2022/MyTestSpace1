#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

 
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {                                       //swap is a built-in function in the C++ Standard Template Library (STL)
           swap(arr[j], arr[j+1]);              //temp = a;
           swapped = true;                      //a = b; //b = temp;                                       
        }
     }
 
     // IF no two elements were swapped
     // by inner loop, then break
     if (swapped == false)
        break;
   }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< arr[i];
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int N = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, N);
    cout <<"Sorted array: \n";
    printArray(arr, N);
    cout<<endl;
    //--------------------------------------
   vector<int> num {3,2,1};

   for(int i = 0; i < num.size(); ++i)
   {
      int temp = 0;
      //cout<<i<<"-"<<num[i]<<endl;
      for(int j = 0; j < num.size()-1; ++j)
      {
         if (num[j] > num[j+1])
         { 
            cout<<"Swap!"<<endl;
            temp = num[j];
            cout<<"temp is "<<temp<<endl;
            num[j] = num[j+1];
            num[j+1] = temp;
         }
      }
   }
   //---- checking ----------------
   for(int i = 0; i < num.size(); ++i)
   {
      cout<<i<<"-"<<num[i]<<endl;
   }

    return 0;
}