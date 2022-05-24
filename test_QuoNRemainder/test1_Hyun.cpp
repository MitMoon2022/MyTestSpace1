#include <iostream>
#include <vector>

// n	result
// 2	3
// 3	12
// 4    30
// Example #1
// When n is 2,

// Both quotient and remainder are 1 when 3 is divided by 2.
// Return 3 because the remainder cannot exceed 2.

// Example #2
// When n is 3,

// Both quotient and remainder are 1 when 4 is divided by 3.
// Both quotient and remainder are 2 when 8 is divided by 3.
// Return 12, the sum of 4 and 8, because the remainder cannot exceed 3.



using namespace std;

 int solution (int n)
{
    int quo = 0;
    int rem = 0;
    int sum = 0;
    int count =0;   //use it to check the remainder cannot exceed n given.
    int ans = 0; 

    for(int i = 1 ; i < 50 ; i++)
    {
        quo = i / n;
        rem = i % n;
        cout<<" i = "<<i<<", quo = "<<quo<<", rem = "<<rem<<endl;

        if((i / n) == (i % n))
        {
            sum += i;
            cout<<"sum is = "<<sum<<endl;
            count++;
        }

        if (count == (n-1))  //rem cannot exceed n; (n-1)
        {
            ans = sum;
            cout<<"In For loop - ans is "<<ans<<endl;
            return ans;
        }

    }//end of for loop
     return ans;
}
//------------------------------------------------------------------




int main()
{

cout<<"Start Program.\n";

int n = 3;  //given natural number.
cout<<"n is : "<<n<<endl;
//int quo = 0;
//int rem = 0;
//int sum = 0;
//int count =0;   //use it to check the remainder cannot exceed n given.
int ans = 0; 

ans = solution(n);


cout<<"ans is "<<ans<<endl;


return 0;
}

