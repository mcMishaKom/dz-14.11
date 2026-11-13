#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class List {
public:
    Node* head;
    Node* tail;
    int sz;

    List() : head(nullptr), tail(nullptr), sz(0) {}

    void push_back(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        sz++;
    }

    void push_front(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        sz++;
    }

    int pop_back() {
        if (!tail) return -1;
        int v = tail->val;
        Node* p = tail->prev;
        if (p) p->next = nullptr;
        else head = nullptr;
        tail = p;
        sz--;
        return v;
    }

    int pop_front() {
        if (!head) return -1;
        int v = head->val;
        Node* n = head->next;
        if (n) n->prev = nullptr;
        else tail = nullptr;
        head = n;
        sz--;
        return v;
    }

    void insert(int pos, int val) {
        if (pos < 0 || pos > sz) return;
        if (pos == 0) { push_front(val); return; }
        if (pos == sz) { push_back(val); return; }
        Node* cur = head;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        Node* n = new Node(val);
        n->prev = cur->prev;
        n->next = cur;
        cur->prev->next = n;
        cur->prev = n;
        sz++;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= sz) return;
        if (pos == 0) { pop_front(); return; }
        if (pos == sz - 1) { pop_back(); return; }
        Node* cur = head;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        sz--;
    }

    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};