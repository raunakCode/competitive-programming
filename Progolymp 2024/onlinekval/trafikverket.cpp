#include "bits/stdc++.h" 
#include <ext/pb_ds/assoc_container.hpp>
         
using namespace std;
using namespace __gnu_pbds;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
         
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
         
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
struct chash { // large odd number for C
      const uint64_t C = ll(4e18 * acos(0)) | 71;
      ll operator()(pll x) const { return __builtin_bswap64((x.F + x.S) * C); }
};
 
template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;
template<typename T, typename H> using fast_set_h = __gnu_pbds::gp_hash_table<T, null_type, H>;
template<typename T, typename U> using fast_map = __gnu_pbds::gp_hash_table<T, U, chash>;

vvi graph;
vi par;
vi depth;
vector<vpii> up;

void precomp(int node, int parent, int d) {
    	par[node] = parent;
    	depth[node] = d;
    	trav(child, graph[node]) {
        	if (child != parent) precomp(child, node, d+1);
    	}
}

int get_lca(int a, int b) {
        if (depth[a] < depth[b]) {
        	swap(a, b);
        }
        int k = depth[a] - depth[b];
        for(int i = 20; i >= 0; i--) {
		if (k & (1<<i)) {
			a = up[a][i].F;
		}
        }
        if (a == b) return a;
        for(int i = 20; i >= 0; i--) {
		if (up[a][i].F != up[b][i].F) {
			a = up[a][i].F;
			b = up[b][i].F;
		}
        }
        a = up[a][0].F;
        return a;
}

void solve() {
    	int n; cin >> n;
    	graph.resize(n);
    	par.resize(n);
    	depth.resize(n);
    	up.resize(n, vpii(21, mp(0, 0)));
    	fast_set<pii> u;
    	rep(i, 0, n-1) {
		int a, b;
		cin >> a >> b; a--, b--;
		graph[a].pb(b);
		graph[b].pb(a);
		u.insert(mp(a, b));
    	}

    	precomp(0, 0, 0);

    	rep(node, 0, n) {
		int p = par[node];
		pii edge = mp(p, node);
		up[node][0].F = p;
		if (u.find(edge) != u.end()) {
		    	up[node][0].S = 1;
		}
    	}
    	rep(k, 1, 21) {
		rep(node, 0, n) {
		    	up[node][k].F = up[up[node][k-1].F][k-1].F;
		    	up[node][k].S = up[node][k-1].S + up[up[node][k-1].F][k-1].S;
		}
    	}

    	int q; cin >> q;
    	while(q--) {
		int h, w;
		cin >> h >> w; h--, w--;
		int lca = get_lca(h, w);
		int lca_depth = depth[lca];
		int workDist = depth[w] - lca_depth;
		int homeLca = 0, workLca = 0;
		for(int k = 20; k >= 0; k--) {
		    	int nxt = up[h][k].F;
		    	if (depth[nxt] > lca_depth) {
				homeLca += up[h][k].S;
				h = up[h][k].F;
		    	}
		}
		if (h != lca) homeLca += up[h][0].S;
		for(int k = 20; k >= 0; k--) {
		    	int nxt = up[w][k].F;
		    	if (depth[nxt] > lca_depth) {
				workLca += up[w][k].S;
				w = up[w][k].F;
		    	}
		}
		if (w != lca) workLca += up[w][0].S;
		cout << (homeLca == 0 && workLca == workDist ? "ja" : "nej") << el;
    	}
}

int main() {
        faster
	solve();
}

