#include<bits/stdc++.h>
using namespace std;

//aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

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

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>> &graph) {
    int n = graph.size()-1;
    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto p = pq.top();
        ll d = p.first;
        int u = p.second;
        pq.pop();

        if(d != dist[u]) continue;

        for(auto x: graph[u]) {
            int v = x.first;
            ll w = x.second;
            ll newDist = max(d, w);

            if(newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    return dist;
}

void solve() {
    int n,m,c;
    cin >> n >> m >> c;
    vector<vector<pair<int,ll>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        ll h;
        cin >> u >> v >> h;
        graph[u].pb({v, h});
    }
    vector<ll> f1 = dijkstra(1, graph);
    vector<ll> fc = dijkstra(c, graph);
    cout << max(f1[c], fc[n]) << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}
