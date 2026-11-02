/*
ll dfs(int pos, int tight, int leadingZero, // other parameters) {
    if(pos == len) {
        // return
    }
    ll &res = dp[pos][tight][leadingZero];
    if(res != -1) return res;
    res = 0;
    int limit = tight ? digits[pos] : 9;
    for(int d=0;d<=limit;d++) {
        int nextTight = tight && (d == limit);
        int nextLeadingZero = leadingZero && (d == 0);
        res += dfs(pos+1, nextTight, nextLeadingZero, // other parameters);
    }
    return res;
}
*/