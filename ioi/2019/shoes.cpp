#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

ll count_swaps(vector<int> S) {
	Tree<ll> t;

	ll n = sz(S) / 2; // number of pairs
	vi a = S;

	vector<bool> done(2 * n);
	vector<set<ll>> pos(2 * n + 1);
	rep(i, 0, 2*n) {
		pos[a[i] + n].insert(i);
	}

	ll ans = 0;
	ll ind = 0;
	while(ind < 2 * n) {
		if (done[ind]) {
			ind++;
			continue;
		}

		ll cur = a[ind];

		auto buddy = pos[-cur + n].upper_bound(ind);
		ll bigger_than_buddy = t.order_of_key(-(*buddy));
		ll bigger_than_ind = t.order_of_key(-ind);

		ans += (*buddy) - ind - (cur < 0 ? 1 : 0) + bigger_than_buddy - bigger_than_ind;

		t.insert(-(*buddy));
		pos[-cur + n].erase(*buddy);
		done[ind] = 1;
		done[*buddy] = 1;
		ind++;
	}
	return ans;
}


