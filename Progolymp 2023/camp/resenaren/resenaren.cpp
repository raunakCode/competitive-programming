#include "bits/stdc++.h"
 
using namespace std;

#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;
#define trav(a, x) for (auto &a : x)

const int inf = 1500000000;

int n, q;
vector<vector<int>> tree;
vector<vector<pii>> up;
vector<int> cost;
vector<int> depth;

int get_lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for(int i = 18; i >= 0; i--) {
        if (k & (1<<i)) {
            a = up[a][i].F;
        }
    }
    if (a == b) return a;
    for(int i = 18; i >= 0; i--) {
        if (up[a][i].F != up[b][i].F) {
            a = up[a][i].F;
            b = up[b][i].F;
        }
    }
    a = up[a][0].F;
    return a;
}

void dfs(int node, int parent, int cnt) {
    if (node != 0) {
        up[node][0].S = min(cost[node], cost[parent]);
        up[node][0].F = parent;
    }
    depth[node] = cnt;
    trav(child, tree[node]) {
        if (child != parent) {
            dfs(child, node, cnt+1);
        } 
    }
}

void solve() {
    cin >> n >> q; 
    tree.resize(n);
    up.resize(n, vector<pii>(18, pii(mp(inf, inf))));
    cost.resize(n);
    depth.resize(n);
    for(int i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    for(int i = 0; i < n; i++) cin >> cost[i];
    dfs(0, -1, 0);
    up[0][0].F = 0;
    up[0][0].S = cost[0];
    for(int k = 1; k <= 18; k++) {
        for(int i = 0; i < n; i++) {
            up[i][k].F = up[up[i][k-1].F][k-1].F;
            up[i][k].S = min(up[i][k-1].S, up[up[i][k-1].F][k-1].S);
        }
    }
    while(q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        int lca = get_lca(u, v);
        x %= cost[u];        
        while(1) {
            if (u == lca) {
                break;
            }
            // find closest min in range
            int mn = inf;
            int cur = u;
            int dist = depth[cur]-depth[lca];
            for(int i = 18; i >= 0; i--) {
                if (dist&(1<<i)) {
                    mn = min(up[cur][i].S, mn);
                    cur = up[cur][i].F;
                    dist -= (1<<i);
                }
            }  
            if (mn > x) {
                break;
            }
            cur = u;
            dist = depth[cur]-depth[lca];
            for(int i = 18; i >= 0; i--) {
                // if are able to jump, and it still doesn't work, then jump
                if (up[cur][i].S > x) {
                    cur = up[cur][i].F;
                    dist = depth[cur]-depth[lca];
                }
            }
            // the min will be your parent now, so you should just go up now
            cur = up[cur][0].F;
            x %= cost[cur];
            u = cur;
        }
        // go from lca to v
        int mover = lca;
        while(1) {
            // TODO: fix some variables here
            if (mover == v) {
                break;
            }
            //find closest min in range
            int mn = inf;
            int cur = v;
            int dist = depth[cur]-depth[mover];
            for(int i = 18; i >= 0; i--) {
                if (dist&(1<<i)) {
                    mn = min(up[cur][i].S, mn);
                    cur = up[cur][i].F;
                    dist -= (1<<i);
                }
            }  
            if (mn > x) {
                break;
            }
            // start moving down now
            cur = v;
            for(int i = 18; i >= 0; i--) {
                // if you are able to jump and it still doesn't work, then jump
                dist = depth[cur] - depth[mover];
                //diff is the amount we need to jump up from cur
                int diff = dist-(1<<i);
                if (diff <= 0) {
                    continue;
                }
                else {
                    // try to make the jump if possible
                    // get to candidate move point
                    int curr = cur;
                    for(int j = 18; j >= 0; j--) {
                        if (diff & (1<<j)) {
                            curr = up[curr][j].F;
                            diff -= (1<<j);
                        }
                    }
                    //compute min down to candidate move point
                    int mn = inf;
                    int temp = curr;
                    int curDiff = depth[curr]-depth[mover];
                    for(int j = 18; j >= 0; j--) {
                        if (curDiff & (1<<j)) {
                            mn = min(up[curr][j].S, mn);
                            curr = up[curr][j].F;
                            curDiff -= (1<<j);
                        } 
                    }
                    //update mover if you make the jump
                    if (mn > x) {
                        mover = temp;
                        cur = v;
                        dist = depth[cur]-depth[mover];
                    }
                }   
                cur = v;
            }
            int trueDist = depth[cur]-depth[mover]-1;
            for(int i = 18; i >= 0; i--) {
                if (trueDist & (1<<i)) {
                    cur = up[cur][i].F;
                    trueDist -= (1<<i);
                }
            }
            mover = cur;
            x %= cost[mover];
            cur = v;
        }
        cout << x << el;
    }
}

int main() {
    faster
    solve();
}