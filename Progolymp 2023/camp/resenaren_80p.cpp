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

int n, q;
vector<vector<int>> tree;
vector<vector<pii>> up;
vector<int> cost;
vector<int> depth;
vector<vector<int>> query;

void dfs1(int node, int destination, int cnt, int parent, int &ans) {
    cnt %= cost[node];
    if (node == destination) {
        ans = cnt;
        return;
    }
    trav(child, tree[node]) {
        if (child != parent) {
            dfs1(child, destination, cnt, node, ans);
        }
    }
}

void dfs4(int node, int parent, int cnt) {
    if (node != 0) {
        up[node][0].S = min(cost[node], cost[parent]);
        up[node][0].F = parent;
    }
    depth[node] = cnt;
    trav(child, tree[node]) {
        if (child != parent) {
            dfs4(child, node, cnt+1);
        } 
    }
}

void solve1() {
    trav(vec, query) {
        int u, v, x;
        u = vec[0];
        v = vec[1];
        x = vec[2];
        u--, v--;
        int ans;
        dfs1(u, v, x, -1, ans);
        cout << ans << el;
    }
}

void solve2() {
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = cost[i];
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
    trav(vec, query) {
        int u, v, x;
        u = vec[0];
        v = vec[1];
        x = vec[2];
        u--,v--;
        x %= cost[u]; 
        if (u <= v) {
            int cur = u;
            while(1) {
                int length = v-cur+1;
                int b;
                int curMin;
                if (length > 0) {
                    b = 31 - __builtin_clz(length);
                    curMin = min(st[b][cur], st[b][v-(1<<b)+1]).F;
                } 
                if (length <= 1 || curMin > x) {
                    break;
                }
                int L = cur, R = v;
                int ans = 0;
                while(L <= R) {
                    int mid = (R+L)/2;
                    b = 31 - __builtin_clz(mid-cur+1);
                    if (min(st[b][cur], st[b][mid-(1<<b)+1]).F <= x) {
                        ans = min(st[b][cur], st[b][mid-(1<<b)+1]).S;
                        R = mid-1;
                    } 
                    else L = mid+1;
                }
                cur = ans;
                x %= cost[cur];
            }
            cout << x << el;
        }   
        else {
            int cur = u;
            while(1) {
                int length = cur-v+1;
                int b;
                int curMin;
                if (length > 0) {
                    b = 31 - __builtin_clz(length);
                    curMin = min(st[b][v], st[b][cur-(1<<b)+1]).F;
                } 
                if (length <= 1 || curMin > x) {
                    break;
                }
                int L = v, R = cur;
                int ans = 0;
                while(L <= R) {
                    int mid = (R+L)/2;
                    b = 31 - __builtin_clz(cur-mid+1);
                    if (min(st[b][mid], st[b][cur-(1<<b)+1]).F <= x) {
                        ans = min(st[b][mid], st[b][cur-(1<<b)+1]).S;
                        L = mid+1;
                    } 
                    else {
                        R = mid-1;
                    }
                }
                cur = ans;
                x %= cost[cur];
            }
            cout << x << el;
        }
    }
}

void solve4() {
    up.resize(n, vector<pii>(20, pii(mp(INT_MAX, INT_MAX))));
    depth.resize(n);
    dfs4(0, -1, 0);
    up[0][0].F = 0;
    up[0][0].S = cost[0];
    for(int k = 1; k <= 20; k++) {
        for(int i = 0; i < n; i++) {
            up[i][k].F = up[up[i][k-1].F][k-1].F;
            up[i][k].S = min(up[i][k-1].S, up[up[i][k-1].F][k-1].S);
        }
    }
    trav(vec, query) {
        int u, v, x;
        u = vec[0];
        v = vec[1];
        x = vec[2];
        u--, v--;
        x %= cost[u];        
        int right = v;
        while(1) {
            if (u == v) {
                break;
            }
            // find closest min in range
            int mn = INT_MAX;
            int cur = u;
            int dist = depth[u]-depth[v];
            while(cur != v) {
                for(int i = 20; i >= 0; i--) {
                    if (dist&(1<<i)) {
                        mn = min(up[cur][i].S, mn);
                        cur = up[cur][i].F;
                        dist = depth[cur];
                    }
                }  
            } 
            if (mn > x) {
                break;
            }
            cur = u;
            dist = depth[cur]-depth[v];
            for(int i = 20; i >= 0; i--) {
                // if are able to jump, and it still doesn't work, then jump
                if (up[cur][i].S > x) {
                    cur = up[cur][i].F;
                    dist = depth[cur]-depth[v];
                }
            }
            // the min will be your parent now, so you should just go up now
            cur = up[cur][0].F;
            x %= cost[cur];
            u = cur;
        }
        cout << x << el;
    }
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> n >> q;
        tree.resize(n);
        cost.resize(n);
        for(int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        for(int i = 0; i < n; i++) cin >> cost[i];
        for(int i = 0; i < q; i++) {
            vector<int> u(3);
            cin >> u[0] >> u[1] >> u[2];
            query.pb(u);
        }
        bool yes = 1;
        trav(u, query) {
            if (u[1] != 1) {
                yes = 0;
                break;
            }
        }
        if (n <= 2000 && q <= 2000) solve1();
        else if (yes == 1) solve4();
        else {
            solve2();
        } 
    }
}