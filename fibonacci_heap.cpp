#include<iostream>
#include<queue>
using namespace std;

class node{
private:
    node* prev;
    node* next;
    node* child;
    node* parent;
    int value;
    int degree;
    bool marked;
public:
    friend class FibHeap; 
    node* getPrev() {return prev;}
    node* getNext() {return next;}
    node* getChild() {return child;}
    node* getParent() {return parent;}
    int getValue() {return value;}
    bool isMarked() {return marked;}

    bool hasChildren() {return child;}
    bool hasParent() {return parent;}
};

class FibHeap {
private:
    node* heap;
    node* _empty(){
        return NULL;
    }

    node* _singleton(int value) {
        node* n = new node;
        n -> value = value; // 访问友元的私有成员
        // n -> prev = n;
        // n -> next = n;
        n->prev = n->next = n;
        n->degree = 0;
		n->marked = false;
		n->child = NULL;
		n->parent = NULL;
        return n;
    }

    node* _nodeMerge(node* a, node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        if(a->value > b->value){
            node* temp = a;
            a = b;
            b = temp;
        }
        node* an = a->next;
        node* bp = b->prev;
        a -> next = b;
        b -> prev = a;
        an -> prev = bp;
        bp -> next = an;
        return a;
    }

    // 析构函数
    void _deleteALL(node* n) {
        if(n != NULL){
            node* c = n;
            do {
                node* d = c;
                c = c -> next;
                _deleteALL(d -> child);
                delete d;
            } while(c != n);
        }
    }

    void _addChild(node* parent, node* child) {
        child -> prev = child -> next = child;
        child -> parent = parent;
        parent -> degree += 1;
        parent -> child = _nodeMerge(parent -> child, child);
    }

    void unMark(node* n){
        if(n == NULL){
            return ;
        }
        node* c = n;
        do {
            c -> marked = false;
            c -> parent = NULL;
            c = c -> next;
        } while(c != n);
    }

    node* _removeMin(node* n) {
        unMark(n -> child);
        if (n -> next == n){
            n = n -> child;
        }
        else{
            n -> next -> prev = n -> prev;
            n -> prev -> next = n -> next;
            n = _nodeMerge(n->next, n->child);
        }

        if(n == NULL){
            return n;
        }
        node* trees[128] = {NULL}; // why is constant ?
        while(true){
            if(trees[n->degree] != NULL){
                node* t = trees[n->degree];
                if(t == n){
                    break;
                }
                trees[n->degree] = NULL;
                if(n->value < t->value){
                    t->prev -> next = t -> next;
                    t->next -> prev = t -> prev;
                    _addChild(n,t);
                }
                else{
                    t->prev->next = t->next;
					t->next->prev = t->prev;
					if(n->next == n) {
						t->next = t->prev = t;
						_addChild(t,n);
						n = t;
					} else {
						n-> prev -> next = t;
						n-> next -> prev = t;
						t-> next = n->next;
						t->prev = n->prev;
						_addChild(t,n);
						n = t;
					}
                    continue;
                }
            }
            else{
                trees[n->degree] = n;
            }
            n = n -> next;
        }
        node* min = n;
		node* start = n;
		do {
			if(n->value < min->value){
                min = n;
            }
			n = n->next;
		} while(n != start);
		return min;
    }

    node* _decreaseKey(node* heap, node* n, int value){
        if(n->value < value){ // 减小值并没有改变堆的结构
            return heap;
        }
        n -> value = value;
        if(n->parent){
            if(n -> value < n -> parent -> value){
                heap = _cut(heap, n);
                node* parent = n -> parent;
                n -> parent = NULL;
                while(parent != NULL && parent -> marked){
                    heap = _cut(heap, parent);
                    n = parent;
                    parent = n -> parent;
                    n -> parent = NULL;
                }
                if(parent != NULL && parent -> parent != NULL){
                    parent -> marked = true;
                }
            }
        }
        else{
            if(n-> value < heap -> value){
                heap = n;
            }
        }
        return heap;
    }

    node* _cut(node* heap,node* n) {
		if(n->next==n) {
			n->parent->child=NULL;
		} else {
			n->next->prev=n->prev;
			n->prev->next=n->next;
			n->parent->child=n->next;
		}
		n->next=n->prev=n;
		n->marked=false;
		return _nodeMerge(heap,n);
	}

public:
    FibHeap() {
        heap = _empty();
    }

    // 析构函数待写

    node* insert(int value){
        node* temp = _singleton(value);
        heap = _nodeMerge(heap, temp);
        return temp; // insert 可否不返回？
    }

    void heapMerge(FibHeap& other){
        heap = _nodeMerge(heap, other.heap);
        other.heap = NULL;
    }

    bool isEmpty(){
        return heap == NULL;
    }
    int pop(){
        node* old = heap;
        heap = _removeMin(heap);
        int result = old -> value;
        delete old;
        return result;
    }

    void decreaseKey(node* n, int value){
        heap = _decreaseKey(heap, n, value);
    }
};

int main(){
    FibHeap my_fib_heap = FibHeap();
    my_fib_heap.insert(6);
    my_fib_heap.insert(7);
    my_fib_heap.insert(8);
    my_fib_heap.insert(9);
    my_fib_heap.insert(10);
    my_fib_heap.insert(11);
    my_fib_heap.insert(12);
    my_fib_heap.insert(13);
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    cout << my_fib_heap.pop() << endl;
    return 0;
}