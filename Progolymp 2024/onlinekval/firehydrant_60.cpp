#include "bits/stdc++.h" 
         
using namespace std;
         
#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
         
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
         
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    vvi grid(h, vi(w));
    vpii fire(n);
    vvi time(h, vi(w));
    rep(i, 0, h) rep(j, 0, w) time[i][j] = i + j;
    rep(i, 0, n) {
        cin >> fire[i].F >> fire[i].S;
        fire[i].F--, fire[i].S--;
        swap(fire[i].F, fire[i].S);
    }
    vvi water(h, vi(w));
    rep(i,0,h) rep(j,0,w) {
        trav(cur, fire) {
            int dist = abs(cur.F-i) + abs(cur.S-j);
            water[i][j] += max(0, time[i][j] - dist +1);
        }
    }
    vvi dp(h, vi(w, 0));
    dp[0][0] = water[0][0];
    rep(j, 1, w) dp[0][j] = water[0][j] + dp[0][j-1];
    rep(i, 1, h) dp[i][0] = water[i][0] + dp[i-1][0];
    rep(i, 1, h) {
        rep(j, 1, w) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + water[i][j];
        }
    }
    cout << dp[h-1][w-1];
}

int main() {
        faster
	solve();
}
