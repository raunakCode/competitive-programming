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
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

const ll infLL = 1e18;

void solve() {
        ll n, t, s;
                cin >> n >> t >> s;
                vpll seg(n);
                rep(i, 0, n) {
                        cin >> seg[i].F >> seg[i].S;
                }
        seg.pb(mp(0, 0));
        seg.pb(mp(t, t));
        sort(all(seg));
	// ! need to also try starting at t-s ! 
        
        n = sz(seg);
                vll pref(n+1);
                pref[1] = seg[0].F;

                rep(i, 1, n) {
                        pref[i+1] = seg[i].F - seg[i-1].S + pref[i];
                }

        ll ans = infLL;

        rep(i, 0, n) {
                ll tid = seg[i].F + s;
                if (tid > t) continue;

                ll bst = 0;
                ll l = 0, r = n-1;
                while(l <= r) {
                        ll mid = l + (r-l)/2;
                        if (seg[mid].F <= tid) {
                                bst = mid;
                                l = mid + 1;
                        }
                        else r = mid - 1;
                }
                
                ll cur = 0;
                if (seg[bst].S >= tid) cur = pref[bst + 1] - pref[i+1];
                else cur = pref[bst + 1] - pref[i + 1] + (tid - seg[bst].S);
                ans = min(cur, ans);
        }

        per(i, 0, n) {
                ll tid = seg[i].S - s;
                if (tid < 0) continue;
                
                ll l = 0, r = n-1;
                ll bst = n-1;
                while(l <= r) {
                        ll mid = l + (r-l)/2;
                        if (seg[mid].S >= tid) {
                                bst = mid;
                                r = mid - 1;
                        }
                        else l = mid + 1;
                }
                
                ll cur = 0;
                if (seg[bst].F <= tid) cur = pref[i + 1] - pref[bst + 1];
                else cur = pref[i+1] - pref[bst + 1] + (seg[bst].F - tid);
                ans = min(cur, ans);
        }

	cout << ans;

}

int main() {
        faster
	solve();
}

