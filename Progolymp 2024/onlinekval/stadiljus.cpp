#include "bits/stdc++.h" 
         
using namespace std;
         
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
         
typedef long long ll;
typedef vector<ll> vll;
         
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    ll sum = 0;
    ll cnt = 0;
    rep(i, 0, n) {
        sum += a[i] * x;
        if (sum > (i + 1) * y) break;
        cnt++;  
    }
    cout << cnt;
    
}

int main() {
        faster
	solve();
}

