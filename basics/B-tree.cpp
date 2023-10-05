#include <iostream>
using namespace std;
const int M = 4;
const int MM = M - 1;
const int MM2 = MM / 2;
struct node {
    int n;
    int key[M];
    node* child[M];
    node() {
        n = 0;
        for (int i = 0; i < M; ++i) {
            child[i] = NULL;
        }
    }
};
node* root = new node();
void split(node* p, int n) {
    node* q = new node();
    q->n = MM2 - 1;
    for (int i = 0; i < MM2 - 1; ++i) {
        q->key[i] = p->key[i + MM2];
        q->child[i] = p->child[i + MM2];
    }
    q->child[MM2 - 1] = p->child[MM - 1];
    p->n = MM2 - 1;
    for (int i = n; i >= 0; --i) {
        p->key[i + 1] = p->key[i];
        p->child[i + 1] = p->child[i];
    }
    p->key[n] = q->key[0];
    p->child[n + 1] = q;
}
void insert(node* p, int k) {
    if (!p) {
        return;
    }
    int n = p->n;
    if (n == MM - 1) {
        split(p, n);
        insert(p, k);
        return;
    }
    while (n >= 1 && k < p->key[n - 1]) {
        p->key[n] = p->key[n - 1];
        --n;
    }
    p->key[n] = k;
    ++p->n;
}
void print(node* p) {
    if (!p) {
        return;
    }
    for (int i = 0; i < p->n; ++i) {
        cout << p->key[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= p->n; ++i) {
        print(p->child[i]);
    }
}
int main() {
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    print(root);
}