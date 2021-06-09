#include "actionvector.h"



void* get_i(vector* v, int index)
{
    return (void*)((index * v->element_size) + (char*)v->mus);
}

void dell(vector* tmp, int index)
{
    if (index < 0) {
        printf("ERROR, index need to be biggest or equally 0");
        return;
    }
    else {
        for (int i = index; i < tmp->length - 1; i++) {
            char* a = (char*)get_i(tmp, i);
            char* b = (char*)get_i(tmp, i + 1);
            for (int j = 0; j < tmp->element_size; j++)
                *(a + j) = *(b + j);
        }
        tmp->length -= 1;
        tmp->mus = (void*)realloc(tmp->mus, tmp->element_size * (tmp->length));
    }
}

void push_back(vector* tmp, void* element) {
    tmp->mus = realloc(tmp->mus, tmp->element_size * (tmp->length + 1));
    for (int j = 0; j < tmp->element_size; j++)
        *((char*)get_i(tmp, tmp->length) + j) = *((char*)element + j);
    tmp->length += 1;
}

int check_index(vector* tmp, void* maselement,  void* element) {
    int k = 0;
    for (int i = 0; i < tmp->element_size; i++)
        if (*((char*)maselement + i) == *((char*)element + i))
            k++;
    if (k == tmp->element_size) return 1;
    else
        return 0;
}

int search_index(vector tmp, void* element) {
    int j = 0, k = -1;
    for (j = 0; tmp.length > j; j++)
        if (check_index(&tmp, tmp.get_i(&tmp, j), element)){
            return j;
    }
}

void concat(vector* v1, vector* v2){
    v1->mus = (void*)realloc(v1->mus, v1->element_size * (v1->length + v2->element_size));
    for (int i = 0; i < )
};

void constructor(vector* typicalvector, int size_element, int length) {
    typicalvector->length = length;
    typicalvector->element_size = size_element;
    typicalvector->push_back = push_back;
    typicalvector->dell = dell;
    typicalvector->get_i = get_i;
    typicalvector->concat = concat;
    typicalvector->search_index = search_index;
    typicalvector->mus = (void*)calloc(typicalvector->length, typicalvector->element_size);
}