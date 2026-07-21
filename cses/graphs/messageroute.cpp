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
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    bool found = false;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                parent[v] = u;
                q.push(v);

                if(v == n) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int curr = n;
    vector<int> path;
    while(curr != -1) {
        path.pb(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    cout << (int)path.size() << endl;
    for(int num: path) cout << num << " ";
    cout << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}