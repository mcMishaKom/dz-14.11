#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node* now = root;
        while (true) {
            if (val < now->val) {
                if (!now->left) {
                    now->left = new Node(val);
                    return;
                }
                now = now->left;
            } else if (val > now->val) {
                if (!now->right) {
                    now->right = new Node(val);
                    return;
                }
                now = now->right;
            } else {
                return;
            }
        }
    }
    int res() {
        Node* mx = root; Node* pr = nullptr;
        while (mx->right) {
            pr = mx;
            mx = mx->right;
        }
        if (mx->left) {
            Node* pred = mx->left;
            while (pred->right) pred = pred->right;
            return pred->val;
        }
        return pr->val;
    }
};