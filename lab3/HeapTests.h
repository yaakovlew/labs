//
// Created by andre on 31.05.2021.
//

#ifndef UNTITLED1_HEAPTESTS_H
#define UNTITLED1_HEAPTESTS_H
#include "BinHeap.h"

void TestHeap1(){
    std::vector<int> el;
    for (int i = 0; i < 6; i++)
        el.push_back(i);
    Heap<int>test = Heap<int>(el);
    std::vector<int> v = test.Kpl(0);
    assert(v[0] == 5);
    assert(v[1] == 3);
    assert(v[2] == 0);
    assert(v[3] == 4);
    assert(v[4] == 1);
    assert(v[5] == 2);
}


void TestHeap2(){
    int mas[6];
    for (int i = 0; i < 6; i++)
        mas[i] = i;
    Heap<int>test = Heap<int>(mas, 6);
    std::vector<int> v = test.Kpl(0);
    assert(v[0] == 5);
    assert(v[1] == 3);
    assert(v[2] == 0);
    assert(v[3] == 4);
    assert(v[4] == 1);
    assert(v[5] == 2);
}


void TestHeap3(){
    Heap<int>test = Heap<int>();
    std::vector<int> v = test.Kpl(0);
    assert(v.size() == 0);
}


void TestHeapAdd(){
    int mas[6];
    for (int i = 0; i < 6; i++)
        mas[i] = i;
    Heap<int>test = Heap<int>(mas, 6);
    std::vector<int> v = test.Kpl(0);
    test.Add(6);
    assert(v[0] == 5);
    assert(v[1] == 3);
    assert(v[2] == 0);
    assert(v[3] == 4);
    assert(v[4] == 1);
    assert(v[5] == 2);
}


void TestHeapDelete(){
    int mas[6];
    for (int i = 0; i < 6; i++)
        mas[i] = i;
    Heap<int>test = Heap<int>(mas, 6);
    std::vector<int> v = test.Kpl(0);
    test.Delete(5);
    assert(v[1] == 3);
    assert(v[2] == 0);
    assert(v[3] == 4);
    assert(v[4] == 1);
    assert(v[5] == 2);
}


void TestHeapToVector() {
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    Heap<int> clas = Heap<int> (mas, 5);
    std::vector<int> l = clas.Klp(0);
    assert(l[0] == 1);
    assert(l[1] == 2);
    assert(l[2] == 3);
    assert(l[3] == 4);
    assert(l[4] == 0);
    std::vector<int> l1 = clas.Kpl(0);
    assert(l1[0] == 1);
    assert(l1[1] == 0);
    assert(l1[2] == 2);
    assert(l1[3] == 3);
    assert(l1[4] == 4);
    std::vector<int> l2 = clas.Lpk(0);
    assert(l2[0] == 0);
    assert(l2[1] == 4);
    assert(l2[2] == 3);
    assert(l2[3] == 2);
    assert(l2[4] == 1);
    std::vector<int> l3 = clas.Plk(0);
    assert(l3[0] == 4);
    assert(l3[1] == 3);
    assert(l3[2] == 2);
    assert(l3[3] == 0);
    assert(l3[4] == 1);
    std::vector<int> l4 = clas.Lkp(0);
    assert(l4[0] == 4);
    assert(l4[1] == 3);
    assert(l4[2] == 2);
    assert(l4[3] == 1);
    assert(l4[4] == 0);
    std::vector<int> l5 = clas.Pkl(0);
    assert(l5[0] == 0);
    assert(l5[1] == 1);
    assert(l5[2] == 2);
    assert(l5[3] == 3);
    assert(l5[4] == 4);
}



#endif //UNTITLED1_HEAPTESTS_H
