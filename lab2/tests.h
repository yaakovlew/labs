#pragma once
#include <iostream>
#include <cassert>
#include "dynamicarr.h"
#include "LinkedList.h"
#include "Matrix.h"
#include "Vector.h"


void test_constructor1(){
    int arr[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(arr, 5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass.GetPointer() + i) == i);
    assert(testclass.GetLength() == 5);
    double arr1[5];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(arr1, 5);
    assert(testclass1.GetLength() == 5);
}

void test_constructor2() {
    DynamicArray<int> testclass = DynamicArray<int>(5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass.GetPointer() + i) == 0);
    assert(testclass.GetLength() == 5);
    DynamicArray<double> testclass1 = DynamicArray<double>(5);
    for (int i = 0; i < 5; i++)
        assert(*(testclass1.GetPointer() + i) == 0);
    assert(testclass1.GetLength() == 5);
}

void test_constructor3() {
    DynamicArray<int> testclass1 = DynamicArray<int>(5);
    DynamicArray<int> testclass2 = DynamicArray<int>(testclass1);
    for (int i = 0; i < testclass1.GetLength(); i++)
        assert(*(testclass2.GetPointer() + i) == *(testclass1.GetPointer() + i));
    assert(testclass2.GetLength() == (testclass1.GetLength()));
    DynamicArray<double> testclass11 = DynamicArray<double>(5);
    DynamicArray<double> testclass22 = DynamicArray<double>(testclass11);
    for (int i = 0; i < testclass1.GetLength(); i++)
        assert(*(testclass22.GetPointer() + i) == *(testclass11.GetPointer() + i));
    assert(testclass22.GetLength() == (testclass11.GetLength()));
}


void test_resize(){
    DynamicArray<int> testclass = DynamicArray<int>(5);
    testclass.Resize(10);
    assert(testclass.GetLength() == 10);
    DynamicArray<double> testclass1 = DynamicArray<double>(5);
    testclass1.Resize(10);
    assert(testclass1.GetLength() == 10);
}


void test_getlength(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    assert(testclass.GetLength() == 10);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    assert(testclass1.GetLength() == 10);
}


void test_Get(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass1.Get(i) == i);
}


void test_Append(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.Append(10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.Append(10);
    assert(testclass1.GetLength() == 11);
}


void test_prepend(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass.Get(0) == 0);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass1.Get(0) == 0);
    assert(testclass1.GetLength() == 11);
}


void test_insertat(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<int> testclass = DynamicArray<int>(mas, 10);
    testclass.InsertAt(11, 4);
    assert(testclass.Get(4) == 11);
    assert(testclass.GetLength() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    DynamicArray<double> testclass1 = DynamicArray<double>(mas1, 10);
    testclass1.InsertAt(11, 4);
    assert(testclass1.Get(4) == 11);
    assert(testclass1.GetLength() == 11);
}


void test_append(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.Append(10);
    assert(testclass.Get(10) == 10);
    assert(testclass.Get_length() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.Append(10);
    assert(testclass1.Get(10) == 10);
    assert(testclass1.Get_length() == 11);
}

void test_prep(){
    int mas[10];
    for (int i = 1; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass.Get(0) == 0);
    assert(testclass.Get_length() == 11);
    double mas1[10];
    for (int i = 1; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.Prepend(0);
    for (int i = 0; i <= 10; i++)
        assert(testclass1.Get(0) == 0);
    assert(testclass1.Get_length() == 11);
}


void test_constr1(){
    LinkedList<int> clas = LinkedList<int>();
    assert(clas.Get_length() == 0);
    LinkedList<double> clas1 = LinkedList<double>();
    assert(clas1.Get_length() == 0);
}


void test_constr2(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        (testclass.Get(i) == i + 1);
    assert(testclass.Get_length() == 10);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        (testclass1.Get(i) == i + 1);
    assert(testclass1.Get_length() == 10);
}


void test_Getl(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(i) == i + 1);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass1.Get(i) == i + 1);
}


void test_Getfirst(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    assert(testclass.Get(0) == testclass.Get_First());
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(0) == testclass.Get_First());
}


void test_Getlast(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    assert(testclass.Get(9) == testclass.Get_last());
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    for (int i = 0; i < 10; i++)
        assert(testclass.Get(9) == testclass.Get_last());
}


void test_InsAt(){
    int mas[10];
    for (int i = 0; i < 10; i++)
        mas[i] = i + 1;
    LinkedList<int> testclass = LinkedList<int>(mas, 10);
    testclass.InsertAt(5,6);
    assert(testclass.Get(6) == 5);
    double mas1[10];
    for (int i = 0; i < 10; i++)
        mas1[i] = i + 1;
    LinkedList<double> testclass1 = LinkedList<double>(mas1, 10);
    testclass1.InsertAt(5,6);
    assert(testclass1.Get(6) == 5);
}



