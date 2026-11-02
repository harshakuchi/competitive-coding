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

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    ll finishing_time = 0;
    ll ans = 0;
    for(auto &task: arr) {
        finishing_time += task.first;
        ans += (task.second - finishing_time);
    }
    cout << ans << endl;
}

int main() {
    fastio;
    // int t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}
