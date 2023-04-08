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

map<pll, pll> parent;
map<pll, ll> mass;

void make(pll node) {
    parent[node] = node;
    mass[node] = 1;
}

pll find(pll node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void unify(pll a, pll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (mass[a] < mass[b]) swap(a, b);
        parent[b] = a;
        mass[a] += mass[b];
    }
}

void solve() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<pll> blocks;
    set<pll> exist;
    for(ll i = 0; i < t; i++) {
        ll y, x;
        cin >> y >> x;
        blocks.pb({y, x});
        make({y, x});
    }
    make({0, 0});
    make({n, n});
    ll ans = t+2;
    for(ll i = 0; i < t; i++) {
        pair<ll, ll> cur = blocks[i];
        exist.emplace(cur);
        if (cur.F+1 == n-1) {
            unify(cur, {n, n});
        }
        else if (cur.F+1 < n && exist.count({cur.F+1, cur.S})) {
            unify(cur, {cur.F+1, cur.S});
        }
        if (cur.F-1 == 0) {
            unify(cur, {0, 0});
        } 
        else if (cur.F-1 > 0 && exist.count({cur.F-1, cur.S})) {
            unify(cur, {cur.F-1, cur.S});
        }
        if (cur.S+1 < m && exist.count({cur.F, cur.S+1})) {
            unify(cur, {cur.F, cur.S+1});
        }
        if (cur.S-1 >= 0 && exist.count({cur.F, cur.S-1})) {
            unify(cur, {cur.F, cur.S-1});
        }
        if (find({0, 0}) == find({n, n})) {
            ans = min(i+1, ans);
            break;
        }
    }
    if (ans == t+2) cout << "nej";
    else cout << ans;
}

int main() {
    faster
    solve();
}