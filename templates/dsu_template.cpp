#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        size.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSize(int u, int v) {
        int a = find(u);
        int b = find(v);

        if(a == b) return;
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
