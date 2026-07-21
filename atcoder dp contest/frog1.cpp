#include<bits/stdc++.h>
using namespace std;
 
//aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
 
//constants
const ll INF = 1e18;
const int MOD = 1e9+7;
 
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
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        int ans1 = dp[i-1] + abs(h[i-1] - h[i]);
        int ans2 = INT_MAX;
        if(i > 1) ans2 = dp[i-2] + abs(h[i-2] - h[i]);
        dp[i] = min(ans1, ans2);
    }
    cout << dp[n-1] << endl;
}
 
int main() {
    fastio;
    solve();
    return 0;
}