#include<bits/stdc++.h>
using namespace std;

//aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;

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

bool dfs(int src, int color, vector<vector<int>> &graph, vector<int> &colors) {
    colors[src] = color;
    for(int v: graph[src]) {
        if(colors[v] == -1) {
            if(!dfs(v, 1-color, graph, colors)) return false;
        }
        else {
            if(colors[v] == colors[src]) return false;
        }
    }
    return true;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bool dividable = true;
    vector<int> colors(n+1, -1);
    for(int i=1;i<=n;i++) {
        if(colors[i] == -1) {
            if(!dfs(i,0,graph,colors)) {
                dividable = false;
                break;
            }
        }
    }
    if(!dividable) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        cout << colors[i]+1 << " ";
    }
    cout << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}