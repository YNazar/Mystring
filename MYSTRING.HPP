#ifndef MYSTRING_HPP_INCLUDED
#define MYSTRING_HPP_INCLUDED
#include <iostream>
class Mystring
{
public:
    Mystring();
    explicit Mystring(size_t ins);
    explicit Mystring ( const char *str1);
    ~Mystring()
    {
        delete [] str;

    }
    Mystring(Mystring &rhs);
    Mystring operator=(const Mystring& rhs);
    void printstr();
    void scanstr();
    size_t  get_size () const;
    char* get_str()const;
    char&  operator [] (size_t idx);
    const char& operator[](size_t idx)const;
    void operator+=(const Mystring&rhs);
    void  deletchr( char a);
    size_t  findchr(const char *str, char a);
private:
    char *str;
    size_t siz;
    void resiz(size_t newsiz);

};
Mystring operator+( const Mystring& a,const Mystring &b);

#endif // MYSTRING_HPP_INCLUDED
