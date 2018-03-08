//
//  Vector_c.h
//  Cprograms
//
//  Created by William Murphy on 3/8/18.
//  Copyright © 2018 William Murphy. All rights reserved.
//
//  unfinished vector and matrix c structs for
//  will be used for ML algorithms
//

#ifndef Vector_c_h
#define Vector_c_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#include <assert.h>


#define NAME_BUFFER_SIZE 20

typedef int (*vector)(int);

typedef int (*pass_two_ints)(int, int);

typedef char (*set_name)(int, char);


// base structure vector_c
typedef struct Vector_c {
    double* data;
    int size;
}Vector_c;

// base structure matrix_c
typedef struct Matrix_c {
    double* data;
    int n_row;
    int m_col;
}matrix_c;

// vector constructor
inline void Vec_alloc(Vector_c* vec, int magnitude){
    
    // set the size of the vector
    vec->size = magnitude;
    
    // allocate memory for vector
    vec->data = (double*)malloc(magnitude*sizeof(double));
    
    // set the empty vector values to 000 to indicate an empty vector
    //for(int i=0; i < vec->size; i++){
    //  vec->data[i] = 000;
    //}
    
}

// clear pointers i.e. set to 0 and call the free function
inline void Vec_dealloc(Vector_c* vec){
    if(vec->data != NULL){
        printf("WARNING: vector_c pointer still points to a memory location...\n");
        printf("clearning pointer ...'n");
        vec->data = NULL;
        printf("pointer cleared, releasing allocated memory ... \n");
        free(vec->data);
        printf("allocated memory has been released ...\n");
    }
}

// access vector elements
//typedef double (*vector_element_access)(Vector_c*, int);

inline double getVecelmt(Vector_c* vec, int i){
    if(i >= vec->size){
        printf("ERROR: Vector index access is out of bounds ...\n");
        exit(1);
    }
    else{
        return vec->data[i];
    }
}

// set vector elements
inline void setVecelmt(Vector_c* vec, double value, int i){
    if(i >= vec->size){
        printf("ERROR: Vector index access is out of bounds ...\n");
        exit(1);
    }
    else{
        vec->data[i] = value;
    }
}


#endif /* Vector_c_h */
