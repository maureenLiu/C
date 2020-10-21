#include <stdio.h>
#include "run.h"

int main()
{
	const char *name_program = "./program";
	const char *name_in = "./in.txt";
	const char *name_out = "./out.txt";
	const char *name_right = "./right.txt";
	run(name_program, name_in, name_out);
	FILE *fpright = fopen(name_right, "r");
	FILE *fpout = fopen(name_out, "r");

	// Input your code here.
	char chright;
	char chout;
	while ((chright = fgetc(fpright)) != EOF && (chout = fgetc(fpout)) != EOF) {
		if (chright != chout) {
			printf("Wrong Answer");
			fclose(fpout);
			fclose(fpright);
			return 0;
		}
	}

    if (chright == EOF) { //right.txt先读完
        chout = fgetc(fpout);
        if (chout == EOF) {
            printf("Accept");
        } else if ((chout == '\n' || chout == ' ') && (chout = fgetc(fpout)) == EOF){
            printf("Accept");
        } else {
            printf("Wrong Answer");
        }
    } else if (chout == EOF) { //out.txt先读完
        if ((chright == '\n' || chright == ' ') && (chright = fgetc(fpright)) == EOF) {
            printf("Accept");
        } else {
            printf("Wrong Answer");
        }
    }

	fclose(fpout);
	fclose(fpright);
	return 0;
}
