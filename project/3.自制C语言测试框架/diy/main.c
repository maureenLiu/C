/*************************************************************************
	> File Name: main.c
	> Author: Maureen 
	> Mail: Maureen@qq.com 
	> Created Time: 日 10/25 17:09:04 2020
 ************************************************************************/

#include <stdio.h>
#include <include/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testfunc, add) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(2, 3), 4);
    EXPECT_LT(add(4, 5), 8);
    EXPECT_LE(add(5, 3), 9);
}

TEST(test, funcadd) {
    EXPECT_EQ(add(0, 0), 1);
    EXPECT_EQ(add(7, 6), 13);
    EXPECT_GT(add(3, 4), 6);
    EXPECT_GE(add(1, 2), 2);
    EXPECT_NEQ(add(2, 6), 8);
}

TEST(my_test, add) {
    EXPECT_EQ(add(2, 7), 9);
    EXPECT_NEQ(add(2, 3), 6);
}

int main() {    
    return RUN_ALL_TESTS();
}
