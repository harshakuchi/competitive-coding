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

vii digits;
ll dp[20][2][2][11]; // dp(pos, tight, leading zeroes, lastDigit) = count of digits where no two adj digits are same
ll dfs(int pos, int tight, int leadingZero, int lastDigit) {
    if(pos == (int)digits.size()) return 1;
    ll &res = dp[pos][tight][leadingZero][lastDigit];
    if(res != -1) return res;
    res = 0;
    int limit = tight ? digits[pos] : 9;
    for(int d=0;d<=limit;d++) {
        if(!leadingZero) {
            if(d == lastDigit) continue;
        }
        int nextTight = tight && (d == limit);
        int nextLeadingZero = leadingZero && (d == 0);
        int nextLast = nextLeadingZero ? 10 : d;
        res += dfs(pos+1, nextTight, nextLeadingZero, nextLast);
    }
    return res;
}

ll count(ll x) {
    if(x < 0) return 0;
    digits.clear();
    if(x == 0) digits.pb(0);
    while(x > 0) {
        digits.pb(x%10);
        x /= 10;
    }
    reverse(all(digits));
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,1,10);
}

void solve() {
    ll a,b;
    cin >> a >> b;
    cout << count(b) - count(a-1);
}   

int main() {
    fastio;
    solve();
    return 0;
}
