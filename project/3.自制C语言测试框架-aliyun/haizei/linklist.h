/*************************************************************************
	> File Name: linklist.h
	> Author: Maureen 
	> Mail: 1437867946@qq.com 
	> Created Time: Wed 21 Oct 2020 06:56:09 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

//获取name字段的偏移量
#define offset(T, name) (long long)(&(((T *)(0))->name))
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

struct LinkNode {
    struct LinkNode *next;
};

#endif
