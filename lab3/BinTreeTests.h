//
// Created by andre on 29.05.2021.
//

#ifndef UNTITLED1_BINTREETESTS_H
#define UNTITLED1_BINTREETESTS_H
#include "Tree.h"
#include <assert.h>


void TestBinTree1() {
    std::vector<int> lem;
    for (int i = 0; i < 5; i++)
        lem.push_back(i);
    BinTree<int> clas = BinTree<int> (lem);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 2);
    assert(l[2] == 3);
    assert(l[3] == 4);
    assert(l[4] == 0);
    assert(clas.Get_head() != nullptr);
}


void TestBinTree2() {
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 2);
    assert(l[2] == 3);
    assert(l[3] == 4);
    assert(l[4] == 0);
    assert(clas.Get_head() != nullptr);
}


void TestBinTree3() {
    BinTree<int> clas = BinTree<int> ();
    assert(clas.Get_head() == nullptr);
}


void TestBinTree4() {
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    BinTree<int> car = BinTree<int>(clas);
    std::vector<int> l = car.ToVector("klp");
    assert(l[0] == 2);
    assert(l[1] == 3);
    assert(l[2] == 4);
    assert(l[3] == 1);
    assert(l[4] == 0);
    assert(clas.Get_head() != nullptr);
}



void TestBinTreeHead() {
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    assert(clas.Get_head() != nullptr);
}


void TestBinTreeConcat() {
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    for (int i = 5; i < 10; i++)
        mas[i - 5] = i;
    BinTree<int> car = BinTree<int>(mas, 5);
    clas.Concat(car);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 3);
    assert(l[1] == 6);
    assert(l[2] == 7);
    assert(l[3] == 8);
    assert(l[4] == 9);
    assert(l[5] == 4);
    assert(l[6] == 5);
    assert(l[7] == 1);
    assert(l[8] == 2);
    assert(l[9] == 0);
    assert(clas.Get_head() != nullptr);
}


void TestBinTreeInsert(){
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    clas.Insert(5);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 3);
    assert(l[2] == 4);
    assert(l[3] == 5);
    assert(l[4] == 2);
    assert(l[5] == 0);
}


void TestBinTreeMax(){
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    clas.Insert(5);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 3);
    assert(l[2] == 4);
    assert(l[3] == 5);
    assert(l[4] == 2);
    assert(l[5] == 0);
    assert(clas.getMaxNode() == 5);
}


void TestBinTreeMin(){
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    clas.Insert(5);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 3);
    assert(l[2] == 4);
    assert(l[3] == 5);
    assert(l[4] == 2);
    assert(l[5] == 0);
    assert(clas.getMinNode() == 0);
}


void TestBinTreeDelete(){
    int mas[5];
    for (int i = 0; i < 5; i++)
        mas[i] = i;
    BinTree<int> clas = BinTree<int> (mas, 5);
    clas.Delete(2);
    std::vector<int> l = clas.ToVector("klp");
    assert(l[0] == 1);
    assert(l[1] == 3);
    assert(l[2] == 4);
    assert(l[3] == 0);
}


#endif //UNTITLED1_BINTREETESTS_H
