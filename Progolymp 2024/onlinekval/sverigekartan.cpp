#include "bits/stdc++.h"
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
         
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
         
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
vpii dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vvi big;
vector<vpii> par;
vector<vector<char>> grid;

pii find(pii node) {
        if (node == par[node.F][node.S]) return par[node.F][node.S];
        return par[node.F][node.S] = find(par[node.F][node.S]);
}

void unify(pii a, pii b) {
        a = find(a);
        b = find(b);
        if (a != b) {
                if (big[a.F][a.S] < big[b.F][b.S]) {
                        swap(a, b);
                }
                par[b.F][b.S] = a;
                big[a.F][a.S] += big[b.F][b.S];
        }
}

void printsz(pii a) {
    a = find(a);
    cout << big[a.F][a.S] << el;
}

void solve() {
    int r, c, u;
    cin >> r >> c >> u;
    par.resize(r, vpii(c));
    big.resize(r, vi(c, 1));
    grid.resize(r, vector<char>(c, '.'));
    pii s;
    rep(i, 0, r) rep(j, 0, c) par[i][j] = mp(i, j);
    rep(i, 0, r) rep(j, 0, c) {
        cin >> grid[i][j];
        if (grid[i][j] == 'S') {
            s = mp(i, j);
            grid[i][j] = '#';
        }
    }
    rep(i, 0, r) rep(j, 0, c) {
        if (grid[i][j] == '#') {
            trav(d, dirs) {
                int y = i+d.F, x = j+d.S;
                if (0 <= y && y < r && 0 <= x && x < c && grid[y][x] == '#') {
                    unify(mp(i, j), mp(y, x));
                }
            }
        }
    }
    printsz(s);
    while(u--) {
        int y, x;
        cin >> y >> x; y--, x--;
        grid[y][x] = '#';
        trav(d, dirs) {
            int Y = y+d.F, X = x+d.S;
            if (0 <= Y && Y < r && 0 <= X && X < c && grid[Y][X] == '#') {
                unify(mp(y, x), mp(Y, X));
            }
        }
        printsz(s);
    }
}

int main() {
        faster
	solve();
}

