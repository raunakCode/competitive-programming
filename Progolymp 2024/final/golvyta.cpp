#include "bits/stdc++.h"
 
using namespace std;
 
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
 
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
 
const int inf = 2e9;

void solve() {
        ll k, r, c;
        string s;
        cin >> k >> s >> r >> c;
        vector<char> lr, ud;
        trav(ch, s) {
                if (ch == 'v' || ch == '^') ud.pb(ch);
                else lr.pb(ch);
        }
        bool mfound, nfound = 0;
        // first up down
        ll lo = r, hi = 300000;
        ll mx_row = 0;
        while(lo <= hi) {
                ll mid = lo + (hi-lo)/2;
                ll pos = 0;
                trav(ch, ud) {
                        if (ch == 'v') pos = min(mid, pos + 1);
                        else pos = max(0LL, pos - 1);
                }
                if (pos < r) {
                        lo = mid + 1;
                }
                else if (pos > r) {
                        hi = mid - 1;
                }
                else if (pos == r) {
                        mx_row = mid;
                        nfound = 1;
                        hi = mid - 1;
                }
        }

        lo = c, hi = 300000;
        ll mx_col = 0;
        while(lo <= hi) {
                ll mid = lo + (hi-lo)/2;
                ll pos = 0;
                trav(ch, lr) {
                        if (ch == '>') pos = min(mid, pos + 1);
                        else pos = max(0LL, pos - 1);
                }
                if (pos < c) {
                        lo = mid + 1;
                }
                else if (pos > c) {
                        hi = mid - 1;
                }
                else if (pos == c) {
                        mx_col = mid;
                        mfound = 1;
                        hi = mid - 1;
                }
        }
        cout << ((mfound && nfound) ? (mx_col + 1) * (mx_row + 1) : -1);
}
 
int main() {
        faster
	solve();
}
