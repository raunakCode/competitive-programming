#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin >> n;
	vector<ll> p(n);

	rep(i, 0, n) cin >> p[i];
	vector<vector<ll>> graph(n);
	rep(_, 0, n - 1) {
		ll x, y;
		cin >> x >> y; x--, y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<ll> dp(n);
	vector<ll> totalTaxi(n);
	auto dfs = [&](auto &self, ll at, ll par = -1) -> ll {
		ll taxi = 0;
		for(auto &child: graph[at]) {
			if (child != par) {
				ll cur = self(self, child, at);
				taxi += cur;
			}
		}
		totalTaxi[at] = taxi;
		dp[at] = max(taxi, p[at]);
		return dp[at];
	};

	dfs(dfs, 0);

	ll tempMx = 0;
	for(auto &child: graph[0]) {
		tempMx = max(dp[child], tempMx);
	}
	ll bst = max(max(tempMx, p[0]), (dp[0] + 1LL) / 2LL);

	auto find_best = [&](auto &self, ll at, ll par) -> void {
		// save old values
		ll at_old = dp[at];
		ll par_old = dp[par];
		// change values (at and par[at])
		ll parTaxi = totalTaxi[par] - dp[at];
		dp[par] = max(parTaxi, p[par]);

		ll mx = 0;
		for(auto &child: graph[at]) {
			mx = max(dp[child], mx);
		}
		totalTaxi[at] = totalTaxi[at] + dp[par];
		dp[at] = max(totalTaxi[at], p[at]);
		ll cur = max(max(mx, p[at]), (dp[at] + 1LL) / 2LL);
		bst = min(cur, bst);

		// make children the root
		for(auto &child: graph[at]) {
			if (child != par) self(self, child, at);
		}

		// return values to their original state
		dp[at] = at_old;
		dp[par] = par_old;
	};

	for(auto &child: graph[0]) {
		find_best(find_best, child, 0);
	}

	cout << bst;
}
