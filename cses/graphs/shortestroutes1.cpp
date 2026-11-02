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

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pli>> graph(n+1);
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dist(n+1, 1e18);
    dist[1] = 0;
    pq.push({0LL,1});

    while(pq.size() > 0) {
        auto p = pq.top();
        int curr = pq.top().second;
        pq.pop();

        if(p.first != dist[p.second]) continue;

        for(auto &v: graph[curr]) {
            if(dist[v.first] > dist[curr] + v.second) {
                dist[v.first] = dist[curr] + v.second;
                pq.push({dist[v.first], v.first});;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}