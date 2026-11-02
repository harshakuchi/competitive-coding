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

ll bin_search(vector<ll> &arr, ll target) {
    int low = 0, high = arr.size()-1;
    ll ans = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == target) {
            ans = mid;
            break;
        }
        else if(arr[mid] > target) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

void solve() {
    //solve
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
