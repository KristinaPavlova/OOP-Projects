#ifndef BOX_CPP 
#define BOX_CPP 
#include<iostream>

template<typename T>
struct Box
{
    T data;
    Box* next;

    Box();
    Box( T data_ , Box* next_);
    Box( const Box& other);
    Box& operator=(const Box&);

};

template<typename T>
Box<T>::Box()
{
    this->next= nullptr;
}

template<typename T>
Box<T>::Box( T data_ , Box* next_)
{
    this->data = data_;
    this->next = next_;
}

template<typename T>
Box<T>::Box( const Box& other)
{
    this->data = other.data;
    this->next = other.next;
}

template<typename T>
Box<T>& Box<T>::operator=( const Box& other)
{
   if(this!= other)
   {
       this->data = other->data;
       this->next = other->next;
   }
   return *this;
}
#endif