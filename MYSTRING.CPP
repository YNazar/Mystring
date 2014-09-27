#include "MYSTRING.HPP"
#include <iostream>
#include <limits>
using  namespace std;
Mystring::Mystring():siz(0)
{
    str=new char[1];
    str[0]='\0';
}
Mystring::Mystring(size_t ins): siz (ins)
{
    str=new char[siz+1];
    for (size_t i=0; i<ins; i++)
        str[i]='0';
    str[ins]='\0';
}
Mystring::Mystring(Mystring &rhs):siz(rhs.siz)
{
    str=new char[siz];
    for (size_t i=0; i<rhs.siz; i++)
        str[i]=rhs.str[i];
}
Mystring Mystring::operator=(const Mystring& rhs)
{
    if (this==&rhs)
        return *this;
    delete[] str;
    siz=rhs.siz;
    str=new char[siz];
    for (size_t i=0; i<siz; i++)
        str[i]=rhs.str[i];
    return *this;
}
size_t  Mystring::get_size () const
{
    return siz;
}
char* Mystring::get_str()const
{
    char*tmp=new char[siz];
    for (size_t i=0;i<siz;i++)
        tmp[i]=str[i];
    return tmp;
}
const char&  Mystring::operator[](size_t idx)const
{
    return str[idx];
}
char&  Mystring::operator [] (size_t idx)
{

    return str[idx];
}
Mystring::Mystring ( const char *str1)
{
    siz=0;
    while (*(str1++)!='\0')
        siz++;
    str =new char[siz];
    for (size_t i=0; i<siz; i++)
        str[i]=str1[i-siz-1];

}
void Mystring::printstr()
{
    for (size_t i=0; i<siz; i++)
        std::cout << str[i]<<" ";
    std::cout << std::endl;
    std::cout <<"Elementiv :" <<siz<<std::endl;

}
void Mystring::scanstr()
{
    cout << "Enter string and | 0 | to break "<< endl;
    delete[] str;
    siz=0;
    str=new char[siz+1];
    while(true)
    {
        cin>>str[siz];
        if (str[siz]=='0')
        {
            str[siz]='\0';
            break;
        }
        siz++;
        this->resiz(siz);
    }
}
void Mystring::resiz(size_t newsiz)
{
    char*tmp=new char [newsiz];
    for (size_t i=0; i<siz; i++)
        tmp[i]=str[i];
    delete[] str;
    siz=newsiz;
    str = tmp;
}
Mystring operator+ (const Mystring& a,const Mystring& b)
{
    Mystring res;
    res=a;
    res+=b;
   return res;
}
void Mystring::operator+=(const Mystring&rhs)
{       char*res=new char[siz+rhs.siz];
    for(size_t i=0;i<siz;i++)
        res[i]=str[i];
    for(size_t i=0;i<rhs.siz;i++)
        res[siz+i]=rhs.str[i];
        delete[] str;
        siz=siz+rhs.siz;
        str=res;

}
void Mystring:: deletchr( char a)
{
    size_t lich=0,n=0;
    for(size_t i=0; i<siz; i++)
    {
        if (str[i]==a)
            lich++;
    }
    siz-=lich;
    char *tmp=new char[siz];
    for (size_t i=0; i<(siz+lich); i++)
    {
        if (str[i]!=a)
        {
            tmp[n]=str[i];
            n++;
        }
    }
    str=tmp;
}
size_t  Mystring::findchr(const char *str, char a)
{

    size_t res=0;
    for (size_t i=0; str[i]!='\0'; i++)
    {
        if (str[i]==a)
            return i;
        else
            res=numeric_limits <size_t>::max();
    }
    return res;
}
