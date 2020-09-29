#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman.h"

#define ROW_LEN 50

int main(int argc, char *argv[]) {
	
	if (argc < 2) exit(-1);
	
	char *in_filename = NULL;
	char *out_filename = NULL;
	char *roman_row = (char *) malloc (ROW_LEN * sizeof(char)); //分配和行数数字位数相等的空间,该变量用于转换罗马数字
	int is_roman = 0;
	if (strcmp (argv[1], "-d")) {
		is_roman = 1;
	}	
	if (argc == 3) {
		in_filename = argv[2];
	} else if (argc == 4) {
		in_filename = argv[2];
		out_filename = argv[3];	
	}
	FILE *fpin = in_filename == NULL ? stdin : fopen(in_filename, "r");
	FILE *fpout = out_filename == NULL ? stdout : fopen(out_filename, "w");
	char ch;
	int row = 1; //行号
	int is_row_print = 1;
	while ((ch = fgetc(fpin)) != EOF) {
		if (is_row_print) {
			if (is_roman) {
				fprintf(fpout, "%s\t", to_roman_numeral(roman_row, row));
			} else {
				fprintf(fpout, "%d\t", row);
			}
			is_row_print = 0;
		}
		if (ch == '\n') {
			++row;
			is_row_print = 1;
		}
		fprintf(fpout, "%c", ch);
	}		
	
	//释放分配的堆区空间
	free(roman_row);
	roman_row = NULL;
	
    fclose(fpin);
    fclose(fpout);
    return 0;
}

