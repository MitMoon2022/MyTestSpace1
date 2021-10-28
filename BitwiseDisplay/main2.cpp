#include <iostream>
#include <bitset>
#include <climits>

/*
If you want to display the bit representation of any object,
not just an integer, remember to reinterpret as a char array first, 
then you can print the contents of that array, as hex, or even as binary (via bitset):

Note that most common systems are little-endian, so the output of show_binrep(c)
is not the 1111111 011000101 you expect, because that's not how it's stored in memory.
If you're looking for value representation in binary, then a simple cout << bitset<16>(c) works.
*/

template <typename T>
void show_binrep(const T &a)
{
    const char *beg = reinterpret_cast<const char *>(&a);
    const char *end = beg + sizeof(a);
    while (beg != end)
        std::cout << std::bitset<CHAR_BIT>(*beg++) << ' ';
        //std::cout << std::bitset<16>(*beg++) << ' ';
    std::cout << '\n';
}
int main()
{
    char a, b;
    short c;
    a = -58;
    c = -315;
    b = a >> 3;
    std::cout<<"a in binary:->"; show_binrep(a);
    std::cout<<"b in binary:->"; show_binrep(b);
    std::cout<<"c in binary:->"; show_binrep(c);
    float f = 3.14;
    std::cout<<"f in binary:->";show_binrep(f);
}