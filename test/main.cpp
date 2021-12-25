//
// Created by zhuangzm on 2021/12/20.
//

#include <iostream>
#include "softHeap.h"
using namespace std;


int main() {
    int r;
    cin >> r;
    Softheap sh = Softheap(r);
    int i = 1, iCount = 0, dCount = 0, pCount = 0;
    char op;
    while (cin >> op){
        bool exit = false;
        int value;
        switch(op){
            case 'i':
                cin >> value;
                sh.insert(value);
                cout << i++ << ": insert " << value << endl;
                iCount++;
                break;
            case 'f':
                if (iCount == pCount + dCount) {
                    cout << "Empty heap!" << endl;
                    break;
                }
                value = sh.findMin();
                cout << i++ << ": findMin " << value << endl;
                pCount++;
                break;
            case 'd':
                cin >> value;
                if (sh.del(value))
                    cout << i++ << ": delete " << value << endl,dCount++;
                else
                    cout << i++ << ": delete " << value << " not found" << endl;
                break;
            case 'p':
                if (iCount == pCount + dCount) {
                    cout << "Empty heap!" << endl;
                    break;
                }
                value = sh.deleteMin();
                cout << i++ << ": pop " << value << endl;
                pCount++;
                break;
            case 'e':
                cout << i++ << ": exit" << endl;
                cout << "insert: " << iCount << endl;
                cout << "delete: " << dCount << endl;
                cout << "pop: " << pCount << endl;
                exit = true;
                break;
            default:
                break;
        }
        if (exit) break;
    }
}