//
//  main.c
//  Cprograms
//
//  Created by William Murphy on 2/8/18.
//  Copyright © 2018 William Murphy. All rights reserved.
//


/* Simple Gradient Descent algorithm built in C
   This is just an example of inner workings
   that are contained in common machine learning
   packages.
   However, I will most likely be using this as a
   model to build a more generalized version that
   will be used to develop a fast Python module.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    double y[5] = {1, 3, 7, 13, 21};
    double x[5][2] = {{1, 0},
        {1, 1},
        {1, 2},
        {1, 3},
        {1, 4}
    };
    double theta[2] = {0, 0};
    double alpha = 0.05;
    double epsilon = 0.01;
    double errors[5];
    double y_hat[5];
    double gradient[2] = {0, 0};
    double magnitude;
    int cntr = 0;
    
    // main loop to calculate gradient descent
    do{
        //printf("iteration | %d \n",  cntr++);
        for(int i=0; i < 5; i++){
            //printf("errors: %f ", errors[i]);
        }
        //printf("\n\n");
        for(int i=0; i < 5; i++){
            y_hat[i] = (theta[0]*x[i][0] + theta[1]*x[i][1]);
            //printf(" y_hat[%d] = %f \n ", i, y_hat[i]);
            errors[i] = y_hat[i]-y[i];
            //printf("errors[%d] = %f ", i, errors[i]);
        }
        //printf("\n\n");
        
        for(int i=0; i < 2; i++){
            gradient[i] = 0;
            for(int j=0; j < 5; j++){
                gradient[i] += errors[j]*x[j][i];
                //printf("gradient[%d] = errors[%d]*x[%d][%d] = %f*%f = %f\n", i,j,j,i, errors[j],x[i][j], gradient[i]);
            }
            //printf("\n");
            //printf("gradient[%d] = %f \n", i, gradient[i]);
            theta[i] = theta[i] - (alpha*gradient[i]);
            //printf("updated theta[%d] = %f \n",i, theta[i]);
        }
        //printf("\n\n");
        magnitude = sqrt((gradient[0]*gradient[0])
                 +(gradient[1]*gradient[1]));
        //printf("magnitude = %f \n", magnitude);
        //printf("\n\n");
    
        printf("=================================\n");
        printf("   \t  Iteration %d complete\n", cntr+1);
        printf("=================================\n");
        printf("======Values======\n");
        printf("Theta|  [%f, %f] \n", theta[0], theta[1]);
        printf("\n");
        printf("Errors| [%f, %f, %f, %f, %f]\n", errors[0], errors[1], errors[2], errors[3], errors[4]);
        printf("\n");
        printf("Predictions| [%f, %f, %f, %f, %f]\n", y_hat[0], y_hat[1], y_hat[2], y_hat[3], y_hat[4]);
        printf("\n");
        printf("Gradient| [%f, %f]\n", gradient[0], gradient[1]);
        printf("\n");
        printf("Adjustment| [%f, %f]\n", alpha*gradient[0], alpha*gradient[1]);
        printf("\n");
        cntr++;
    }while(magnitude > epsilon);
    printf("\n");
    printf("Gradient Descent Algorithm converged in %d iterations to theta = [%f, %f]\n\n", cntr, theta[0], theta[1]);

     
    return 0;
}


