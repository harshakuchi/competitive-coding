#include<bits/stdc++.h>
using namespace std;

//aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;

//constants
const ll INF = 1e18;
const int MOD = 1e9 + 7;

//macros
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

//functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modexp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int src, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[src] = true;
    for(int nei: adj[src]) {
        if(!vis[nei]) {
            dfs(nei,adj,vis);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> vis(n+1, false);
    vector<int> nodes;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            nodes.pb(i);
            dfs(i,adj,vis);
        }
    }
    int k = nodes.size();
    cout << k - 1 << endl;
    for(int i=1;i<k;i++) {
        cout << nodes[0] << " " << nodes[i] << endl;
    }
}

int main() {
    fastio;
    solve();
    return 0;
}