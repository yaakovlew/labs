#include <iostream>
#include "Tree.h"
#include <complex>
#include "BinHeap.h"
#include "Menu.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include "BinTreeTests.h"
#include "HeapTests.h"


std::ostream &operator<<(std::ostream &out, const std::complex<double> &element) {
    if (element.real() != 0) out << element.real();
    if (element.real() != 0 && element.imag() != 0) out << " + ";
    if (element.imag() != 0) out << element.imag() << " * i";
    return out;
}


int pr(int element) {
    return element * 2;
}


template<typename T>
bool fu(T el) {
    if (el >= 3)
        return true;
    else return false;
}


int main() {
    TestBinTree1();
    TestBinTree2();
    TestBinTree3();
    TestBinTree4();
    TestBinTreeHead();
    TestBinTreeConcat();
    TestBinTreeInsert();
    TestBinTreeMax();
    TestBinTreeMin();
    TestBinTreeDelete();
    Menu();
}


