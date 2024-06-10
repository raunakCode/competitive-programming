#include "bits/stdc++.h"
         
using namespace std;
         
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
         
typedef long long ll;
typedef vector<ll> vll;
         
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
 
void solve() {
	ll n, res;
	cin >> n;

	vll vals(n, 1);
	auto query = [&](ll a, ll b) -> void {
		cout << "? " << a + 1 << " " << b + 1 << endl;	
		cin >> res;
	};
	auto answer = [&]() -> void {
		cout << "! ";
		rep(i, 0, n) {
			cout << vals[i] << " ";
		}
		cout << endl;
	};

	vll nums(n);
	iota(all(nums), 0);

	random_device rd;
	mt19937 g(rd());
	shuffle(all(nums), g);	

	ll one = 0, two = 1;
	query(nums[one], nums[two]);
	ll val1 = res, val2;
	rep(i, 2, n) {
		query(nums[one], nums[i]);
		val2 = res;
		if (val2 < val1) {
			vals[nums[i]] = val2;
		}
		else if (val1 == val2) {
			vals[nums[one]] = val1;
			one = i;
			query(nums[one], nums[two]);
			val1 = res;
		}
		else {
			// val1 > val2
			vals[nums[two]] = val1;
			two = i;
			val1 = val2;	
		}
	}
	vals[nums[one]] = vals[nums[two]] = val1;

	answer();
}
 
int main() { 
        faster
	solve();
}

