#ifndef STRING_H
#define STRING_H
#include<iostream>

class String
{
    private:

    char* data;
    size_t size;
    size_t capacity;
    
    void copy(const String&);
    void destroy();
    char& at(const size_t&)const;
    char& at(const size_t&);
    void resize();
    void add(const String&);


    public:
    //constructors
    String();
    String(const char*);
    String(const String& other);
    String& operator=(const String&);
    ~String();


    
    const size_t lenght()const;
    size_t getSize();
    const size_t getCapacity()const;
    char& operator[](const size_t&);
    char operator[](const size_t&)const;
    char& back();
    char& front();
    void clear();
    bool empty();
    void push_back (char c);
    void pop_back();
    void swap (String&);
    String& erase (size_t , size_t );
    
    friend std::ostream& operator<<(std::ostream& out, const String&);
    friend std::istream& operator>>(std::istream& in, String&);

    bool operator==(const char* ) const;
    bool operator==(const String& ) const;
    String operator+(const String& )const;

    String& operator+= (const String& str);
    	
    String& operator+= (const char* s);
    	
    String& operator+= (char c);

};
#endif