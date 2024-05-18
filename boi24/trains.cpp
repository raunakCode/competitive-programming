#include "bits/stdc++.h"
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
         
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
         
const ll S = 250;
const ll mod = 1e9+7;

void solve() {
	ll n; cin >> n;
	vpll trains(n);
	rep(i, 0, n) {
		cin >> trains[i].F >> trains[i].S;
	}

	vll dp(n);
	vvll rest(S, vll(S));
	vector<vpll> rmv(n);
	dp[0] = 1;

	rep(i, 0, n) {
		ll d, x;
		tie(d, x) = trains[i];

		// remove stage - Sqrt(N)
		trav(block, rmv[i]) {
			ll amount, D;
			tie(amount, D) = block;
			rest[D][i % D] -= amount;	
			rest[D][i % D] = (rest[D][i % D] + 2 * mod) % mod;
		}

		// calc dp[i] stage
		rep(j, 1, S) {
			ll res_class = i % j;
			dp[i] = (dp[i] + rest[j][res_class]) % mod;
		}

		if (d == 0) continue; // useless

		// sqrt decomp
		if (d > S - 1) {
			// brute if bigger then S
			for(ll j = i + d; j <= i + d*x && j < n; j += d) {
				dp[j] = (dp[j] + dp[i]) % mod;
			}
		}
		else {
			// add to special array
			rest[d][i % d] = (rest[d][i % d] + dp[i]) % mod;
			// remove from special array when it stops applying
			if (i + d * (x + 1) < n) {
				rmv[i + d * (x + 1)].pb(mp(dp[i], d));
			}
		}
	}
	ll ans = 0;
	rep(i, 0, n) {
		ans = (ans + dp[i]) % mod;
	}
	cout << ans;
}

int main() { 
        faster
	solve();
}

