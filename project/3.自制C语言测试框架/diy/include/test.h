/*************************************************************************
	> File Name: test.h
	> Author: Maureen 
	> Mail: Maureen@qq.com 
	> Created Time: 日 10/25 17:12:01 2020
 ************************************************************************/
#include <include/linklist.h>

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define RED(a)   COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BULE(a) COLOR(a, 34)

#define RED_HL(a)   COLOR_HL(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define BLUE_HL(a) COLOR_HL(a, 34)

#define TEST(a, b)\
void a##_maureen_##b();\
__attribute__((constructor)) void add##_maureen_##a##__maureen_##b() {\
    add_function(a##_maureen_##b, #a"."#b);\
}\
void a##_maureen_##b()

#define TYPE(a) _Generic((a),\
    long long : "%lld",\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    char : "%c",\
    char * : "%s",\
    const char * : "%s"\
)

#define P(a, color) {\
    char frm[100];\
    sprintf(frm, color("%s"), TYPE(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    function_info.total += 1;\
    if ((a) comp (b)) function_info.success += 1;\
    else {\
        __typeof(a) _a = (a);\
        __typeof(b) _b = (b);\
        printf("\n" YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n"));\
        printf(YELLOW_HL("\t\tactual : "));\
        P(_a, YELLOW_HL);\
        printf(YELLOW_HL(" vs "));\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------] ") #a " " #comp " " #b);\
    printf(" %s\n", (a) comp (b) ? GREEN_HL("true") : RED_HL("false"));\
} 

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NEQ(a, b) EXPECT(a, b, !=)

struct FunctionInfo {
    int total;
    int success;
};
extern struct FunctionInfo function_info;

int RUN_ALL_TESTS();

typedef void (*TestFunc)();
typedef struct Function {
    struct LinkNode node; 
    TestFunc func;
    const char *str;
} Function;
void add_function(TestFunc, const char *);

#endif
