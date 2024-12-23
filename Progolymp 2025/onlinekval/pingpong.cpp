#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
         
using namespace std;
using namespace __gnu_pbds;
 
/* typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set; */
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define sq(x) (x)*(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
         
#define umap unordered_map
#define uset unordered_set

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
#define per(i, a, b) for (int i = (b-1); i >= (a); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)
         
struct chash { // large odd number for C
      const uint64_t C = ll(4e18 * acos(0)) | 71;
      ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};
 
template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;
template<typename T, typename H> using fast_set_h = __gnu_pbds::gp_hash_table<T, null_type, H>;
template<typename T, typename U> using fast_map = __gnu_pbds::gp_hash_table<T, U, chash>;
 
#ifdef DEBUG
#include "/home/redkar/kod/cp/lib/debug.cpp"
#else
#define dbg(...)
#define dbgArr(...)
#endif

const ll inf = 1e11;

void solve() {
        ll n; cin >> n;
        vll wins(n);
        ll LOG = 63 - __builtin_clzll(n);
        vll freq(LOG + 1);
    	map<ll, vll> who;
        rep(i, 0, n) {
		cin >> wins[i];
		if (wins[i] > LOG) {
		    cout << -1;
		    return;
		}
		freq[wins[i]]++;
		who[wins[i]].pb(i);
        }
        per(i, 0, LOG + 1) {
                ll val = LOG - i;
                if (freq[i] != (1LL<<val) - (val == 0 ? 0 : (1LL<<(val-1)))) {
                        cout << -1;
                        return;
                }
        }
        vll ans = who[LOG];
        per(i, 0, LOG) {
                vll cur = who[i];
                sort(all(cur));
                vll temp;
                rep(i, 0, sz(ans)) {
                        temp.pb(min(ans[i], cur[i]));
                        temp.pb(max(ans[i], cur[i]));
                }
                swap(temp, ans);
        }
        trav(x, ans) cout << x + 1 << " ";


}


int main() { 
    faster
    int test = 1; // cin >> test;
    REP(tc, 1, test) {
        solve();
    }
}
 
