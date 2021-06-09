//
// Created by andre on 10.05.2021.
//
#pragma once
#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H
#include "ArrSequence.h"
#include <iostream>
#include <cmath>
#include <complex>



class Matrixs_sizes_need_be_equally{
};

class Index_need_be_equally_or_biggest_then_zero{
};


template <class T>
class Matrix:ArrSequence<T> {
private:

    ArrSequence<T> arrSequence;
    int length = 0;
    int height = 0;
    size_t elementSize = sizeof(T);


public:

    Matrix(T *pointer, int length1) {
        arrSequence = ArrSequence<T>(pointer, length1 * length1);
        length = length1;
        height = length1;
    }


    Matrix() {
        arrSequence = ArrSequence<T>();
    }


    Matrix(int length1) {
        arrSequence = ArrSequence<T>(length1 * length1);
        length = length1;
        height = length1;
    }


    Matrix(const Matrix<T> &mat) {
        arrSequence = mat.arrSequence;
        height = mat.GetSize();
        length = mat.GetSize();
    }


    T GetFirst() {
        return arrSequence.GetFirst();
    }


    T GetLast() {
        return arrSequence.GetLast();
    }


    int GetLength() {
        return arrSequence.GetLength();
    }

    T Get(int str, int stb) {
        return arrSequence.Get(str * arrSequence.GetLength() + stb);
    }


    void Multip_for_number(double number) {
        for (int i = 0; i < arrSequence.GetLength(); i++)
            arrSequence.Get_pointer()[i] = arrSequence.Get(i) * number;
    }


    Matrix operator+(const Matrix &v2) const {
        if (length != v2.GetSize())
            throw Matrixs_sizes_need_be_equally();
        else {
            Matrix<T> v3 = Matrix<T>(length);
            for (int i = 0; i < length * height; i++)
                v3.arrSequence.Get_pointer()[i] = arrSequence.Get(i) + v2.arrSequence.Get(i);
            return v3;
        }
    }


    Matrix operator-(const Matrix &v2) const {
        if (length != v2.GetSize())
            throw Matrixs_sizes_need_be_equally();
        else {
            Matrix<T> v3 = Matrix<T>(length);
            for (int i = 0; i < length * height; i++) {
                v3.arrSequence.Get_pointer()[i] = arrSequence.Get(i) - v2.arrSequence.Get(i);
                //std::cout<<arrSequence.Get(i)<<' '<<v2.arrSequence.Get(i)<<' '<<v3.arrSequence.Get_pointer()[i]<<std::endl;
            }
            return v3;
        }
    }

    void ElemChangeStrSum(int str11, int str22) {
        int str1 = str11 - 1, str2 = str22 - 1;
        if (str11 < 1 || str22 < 1)
            throw Index_need_be_equally_or_biggest_then_zero();
        else
        {
            int str1 = str11 - 1, str2 = str22 - 1;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < length; j++)
                    if (i == str1) arrSequence.Get_pointer()[str1 * length + j] =
                                           arrSequence.Get_pointer()[str1 * length + j] +
                                           arrSequence.Get_pointer()[str2 * length + j];
            }
        }
    }


    void ElemChangeStrSub(int str11, int str22) {
        int str1 = str11 - 1, str2 = str22 - 1;
        if (str11 < 1 || str22 < 1)
            throw Index_need_be_equally_or_biggest_then_zero();
        else
        {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++)
                if (i == str1) arrSequence.Get_pointer()[str1 * length + j] =
                                       arrSequence.Get_pointer()[str1 * length + j] -
                                       arrSequence.Get_pointer()[str2 * length + j];
        }
    }
}

    void ElemChangeStbSum(int stb11,int stb22) {
        int stb1 = stb11 - 1, stb2 = stb22 - 1;
        if (stb11 < 1 || stb22 < 1)
            throw Index_need_be_equally_or_biggest_then_zero();
        else {
            int stb1 = stb11 - 1, stb2 = stb22 - 1;
            for (int i = 0; i <= length * (height - 1); i = i + length)
                arrSequence.Get_pointer()[stb1 + i] =
                        arrSequence.Get_pointer()[i + stb1] + arrSequence.Get_pointer()[stb2 + i];
        }
    }


    void Append (T item){}


    int GetSize()const{
        return length;
    }

    void Prepand(T item){}


    void ElemChangeStbSub(int stb11,int stb22) {
        int stb1 = stb11 -1, stb2 = stb22 -1;
        for (int i = 0; i <= length * (height - 1); i = i + length )
            arrSequence.Get_pointer()[stb1 + i] = arrSequence.Get_pointer()[i + stb1] - arrSequence.Get_pointer()[stb2 + i];
    }


    T Norm(){
        T minnorm = 0, sum = 0;
        for (int i = 0; i < length; i++)
            minnorm = minnorm + arrSequence.Get_pointer()[i];
        for (int i = 0; i < length; i++){
            sum = 0;
            for (int j = 0; j < height; j++){
                sum = sum + arrSequence.Get_pointer()[i * length + j];
                if (minnorm < sum) minnorm = sum;
            }
        }
        return minnorm;
    }



    T Get(int index)const{
        return arrSequence.Get(index);
    }

    template <class U>
    friend std::ostream& operator<< (std::ostream &out, const Matrix<U> &matrix);
};

template <class U>
std::ostream& operator<< (std::ostream &out, const Matrix<U> &matrix)
{

    out << "Matrix's size(N*N): " << matrix.GetSize() << std::endl;
    for (int i = 0; i < matrix.GetSize(); i++) {
        if (i != 0) out << std::endl;
        for (int j = 0; j < matrix.GetSize(); j++)
            out << matrix.Get(i * matrix.GetSize() + j) << " ";
    }
    out<<std::endl;
    return out;
}


#endif //UNTITLED_MATRIX_H
