#pragma once
#include "actionvector.h"
#include <assert.h>

void test_look() {
    vector v1;
    int length1 = 4;
    int el_size1 = 1;
    constructor(&v1, el_size1, length1);
    assert(v1.length == length1);
    assert(v1.element_size == el_size1);
}

void test_search() {
    vector v1;
    int length1 = 4;
    double a = 1.1;
    int el_size1 = sizeof(double);
    constructor(&v1, el_size1, length1);
    for (int i = 0; i < v1.length ; i++)
        *(double*)v1.get_i(&v1, i) = i + 0.1;
    int result = v1.search_index(v1, (void*)&a);
    assert(result == 1);
}

void test_concat(){
    vector v1;
    int length1 = 4, length2 = 3;
    double a = 1.1;
    int el_size1 = sizeof(double );
    double mass[3];
    for (int i = 0; i < length2; i++)
        mass[i] = 4 + i + 0.1;
    constructor(&v1, el_size1, length1);
    for (int i = 0; i < v1.length ; i++)
        *(double*)v1.get_i(&v1, i) = i + 0.1;
    v1.concat(&v1, &mass, length2);
    assert(v1.length == length1 + length2);
    for (int i = 0; i < v1.length ; i++)
        assert(*(double*)v1.get_i(&v1, i) == i + 0.1);
}


void test_push() {
    vector v1;
    int length1 = 4;
    double a = 1.2;
    int el_size1 = sizeof(double);
    constructor(&v1, el_size1, length1);
    for (int i =0; i < v1.length ; i++)
        *(double*)v1.get_i(&v1, i) = i + 0.1;
    for (int i = 0; i < v1.length ; i++)
        assert(*(double*)v1.get_i(&v1, i) == i + 0.1);
    v1.push_back(&v1, &a);
    assert(*(double*)v1.get_i(&v1, v1.length - 1) == a);
    assert(v1.length == length1 + 1);
}

void test_dell() {
    vector v1;
    int length1 = 4;
    int el_size1 = sizeof(double);
    constructor(&v1, el_size1, length1);
    for (int i =0; i < v1.length ; i++)
        *(double*)v1.get_i(&v1, i) = i + 0.1;
    for (int i =0; i < v1.length ; i++)
       assert(*(double*)v1.get_i(&v1, i) == i + 0.1);
    v1.dell(&v1, 0);
    assert(v1.length == length1 - 1);
    for (int i = 1; i < v1.length ; i++)
        assert(*(double*)v1.get_i(&v1, i - 1) == i + 0.1);
}

/*void test_klei() {
	vector v1;
	int length1 = 4, length2 = 32;
	int el_size1 = 1;
	constructor(&v1, el_size1, length1);

	assert(v1.length == length1 + length2);
	assert(v1.element_size == el_size1);
}*/

