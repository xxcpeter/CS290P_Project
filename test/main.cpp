//
// Created by zhuangzm on 2021/12/20.
//

#include <iostream>
#include <queue>
#include "softHeap.h"
using namespace std;


int main() {
    int r;
    cin >> r;
    Softheap sh = Softheap(r);
    priority_queue<int, vector<int>, greater<>> pq;
    int i = 1, value, iCount = 0, dCount = 0;
    char op;
    while (cin >> op){
        bool exit = false;
        switch(op){
            case 'i':
                cin >> value;
                sh.insert(value);
                cout << i++ << ": insert " << value << endl;
                iCount++;
                break;
            case 'd':
                if (iCount == dCount) {
                    cout << "Empty heap!" << endl;
                    break;
                }
                value = sh.deleteMin();
                cout << i++ << ": delete " << value << endl;
                dCount++;
                break;
            case 'p':
                cout << i++ << ": print heap" << endl;
                sh.printSoftheap();
                break;
            case 'e':
                cout << i++ << ": exit" << endl;
                cout << "insert: " << iCount << endl;
                cout << "delete: " << dCount << endl;
                exit = true;
                break;
            default:
                break;
        }
        if (exit) break;
    }
}