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

ll r, c, k, n;
set<ll> water;  
vector<pll> block;
set<pll> exist;
set<pll> vis;

void solve() {
    cin >> r >> c >> k >> n;
    block.resize(n);
    for(int i = 0; i < k; i++) {
        ll x; cin >> x;
        water.emplace(x);
    } 
    for(int i = 0; i < n; i++) {
        ll y, x;
        cin >> y >> x;
        block[i] = {y, x};
        exist.emplace(block[i]);
    }
    sort(all(block), greater<pll>());
    for(int i = 0; i < block.size(); i++) {
        int curY = block[i].F;
        if (water.count(block[i].S) && vis.count({curY, block[i].S}) == 0) {
            queue<ll> q;
            q.push(block[i].S);
            while(q.size()) {
                ll cur = q.front();
                vis.emplace((pll){curY, cur});
                q.pop();
                if (cur+1 < c && exist.count({curY+1, cur+1}) == 0) {
                    if (vis.count({curY, cur+1}) == 0) water.emplace(cur+1);
                    if (exist.count({curY, cur+1}) == 1 && vis.count({curY, cur+1}) == 0) {
                        pii w = {curY, cur+1};
                        q.push(cur+1);
                    }
                }
                if (cur-1 >= 0 && exist.count({curY+1, cur-1}) == 0) {
                    if (vis.count({curY, cur-1}) == 0) water.emplace(cur-1);
                    if (exist.count({curY, cur-1}) == 1 && vis.count({curY, cur-1}) == 0) {
                        pii w = {curY, cur-1};
                        q.push(cur-1);
                    }
                }
                water.erase(cur);
            }
        }
    }
    cout << water.size();

}

int main() {
    faster
    solve();
}