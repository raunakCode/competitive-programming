#include "bits/stdc++.h"
                 
using namespace std;
                 
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
                 
#define uset unordered_set

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
                 
#define all(x) (x).begin(), (x).end()

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)

vpll dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

ll r, c, q;

ll get_ind(ll R, ll C) {
	if (0 <= R && R < r && 0 <= C && C < c) {
		return R*c + C;
	}
	else return -1;
}

struct UF {
	vll col, parent;
	vector<uset<ll>> buddy;
	
	UF(ll n, vll grid): col(n), parent(n), buddy(n) {
		rep(i, 0, n) {
			parent[i] = i;
			col[i] = grid[i];
		}
	}

	ll find(ll x) {
		if (x != parent[x]) parent[x] = find(parent[x]);
		return parent[x];
	}
	void join(ll a, ll b, ll C) {
		a = find(a); b = find(b);
		if (a == b) return;

		assert(sz(buddy[a]) >= sz(buddy[b]));
		if (sz(buddy[a]) < sz(buddy[b])) swap(a, b);

		trav(nb, buddy[b]) {
			buddy[nb].erase(b);
			buddy[a].insert(nb);
			buddy[nb].insert(a);
		}
		buddy[b].clear(); // his list should be useless now
		parent[b] = a;
		assert(col[a] == C);
		col[a] = C;
	}
	void add_neighbor(ll a, ll b) {
		a = find(a); b = find(b);
		buddy[a].insert(b);
		buddy[b].insert(a);
	}
};

void solve() {
	vll mat(r*c);
	rep(i, 0, r*c) {
		cin >> mat[i];
	}

	UF uf(r*c, mat);

	rep(phase, 0, 2) { // good to make all the sets before making the neighbour list
		rep(i, 0, r) rep(j, 0, c) {
			ll cur = get_ind(i, j);
			trav(d, dirs) {
				ll y = i + d.F, x = j + d.S;
				ll nb = get_ind(y, x);

				if (nb == -1) continue;

				if (uf.col[cur] == uf.col[nb] && phase == 0) {
					uf.join(cur, nb, mat[nb]);
				}
				else if (uf.col[cur] != uf.col[nb] && phase == 1) {
					uf.add_neighbor(cur, nb);
				}
			}
		}
	}

	cin >> q;
	while(q--) {
		ll y, x, C;
		cin >> y >> x >> C; y--, x--; 
		ll cur = uf.find(get_ind(y, x));
		if (uf.col[cur] != C) {
			ll bst = 0;
			ll mx = 0;
			trav(nb, uf.buddy[cur]) {
				uf.buddy[nb].erase(cur);
				if (sz(uf.buddy[nb]) > mx) {
					mx = sz(uf.buddy[nb]);
					bst = nb;
				}
			}
			uf.parent[cur] = bst;
			trav(nb, uf.buddy[cur]) {
				uf.join(bst, nb, C);
			}
			uf.buddy[cur].clear();
		}
	}

	rep(i, 0, r) {
		rep(j, 0, c) {
			cout << uf.col[uf.find(get_ind(i, j))] << " ";
		}
		cout << el;
	}
}

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
	cin >> r >> c;	
	if (r * c <= 10000) solve1();
	else if (r == 1) solve2();
	else solve();
}


