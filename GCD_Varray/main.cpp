#include <iostream>
#include <vector>
#include <algorithm>    //required when using sort()
//#include <bits/stdc++.h>
using namespace std;

/* 
The GCD of three or more numbers equals the product of the prime factors common to all the numbers, but it can also be calculated by repeatedly taking the GCDs of pairs of numbers. 
 

gcd(a, b, c) = gcd(a, gcd(b, c)) 
             = gcd(gcd(a, b), c) 
             = gcd(gcd(a, c), b)
For an array of elements, we do the following. We will also check for the result if the result at any step becomes 1 we will just return the 1 as gcd(1,x)=1. 
 

result = arr[0]
For i = 1 to n-1
   result = GCD(result, arr[i]) 
*/

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function to find gcd of array of numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

// Function to find gcd using vector
int find_GCD(vector<int>& num)
{
    cout << "Initial Vector: ";

  for (const int& j : num) {
    cout << j << "  ";
  }

cout<<endl;
//---------------------------------    
 // sort(num.begin(), num.end());
  
//      cout << "Sorted \n";
//      for (auto x : num)
//          cout << x << " ";
//      cout<<endl;

//---------Working solution------------------------
    int result = num[0];
    for (long long unsigned int i = 1; i < num.size(); i++)
    {
        // if(result<num[i])
        // {
        //     result = gcd(num[i], result);
        // }else
        //     result = gcd(result, num[i]);
            
         result = gcd(num[i], result);    //original one!
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

// Driver code
int main()
{
    //int arr[] = { 2, 4, 6, 8, 16 };
    //vector<int> num = {10, 20, 15, 35, 65};
    vector<int> num {10,20,15,30}; 
    //vector<int> num {2,3,5};                              //{12, 4, 6, 8, 16};
    int ans = 0;
    //cout<< num[0].size();
    //cout<< sizeof(arr)<<endl;

    //cout<< sizeof(arr[0]) <<endl;
    //int n = sizeof(arr) / sizeof(arr[0]);

    //int n = num.size() / num[0].size();                                            //int n = sizeof(arr) / sizeof(arr[0]);
    
    //cout << findGCD(arr, n) << endl;
    ans = find_GCD(num);
    cout <<"The ans is :"<<ans <<endl;

    return 0;
}