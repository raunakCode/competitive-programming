#include "bits/stdc++.h"

using namespace std;

#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)

int r, c;
pii attack, king;
vector<vector<char>> grid;
vvi dist;
vector<vector<vector<bool>>> dfsVis; 
vpii dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool dfs(int y, int x, int D, int mid) {
        dfsVis[y][x][D] = 1;
        if (grid[y][x] == 'K') return 1;
        bool ret = 0;
        if (grid[y][x] == 'o' || grid[y][x] == 'A') {
                rep(i, 0, dir.size()) {
                        pii d = dir[i];
                        int Y = y+d.F;
                        int X = x+d.S;
                        if (Y >= 0 && Y < r && X >= 0 && X < c && !dfsVis[Y][X][i] && dist[Y][X] > mid) {
                                ret = ret || dfs(Y, X, i, mid);
                        }
                }
        }
        else {
                int Y = y+dir[D].F;
                int X = x+dir[D].S;
                if (Y >= 0 && Y < r && X >= 0 && X < c && !dfsVis[Y][X][D] && dist[Y][X] > mid) {
                        ret = ret || dfs(Y, X, D, mid);
                }
        }
        return ret;
}
        
void solve() {
        cin >> r >> c;
        grid.resize(r, vector<char>(c));
        dfsVis.resize(r, vector<vector<bool>>(c, vector<bool>(4, 0)));
        dist.resize(r, vi(c));
        queue<pii> q;
        vector<vector<bool>> bfsVis(r, vector<bool>(c, 0));
        rep(i, 0, r) {
                rep(j, 0, c) {
                        cin >> grid[i][j];
                        if (grid[i][j] == 'R') {
                                q.push(mp(i, j));
                                bfsVis[i][j] = 1;
                        }
                        if (grid[i][j] == 'A') attack = mp(i, j);
                        if (grid[i][j] == 'K') king = mp(i, j);
                }
        }

        // multisource bfs
        int DIST = 0;
        while(!q.empty()) {
                vpii next;
                while(!q.empty()) {
                        pii cur = q.front();
                        q.pop();
                        dist[cur.F][cur.S] = DIST;
                        trav(d, dir) {
                                int y = cur.F+d.F;
                                int x = cur.S+d.S;
                                if (y >= 0 && y < r && x >= 0 && x < c && !bfsVis[y][x]) {
                                        bfsVis[y][x] = 1;
                                        next.pb(mp(y, x));
                                }
                        }
                }
                trav(p, next) {
                        q.push(p);
                }
                DIST++;
        }

        // binary search over ans
        int ans;
        int lo = 0, hi = r+c+1;
        while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if (dist[attack.F][attack.S] > mid && dfs(attack.F, attack.S, 0, mid)) {
                        ans = mid;
                        lo = mid+1;
                }
                else hi = mid-1;
                dfsVis = vector<vector<vector<bool>>>(r, vector<vector<bool>>(c, vector<bool>(4, 0)));
        }

        cout << ans+1;
}

int main() {
        faster
        solve();
}