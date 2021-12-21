//
// Created by zhuangzm on 2021/12/20.
//

#ifndef SOFTHEAP_HEAD_H
#define SOFTHEAP_HEAD_H
#include "node.h"

class Head {
public:
    int rank;
    Node *queue;
    Head *next;
    Head *prev;
    Head *suffix_min;

    Head() :
        rank(0),
        queue(nullptr),
        next(nullptr),
        prev(nullptr),
        suffix_min(nullptr) {}

    Head(int r) :
        rank(r),
        queue(nullptr),
        next(nullptr),
        prev(nullptr),
        suffix_min(nullptr) {}
};
#endif //SOFTHEAP_HEAD_H
