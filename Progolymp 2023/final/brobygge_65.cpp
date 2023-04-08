#include "bits/stdc++.h"
 
using namespace std;

#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)

int n, m, t;
vector<pair<int,int>> toppers;
map<pair<int, int>, bool> blocks;
map<pair<int, int>, int> when;

bool dfs(int y, int x, map<pair<int,int>, bool>& vis, int mid) {
    bool ret = 0;
    vis[{y, x}] = 1;
    if (y == 1) return 1;
    if (blocks[{y+1, x}] == 1 && !vis[{y+1, x}] && mid >= when[{y+1, x}]) {
        ret = ret || dfs(y+1, x, vis, mid);
    }
    if (blocks[{y-1, x}] == 1 && !vis[{y-1, x}] && mid >= when[{y-1, x}]) {
        ret = ret || dfs(y-1, x, vis, mid);
    }
    if (blocks[{y, x+1}] == 1 && !vis[{y, x+1}] && mid >= when[{y, x+1}]) {
        ret = ret || dfs(y, x+1, vis, mid);
    }
    if (blocks[{y, x-1}] == 1 && !vis[{y, x-1}] && mid >= when[{y, x-1}]) {
        ret = ret || dfs(y, x-1, vis, mid);
    }
    return ret;
}

bool check(int mid) {
    bool ret = 0;
    map<pair<int,int>, bool> vis; 
    for(int i = 0; i < toppers.size(); i++) {
        int curY = toppers[i].F;
        int curX = toppers[i].S;
        if (!vis[{curY, curX}] && mid >= when[{curY, curX}]) {
            ret = ret || dfs(curY, curX, vis, mid);
        }
    }
    return ret;
}

void solve() {
    cin >> n >> m >> t;
    for(int i = 0; i < t; i++) {
        int y, x;
        cin >> y >> x;
        int curTime = i+1;
        blocks[{y, x}] = 1;
        when[{y, x}] = i+1;
        if (y == n-2) toppers.pb({y, x});
    }
    bool works = 0;
    int ans = 1000000000;
    int l = 0, r = 1000000000;
    while(l <= r) {
        int mid = l + (r-l)/2;
        bool win = check(mid);
        if (win) {
            works = 1;
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    } 
    if (works) {
        cout << ans;
    }
    else cout << "nej";

} 

int main() {
    faster
    solve();
}