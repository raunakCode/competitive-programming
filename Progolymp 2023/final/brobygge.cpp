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

ll n, m, t;

vector<pll> toppers;
set<pll> blocks;
map<pll, ll> when;
set<pll> vis;

bool dfs(ll y, ll x, ll mid) {
    bool ret = 0;
    vis.emplace((pii){y, x});
    if (y == 1) return 1;
    if (blocks.count({y+1, x}) == 1 && vis.count({y+1, x}) == 0 && mid >= when[{y+1, x}]) {
        ret = ret || dfs(y+1, x, mid);
        if (ret == 1) return 1;
    }
    if (blocks.count({y-1, x}) == 1 && vis.count({y-1, x}) == 0 && mid >= when[{y-1, x}]) {
        ret = ret || dfs(y-1, x, mid);
        if (ret == 1) return 1;
    }
    if (blocks.count({y, x+1}) == 1 && vis.count({y, x+1}) == 0 && mid >= when[{y, x+1}]) {
        ret = ret || dfs(y, x+1, mid);
        if (ret == 1) return 1;
    }
    if (blocks.count({y, x-1}) == 1 && vis.count({y, x-1}) == 0 && mid >= when[{y, x-1}]) {
        ret = ret || dfs(y, x-1, mid);
        if (ret == 1) return 1;
    }
    return ret;
}

bool checkDfs(ll mid) {
    bool ret = 0;
    for(ll i = 0; i < toppers.size(); i++) {
        ll curY = toppers[i].F;
        ll curX = toppers[i].S;
        if (vis.count({curY, curX}) == 0 && mid >= when[{curY, curX}]) {
            ret = ret || dfs(curY, curX, mid);
            if (ret == 1) return 1;
        }
    }
    return ret;
}

void solve() {
    cin >> n >> m >> t;
    for(ll i = 0; i < t; i++) {
        ll y, x;
        cin >> y >> x;
        ll curTime = i+1;
        blocks.emplace((pll){y, x});
        when[{y, x}] = i+1;
        if (y == n-2) toppers.pb({y, x});
    }

    bool works = 0;
    ll ans = 1000000000;
    ll l = 0, r = 1000000000;
    while(l <= r) {
        vis.clear();
        ll mid = l + (r-l)/2;
        bool win = checkDfs(mid);
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