#include "MYSTRING.HPP"
#include <iostream>

using namespace std;

int main()
{
//Mystring a;

    Mystring c;
    Mystring a("abcde");
    a.printstr();
    char* str;
    str=a.get_str();
    delete str;    
    cout <<str<<endl;
    a.printstr();
    return 0;
}
