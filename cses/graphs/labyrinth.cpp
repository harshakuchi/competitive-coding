#include<bits/stdc++.h>
using namespace std;

//aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;

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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> prev_dir(n, vector<char>(m));

    vector<char> dirsChar = {'U','D','L','R'};
    vector<pii> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    pii start, end;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'A') start = {i,j};
            else if(grid[i][j] == 'B') end = {i,j};
        }
    }

    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;

    bool found = false;
    while(!q.empty() && !found) {
        pii cur = q.front(); q.pop();
        int r = cur.first;
        int c = cur.second;
        for(int d=0;d<4;d++) {
            int nr = r + dirs[d].first;
            int nc = c + dirs[d].second;

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#') {
                vis[nr][nc] = true;
                prev_dir[nr][nc] = dirsChar[d];
                q.push({nr,nc});

                if(make_pair(nr,nc) == end) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(!vis[end.first][end.second]) {
        cout << "NO\n";
        return;
    }

    string path;
    pii curr = end;

    while(curr != start) {
        char dir = prev_dir[curr.first][curr.second];
        path.pb(dir);

        int idx = find(dirsChar.begin(), dirsChar.end(), dir) - dirsChar.begin();
        curr.first -= dirs[idx].first;
        curr.second -= dirs[idx].second;
    }

    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << (int)path.size() << endl;
    cout << path << endl;

}

int main() {
    fastio;
    solve();
    return 0;
}