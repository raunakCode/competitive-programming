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

int n, k;
vvi graph;

int rec(int node, int par, int mid, int &walls) {
        int val = 1;        
        trav(child, graph[node]) {
                if (child != par) {
                        val += rec(child, node, mid, walls);
                }
        }
        if (val > mid) {
                walls++;
                return 0;
        }
        return val;
}

void solve() {
        cin >> n >> k;
        graph.resize(n);
        rep(i, 0, n-1) {
                int v; cin >> v;
                v--;
                graph[i+1].pb(v);
                graph[v].pb(i+1);
        }

        int lo = 0, hi = n;
        int ans = n;
        while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                int walls = 0;
                rec(0, 0, mid, walls);
                if (walls <= k) { // aka joshua could save it
                        hi = mid - 1;   
                        ans = min(mid, ans);
                }
                else {
                        lo = mid + 1;
                }
        }
        cout << ans;
}

int main() {
        faster
	solve();
}

