#include <bits/stdc++.h>
using namespace std;
 
// aliases
using i32 = int;
using u32 = unsigned int;
using ll = long long;
using ull = unsigned long long;
// using i128 = __int128_t;
// using u128 = __uint128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
// constants
const int MOD = 1e9 + 7;
// macros
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
// vector aliases
#define vii vector<int>
#define vbb vector<bool>
#define vll vector<ll>
#define vs vector<string>
#define vii2 vector<vector<int>>
#define vll2 vector<vector<ll>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
 
// functions
ll ceil_div(ll x, ll y) { return (x + y - 1LL) / y; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modexp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vii2 adj(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int totalMasks = 1<<n;
    vll2 dp(totalMasks, vll(n,0));
    for(int i=0;i<n;i++) {
        dp[1<<i][i] = 1;
    }
    ll ans = 0;
    for(int mask=0;mask<totalMasks;mask++) {
        int start = __builtin_ctz(mask);
        for(int last=start;last<n;last++) {
            if(dp[mask][last] == 0) continue;
            for(int v: adj[last]) {
                if(v < start) continue;
                if(mask & (1<<v)) {
                    if(v == start && __builtin_popcount(mask) >= 3) ans += dp[mask][last];
                }
                else {
                    int newMask = mask | (1<<v);
                    dp[newMask][v] += dp[mask][last];
                }
            }
        }
    }
    cout << ans/2 << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}
