#include "bits/stdc++.h"

#define faster ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

void solve() {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);
        vector<ll> b(m);
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < m; i++) cin >> b[i];
        sort(all(a));
        sort(all(b));

        if (n == m) {
                ll sum = 0;
                for(ll i = 0; i < n; i++) {
                        sum += abs(a[i]-b[i]);
                }
                cout << sum;
                return;
        }

        vector<ll> forward(n);
        vector<ll> backward(n);
        ll sum = 0;
        for(ll i = 0; i < n; i++) {
                sum += abs(a[i]-b[i]);
                forward[i] = sum; 
        }
        sum = 0;
        for(ll i = m-1; i >= 1; i--) {
                sum += abs(a[i-1]-b[i]);
                backward[i-1] = sum;
        }

        ll mn = LLONG_MAX;
        for(ll i = 0; i < m; i++) {
                ll sum = 0;
                if (i == 0) {
                        sum = backward[0];
                }
                else if (i == n) {
                        sum = forward[n-1];
                }
                else {
                        ll c = forward[i-1];
                        ll d = backward[i];
                        sum = c+d;
                }       
                mn = min(sum, mn);
        }
        cout << mn;
}

int main() {
        faster
        solve();
}