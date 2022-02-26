#ifndef STRING_CPP
#define STRING_CPP

#include"string.h"


void String::copy(const String& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->data=new (std::nothrow) char[other.size+1];
    if( this->data == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
    else
    {
        int i=0 ;
        for(; i < size ; ++i)
        {
            this->data[i] = other[i];
        }
        this->data[i] = '\0';

    } 

}
void String::destroy()
{
    if(this->data != nullptr)
    {
        delete[] this->data;
        this->data = nullptr;
    }
}
// size_t guarantees for positive index
char& String::at(const size_t& index)const
{
    if(index < this->size)
    {
        return this->data[index];
    }
}
char& String::at(const size_t& index)
{
    if(index < size)
    {
        return data[index];
    }
}
void String::resize()
{
    this->capacity *= 2;
    char* newString = new (std::nothrow) char[this->capacity];
    if( this->data == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
    else
    {
        int i=0 ;
        for( ; i < size ; ++i)
        {
            newString[i] = this->data[i];
        }
        newString[i] = '\0';
        this->destroy();
        this->data=newString;
    }
    
}
void String::add(const String& other)
{
    int index = this->lenght();
    this->size+=other.size;
    while( this->size >= this->capacity)
    {
        this->resize();
    }
    for(int i=index , j=0 ; i < this->size ; ++i , ++j)
    {
        this->data[i] = other[j];
    }
}
String::String()
{
    capacity = 8;
    size=0;
    this->data = nullptr;
}
String::String(const char* str)
{
    int len =0 ;
    for(int i = 0 ; str[i] != '\0' ; ++i)
    {
        len++;
    }
    this->data = new (std::nothrow) char[len+1];
    if(this->data == nullptr)
    {
        std::cout << "Could not allocate memory for array." << std::endl;
    }
    int i=0;
    for( ; i<len ; ++i)
    {
        this->data[i] = str[i];
    }
    this->data[i] = '\0';
    this->size = len;

}
String::String(const String& other)
{
    this->copy(other);
}
String& String::operator=(const String& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other);
    }
}
String::~String()
{
    this->destroy();
}

const size_t String::lenght()const
{
    return this->size;
}

size_t String::getSize()
{
    return this->size;
}

const size_t String::getCapacity()const
{
    return this->capacity;
}

char& String::operator[](const size_t& index)
{
    return this->at(index);
}

char String::operator[](const size_t& index) const
{
    return this->at(index);
}

char& String::back()
{
    return this->data[size-1];
}

char& String::front()
{
    return this->data[0];
}

void String::clear()
{
    this->destroy();
    this->size=0;
}

bool String::empty()
{
    return (this->size == 0);
}

void String::push_back (char c)
{
    if( ( this->size + 1 ) >= this->capacity )
    {
        this->resize();
    }

    char* copy = new char[size+1];
    int  i = 0;
    for( ; i<this->size ; ++i)
    {
        copy[i] = this->data[i];

    }
    copy[i] = '\0';
    this->size+=1;
    this->destroy();
    this->data = new char[size+1];
    for( int j = 0 ; copy[j] != '\0' ; ++j)
    {
        this->data[j] = copy[j];

    }
    this->data[size-1] = c ;
    this->data[size] = '\0';
    delete[] copy;
}

void String::pop_back()
{
    if(this->size > 0)
    {
        this->size-=1;
    }
}

void String::swap (String& other)
{
    String helper;
    helper.copy(*this);
    this->copy(other);
    other.copy(helper);
}

String& String::erase (size_t start, size_t len )
{
    char* brandNew = new char[this->lenght()-len];
    for(int i=0 ; i < start ; i++)
    {
        brandNew[i] = this->data[i];
    }
    for(int i=start+len ; i < this->size ; ++i)
    {
        brandNew[i] = this->data[i];
    }
    this->size-=len;
    this->destroy();
    this->data = brandNew;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const String& item)
{
    for(int i=0 ; i < item.size ; i++)
    {
        out<<item.data[i];
    }
    out<<'\n';
    return out;
}

std::istream& operator>>(std::istream& in,  String& item)
{
    
    char symbol;
    do
    {
        symbol = getchar();
        item.push_back(symbol);

    } while (symbol != '\n');
    item.pop_back();

    return in;
}

bool String::operator==(const char* other)const
{
    
    int i=0;
    for( ; i< this->lenght() ; ++i)
    {
        if(this->data[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

bool String::operator==(const String& other)const
{
    if(this->lenght() != other.lenght())
    {
        return false;
    }
    int i=0;
    for( ; i< this->lenght() ; ++i)
    {
        if(this->data[i] != other[i])
        {
            return false;
        }
    }
    return true;
}

String String::operator+(const String& other)const
{
    String brandNew(*this);
    brandNew.add(other);
    return brandNew;

}

String& String::operator+= (const String& other)
{
    this->add(other);
    return *this;
}
    	
String& String::operator+= (const char* str)
{
    int sizeOfStr=0;
    for(int i =0 ; str[i] != '\0' ; ++i)
    {
        sizeOfStr++;
    }
    int index = this->size;
    this->size += sizeOfStr;
    while( this->size >= this->capacity)
    {
        this->resize();
    }
    for( int i=index ; i< this->size ; ++i)
    {
        this->data[i] = str[i];
    }
    return *this;

}

String& String::operator+= (char c)
{
    this->size+=1;
    if( this->size  >= this->capacity )
    {
        this->resize();
    }
    this->data[size-1] = c;
    return *this;
}

#endif