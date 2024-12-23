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

	cout.precision(20);
    	ll n; cin >> n;
    	vector<pair<ll, ll>> ducks(2*n);
    	rep(i, 0, 2*n) {
        	cin >> ducks[i].first >> ducks[i].second;
    	}
    	long double k = 3.1415926535;
    	long double lo = -10000000;
    	long double hi = 10000000;
    	rep(_, 0, 70) {
        	long double mid = lo + (hi - lo) * 0.5;
        	ll cnt = 0;
        	for(auto &duck: ducks) {
            		long double x = double(duck.first);
            		long double y = double(duck.second);
            		if (y <= k * x + mid) cnt++;
        	}
        	if (cnt < n) lo = mid;
        	else hi = mid;
    	}
    	cout << k << " " << lo + 0.00000001;
}
