//
// Created by andre on 10.05.2021.
//

#ifndef UNTITLED_LISTSEQUENCE_H
#define UNTITLED_LISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class ListSequence:Sequence<T> {


private:

    LinkedList<T> LiLi;

public:

    ListSequence(){
        LiLi = LinkedList();
    }


    ListSequence(const ListSequence<T> &copy){
        LiLi = copy.LiLi;
    }


    ListSequence(T* items, int count){
        LiLi = LinkedList(items, count);
    }


    ListSequence(){
        LiLi = LinkedList();
    }


    T Get_First(){
        return LiLi.Get_First()
    }


    T Get_Last(){
        return LiLi.Get_last()
    }


    int Get_length(){
        return LiLi.Get_length();
    }


    T Get(int index)const{
        return LiLi.Get();
    }


    void Prepend(T item){
        LiLi.Prepend(item);
    }


    void Append(T item){
        LiLi.Append(item);
    }


    void InsertAt(T item, int index) {
         LiLi.InsertAt(item, index);
    }


    LinkedList* GetSubList(int startIndex, int endIndex) {
        return LiLi.GetSubList(startIndex, endIndex);
    }

#endif //UNTITLED_LISTSEQUENCE_H
