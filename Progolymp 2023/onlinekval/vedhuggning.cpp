#include "bits/stdc++.h"
 
#define el "\n"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
 
using namespace std;

void solve() {
    ll n, s;
    cin >> n >> s;
    ll inc = 0;
    ll l = 0;
    vector<vector<ll>> tree;
    set<ll> times;
    map<ll, ll> w;
    rep(i, 0, n) {
        vector<ll> k;
        ll x;
        rep(j, 0, 3) {
            cin >> x;
            if (j == 0) l += x;
            if (j == 1) inc += x;
            if (j == 2) {
                times.insert(x);
            }
            k.pb(x);
        }
        vector<ll> tru;
        tru.pb(k[2]);
        tru.pb(k[0]);
        tru.pb(k[1]);
        tree.pb(tru);
    }
    ll needed = s-l;
    if (needed <= 0) {
        cout << 0;
        return;
    }
    sort(all(tree));
    rep(i, 0, n) {
        w[tree[i][0]] += tree[i][2];
    }
    vector<ll> rTimes;
    trav(x, times) rTimes.pb(x);
    vector<ll> psum(rTimes.size(), inc);    
    psum[0] -= w[rTimes[0]];
    for(ll i = 1; i < rTimes.size(); i++) {
        psum[i] = psum[i-1];
        psum[i] -= w[rTimes[i]];
    }
    ll cnt = 0;
    ll pos = 0;
    ll bought = inc*(rTimes[0]-0);
    cnt += bought;
    if (cnt < needed) {
        for(ll i = 1; i < psum.size(); i++) {
            bought = psum[i-1]*(rTimes[i]-rTimes[i-1]);
            cnt += bought;
            if (cnt >= needed) {
                pos = i;
                break;
            } 
        } 
    }
    else {
        ll sec = (needed + inc - 1) / inc;
        cout << sec;
        return;
    }
    if (cnt == needed) {
        cout << rTimes[pos];
        return;
    }
    else {
        pos--;
        cnt-=bought;
        ll r = needed-cnt;
        ll sec = (r + psum[pos] - 1) / psum[pos];
        cout << sec + rTimes[pos];
        return;

    }

}
 
int main() {
    faster
    //cout << fixed << setprecision(10);
    int tt = 1;
    while(tt--) {
        solve();
    }
}