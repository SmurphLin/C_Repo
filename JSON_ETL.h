//
// Created by William Murphy on 3/18/18.
//

#ifndef ETL_C_JSON_ETL_H
#define ETL_C_JSON_ETL_H

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1000


void parseJSON(char filename[]){

    // set the name of the file
    char *f_name;
    f_name = filename;
    //char *js_file = json_file;
    //int file_cntr = 0;
    //char json[100];          /* allocated 100 bytes to json array */

    // open file for reading
    FILE *read_file = fopen(f_name, "r");
    if(!read_file){
        fprintf(stderr, "ERROR: file could not be opened ... exiting\n");
        exit(1);
    }

    // allocate 1000 bytes of memory to store JSON
    char *json_stream = (char*)malloc(BUFFER*sizeof(char));


    char c;                          /* read each character of the file */
    int buffer_counter = 0;          /* get the current buffer size */
    int n = 1;                       /* used to increase buffer size */
    int num_open_brackets = 0;       /* count number of open brackets */
    int i;                           /* holds the position in the json file */
    //int current;                     /* current i position */
    //int previous = 0;                /* previous i position */
    int n_json_files = 0;            /* counter for number of json files */


    // while not finished reading through the JSON file
    while((c = getc(read_file)) != EOF){

        ++buffer_counter;
        // if buffer_counter is larger than allocated buffer
        if(buffer_counter >= n*BUFFER*sizeof(char)){

            n++;
            printf("buffer increased to %d\n", n*BUFFER*sizeof(char));
            char *new_json_stream = (char*)realloc(json_stream, n*BUFFER*sizeof(char));

            // reset the buffer counter
            buffer_counter = 0;

           // if there is no memeory left to allocate
            if(!new_json_stream){
                fprintf(stderr, "ERROR: No memory left to allocate\n");
                exit(1);
            }

            // json_stream points to new_json_stream
            json_stream = new_json_stream;
        }

        // increment
        if(c == '{'){num_open_brackets++;}

        // decrement
        if(c == '}'){num_open_brackets--;}

        if(num_open_brackets == 0 && i != 0){
            *(json_stream + i) = '}';
            n_json_files++;
            if(n_json_files == 1){

                // allocate the precise number of bytes to the json output stream
                char *json_stream_out = (char*)malloc(i*sizeof(char));
                //previous = i; // 1000 bytes
                for(int m = 0; m <= i* sizeof(char); m++){
                    *(json_stream_out + m) = *(json_stream + m);
                }
                FILE *f_write;
                f_write = fopen("json.txt", "w");

                // write the file to location
                fwrite(json_stream_out, i, sizeof(json_stream_out), f_write);
                fclose(f_write);
                // free allocated memory
                free(json_stream_out);
                json_stream_out = NULL;
                break;
            }

        }
        // insert the next char into allocated memory
        *(json_stream + i) = c;
        i++;    /* increase char count by one */
    }
    // release allocated memory
    free(json_stream);
    json_stream = NULL;

}


#endif //ETL_C_JSON_ETL_H
