#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include"linkedList.h"

template<typename T>
LinkedList<T>::LinkedList()
{
    this->list = nullptr;

}
template<typename T>
LinkedList<T>::LinkedList( T& first_data , T& last_data)
{
    if(first_data > last_data)
    {
        std::cout<<"wrong parametres"<<std::endl;
        return;
    }
    T current_data = first_data;
    Box<T>* current = new Box<T>(first_data , nullptr);
    this->list = current;
    current_data++;
    while(current_data <= last_data)
    {
        current->next = new Box<T>(current_data , nullptr);
        current = current->next;
        current_data++;
        
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    if(other.list != nullptr)
    {
        Box<T>* currentOther = other.list;
        Box<T>* currentThis = new Box<T>(other.list->data , nullptr);
        this->list = currentThis;
        while(currentOther-> next != nullptr)
        {
            currentOther = currentOther->next;
            currentThis->next = new Box<T>(currentOther->data , nullptr);
            currentThis = currentThis->next;

        }
    }
    else
    {
        std::cout<<"error"<<std::endl;
    }
    

}
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if(!other.empty())
    {
        this->clear();
        Box<T>* currentOther = other.list;
        Box<T>* currentThis = new Box<T>(other.list->data , nullptr);
        this->list = currentThis;
        while(currentOther-> next != nullptr)
        {
            currentOther = currentOther->next;
            currentThis->next = new Box<T>(currentOther->data , nullptr);
            currentThis = currentThis->next;

        }
    }
    else
    {
        std::cout<<"error"<<std::endl;
    }
    return *this;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}
template<typename T>
void LinkedList<T>::print()
{
    Box<T>* currentBox = this->list;
    while( currentBox->next != nullptr)
    {
        std::cout<<currentBox->data<<"->";
        currentBox = currentBox->next;
    }
    std::cout<<currentBox->data<<std::endl;
}
template<typename T>
void LinkedList<T>::push(const T data_)
{
   list = new Box<T>(data_, list);
}
template<typename T>
void LinkedList<T>::push_back(const T data_)
{
    if(list == nullptr)
    {
        list = new Box<T>(data_, nullptr);
        return;
    }

    Box<T>* current = list;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Box<T>(data_, nullptr);

}
template<typename T>
void LinkedList<T>::pop()
{
    if(this->list != nullptr)
    {
        Box<T>* first = list;
        list = list->next;
        delete[] first;
    }
}
template<typename T>
void LinkedList<T>::pop_back()
{
    if(this->list != nullptr)
    {
        Box<T> *current = list;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete[] current->next;
        current->next = nullptr;
    }
}

template<typename T>
void LinkedList<T>::clear()
{
    if(this->list != nullptr)
    {
        while (!this->empty())
        {
            Box<T>* toDelete = this->list;
            this->list = this->list->next;
            // std::cout<<this->list<<std::endl;
            // std::cout<<(this->list == nullptr)<<std::endl;
            delete toDelete;
        }
       
    }
    
}

template<typename T>
void LinkedList<T>::insertAfter(const T data_ ,const int position)
{
    if(this->list != nullptr)
    {
        int myPosition = 0 ;
        Box<T>* currentBox = this->list;
        Box<T>* newBox = new Box<T>(data_ , nullptr);
        while( myPosition != position)
        {   
            currentBox = currentBox->next;
            myPosition++;
        }
        newBox->next = currentBox->next;
        currentBox->next = newBox;
    }
}

template<typename T>
void LinkedList<T>::deleteAt(const int position)
{
    if(this->list != nullptr)
    {
        if( position == 0)
        {
            this->pop();
            return;
        }
        else if( position == this->size())
        {
            this->pop_back();
            return;
        }
        //my pos starts from 1 in order to delete the element after passed position
        int myPosition = 1 ;
        Box<T>* currentBox = this->list;
        Box<T>* toBeDeleted;
        while( myPosition != position)
        {   
            currentBox = currentBox->next;
            myPosition++;
        }
        toBeDeleted = currentBox->next;
        currentBox->next = toBeDeleted->next;
        delete toBeDeleted;
    }
}
template<typename T>
int LinkedList<T>::size()const
{
    Box<T>* current = this->list;
    int cnt = 0;
    while(current != nullptr)
    {
        current = current->next;
        cnt++;
    }

    return cnt;
}
template<typename T>
Box<T>& LinkedList<T>::first()
{
    if(this->list != nullptr)
    {
        return *list;
    }
    else
    {
        std::cout<<"error"<<std::endl;
    }
    
}
template<typename T>
Box<T>& LinkedList<T>::last()
{
    
    if(this->list != nullptr)
    {
        Box<T> *last = list;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        return *last;
    }
    else
    {
        std::cout<<"error"<<std::endl;
    }
}
template<typename T>
Box<T>& LinkedList<T>::operator [](int index)
{
    
    Box<T>* current = list;
    while(index)
    {
        current = current->next;
        index--;
    }
    return *current;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    if(this->list == nullptr)
    {
        return true;
    }
    return false;
}
template<typename T>
void LinkedList<T>::removeDublicates()
{
    Box<T>* current = this->list;
    Box<T>* nextElem;
    int positionOfNextElem , currentPosition = 0;
    bool forDelete;
    while(current->next != nullptr)
    {
       forDelete = false;
       nextElem = current->next;
       positionOfNextElem = currentPosition+1;
       while(nextElem != nullptr)
       {
           if(nextElem->data == current->data)
           {
               nextElem = nextElem->next;
               this->deleteAt(positionOfNextElem);
               forDelete = true;
               continue;
           }
           nextElem = nextElem->next;
           positionOfNextElem++;
       }
       if(forDelete)
       {
           current = current->next;
           this->deleteAt(currentPosition);
           
       }
       else
       {
           current = current->next;
            currentPosition++;
       }
       
    }
}
template<typename T>
void LinkedList<T>::reverse()
{
    if(this->list != nullptr)
    {
        Box<T>* curent;
        int position_ = 0;
        for(int i=0 ; i < this->size()-1 ; ++i)
        {    
            curent = new Box<T> (last());
            this->insertAfter(curent->data , position_);
            this->pop_back();
            position_ ++;
        }
         curent = new Box<T> (first());
         this->pop();
         this->push_back(curent->data); 
    }
    
}
template<typename T>
int LinkedList<T>::countElement(const T data_)
{
    Box<T>* current = list;
    int counter = 0;
    if(this->list == nullptr)
    {
        return 0;
    }
    while(current != nullptr)
    {
        if(current->data == data_)
        {
            counter++;
        }
        current = current->next;
    }
    return counter;
}
template<typename T>
LinkedList<T>& LinkedList<T>:: operator+=(const LinkedList& other)
{
    if(other.list == nullptr)
    {
        return *this;
    }
    Box<T>* current = other.list;
    while(current != nullptr)
    {
        this->push_back(current->data);
        current=current->next;
    }
    return *this;
}
template<typename T>
LinkedList<T> LinkedList<T>:: operator+(const LinkedList& other)const
{
    LinkedList<T> newList;
    newList = *this;
    newList += other;
    return newList;
}
template<typename T>
void LinkedList<T>::readFromFile(const char* fileName)
{
    std:: ifstream in(fileName);
    T elem;
    in>>elem;
    while(!in.eof())
    {
        this->push(elem);
        in>>elem;
    }

    in.close();
}
template<typename T>
void LinkedList<T>::writeInFile(const char* fileName)const
{
    std::ofstream out(fileName);

    Box<T>* current = list;
    while(current != nullptr)
    {
        out<<(current->data);
        out<<'\n';
        current = current->next;
    }
    out.close();
}
#endif