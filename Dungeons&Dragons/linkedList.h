#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"box.cpp"
#include<fstream>
#include<cassert>
#include<iostream>

template<typename T>

class LinkedList
{
    private:
    Box<T>* list;
    
    public:
    //constructors
    LinkedList();
    LinkedList(T& , T&); 
    LinkedList(const LinkedList<T>& );
    LinkedList& operator=(const LinkedList<T>&);
    ~LinkedList();

    void print();
    void push(const T);
    void push_back(const T);
    void pop();
    void pop_back();
    void clear();
    void insertAfter(const T ,const int);
    void deleteAt(const int);
    int size() const;
    Box<T>& first();
    Box<T>& last();
    Box<T>& operator [](int);
    bool empty()const;
    void removeDublicates();
    void reverse(); 

    int countElement(const T);
    LinkedList<T>& operator+=(const LinkedList<T>&);
    LinkedList<T> operator+(const LinkedList<T>&)const;
    
    void readFromFile(const char*);
    void writeInFile(const char*)const;
};
#include"linkedList.inl"
#endif