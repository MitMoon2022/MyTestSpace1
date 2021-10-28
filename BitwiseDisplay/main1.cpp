#include <iostream>
#include <bitset>

using namespace std;
int main()
{
// The easiest way is probably to create an std::bitset representing the value,
// then stream that to cout.
    char a = -58;
    bitset<8> x(a);
    cout << x << '\n';

    short c = -315;
    bitset<16> y(c);
    cout << y << '\n';

    //Another example
    int i = -58, j = a>>4, k = -315;

        cout << "i = " << std::bitset<8>(i)  <<endl;
        cout << "j = " << std::bitset<8>(j)  <<endl;
        cout << "k = " << std::bitset<16>(k) <<endl;

        cout << "i in dec = " << dec<<i<<endl;
        cout << "j in hex = " << hex <<j<<endl;
        cout << "k in oct= " << oct<< k <<endl;

    cout<<"The End"<<endl;

return 0;
}