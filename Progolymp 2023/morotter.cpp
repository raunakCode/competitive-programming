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
    int t, m;
    cin >> t >> m;
    int tor = 0, mor = 0;
    int cnt = 40;
    int time = 0;
    while(cnt > 0) {
        if (cnt == 1 && time%t == 0 && time%m == 0) {
            break;
        }
        if (cnt > 0 && time%t == 0) {
            tor++;
            cnt--;
        }
        if (cnt > 0 && time%m == 0) {
            mor++;
            cnt--;
        }
        time++;
    }
    cout << "Tor: " << tor << " Mor: " << mor;
}
 
int main() {
    faster
    //cout << fixed << setprecision(10);
    int tt = 1;
    while(tt--) {
        solve();
    }
}