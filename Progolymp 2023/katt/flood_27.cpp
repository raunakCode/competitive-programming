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

ll r, c, q;
vector<vector<ll>> grid;

void dfs(ll R, ll C, ll x) {
    ll curColour = grid[R][C];
    grid[R][C] = x;
    if (R+1 < r && grid[R+1][C] == curColour) dfs(R+1, C, x);
    if (R-1 >= 0 && grid[R-1][C] == curColour) dfs(R-1, C, x);
    if (C+1 < c && grid[R][C+1] == curColour) dfs(R, C+1, x);
    if (C-1 >= 0 && grid[R][C-1] == curColour) dfs(R, C-1, x);
}

void solve1() {
    grid.resize(r, vector<ll>(c));
    rep(i, 0, r) {
        rep(j, 0, c) {
            cin >> grid[i][j];
        } 
    }
    cin >> q;
    while(q--) {
        ll R, C, x;
        cin >> R >> C >> x;
        R--, C--;
        if (grid[R][C] != x) dfs(R, C, x);
    }
    rep(i, 0, r) {
        rep(j, 0, c) {
            cout << grid[i][j] << " ";
        }
        cout << el;
    }
}

// second test case
vector<ll> parent;
vector<ll> mass;
vector<ll> color;
vector<pll> ED;
map<ll, set<ll>> nb;

void make(ll node) {
    parent[node] = node;
    mass[node] = 1;
    ED[node] = mp(node, node);
}

ll root(ll node) {
    if (node == parent[node]) return node;
    return parent[node] = root(parent[node]);
}

void join(ll a, ll b) {
    a = root(a);
    b = root(b);
    if (a != b) {
        if (mass[a] < mass[b]) swap(a, b);
        parent[b] = a;
        mass[a] += mass[b];
        ED[a].F = min({ED[a].F, ED[b].F, ED[a].S, ED[b].S});
        ED[a].S = max({ED[a].F, ED[b].F, ED[a].S, ED[b].S});
    }
}

void solve2() {
    color.resize(c+1);
    parent.resize(c+1);
    mass.resize(c+1);
    ED.resize(c+1); 
    for(ll j = 0; j < c; j++) {
        ll col; cin >> col;
        color[j] = col;
        make(j);
    }
    for(ll j = 0; j < c; j++) {
        if (j+1 < c) {
            if (color[root(j)] == color[root(j+1)]) {
                join(j, j+1);
            }
        } 
        if (j-1 >= 0) {
            if (color[root(j)] == color[root(j-1)]) {
                join(j, j-1);
            }
        }
    }
    cin >> q;
    while(q--) {
        ll R, C, x;
        cin >> R >> C >> x;
        C--;
        color[root(C)] = x;
        ll left = ED[root(C)].F-1;
        ll right = ED[root(C)].S+1;
        if (left >= 0 && root(C) != root(left) && color[root(left)] == x) {
            join(C, left);
        }
        if (right < c && root(C) != root(right) && color[root(right)] == x) {
            join(C, right);
        }
    }
    for(ll i = 0; i < r; i++) {
        for(ll j = 0; j < c; j++) {
            cout << color[root(j)] << " ";
        }
        cout << el;
    }
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> r >> c;
        if (r == 1) {
            solve2();
        }
        else solve1();
    }
}