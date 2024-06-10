#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

int n, m, q;

vector<int> parent;
vector<int> big;
vector<set<int>> graph;

void make(int node) {
    parent[node] = node;
    big[node] = 1;
}

int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (graph[a].size() > graph[b].size()) swap(a, b);
        trav(con, graph[a]) {
            graph[b].insert(con);
        }
        parent[a] = b;
        big[b] += big[a];
    }
}

void solve() {
    cin >> n >> m >> q;
    graph.resize(n);
    parent.resize(n);
    big.resize(n);
    rep(i, 0, n) {
        make(i);
    }
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u = find(u);
        v = find(v);
        // check if they distrust each other
        bool works = 1;
        trav(con, graph[u]) {
            if (find(con) == v) {
                works = 0;
                break;
            }
        }
        if (works) {
            cout << "APPROVE" << el;
            join(u, v);
            
        }
        else cout << "REFUSE" << el;
        //possibly merge
    }
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}