#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> st;
public:
    void push(int val) {
        st.push_back(val);
    }

    int pop() {
        if (st.empty()) return -1;
        int v = st.back();
        st.pop_back();
        return v;
    }

    int top() {
        if (st.empty()) return -1;
        return st.back();
    }

    bool empty() {
        return st.empty();
    }

    int size() {
        return st.size();
    }
};