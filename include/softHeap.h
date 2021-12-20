//
// Created by zhuangzm on 2021/12/20.
//

#ifndef CS290P_PROJECT_SOFTHEAP_H
#define CS290P_PROJECT_SOFTHEAP_H
#include "head.h"

class Softheap {
    int r;
    Head *header;
    Head *tail;
    Softheap(int r, Head *header, Head *tail);
};
#endif //CS290P_PROJECT_SOFTHEAP_H
