#include "bits/stdc++.h"
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
 
#define umap unordered_map
#define uset unordered_set
         
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
         
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
// RMQ and LCA taken from kactl

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi depth, time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vll>& C) : depth(sz(C)), time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vll>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			depth[y] = depth[v] + 1;
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	ll dist(ll a, ll b) {return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

ll t;

vvll graph;
vll parent;
vll euler;
vll deg;

void precomp(ll node, ll p) {
	euler.pb(node);
	parent[node] = p;	
	trav(child, graph[node]) {
		if (child != p) {
			precomp(child, node);
		}
	}
	euler.pb(node);
}

void encode() {
	ll n; cin >> n;	
	graph.assign(n, vll());
	parent.assign(n, -1);
	deg.assign(n, 0);
	rep(i, 0, n - 1) {
		ll a, b;
		cin >> a >> b; a--, b--;
		graph[a].pb(b);
		graph[b].pb(a);
		deg[a]++, deg[b]++;
	}

	precomp(0, -1);
	
	LCA lca(graph);

	vll code;

	trav(node, euler) {
		if (deg[node] == 1) {
			code.pb(node);
			deg[node]--;
			if (parent[node] != -1) deg[parent[node]]--;
		}
	}
	code.pb(0);

	trav(d, code) cout << d + 1 << " ";
}

void decode() {
	ll n; cin >> n;
	vll op(n-1);
	rep(i, 0, n-1) cin >> op[i];

	graph.assign(n, vll());
	umap<ll, ll> par;
	ll vertices = 1;	

	auto add_edge = [&](ll a, ll b) -> void {
		graph[a].pb(b);
		graph[b].pb(a);
	};

	ll cur = 0;
	trav(d, op) {
		assert(d > 0);
		if (d == 1) {
			if (!par.count(cur)) {
				par[cur] = vertices;
				vertices++;
				add_edge(cur, par[cur]);
				cur = par[cur];
			}
			else {
				cur = par[cur];
			}
		}
		else {
			ll down = d - 1;
			if (!par.count(cur)) {
				par[cur] = vertices;
				add_edge(cur, par[cur]);
				vertices++;
			}

			cur = par[cur];

			while(down > 0) {
				ll new_node = vertices;
				add_edge(cur, new_node);
				vertices++;
				par[new_node] = cur;
				cur = new_node;
				down--;
			}
		}
	}

	set<pll> edges;
	rep(node, 0, n) {
		trav(child, graph[node]) {
			edges.insert(mp(min(ll(node), child), max(ll(node), child)));
		}
	}

	trav(edge, edges) {
		cout << edge.F + 1 << " " << edge.S + 1 << el;
	}
}

int main() { 
        faster
	cin >> t;		
	if (t == 1) encode();
	else decode();
}
