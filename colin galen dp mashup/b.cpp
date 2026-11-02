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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    bool typeable[26] = {};
    for(int i=0;i<k;i++) {
        char c; cin >> c;
        typeable[c -'a'] = 1; 
    }
    vii ar(n, 0);
    for(int i=0;i<n;i++) {
        if(typeable[s[i] - 'a']) ar[i] = 1;
    }
    vii dp(n+1);
    ll ans = 0;
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        if(ar[i-1]) dp[i] = dp[i-1] + 1; 
        else dp[i] = 0;
        ans += dp[i];
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}
