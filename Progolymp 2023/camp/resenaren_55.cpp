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

void dfs(ll node, ll destination, ll cnt, ll parent, ll &ans) {
    cnt %= cost[node];
    if (node == destination) {
        ans = cnt;
        return;
    }
    trav(child, tree[node]) {
        if (child != parent) {
            dfs(child, destination, cnt, node, ans);
        }
    }
}

void solve1() {
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
        ll u, v, x;
        cin >> u >> v >> x;
        ll ans;
        dfs(u, v, x, -1, ans);
        cout << ans << el;
    }
}

void solve2() {
    tree.resize(n);
    cost.resize(n);
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    } 
    rep(i, 0, n) cin >> cost[i];
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = cost[i];
    int K = 25; 
    vector<vector<pii>> st(25, vector<pii>(n, pii()));
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < n; j++) {
            st[i][j] = mp(INT_MAX, j);
        }
    }
    for (int i = 0; i < n; i++) {
        st[0][i].F = a[i];
        st[0][i].S = i;
    }
    for (int i = 1; i <= 25; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            pii cur = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
            st[i][j].F = cur.F;
            st[i][j].S = cur.S;
        }
    }
    while(q--) {
        ll u, v, x;
        cin >> u >> v >> x;
        u--,v--;
        x %= cost[u]; 
        if (u <= v) {
            ll cur = u;
            while(1) {
                ll length = v-cur+1;
                ll b;
                ll curMin;
                if (length > 0) {
                    b = 31 - __builtin_clz(length);
                    curMin = min(st[b][cur], st[b][v-(1<<b)+1]).F;
                } 
                if (length <= 1 || curMin > x) {
                    break;
                }
                ll L = cur, R = v;
                ll ans = 0;
                while(L <= R) {
                    ll mid = (R+L)/2;
                    b = 31 - __builtin_clz(mid-cur+1);
                    if (min(st[b][cur], st[b][mid-(1<<b)+1]).F <= x) {
                        pii p = min(st[b][cur], st[b][mid-(1<<b)+1]);
                        ans = p.S;
                        R = mid-1;
                    } 
                    else L = mid+1;
                }
                cur = ans;
                x %= cost[cur];
            }
            x %= cost[cur]; 
            cout << x << el;
        }   
        else {
            ll cur = u;
            while(1) {
                ll length = cur-v+1;
                ll b;
                ll curMin;
                if (length > 0) {
                    b = 31 - __builtin_clz(length);
                    curMin = min(st[b][v], st[b][cur-(1<<b)+1]).F;
                } 
                if (length <= 1 || curMin > x) {
                    break;
                }
                ll L = v, R = cur;
                ll ans = 0;
                while(L <= R) {
                    ll mid = (R+L)/2;
                    b = 31 - __builtin_clz(cur-mid+1);
                    pii sdf = min(st[b][mid],st[b][cur-(1<<b)+1]);
                    if (min(st[b][mid], st[b][cur-(1<<b)+1]).F <= x) {
                        pii p = min(st[b][mid], st[b][cur-(1<<b)+1]);
                        ans = p.S;
                        L = mid+1;
                    } 
                    else {
                        R = mid-1;
                    }
                }
                cur = ans;
                x %= cost[cur];
            }
            x %= cost[cur]; 
            cout << x << el;
        }
    }
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> n >> q;
        if (n <= 2000 && q <= 2000) solve1();
        else {
            solve2();
        } 
    }
}