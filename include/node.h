//
// Created by zhuangzm on 2021/12/20.
//

#ifndef SOFTHEAP_NODE_H
#define SOFTHEAP_NODE_H
#include "ilcell.h"

class Node {
public:
    int ckey;
    int rank;
    Ilcell *il_head;
    Ilcell *il_tail;
    Node *next;
    Node *child;

    Node() :
        ckey(0),
        rank(0),
        il_head(nullptr),
        il_tail(nullptr),
        next(nullptr),
        child(nullptr) {}

    Node(int k, int r, Ilcell *il_h, Ilcell *il_t) :
        ckey(k),
        rank(r),
        il_head(il_h),
        il_tail(il_t),
        next(nullptr),
        child(nullptr) {}

    Node(int k, int r, Ilcell *il_h, Ilcell *il_t, Node *n, Node *c) :
        ckey(k),
        rank(r),
        il_head(il_h),
        il_tail(il_t),
        next(n),
        child(c) {}
};
#endif //SOFTHEAP_NODE_H
