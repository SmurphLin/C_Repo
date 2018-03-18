//
// Created by William Murphy on 3/17/18.
//



#ifndef ETL_C_ETL_C_H
#define ETL_C_ETL_C_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER 1000

// set the name of the file
//char* setFileName(char filename[]){

   // return filename;

//}


// split json files into separate .txt files
void configureJSON(char filename[]){

    char *f_name;
    f_name = filename;


    // open the file for reading
    FILE *read_file = fopen(f_name, "r");
    if(!read_file){
        fprintf(stderr, "ERROR: file |%s| could not be opened ... exiting\n");
        exit(1);
    }

    // allocate 1000 bytes of memory to store the file(EDIT: changed json_feed to json_stream)
    char* json_stream = (char*)malloc(BUFFER* sizeof(char));
    char c;
    int buffr_cntr = 0;
    int i = 0;
    int j = 0;
    int num_chars = 0;
    int n_open_brakets = 0;
    int n = 1;
    int file_cntr = 0;

    // while not finished reading through the JSON file
    while ((c = getc(read_file)) != EOF){

        ++buffr_cntr;
        //printf("buffr_cntr = %d\n", buffr_cntr);

        if(buffr_cntr >= BUFFER*sizeof(char)){

            n++;
            printf("buffer increased to %d\n", n*BUFFER*sizeof(char));
            char* new_json_stream = (char*)realloc(json_stream, n*BUFFER*sizeof(char));

            // if there isn't any memory to allocate
            if(!new_json_stream){
                fprintf(stderr, "ERROR: Not enough memory for reallocation...exiting\n");
                exit(1);
            }

            // json_stream points to new_json_stream
            json_stream = new_json_stream;
        }

        // increment
        if(c == '{') {n_open_brakets++;}

        // decrement
        if(c == '}') {n_open_brakets--;}

        if(n_open_brakets == 0 && i != 0){
            *(json_stream + i) = '}';

            // calculate number of chars
            printf("number of chars read = %d\n", i);
            num_chars = file_cntr;
            char json_files[100];
            sprintf(json_files, "/Users/williammurphy/Desktop/json/json_stream_%d.txt", ++file_cntr);
            FILE *f_write;
            f_write = fopen(json_files, "w");
            if(!f_write){
                fprintf(stderr, "ERROR: File stream could not be written!\n");
                exit(1);
            }
            if(num_chars == 1) {
                fwrite(json_stream, i*sizeof(json_stream), sizeof(json_stream), f_write);
                j = i;
            }
            else if(num_chars > 1){
                int diff = i-j;
                fwrite(json_stream, diff*sizeof(json_stream), sizeof(json_stream), f_write);
                j = i;
            }
            // close the write file
            fclose(f_write);
        }

        // insert the next char into allocated memory
        *(json_stream + i) = c;
        i++;

    }

    //printf("%s",json_stream);


}


#endif //ETL_C_ETL_C_H

// from JSON_ETL header file
/*
if(n_json_files > 1){
current = i - previous;
char *json_stream_out = (char*)malloc(current*sizeof(char));
for(int m = 0; m < current; m++){
*(json_stream_out + m) = *(json_stream + i);
}
FILE *f_write;
f_write = fopen("json.txt", "w");

// write the file to location
fwrite(json_stream_out, current, sizeof(json_stream_out), f_write);
fclose(f_write);
// free allocated memory
//free(f_write);
//f_write = NULL;
previous = i; // new byte count
}*/