#include "bits/stdc++.h" 
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define F first
#define S second
         
typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
    ll l, r;
    cin >> l >> r;
    int q; cin >> q;
    set<pll> lt;
    set<pll> rt;
    map<ll, pll> w;
    while(q--) {
        char c; cin >> c;
        if (c == '+') {
            ll s, a, b;
            cin >> s >> a >> b;
            w[s] = mp(a, b);
            if (a <= l && l <= b) {
                lt.insert(mp(b-l, s));
            }
            if (a <= r && r <= b) {
                rt.insert(mp(r-a, s));
            }
        }
        else {
            ll s; cin >> s;
            ll a, b;
            tie(a, b) = w[s];
            if (a <= l && l <= b) {
                lt.erase(mp(b-l, s));
            }
            if (a <= r && r <= b) {
                rt.erase(mp(r-a, s));
            }
        }
        if ((int) lt.empty() || rt.empty()) {
            cout << -1 << el;
            continue;
        }
        ll ls = (*lt.rbegin()).F;
        ll rs = (*rt.rbegin()).F;
        if (max(ls, rs) >= r-l) {
            cout << 1 << el;
        }
        else if (ls + rs >= r-l) {
            cout << 2 << el;
        }
        else cout << -1 << el;
    }
}

int main() {
        faster
	solve();
}

