#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    void up(int i) {
        while (i > 0) {
            int pr = (i - 1) / 2;
            if (heap[pr] < heap[i]) {
                swap(heap[pr], heap[i]);
                i = pr;
            } else {
                break;
            }
        }
    }
    void down(int i) {
        int n = heap.size();
        while (true) {
            int mx = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n && heap[l] > heap[mx]) mx = l;
            if (r < n && heap[r] > heap[mx]) mx = r;
            if (mx == i) break;
            swap(heap[i], heap[mx]);
            i = mx;
        }
    }

public:
    void insert(int k) {
        heap.push_back(k);
        up(heap.size() - 1);
    }
    int res() {
        int mx = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())  down(0);
        return mx;
    }
};