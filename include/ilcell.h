//
// Created by zhuangzm on 2021/12/20.
//

#ifndef SOFTHEAP_ILCELL_H
#define SOFTHEAP_ILCELL_H
class Ilcell {
public:
    int key;
    Ilcell *next;
    Ilcell() {};
    Ilcell(int key) :
        key(key),
        next(nullptr) {}
};
#endif //SOFTHEAP_ILCELL_H
