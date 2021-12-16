#include <iostream>
using namespace std;


void OnAbortReelCommand()
{
    bool bPwdForAbortReel = true;
    bool m_UserAccountService =true;

    cout<<"InAbortReel-1"<<endl;

    if (bPwdForAbortReel)
    {
        cout<<"in if - 1"<<endl;
        if (!m_UserAccountService)
        {
             cout<<"in if - 2 UserAccountService is > than"<<endl;
            return;     //this first return will exit the function call "OnAbortReelCommand"
        }

        cout<<"out if - 1"<<endl;
    }

     cout<<"Out AbortReel-1"<<endl;
}



int main()
{
cout << "My first C++ program." << endl;

for (int i = 0 ; i<10 ; i++)
        cout<<i<<" ";
    cout<<endl;
    
    OnAbortReelCommand();

    cout<<"The End"<<endl;



return 0;
}