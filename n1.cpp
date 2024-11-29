#include <iostream>
#include <string>
using namespace std;

char* CopyString(const char* str)
{
    size_t i = 0;
    while(str[i] != '\0') ++i;
    char* cp = new char[i];
    memcpy(cp, str, i);
    return cp;
}

char* ConcatinateStrings(const char* a, const char* b)
{
    size_t sa = 0, sb = 0;
    while(a[sa] != '\0') ++sa;
    while(b[sb] != '\0') ++sb;
    char* cp = new char[sa + sb];
    copy(a, a + sa, cp);
    copy(b, b + sb, cp + sa);
    return cp;
}

int main()
{
    char* str1 = new char;
    char* str2 = new char;
    cin >> str1 >> str2;
    auto k = ConcatinateStrings(str1, str2);
    int size = 0;
    while(k[size] != '\0') ++size;
    for(int i = 0; i < size; ++i) cout << k[i];
    return 0;
}
