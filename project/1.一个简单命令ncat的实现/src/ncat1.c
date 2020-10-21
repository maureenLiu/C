#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman.h"

#define ROW_LEN 50
#define LINE_MAX_LEN 80

int main(int argc, char *argv[]) {
  //  printf("输入的参数个数：%d\n", argc);
   // int i;
    //for(i = 0; i < argc; i++) {
     //   printf("第%d个参数是：%s\n", i + 1, argv[i]);
   // } 
	if (argc < 2) exit(-1);
	int row = 1; //行号
	char *roman_row = (char *) malloc (ROW_LEN * sizeof(char)); //分配和行数数字位数相等的空间,该变量用于转换罗马数字
	if(argc == 2) { //标准输入
		char ch;
		int ch_cnt = 0;
		int is_row_print = 1;
		char *str = (char *) malloc (sizeof(char) * 100000);
		char *p = str;
		while(scanf("%c", &ch) != EOF) {
			*p = ch;
			p++;
		}
		*(--p) = '\0';
		char *q = str;
		while(*q != '\0') {
			if(ch_cnt == LINE_MAX_LEN && *q != '\n') {
				printf("\n");
				is_row_print = 1;
				ch_cnt = 0;
			}
			if(is_row_print == 1) {
				if(strcmp(argv[1], "-d") == 0) { //以阿拉伯数字作为行号输出
					printf("%d\t", row++);
				} else if(strcmp(argv[1], "-r") == 0) {
					printf("%s\t", to_roman_numeral(roman_row, row++));
				}
				is_row_print = 0;
			}
			if(*q == '\n') {
				is_row_print = 1;
				ch_cnt = 0;
			}
			printf("%c", *q);
			ch_cnt++;
			q++; 
		}
		printf("\n");
		
		
		//释放分配的堆区空间
		free(str);
		str = NULL;
		free(roman_row);
		roman_row = NULL;
		return 0;
	}
//	printf("Not std input\n");	
    char *in_filename;
	char *out_filename; //如果argc = 3,argv[4]默认会读取到环境变量数组envp中的第一个值
	if (argc == 3) {
		in_filename = argv[2];
		out_filename = NULL;
	}  else {
		in_filename = argv[2];
		out_filename = argv[3];
    }
    //printf("in_filename=%s, out_filename=%s\n", in_filename, out_filename);
    FILE *in_fp = fopen(in_filename, "r");
    FILE *out_fp = fopen(out_filename, "w");
	if(out_fp == NULL) { //没有输出文件，就标准输出
		out_fp = stdout;
	}
   
    char line[LINE_MAX_LEN]; //保存读取一行的信息line数组
	while(fgets(line, sizeof(line), in_fp)) {
		if(strcmp(argv[1], "-d") == 0) { //以阿拉伯数字作为行号输出
			fprintf(out_fp, "%d\t%s", row++, line);
		} else if(strcmp(argv[1], "-r") == 0) { //行号以罗马数字输出
			fprintf(out_fp, "%s\t%s", to_roman_numeral(roman_row, row), line);
			row++;
		}
    }
	//释放分配的堆区空间
	free(roman_row);
	roman_row = NULL;
	
    fclose(in_fp);
    fclose(out_fp);
    return 0;
}

