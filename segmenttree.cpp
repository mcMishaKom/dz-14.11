#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = -10000000000;

struct Node {
    long long val;
    int idx;
};

Node tree[4 * N];

class SegmentTree {
public:
    int s = 1;
    void recalc(int i) {
        tree[i] = (tree[i * 2].val >= tree[i * 2 + 1].val) ? tree[i * 2] : tree[i * 2 + 1];
    }
    void build() {
        for (int i = s - 1; i >= 1; --i) {
            recalc(i);
        }
    }
    void init(int n, vector<int> a) {
        while (s < n) s *= 2;
        for (int i = 0; i < s; ++i) {
            if (i < n)
                tree[s + i] = {a[i], i + 1};
            else
                tree[s + i] = {INF, -1};
        }
        build();
    }
    Node get(int lq, int rq, int i, int l, int r) {
        if (lq <= l && r <= rq) {
            return tree[i];
        }
        if (r <= lq || rq <= l) {
            return {INF, -1};
        }
        int mid = (l + r) / 2;
        Node left = get(lq, rq, i * 2, l, mid);
        Node right = get(lq, rq, i * 2 + 1, mid, r);
        return (left.val >= right.val) ? left : right;
    }
    Node query(int l, int r) {
        return get(l - 1, r, 1, 0, s);
    }
};