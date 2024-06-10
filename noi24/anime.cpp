#include "bits/stdc++.h"
         
using namespace std;
         
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
         
#define uset unordered_set

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
         
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
         
const ll inf = 1e11;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vvll graph(n);
	vll anime(k);
	rep(i, 0, k) {
		cin >> anime[i];
		anime[i]--;
	}
	rep(i, 0, m) {
		ll x, y;
		cin >> x >> y; x--, y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	vll dist(n, inf);

	min_heap<pair<ll, pll>> pq;
	trav(shop, anime) pq.push(mp(0, mp(shop, shop)));

	vector<uset<ll>> vis(n);

	while(!pq.empty()) {
		min_heap<pair<ll, pll>> nxt;

		while(!pq.empty()) {
			pair<ll, pll> cur = pq.top();
			pq.pop();
			ll d = cur.F, node, source;
			tie(node, source) = cur.S;

			if (sz(vis[node]) == 2) continue;
			vis[node].insert(source);
			assert(sz(vis[node]) <= 2);

			if (node != source) {
				dist[node] = min(d, dist[node]);
			}
			trav(child, graph[node]) {
				if (sz(vis[child]) < 2 && !vis[child].count(source)) {
					nxt.push(mp(d + 1, mp(child, source)));
				}
			}
		}

		swap(nxt, pq);
	}

	trav(d, dist) {
		cout << (d == inf ? -1 : d) << " ";
	}

}

int main() { 
	faster
	solve();
}

