//
// Created by William Murphy on 3/18/18.
//
// fileLength:
//      int: returns the number of bytes in entire JSON stream
//
// numJSONrecords:
//      int: returns the number of complete JSON records
//              contained within the file stream
//
// TODO:
//      ADD:
//      function:
//      returns: array the size of number of complete
//                  JSON files
//
//      function:
//      returns: exact allocation of bytes per JSON file
//
//

#ifndef ETL_C_ETL_TEST_C_H
#define ETL_C_ETL_TEST_C_H


#include <stdio.h>

#define FILENAME "/Users/williammurphy/Downloads/ls.s3.0.0.0.0.2018-03-14T00.01.tag_http-prefix-tag-2.part4231.txt"



int fileLength(){

    FILE *f;
    f = fopen(FILENAME, "r");

    char c;
    int cntr = 0;

    while ((c = getc(f)) != EOF){
        cntr++;
        printf("current character: %c\n \tcounter: %d\n", c, cntr);
    }

    fclose(f);
    return cntr;
}


int numJSONrecords(){

    int num_recs = 1;
    char c;
    int c_cntr = 0;
    int previous = 0;
    int current = 0;
    int c_cntr_copy = c_cntr;
    int num_brackets = 0;

    FILE *file;
    file = fopen(FILENAME, "r");
    while ((c = getc(file)) != EOF){

        if(c_cntr_copy == 0 && c != '{'){
            fprintf(stderr, "ERROR: JSON file not correctly formatted\n");
            exit(1);
        }

        if(c == '{'){
            num_brackets++;
            printf("\tNUMBER OF OPENING BRACKETS: %d\n", num_brackets);
        }

        if(c == '}'){
            num_brackets--;
            printf("\tNUMBER OF OPENING BRACKETS: %d\n", num_brackets);
        }

        if(num_brackets <= 0 && c_cntr_copy > 0){
            num_recs++;
            current = c_cntr;

            printf("\t number of chars: %d\n", c_cntr);
            printf("COMPLETE JSON FILE: increasing json file counter to %d\n", num_recs);
            printf("JSON FILE BYTE SIZE: %d\n", current-previous);
            // next char should be '{' if JSON file format is correct
            previous = current;
            num_brackets = 0;
            c_cntr_copy = 0;
        }
        else {
            //c_cntr++;
            c_cntr_copy++;
        }
        c_cntr++;
    }

    return num_recs-1;
}





#endif //ETL_C_ETL_TEST_C_H
