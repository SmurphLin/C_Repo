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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// define the structure abstractly
typedef struct C_Vector{
    double *data_;
    int size_;

}C_Vector;

// init the struct
void Vector_Alloc(C_Vector* in, const int sz){
    in->size_ = sz;
    in->data_ = (double*)malloc(sz* sizeof(double));
    assert(in->data_ != NULL);
}

// set data
void set_data(C_Vector* in, int i, double value){
   assert(i >= 0 && i < in->size_);
    in->data_[i] = value;
}

// print vector values
void vector_print(C_Vector* in){
    for(int i=0; i < in->size_; i++){
        printf("|%f|\n", in->data_[i]);
    }
}

// vector addition(must take 2 vectors and return a new vector)
void sum_C_Vector(C_Vector* x, const C_Vector* y, const C_Vector* z){
    // check for length equality
    assert(x->size_ == y->size_);
    assert(y->size_ == z->size_);
    for(int i=0; i < z->size_; ++i){
        x->data_[i] = (y->data_[i]+z->data_[i]);
    }
}

// dot product
double c_dot(C_Vector* x, C_Vector* y){
    assert(x->size_ == y->size_);
    double sum_dot = 0.0;
    for(int i=0; i < x->size_; i++){
        sum_dot += (x->data_[i]*y->data_[i]);
    }
    assert(sum_dot >= 0.0);
    return sum_dot;
}

// zeros vector
void c_zeros(C_Vector* x){
    assert(x->size_ > 0);
    assert(x->data_ != NULL);
    for(int i=0; i < x->size_; i++){
        x->data_[i] = 0.0;
    }
}

// ones vector
void c_ones(C_Vector* x){
    assert(x->size_ > 0);
    assert(x->data_ != NULL);
    for(int i=0; i < x->size_; i++){
        x->data_[i] = 1.0;
    }
}

// scalar multiplication
void scale(C_Vector* x, double scaler){
    assert(x->size_ > 0);
    for(int i=0; i< x->size_; i++){
        x->data_[i] = scaler*(x->data_[i]);
    }
}

#endif /* Vector_c_h */
