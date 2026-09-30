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

vll divisors;
void find_divisors(ll n) {
    for(ll i=1;i*i<=n;i++) { // we need to run the loop till i <= sqrt(n)
        if(n%i == 0) {
            divisors.pb(i);
            if(i != n/i) divisors.pb(n/i);
        }
    }
}

ll no_of_divisors(ll n) {
    ll ans = 1;
    for(ll i=2;i*i<=n;i++) {
        ll cnt = 0;
        while(n%i == 0) {
            n /= i;
            cnt++;
        }
        ans *= (cnt + 1);
    }
    if(n > 1) ans *= 2;
    return ans;
}

int N = 1e6;
// TC: O(NlogN)
vector<vector<int>> divisors_all(N+1);
void precompute_divisors() {
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            divisors_all[j].push_back(i);
        }
    }
}

ll sum_of_factors(ll n) {

}

void solve() {
    ll n; cin >> n;
}

int main() {
    fastio;
    solve();
    return 0;
}