void test_matconstructor1(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.GetSize() == 3);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    assert(testclass1.GetSize() == 3);
}


void test_matconstructor2(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.GetSize() == 3);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    assert(testclass1.GetSize() == 3);
}


void test_matconstructor3(){
    Matrix<int> testclass = Matrix<int>();
    assert(testclass.GetSize() == 0);
    Matrix<double> testclass1 = Matrix<double>();
    assert(testclass1.GetSize() == 0);
}


void test_matsum(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.GetSize() == 3);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    Matrix<double> testclass2 = Matrix<double>(mas1, 3);
    Matrix<double> testclass3 = testclass2 + testclass1;
    assert(testclass1.GetSize() == 3);
}


void test_matraz(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.GetSize() == 3);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    Matrix<double> testclass2 = Matrix<double>(mas1, 3);
    Matrix<double> testclass3 = testclass2 - testclass1;
    assert(testclass1.GetSize() == 3);
}


void test_stbsum(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    testclass.ElemChangeStbSum(1,2);
    assert(testclass.Get(0) == 3);
    assert(testclass.Get(3) == 9);
    assert(testclass.Get(6) == 15);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    testclass.ElemChangeStbSum(1,2);
}


void test_stbraz(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    testclass.ElemChangeStbSum(1,2);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    testclass.ElemChangeStbSum(1,2);
}



void test_get(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.Get(0) == 1);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    assert(testclass1.Get(0) == 1);

}



void test_norm(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i + 1;
    Matrix<int> testclass = Matrix<int>(mas, 3);
    assert(testclass.Norm() == 24);
    //std::cout<<testclass.Norm();
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i + 1;
    Matrix<double> testclass1 = Matrix<double>(mas1, 3);
    assert(testclass1.Norm() == 24);
}



void test_Getv(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i;
    Vector<int> testclas = Vector<int> (mas, 9);
    for (int i = 0; i < 9; i++)
        assert(testclas.Get(0) == 0);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i;
    Vector<double> testclas1 = Vector<double> (mas1, 9);
    for (int i = 0; i < 9; i++)
        assert(testclas1.Get(i) == i);
}


void test_vconstructor1(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i;
    Vector<int> testclas = Vector<int> (mas, 9);
    for (int i = 0; i < 9; i++)
        assert(testclas.Get(0) == 0);
    assert(testclas.GetLength() == 9);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i;
    Vector<double> testclas1 = Vector<double> (mas1, 9);
    for (int i = 0; i < 9; i++)
        assert(testclas1.Get(i) == i);
    assert(testclas1.GetLength() == 9);
}


void test_vconstructor2(){
    Vector<int> testclas = Vector<int> ();
    assert(testclas.GetLength() == 0);
    Vector<double> testclas1 = Vector<double> ();
    assert(testclas1.GetLength() == 0);
}



void test_vconstructor3(){
    Vector<int> testclas = Vector<int> (10);
    assert(testclas.GetLength() == 10);
    Vector<double> testclas1 = Vector<double> (10);
    assert(testclas1.GetLength() == 10);
}


void test_vlength(){
    Vector<int> testclas = Vector<int> (10);
    assert(testclas.GetLength() == 10);
    Vector<double> testclas1 = Vector<double> (10);
    assert(testclas1.GetLength() == 10);
}


void test_mult_by_number(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i;
    Vector<int> testclas = Vector<int> (mas, 9);
    testclas.Multip_by_number(3);
    for (int i = 0; i < 9; i++)
        assert(testclas.Get(i) == i * 3);
    assert(testclas.GetLength() == 9);
    double mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i;
    Vector<double> testclas1 = Vector<double> (mas1, 9);
    testclas.Multip_by_number(3);
    for (int i = 0; i < 9; i++)
        assert(testclas1.Get(0) == 0);
    assert(testclas1.GetLength() == 9);
}


void test_normv(){
    int mas[9];
    for (int i = 0; i < 9; i++)
        mas[i] = i;
    Vector<int> testclas = Vector<int> (mas, 9);
    for (int i = 0; i < 9; i++)
        assert(testclas.Get(i) == i);
    assert(testclas.GetLength() == 9);
    assert(testclas.Norm() == 36);
    float mas1[9];
    for (int i = 0; i < 9; i++)
        mas1[i] = i;
    Vector<float> testclas1 = Vector<float> (mas1, 9);
    testclas.Multip_by_number(3);
    for (int i = 0; i < 9; i++)
        assert(testclas1.Get(0) == 0);
    assert(testclas1.GetLength() == 9);
    assert(testclas1.Norm() == 36);
}