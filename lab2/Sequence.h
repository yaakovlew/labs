#pragma once
#include <iostream>


template <class T>
class Sequence{
public:

    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index)const = 0;
    virtual int GetLength() const = 0;
    virtual void Prepand(T item) = 0;
    virtual void Append (T item) = 0;
    virtual void InsertAt(T element, int index) = 0;
    };