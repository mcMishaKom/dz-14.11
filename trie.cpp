#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool is_end;
    int count;
    Node* children[26];
    Node() : is_end(false), count(0) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    Node* root;
    vector<string> a;
    string cur;

    void dfs(Node* v) {
        if (v->is_end)
            for (int i = 0; i < v->count; ++i)
                a.push_back(cur);
        for (int i = 0; i < 26; ++i) {
            if (v->children[i] != nullptr) {
                cur.push_back('a' + i);
                dfs(v->children[i]);
                cur.pop_back();
            }
        }
    }

public:
    Trie() : root(new Node()) {}

    void insert(const string& w) {
        Node* c = root;
        for (char x : w) {
            int idx = x - 'a';
            if (c->children[idx] == nullptr)
                c->children[idx] = new Node();
            c = c->children[idx];
        }
        c->is_end = true;
        c->count++;
    }

    void collect(vector<string>& res) {
        dfs(root);
        res = a;
    }
};