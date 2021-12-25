//
// Created by zhuangzm on 2021/12/21.
//

#ifndef CS290P_PROJECT_SOFTHEAP_H
#define CS290P_PROJECT_SOFTHEAP_H
#include "ilcell.h"
#include "node.h"
#include "head.h"
const int INF = INT32_MAX;


class Softheap {
public:
    // Create a new softHeap with corruption degree r
    explicit Softheap(int r);
    // Meld q into current heap
    void meld(Node *q);
    // Insert newKey into current heap
    void insert(int newKey);
    // Pop out the smallest ckey
    int deleteMin();
    // Find the smallest ckey
    int findMin();
    // Delete the node or item if exist
    bool del(int key);

private:
    int m_r;        // rank
    Head *m_header;  // header of heads
    Head *m_tail;    // tail of heads

    // Find the new suffix_min in Head
    void fix_minList(Head *h);
    // Rearrange the tree when deleting
    Node* sift(Node *v);
};
#endif //CS290P_PROJECT_SOFTHEAP_H
