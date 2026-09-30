//used for problems in cf

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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    ll bob_work = 0;
    vector<ll> val(n);
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            bob_work += arr[i];
            val[i] = -1LL*arr[i];
        }
        else val[i] = arr[i];
    }
    ll cur = 0;
    ll mini = 0;
    for(ll x: val) {
        cur = min(x, cur+x);
        mini = min(mini, cur);
    }
    cout << bob_work + mini << endl;
}   
 
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}