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

int n;
int dp[1000005];
int ways(int level) {
    if(level == n) return 1;
    if(level > n) return 0;

    if(dp[level] != -1) return dp[level] % MOD;

    int ans = 0;
    for(int i=1;i<=6;i++) {
        ans = (ans + ways(level + i)) % MOD;
    }

    return dp[level] = ans % MOD;
}

void solve() {
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cout << ways(0) << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
