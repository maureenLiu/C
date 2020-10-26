#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int func_cnt = 0; //记录函数的个数
Function func_arr[100];//函数类型的数组
struct FunctionInfo haizei_test_info; //将变量定义放在源文件中，而将声明放在头文件中使用extern修饰，以避免重复定义
int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN("[====RUN====]") RED_HL(" %s") "\n", func_arr[i].str);
        haizei_test_info.total = 0;//每组测试用例(TEST)执行之前的初始化操作，赋值操作在头文件的EXPECT宏中
        haizei_test_info.success = 0;
        func_arr[i].func();
        double rate = 100 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) { //判断浮点数两个数是否相等
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]") " total:%d  success:%d\n", haizei_test_info.total, haizei_test_info.success);
    }

    return 0;
}

//func为函数指针变量
void add_function(TestFunc func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //strdup函数的所用：将原字符串拷贝一份，将拷贝份的地址赋给其他变量，避免对原字符串进行操作
    func_cnt++;
    return ;
} 
