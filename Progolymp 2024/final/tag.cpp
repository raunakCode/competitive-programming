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

void solve() {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        unordered_map<string, bool> hunter;
        rep(i, 0, n) {
                cin >> a[i];
        }
        hunter[a[0]] = 1;
       	set<string> cheaters;
        while(m--) {
                string A, c, B; 
                cin >> A >> c >> B;
                if (!hunter[A]) cheaters.insert(A);
                hunter[B] = 1;
                if (hunter[A]) hunter[A] = 0;
        }
        cout << sz(cheaters) << el;
        trav(x, cheaters) cout << x << " ";
}

int main() {
        faster
	solve();
}
