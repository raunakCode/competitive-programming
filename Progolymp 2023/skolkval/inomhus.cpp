#include "bits/stdc++.h"
 
#define el "\n"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
 
using namespace std;

void solve() {
    int n; cin >> n;
    set<char> unique;
    map<char, vector<int>> connect;
    map<int, int> floor;
    for(int i = 1; i <= n; i++) {
        int van;
        string trap;
        cin >> van >> trap;
        floor[i] = van;
        for(int j = 0; j < trap.size(); j++) {
            char c = trap[j];
            unique.insert(c);
            connect[c].pb(i);
        }
    }
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    trav(x, unique) {
        for(int i = 0; i < connect[x].size(); i++) {
            for(int j = 0; j < connect[x].size(); j++) {
                int a = connect[x][i];
                int b = connect[x][j];
                graph[a][b] = abs(floor[a]-floor[b]);
            }
        }
    }
    //floyd warshall
    vector<vector<int>> distance(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i==j) distance[i][j] = 0;
            else if (graph[i][j] > 0) distance[i][j] = graph[i][j];
            else distance[i][j] = 100000000;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans += distance[i][i+1];
    }
    cout << ans;
}
 
int main() {
    faster
    //cout << fixed << setprecision(10);
    int tt = 1;
    while(tt--) {
        solve();
    }
}