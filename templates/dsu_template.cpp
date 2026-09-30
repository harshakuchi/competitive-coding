#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) {
            parent[i] = i; size[i] = 1;
        }
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u, int v) {
        int a = find(u);
        int b = find(v);
        if(a == b) return;
        if(size[a] > size[b]) {
            swap(a,b);
        }
        parent[a] = b;
        size[b] += size[a];
    }
};