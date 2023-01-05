#include "bits/stdc++.h"
 
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
 
using namespace std;

int n;
vector<vector<int>> tree;
vector<int> depth(100001);
vector<int> daddy(100001);

int dfs(int node, int parent) {
    int curDepth = 0;
    daddy[node] = parent;
    trav(child, tree[node]) {
        if (child != parent) curDepth = max(curDepth, 1 + dfs(child, node)); 
    } 
    depth[node] = curDepth;
    return curDepth;
}

void solve() {
    cin >> n;
    rep(i, 0, n) {
        vector<int> k;
        tree.pb(k);
    }
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    dfs(0, -1);
    priority_queue<pair<int, int>> pq;
    daddy[0] = -1;
    vector<int> ans;
    for(int i = 0; i < tree[0].size(); i++) {
        int child = tree[0][i];
        pq.push({depth[child], child});
    }
    int cnt = 0;
    while(cnt < n-1) {
        int node = pq.top().second;
        int curDepth = pq.top().first;
        ans.pb(curDepth + 1);
        cnt += curDepth+1;
        pq.pop();
        while(tree[node].size() != 1) {
            bool found = 0;
            int newNode = 0;
            for(int i = 0; i < tree[node].size(); i++) {
                int curChild = tree[node][i];
                if (curChild != daddy[node]) {
                    if (depth[curChild] == curDepth-1 && found == 0) {
                        found = 1;
                        newNode = curChild;
                    }
                    else if (found == 1 || depth[curChild] != curDepth-1) {
                        pq.push({depth[curChild], curChild});
                    } 
                }
            }
            node = newNode;
            curDepth = depth[newNode];
        }
    }
    int currentPrint = 1;
    trav(x, ans) {
        while(x--) {
            cout << currentPrint << " ";
        }
        currentPrint++;
    }
}

int main() {
    faster
    solve();
}