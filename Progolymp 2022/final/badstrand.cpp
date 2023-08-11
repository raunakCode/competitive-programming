#include "bits/stdc++.h"
 
using namespace std;

#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
        int n, b;
        cin >> n >> b;
        int a[n];
        rep(i, 0, n) cin >> a[i];
        int maxcnt = 0, sum = 0, cnt = 0;
        rep(i, 0, n) {
                if (sum + a[i] <= b) {
                        sum += a[i];
                        cnt++;
                }
                else {
                        sum += a[i] - a[i-cnt];
                }
                maxcnt = max(cnt, maxcnt);
        }
        cout << maxcnt;
}

int main() {
        faster
        solve();
}

