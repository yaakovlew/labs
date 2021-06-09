//
// Created by andre on 11.05.2021.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include "ArrSequence.h"
#include <complex>


class Vectors_sizes_need_be_equally{
};

class Indexs_need_be_equally_or_biggest_then_zero{
};


template <class T>
class Vector {

private:
    ArrSequence<T> arrSequence;
    size_t elementSize =  sizeof(T);
    public:

    Vector(T* pointer, int length){
        arrSequence = ArrSequence<T>(pointer, length);
    }


    Vector(){
        arrSequence = ArrSequence<T>();
    }


    Vector(int length){
        arrSequence = ArrSequence<T>(length);
    }


    Vector(const Vector<T>& vecc){
        arrSequence = vecc.arrSequence;
    }


    Vector operator+(const Vector& v2)const {
        if (arrSequence.GetLength() != v2.GetLength())
            throw Vectors_sizes_need_be_equally();
        else {
            Vector<T> v3 = Vector<T>(arrSequence.GetLength());;
            for (int i = 0; i < arrSequence.GetLength(); i++) {
                v3.arrSequence.Get_pointer()[i] = arrSequence.Get(i) + v2.arrSequence.Get(i);
            }
            return v3;
        }
    }

    T Get(int index)const{
        return arrSequence.Get(index);
    }


    int GetLength()const{
        return arrSequence.GetLength();
    }


    Vector operator-(const Vector& v2)const {
        if (arrSequence.GetLength() != v2.GetLength())
            throw Vectors_sizes_need_be_equally();
        else {
            Vector<T> v3 = Vector<T>(arrSequence.GetLength());;
            for (int i = 0; i < arrSequence.GetLength(); i++) {
                v3.arrSequence.Get_pointer()[i] = arrSequence.Get(i) - v2.arrSequence.Get(i);
            }
            return v3;
        }
    }

    void Multip_by_number(T number){
        for (int i = 0; i < arrSequence.GetLength(); i++)
            arrSequence.Get_pointer()[i] = arrSequence.Get_pointer()[i] * number;
    }


    T operator*(const Vector& v2)const {
        if (arrSequence.GetLength() != v2.GetLength())
            throw Vectors_sizes_need_be_equally();
        else {
            T multip = 0;
            for (int i = 0; i < v2.arrSequence.GetLength(); i++)
                multip = multip + arrSequence.Get(i) * v2.arrSequence.Get(i);
            return multip;
        }
    }

    T Norm(){
        T sum = 0;
        for (int i = 0; i < arrSequence.GetLength(); i++)
            sum = sum + arrSequence.Get_pointer()[i];
        return sum;
    }

    template<class U>
    friend std::ostream& operator<< (std::ostream &out, const Vector<U> &vector);
    };

template <typename T>
std::ostream& operator<< (std::ostream &out, const Vector<T> &vector)
{

    out << "Linear space: " << vector.GetLength() << std::endl << "<";
    for (int i = 0; i < vector.GetLength() - 1; i++)
        out << vector.Get(i) << ", ";
    out << vector.Get(vector.GetLength() - 1) << ">";
    return out;
}

#endif //UNTITLED_VECTOR_H
