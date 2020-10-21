/*************************************************************************
	> File Name: main.cpp
	> Author: Maureen 
	> Mail: Maureen@qq.com 
	> Created Time: 五 10/16 18:18:58 2020
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testfunc, add) { //TEST不满足函数的特征，而是一个宏。一个TEST叫做一组测试
    EXPECT_EQ(add(3,4), 7); //一组测试行为
    EXPECT_NE(add(2,3), 5);
    EXPECT_EQ(add(1,2), 4);
}

TEST(testfunc, add2) { //TEST不满足函数的特征，而是一个宏。一个TEST叫做一组测试
    EXPECT_GE(add(3,4), 7); //一组测试行为
    EXPECT_LT(add(2,3), 6);
    EXPECT_EQ(add(1,2), 4);
}

TEST(test, funcadd) { //TEST不满足函数的特征，而是一个宏。一个TEST叫做一组测试
    EXPECT_EQ(add(0,0), 0); //一组测试行为
    EXPECT_EQ(add(2,3), 5);
    EXPECT_EQ(add(1,2), 3);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
