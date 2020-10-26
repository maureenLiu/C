#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info; //将变量定义放在源文件中，而将声明放在头文件中使用extern修饰，以避免重复定义

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        Function *func = Head(p, Function, p); 
        printf(GREEN("[====RUN====]") RED_HL(" %s") "\n", func->str);
        haizei_test_info.total = 0;//每组测试用例(TEST)执行之前的初始化操作，赋值操作在头文件的EXPECT宏中
        haizei_test_info.success = 0;
        func->func();
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
    //链表的插入
    Function *temp = (Function*)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
} 
