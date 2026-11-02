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

string s;
ll L,R;
int K;

ll dp[20][2][2][10][200];

ll dfs(int pos, bool tight, bool started, int last, int sum) {
    if(pos == (int)s.size()) {
        return sum >= K;
    }

    if(dp[pos][tight][started][last][sum] != -1) return dp[pos][tight][started][last][sum];

    ll ans = 0;

    int limit;
    if(tight) {
        limit = s[pos]-'0';
    }
    else limit = 9;

    for(int d=0;d<=limit;d++) {
        int tight1 = tight && (d == s[pos]-'0');
        // not started == leading zeroes
        if(!started) {
            // still zeros
            if(d == 0) {
                ans += dfs(pos+1,tight1,0,0,0);
            }
            // first non-zero
            else {
                ans += dfs(pos+1,tight1,1,d,d);
            }
        }
        else {
            // add to sum and use last as current
            if(d >= last) {
                ans += dfs(pos+1,tight1,1,d,sum+d);
            }
            // discard
            else {
                ans += dfs(pos+1,tight1,1,last,sum);
            }
        }
    }
    return dp[pos][tight][started][last][sum] = ans;
}

ll count(ll x) {
    if(x < 0) return 0;
    s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return dfs(0,1,0,0,0);
}

void solve() {
    cin >> L >> R >> K;

    ll left_cnt = count(L-1);
    ll right_cnt = count(R);

    if(right_cnt - left_cnt == 0) {
        cout << -1 << endl;
        return;
    }
    ll l = L, r = R;
    ll ans = -1;

    while(l<=r) {
        ll mid = (l+r)/2;
        if(count(mid)-left_cnt > 0) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}
 
int main() {
    fastio;
    solve();
    return 0;
}