//
// Created by Lenovo on 13.04.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_create(struct array_t *a, int N){
    if ( N <= 0 || a == NULL )
        return 1;
    a->ptr = malloc(sizeof(int) * N);
    if ( a->ptr == NULL )
        return 2;

    a->capacity = N;
    a->size = 0;
    return 0;
}


int array_push_back(struct array_t *a, int value){
    if (a == NULL || a->ptr == NULL || a->size < 0 || a->capacity <= 0 || a->size > a->capacity)
        return 1;
    if (a->size >= a->capacity)
        return 2;
    *(a->ptr + a->size) = value;
    a->size++;
    return 0;
}

void array_display(const struct array_t *a){
    if (a == NULL || a->ptr == NULL || a->size > a->capacity || a->size <= 0 || a->capacity <= 0)
        return;
    for (int i = 0; i < a->size; i++) {
        printf("%d ", *(a->ptr + i));
    }
    printf("\n");
}
void array_destroy(struct array_t *a){
    if (a == NULL)
        return;
    if (a->ptr != NULL && a != NULL)
        free(a->ptr);

}