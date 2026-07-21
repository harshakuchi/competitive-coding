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
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    ll res = 0;
    for(int i=1;i<n;i++) {
        if(arr[i] < arr[i-1]) {
            res += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << res << endl;

    //invariants - array is always increasing
    //monovariants - result is always increased by arr[i-1] - arr[i] (progress) and it is terminated
}

int main() {
    fastio;
    solve();
    return 0;
}
