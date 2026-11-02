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

ll l,r;
vii digits;
ll dp[20][2][4]; // dp(pos, tight, leadingZero, nonZeroCount)

ll dfs(int pos, int t, int nz) {
    if(pos == (int)digits.size()) {
        return (nz <= 3 ? 1 : 0);
    }
    ll &res = dp[pos][t][nz];
    if(res != -1) return res;
    res = 0;
    int limit = t ? digits[pos] : 9;
    for(int d=0;d<=limit;d++) {
        int nt = t && (d == limit);
        int nnz = nz + (d != 0);
        if(nnz <= 3) {
            res += dfs(pos+1, nt, nnz);
        }
    }
    return res;
}

ll count(ll x) {
    if(x < 0) return 0;
    digits.clear();
    if(x == 0) digits.pb(0);
    while(x > 0) {
        digits.pb(x%10);
        x/=10;
    }
    memset(dp,-1,sizeof(dp));
    reverse(all(digits));
    return dfs(0,1,0);
}

void solve() {
    cin >> l >> r;
    cout << count(r) - count(l-1) << '\n';
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
