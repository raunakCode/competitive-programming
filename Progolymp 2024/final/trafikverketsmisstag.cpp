#include "bits/stdc++.h"
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
         
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
         
#define all(x) (x).begin(), (x).end()

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b-1); i >= (a); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

const int inf = 1e9;

// rmq and lca taken from kactl https://github.com/kth-competitive-programming/kactl
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
        vi time, path, ret, depth;
        RMQ<int> rmq;

        LCA(vector<vll>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
        void dfs(vector<vll>& C, int v, int par) {
            time[v] = T++;
            for (int y : C[v]) if (y != par) {
                depth[y] = depth[v] + 1;
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
        }

        ll lca(int a, int b) {
            if (a == b) return a;
            tie(a, b) = minmax(time[a], time[b]);
            return path[rmq.query(a, b)];
        }
        //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void solve() {
	ll n, c;
        cin >> n >> c;
        vvll graph(n);
        vector<bool> car(n);
        vll id(n), p(n), order;
        rep(i, 0, n-1) {
                ll x, y;
                cin >> x >> y; x--, y--;
                graph[x].pb(y);
                graph[y].pb(x);
        }
        LCA T(graph);
        vll w(n), h(n);
        rep(i, 0, c) {
                cin >> w[i];
        	w[i]--;
        	cin >> h[w[i]];
        	h[w[i]]--;
                car[w[i]] = 1;
                id[w[i]] = i + 1;
        }

        auto dfs = [&](const auto &self, ll v, ll par, ll car_parent) -> void {
                p[v] = car_parent;
                trav(child, graph[v]) {
                        if (child != par) {
                                ll x = (car[v] ? v : car_parent);
                                self(self, child, v, x);
                        }
                }
                return;
        };

        auto pfind = [&](const auto &self, ll v) -> ll {
		if (car[v]) return v;
		if (v == 0 || p[v] == inf) return inf;
                return p[v] = self(self, p[v]);
        };

        auto find_block = [&](ll start, ll home) -> ll {
                ll one = pfind(pfind, start);
                ll two = pfind(pfind, home);
        	ll onedepth = (one == inf ? -1 : T.depth[one]);
        	ll twodepth = (two == inf ? -1 : T.depth[two]);
                ll L = T.lca(start, home);
                if (onedepth >= T.depth[L]) return one;
                if (twodepth >= T.depth[L]) return two;
                return -1;
        };

        auto find_order = [&](const auto &self, ll at) -> void {
		car[at] = 0;
		ll block = find_block(at, h[at]);
		while(block != -1) {
			self(self, block);
			block = find_block(at, h[at]);
		}
                order.pb(at);
                return;
        };

        dfs(dfs, 0, -1, 0);

        rep(i, 0, n) {
                if (car[i]) {
                        find_order(find_order, i);
                }
        }

        bool win = (sz(order) == c);
	// we reset everything and try taking the order found
	trav(v, order) car[v] = 1;
	dfs(dfs, 0, -1, 0);
	trav(v, order) {
		car[v] = 0;
		ll block = find_block(v, h[v]);
		if (block != -1) win = 0;
	}

        if (win) {
                cout << "Yes" << el;
                trav(v, order) cout << id[v] << " ";
        }
    	else cout << "NO";
}

int main() {
        faster
	solve();
}
