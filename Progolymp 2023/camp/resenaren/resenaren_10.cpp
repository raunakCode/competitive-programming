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

ll n, q;
vector<vector<ll>> tree;
vector<ll> cost;
set<ll> vis;
void dfs(ll node, ll destination, ll cnt, ll parent, ll &ans) {
    vis.emplace(node);
    cnt %= cost[node];
    if (node == destination) {
        ans = cnt;
        return;
    }
    trav(child, tree[node]) {
        if (child != parent && vis.count(child) == 0) {
            dfs(child, destination, cnt, node, ans);
        }
    }
}

void solve() {
    cin >> n >> q;
    tree.resize(n+1);
    cost.resize(n+1);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    rep(i, 1, n+1) cin >> cost[i];
    while(q--) {
        vis.clear();
        ll u, v, x;
        cin >> u >> v >> x;
        ll ans;
        dfs(u, v, x, -1, ans);
        cout << ans << el;
    }
}

int main() {
    faster
    solve();
}