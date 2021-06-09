#pragma once
#include <iostream>
#include "IndexOutOfRange.h"
#include <algorithm>


template <class T>
class DynamicArray{
public:
    DynamicArray(T* items, int count) {
        length = count;
        point = nullptr;
        point = new T[count];
        for (int i = 0; i < count; i++)
            point[i] = items[i];
    }



    DynamicArray(int count) {
        length = count;
        point = new T[count];
        for (int i = 0; i < count; i++)
            point[i] = 0;
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) {
        length = dynamicArray.length;
        point = new T(length);
        for (int i = 0; i < dynamicArray.length; i++)
            point[i] = dynamicArray.point[i];
    }


    DynamicArray() {}


    int GetLength()const {
        return length;
    }
    T* GetPointer() {
        return point;
    }

    T Get(int index)const{
        IndexOutOfRangeexeption Ex;
        if (index >= 0 && index < length){ return point[index];}
        else std::cout<<Ex.er<<std::endl;
    }

    void Resize(int newSize){
        T* arr = point;
        point = new T[newSize];
        for (int i = 0; i < std::min(newSize, length); i++)
            point[i] = arr[i];
        length = newSize;
        delete[](arr);
    }

    void Append(T element){
        Resize(length + 1);
        point[length] = element;
    }


    void Prepend(T element){
        T* elem = point;
        Resize(length + 1);
        for (int i = 1; i <= length - 1; i++)
            point[i] = elem[i - 1];
        point[0] = element;
    }


    void InsertAt(T element, int index){
        T* elem = point;
        T item = point[length - 1];
        Resize(length + 1);
        point[index] = element;
        for (int i = index + 1; i < length - 1; i++)
            point[i] = elem[i - 1];
        point[length - 1] = item;
    }


    DynamicArray<T>* GetSubArr(int startIndex, int endIndex){
        T* arr;
        for (int i = startIndex; i < endIndex; i++)
            arr[i - startIndex] = point[i];
        DynamicArray<T> clas = DynamicArray<T>(arr, endIndex - startIndex);
        return clas;
    }


private:
    int length = 0;
    T* point;
};