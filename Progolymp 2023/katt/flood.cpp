#include "bits/stdc++.h"
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define sz(x) (int)(x).size()
#define setcontains(set, x) (set.find(x) != set.end())
         
#define umap unordered_map
#define uset unordered_set

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
         
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
const ll inf = 1e11;
const ll heavy = 30;

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
	vector<uset<ll>> edges;
	vector<umap<ll, set<ll>>> buddy;
	vector<uset<ll>> heavybuddy;
	uset<ll> bigboys;
	
	UF(ll n, vll grid): col(n), parent(n), edges(n), buddy(n), heavybuddy(n) {
		rep(i, 0, n) {
			parent[i] = i;
			col[i] = grid[i];
		}
	}

	ll find(ll x) {
		if (x != parent[x]) parent[x] = find(parent[x]);
		return parent[x];
	}
	void merge(ll a, ll b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[b] = a;
	}
	void bucket(ll node, ll C) {
		node = find(node);
		col[node] = C;
		ll bst = node;

		uset<ll> compnodes;
		for(auto it = buddy[node][C].begin(); it != buddy[node][C].end();) {
			ll e = find(*it);
			if (col[e] == C) {
				compnodes.insert(*it);
				if (sz(edges[e]) > sz(edges[bst])) {
					bst = e;
				}
				it = next(it);
			}
			else {
				it = buddy[node][C].erase(it);
			}
		}
		buddy[node][C].clear();
		
		trav(edge, heavybuddy[node]) {
			ll e = find(edge);
			if (col[e] == C) {
				compnodes.insert(e);
				if (sz(edges[e]) > sz(edges[bst])) {
					bst = e;
				}
			}
		}
		compnodes.insert(node);
		trav(cur, compnodes) {
			ll cnode = find(cur);
			if (cnode == bst) continue; 
			parent[cnode] = bst;
			trav(edge, edges[cnode]) {
				heavybuddy[edge].erase(cur);	
				heavybuddy[edge].erase(cnode);	
				ll e = find(edge);
				if (setcontains(bigboys, bst)) {
					heavybuddy[e].insert(bst);
				}
				edges[bst].insert(e);
			}
			trav(edge, heavybuddy[cnode]) {
				ll e = find(edge);
				heavybuddy[bst].insert(e);
			}
			trav(edge, buddy[cnode]) {
				trav(nb, edge.S) {
					buddy[bst][edge.F].insert(nb);
				}
			}
		}
		node = find(node);
		if (!setcontains(bigboys, node)) {
			if (sz(edges[node]) > heavy) {
				bigboys.insert(node);
				trav(edge, edges[node]) {
					ll e = find(edge);
					heavybuddy[e].insert(node);
				}
			}
			else {
				trav(edge, edges[node]) {
					ll e = find(edge);
					buddy[e][C].insert(node);
				}
			}
		}
	}
};

void solve() {
	cin >> r >> c;
	vll grid(r*c);
	rep(i, 0, r*c) {
		cin >> grid[i];
	}

	UF uf(r*c, grid);

	rep(phase, 0, 2) {
		rep(i, 0, r) rep(j, 0, c) {
			ll cell = get_ind(i, j);
			ll cell_leader = uf.find(cell);
			trav(d, dirs) {
				ll y = i + d.F, x = j + d.S;		
				if (y < 0 || y >= r || x < 0 || x >= c) continue;
				ll nb_cell = get_ind(y, x);
				ll nb_leader = uf.find(nb_cell);

				if (grid[cell] == grid[nb_cell] && phase == 0) {
					uf.merge(cell, nb_cell);
				}
				else if (grid[cell] != grid[nb_cell] && phase == 1) {
					uf.buddy[cell_leader][uf.col[nb_leader]].insert(nb_leader);
					uf.buddy[nb_leader][uf.col[cell_leader]].insert(cell_leader);
					uf.edges[cell_leader].insert(nb_leader);
					uf.edges[nb_leader].insert(cell_leader);
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
			uf.bucket(cur, C);
		}
	}

	rep(i, 0, r) {
		rep(j, 0, c) {
			cout << uf.col[uf.find(get_ind(i, j))] << " ";
		}
		cout << el;
	}
}

int main() { 
	faster
	solve();
}


