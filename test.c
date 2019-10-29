#include <stdlib.h>
#include <stdio.h>
#include "libreria.h"
#include <string.h>

int main (int argc, char **argv) {

    //Variable declaration and initializing.
    int lines, successStatus = 1;

    //Arguments control and information for the user on how to use the implemented functionality.
	if ((argc == 3) || (argc == 2)) {

        if (argc != 3) lines = 10;
        else {
            if (argv[2][0] == '-')
                lines = atoi(argv[2] + 1);
            else {
                fprintf(stderr,"ERROR: Wrong syntax or arguments.\n");
                fprintf(stderr,"Usage: \"%s [head|tail|longlines] -N\" for showing the longest N lines, or \"%s [head/tail/longlines]\" for the longest 10.\n", argv[0], argv[0]);
                exit(successStatus);
            }
        }

        if (strcmp(argv[1], "head") == 0) {
            successStatus = head(lines);
        }
        else if (strcmp(argv[1], "tail") == 0) {
            successStatus = tail(lines);
        }
        else if (strcmp(argv[1], "longlines") == 0) {
            successStatus = longlines(lines);
        }
        else {
            fprintf(stderr,"ERROR: Wrong syntax or arguments.\n");
            fprintf(stderr,"Usage: \"%s [head|tail|longlines] -N\" for showing the longest N lines, or \"%s [head/tail/longlines]\" for the longest 10.\n",argv[0], argv[0]);
        }

        exit(successStatus);
    }
	else {
        fprintf(stderr,"ERROR: Wrong syntax or arguments.\n");
		fprintf(stderr,"Usage: \"%s [head|tail|longlines] -N\" for showing the longest N lines, or \"%s [head/tail/longlines]\" for the longest 10.\n", argv[0], argv[0]);
		exit(successStatus);
	}
}
