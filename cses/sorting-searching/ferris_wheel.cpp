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
    ll n,x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(all(arr));
    int ans = 0;
    int l = 0, r = n-1;
    while(l <= r) {
        if(arr[l] + arr[r] <= x) {
            l++;
        }
        r--;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
