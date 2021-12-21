//
// Created by zhuangzm on 2021/12/21.
//

#include <iostream>
#include <queue>
#include <ctime>
#include "softHeap.h"
using namespace std;

const int N = 100000;


int main() {
    clock_t start, end;
    double cost;
    int r;
    cin >> r;
    Softheap sh = Softheap(r);
    priority_queue<int, vector<int>, greater<>> pq;
    int data[N],shOut[N], pqOut[N];

    // Generate data
    for (int i = 0; i < N; ++i)
        data[i] = rand();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout << "Soft Heap: " << endl;
    start = clock();
    for (int i = 0; i < N; ++i)
        sh.insert(data[i]);
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\tInsert: " << cost * 1000 << "ms" << endl;

    start = clock();
    for (int i = 0; i < N; ++i) {
        sh.deleteMin();
//        shOut[i] = sh.deleteMin();
    }
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\tDelete: " << cost * 1000 << "ms" << endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout << "Priority Queue: " << endl;
    start = clock();
    for (int i = 0; i < N; ++i)
        pq.push(data[i]);
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\tInsert: " << cost * 1000 << "ms" << endl;

    start = clock();
    for (int i = 0; i < N; ++i) {
        pq.pop();
//        pqOut[i] = pq.top();
//        pq.pop();
    }
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\tDelete: " << cost * 1000 << "ms" << endl;

//    int error = 0;
//    for (int i = 0; i < N; ++i)  error += (shOut[i] != pqOut[i]);
//    cout << "Error rate: " << (double)error/N;

    return 0;
}