/*************************************************************************
	> File Name: test.c
	> Author: Maureen 
	> Mail: Maureen@qq.com 
	> Created Time: 日 10/25 17:23:50 2020
 ************************************************************************/
#include <stdio.h>
#include <include/test.h> 
#include <string.h>
#include <math.h>
#include <stdlib.h>

Function func_head, *func_tail = &func_head;
struct FunctionInfo function_info;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.node.next; p; p = p->next) {
        Function *func = (Function *)p;
        printf(GREEN_HL("[====RUN====]") RED(" %s\n"), func->str);
        function_info.total = 0;
        function_info.success = 0;
        func->func();
        double rate = 100 * function_info.success / function_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]") " total:%d success:%d\n", function_info.total, function_info.success);
    }
    return 0;
}

void add_function(TestFunc func, const char *name) {
    Function *temp = (Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(name);
    func_tail->node.next = &(temp->node);
    func_tail = temp;
}

