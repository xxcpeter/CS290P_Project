//
// Created by zhuangzm on 2021/12/20.
//

#ifndef SOFTHEAP_HEAD_H
#define SOFTHEAP_HEAD_H
#include "node.h"

class Head {
    int rank;
    Node *queue;
    Head *next;
    Head *prev;
    Head *suffix_min;
    Head() {};
};
#endif //SOFTHEAP_HEAD_H
