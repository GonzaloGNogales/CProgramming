#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH 1024

int head (int n) {
    int lines = n, i = 0;
    //Buffer declaration for holding the input until it is used.
    char buffer[BUFFER_LENGTH];

    //Shows the input taken form the standard mode input until it receives a NULL entry or i index reaches the number of lines the user wants to show.
    while ((i < lines) && (fgets(buffer,1024, stdin) != NULL)) {
        fprintf(stdout,"%s",buffer);
        i++;
    }

    //Exit 0 Success mode.
    exit(0);
}

int tail (int n) {
    int lines = n, i = 0, j, reallocationIndex, usingAlgorithm = 0;
    //Buffer declaration for holding the input until it is used.
    char buffer[BUFFER_LENGTH];

    //Unique memory reserve of the entire string pointer that will set the needed memory just once for maximizing optimization.
    char **stringOut = (char **) malloc(lines*sizeof(char *));

    //While the standard input keeps receiving entries this algorithm won't stop.
    while (fgets(buffer,BUFFER_LENGTH, stdin) != NULL) {
        if (i == lines) {
            //Loop for making room for the next entry coming from the standard input maximizing optimal memory usage. (NOT WASTING MEMORY NEEDLESSLY).
            for (reallocationIndex = 0; reallocationIndex < lines-1; reallocationIndex++) {
                strcpy(stringOut[reallocationIndex], stringOut[reallocationIndex+1]);
            }
            i--;

            //Integer variable initialized to zero for controlling when the reallocation loop is starting for optimization.
            usingAlgorithm = 1;
        }

        //This condition is for not keeping reserving space all the time in the 9th pos of the memory pointer (optimization).
        if (usingAlgorithm != 1) {
            stringOut[i] = (char *) malloc(BUFFER_LENGTH*sizeof(char)); //Reserves with malloc the memory for a BUFFER_LENGTH string input.
        }

        //Puts the input gotten from a file or keyboard (standard mode) into its reserved memory location.
        strcpy(stringOut[i], buffer);
        i++;
    }

    //Loop for showing the result of the program on screen or on a file if wanted (standard output).
    for (j = 0; j < i; j++) {
        fprintf(stdout,"%s",stringOut[j]);
    }

    //Frees the memory reserved for the buffer and the output.
    free(stringOut);
    //Exit 0 Success mode.
    exit(0);
}

int longlines (int n) {
    int lines = n, i = 0, j, k, t, p, controlFirst = 0, countLowerOrEqual = 0, reallocationDone, memoryFulfilledOnce = 0;
    //Buffer declaration for holding the input until it is used.
    char buffer[BUFFER_LENGTH];

    char **stringOut = (char **) malloc(lines*sizeof(char *));

    while ((i < lines) && (fgets(buffer,BUFFER_LENGTH, stdin) != NULL)) {
        if (controlFirst == 0) {
            for (t = 0; t < lines; t++)
                stringOut[t] = (char *) malloc(BUFFER_LENGTH*sizeof(char)); //Reserves with malloc the memory for all BUFFER_LENGTH string inputs.

            strcpy(stringOut[i], buffer);
        }
        else {
            countLowerOrEqual = 0;
            reallocationDone = 0;

            for (k = 0; k < i; k++) {
                if (reallocationDone == 0) {
                    if (strlen(buffer) > strlen(stringOut[k])) {
                        if (i != lines-1) {
                            for (p = i; p >= k; p--)
                                strcpy(stringOut[p + 1], stringOut[p]);

                            strcpy(stringOut[k], buffer);
                            reallocationDone = 1;
                        }
                        else {
                            for (p = i-1; p >= k; p--)
                                strcpy(stringOut[p + 1], stringOut[p]);

                            strcpy(stringOut[k], buffer);
                            reallocationDone = 1;
                        }
                    }
                    else
                        countLowerOrEqual++;
                }
            }
        }


        if (i != lines-1) {
            if (memoryFulfilledOnce == 0) {
                if (countLowerOrEqual == i) {
                    strcpy(stringOut[i], buffer);
                }
            }

            i++;
        }
        else {
            memoryFulfilledOnce = 1;
            i--;
        }

        controlFirst = 1;
    }

    //Loop for showing the result of the program on screen or on a file if wanted (standard output).
    for (j = 0; j < lines; j++) {
        fprintf(stdout,"%s",stringOut[j]);
    }

    //Frees the memory reserved for the buffer and the output.
    free(stringOut);
    //Exit 0 Success mode.
    exit(0);
}

