//
// Created by zhuangzm on 2021/12/20.
//

#include <iostream>
#include "softHeap.h"
using namespace std;

Softheap::Softheap(int r) {
    m_header = new Head();
    m_tail = new Head();
    m_tail->rank = INF;
    m_header->next = m_tail;
    m_tail->prev = m_header;
    m_r = r;
}


void Softheap::meld(Node *q) {
    // Find the minimum Head where r(Head)>r(q)
    Head *prevHead, *toHead = m_header->next;
    while (q->rank > toHead->rank) toHead = toHead->next;
    prevHead = toHead->prev;

    // Conflict when equal rank
    while (q->rank == toHead->rank) {
        Node *top, *bottom;
        if (q->ckey < toHead->queue->ckey) {
            top = q;
            bottom = toHead->queue;
        } else {
            top = toHead->queue;
            bottom = q;
        }
        q = new Node(top->ckey, top->rank+1, top->il_head,
                     top->il_tail, top, bottom);
        toHead = toHead->next;
    }

    // Insert the new softQueue into current heap
    Head *h;
    if (prevHead == toHead->prev) h = new Head();
    else h = prevHead->next;
    h->queue = q;
    h->rank = q->rank;
    h->prev = prevHead;
    h->next = toHead;
    prevHead->next = h;
    toHead->prev = h;
    fix_minList(h);
}


void Softheap::insert(int newKey) {
    // Create a softQueue with only one Node
    Ilcell *l = new Ilcell(newKey);
    Node *q = new Node(newKey, 0, l, l);

    meld(q);
}


int Softheap::deleteMin() {
    Head *h = m_header->next->suffix_min;
    while (h->queue->il_head == nullptr) {
        Node *tmp = h->queue;
        int childCount = 0;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
            childCount++;
        }

        // remove tree if not rank-invariant (too few children)
        if (childCount < h->rank/2) {
            h->prev->next = h->next;
            h->next->prev = h->prev;
            fix_minList(h->prev);

            // then meld back its children
            tmp = h->queue;
            while (tmp->next != nullptr) {
                meld(tmp->child);
                tmp = tmp->next;
            }
        } else {
            h->queue = sift(h->queue);
            if (h->queue->ckey == INF) {
                h->prev->next = h->next;
                h->next->prev = h->prev;
                h = h->prev;
            }
            fix_minList(h);
        }
        h = m_header->next->suffix_min;
    }

    // delete the min ckey
    int min = h->queue->il_head->key;
    h->queue->il_head = h->queue->il_head->next;
    if (h->queue->il_head == nullptr) h->queue->il_tail = nullptr;
    return min;
}


void Softheap::fix_minList(Head *h) {
    Head *tmpMin;
    if (h->next == m_tail) tmpMin = h;
    else tmpMin = h->next->suffix_min;
    while (h != m_header) {
        if (h->queue->ckey < tmpMin->queue->ckey) tmpMin = h;
        h->suffix_min = tmpMin;
        h = h->prev;
    }
}


Node* Softheap::sift(Node *v) {
    v->il_head = nullptr;
    v->il_tail = nullptr;
    // whether v is a leaf
    if (v->next == nullptr && v->child == nullptr) {
        v->ckey = INF;
        return v;
    }

    v->next = sift(v->next);

    // next-invariant (next->ckey < child->ckey)
    if (v->next->ckey > v->child->ckey) swap(v->next, v->child);

    v->il_head = v->next->il_head;
    v->il_tail = v->next->il_tail;
    v->ckey = v->next->ckey;

    // loop-condition
    if (v->rank > m_r && (v->rank % 2 == 1 || v->child->rank <= v->rank - 2)) {

        v->next = sift(v->next);

        // check again after sift
        if (v->next->ckey > v->child->ckey) swap(v->next, v->child);

        // Concatenate v->next->il with v->il
        if (v->next->ckey != INF && v->next->il_head != nullptr) {
            v->next->il_tail->next = v->il_head;
            v->il_head = v->next->il_head;
            if (v->il_tail == nullptr) v->il_tail = v->next->il_tail;
            v->ckey = v->next->ckey;
        }
    }

    // remove the node with INF ckey
    // do not update rank ???
    if (v->child->ckey == INF) {
        if (v->next->ckey == INF) {
            v->child = nullptr;
            v->next = nullptr;
        } else {
            v->child = v->next->child;
            v->next = v->next->next;
        }
    }
    return v;
}
