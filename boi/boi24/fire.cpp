#include "bits/stdc++.h"
         
using namespace std;
        
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define sz(x) (int)(x).size()
         
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
         
#define all(x) (x).begin(), (x).end()

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b-1); i >= (a); --i)
#define trav(a, x) for (auto &a : x)

const ll inf = 1e11;

void solve() {
	ll n, m;
	cin >> n >> m;
	ll mn = inf;
	vector<array<ll, 2>> times;
	rep(i, 0, n) {
		array<ll, 2> cur;
		rep(j, 0, 2) {
			cin >> cur[j];
		}
		times.pb(cur);
		if (times.back()[0] > times.back()[1]) times.back()[1] += m;
		else {
			array<ll, 2> tmp;
			tmp[0] = times.back()[0] + m;
			tmp[1] = times.back()[1] + m;
			times.pb(tmp);
		}
	}

	sort(all(times));

	vector<array<ll, 2>> itv;
	ll R = -1;
	rep(i, 0, sz(times)) {
		if (times[i][1] > R) {
			R = times[i][1];
			itv.pb(times[i]);
		}
	}
	swap(times, itv);

	vector<vector<ll>> up(25, vll(sz(times)));

	ll ind = 0;
	
	ll bst = 0;

	rep(i, 0, sz(times)) {
		array<ll, 2> seg = times[i];

		while(ind < sz(times)) {
			if (times[ind][0] > seg[1]) break;
			if (times[ind][1] > times[bst][1]) bst = ind;
			ind++;
		}
		up[0][i] = bst;
	}

	rep(k, 1, 25) {
		rep(i, 0, sz(times)) {
			up[k][i] = up[k-1][up[k-1][i]];
		}
	}
	
	rep(i, 0, sz(times)) {
		array<ll, 2> cur = times[i];
		ll endpoint = cur[0] + m;

		ll cnt = 1;
		int ind = i;
		per(k, 0, 25) {
			if (times[up[k][ind]][1] < endpoint) {
				cnt += (1 << k);
				cur = times[up[k][ind]];
				ind = up[k][ind];
			}
		}
		cnt++;
		cur = times[up[0][ind]];
		if (cur[1] >= endpoint) {
			mn = min(cnt, mn);
		}
	}

	cout << (mn == inf ? -1 : mn);
}

int main() { 
        faster
	solve();
}

