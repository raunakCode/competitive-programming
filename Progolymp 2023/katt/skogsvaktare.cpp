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
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto &a : x)

int n, f;

vector<vector<int>> tree;
vector<int> dist;
vector<int> fruit;
vector<bool> bfsVis;
vector<int> depth;
vector<int> par;
vector<int> vis;

void bfs() {
    // multisource bfs for getting dist for every node from nearest fruit
    queue<int> q;
    rep(i, 0, f) {
        int x; cin >> x;
        fruit[i] = x-1;
        q.push(fruit[i]);
        bfsVis[fruit[i]] = 1;
    } 
    int travel = 0;
    while(!q.empty()) {
        vector<int> nb;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            dist[cur] = travel;
            trav(child, tree[cur]) {
                if (bfsVis[child] == 0) {
                    nb.pb(child);
                    bfsVis[child] = 1;
                }
            }
        }
        trav(child, nb) q.push(child);
        travel++;
    }
}

void pc(int node, int d, int parent) {
    // precomputation dfs to get the parent and depth of all nodes
    depth[node] = d;
    par[node] = parent;
    trav(child, tree[node]) {
        if (child != parent) {
            pc(child, d+1, node);
        }
    }
}

void dfs(int node) {
    /* dfs to let the guard protect and visit the all nodes
       until the fruits it guards */
    vis[node] = 1;
    trav(child, tree[node]) {
        if (!vis[child] && dist[child] == dist[node] - 1) {
            dfs(child);
        }
    }  
}

bool depthSort(int a, int b) {
    return depth[b] < depth[a];
}

void solve() {
    cin >> n >> f;

    tree.resize(n);
    dist.resize(n);
    fruit.resize(f);
    bfsVis.resize(n);
    depth.resize(n);
    par.resize(n);
    vis.resize(n);

    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    bfs();
    pc(0, 0, 0);
    sort(all(fruit), depthSort);

    vector<int> ans;
    rep(i, 0, f) {
        // 1. find best ancestor and store him in a solution
        int node = fruit[i];
        if (vis[node]) continue;
        while(dist[par[node]] == 1 + dist[node]) {
            node = par[node];
        }
        ans.pb(node);
        // 2. dfs outwards from him, and visit all nodes that he would during his guard 
        dfs(node);
    }
    cout << ans.size() << el;
    trav(x, ans) cout << x+1 << " ";
}

int main() {
    faster
    solve();
}