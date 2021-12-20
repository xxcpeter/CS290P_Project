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
    Node() {};
};
#endif //SOFTHEAP_NODE_H
