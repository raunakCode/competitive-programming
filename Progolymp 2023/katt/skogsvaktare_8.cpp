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
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)

ll n, f;
vector<bool> contain;
vector<ll> fruit;

void solve() {
    cin >> n >> f;
    contain.resize(n, 0);
    for(ll i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
    }
    for(ll i = 0; i < f; i++) {
        ll node; cin >> node;
        node--;
        contain[node] = 1;
        fruit.pb(node);
    }
    sort(all(fruit));
    vector<ll> ans;
    for(ll i = 0; i < fruit.size(); i++) {
        if (i+1 < fruit.size() && (fruit[i+1]-fruit[i]) % 2 == 0) {
            ll mid = fruit[i] + (fruit[i+1]-fruit[i])/2;
            ans.pb(mid);
            i++;
        }
        else ans.pb(fruit[i]); 
    }
    cout << ans.size() << el;
    trav(x, ans) cout << x+1 << " ";
    
}

int main() {
    faster
    solve();
}