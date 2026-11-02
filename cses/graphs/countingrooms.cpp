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

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == '#') return;

    vis[i][j] = true;
    dfs(i-1,j,grid,vis);
    dfs(i,j-1,grid,vis);
    dfs(i+1,j,grid,vis);
    dfs(i,j+1,grid,vis);
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '.' && !vis[i][j]) {
                dfs(i,j,grid,vis);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
