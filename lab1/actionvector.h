#pragma once
#include <stdio.h>
#include <string.h>



/*
dellete element
append element
sort
write for index
map
glue massives

*/

struct vector;

typedef struct vector
        vector;

struct vector {
    // core
    void* mus;
    int length;
    int element_size;

    // interface
    void* (*get_i)(vector *v, int index);
    void (*dell)(vector* v, int index);
    void (*push_back)(vector* v, void* element);
    int (*search_index)(vector v, void* element);
    //setindex;
    void (*concat )(vector* v1, vector* v2);
    vector (*map)(vector v, void*(*f)(void*));
};


void constructor(vector* typicalvector, int size_element, int length);