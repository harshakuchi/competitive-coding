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

ll n,k,m,b;
vll arr;

bool possible(ll p) {
    ll tm = m;
    ll rifts = 0;
    for(ll i=0;i<k;i++) {
        if(arr[i] > p) {
            tm -= (arr[i] - p);
            rifts++;
        }
    }
    if(rifts <= b && tm >= 0) return true;
    for(ll i=k;i<n;i++) {
        if(arr[i-k] > p) {
            tm += (arr[i-k] - p);
            rifts--;
        }
        if(arr[i] > p) {
            tm -= (arr[i] - p);
            rifts++;
        }
        if(rifts <= b && tm >= 0) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k >> m >> b;
    arr.resize(n);
    for(ll &x: arr) cin >> x;
    ll low = 0, high = 1e9;
    while(low < high) {
        ll mid = low + (high - low)/2;
        if(possible(mid)) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout << high << '\n';
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
