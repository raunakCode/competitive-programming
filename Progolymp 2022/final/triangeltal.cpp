#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

void solve() {
        int n; cin >> n;
        vpii a(n);
        rep(i, 0, n) {
                cin >> a[i].F;
                a[i].S = i; 
        } 
        sort(all(a));
        vi ans(n);
        int mx = a[n-1].F;
        bool win = 0;
        rep(i, 0, n-2) {
                int endTwo = i + a[i].F;
                int endTwo2 = n-1-a[i].F;
                bool type2 = 0;

                // first case : 1 2 3
                if (endTwo < n && i+1 >= mx && endTwo-i >= a[i].F && n-1-endTwo >= a[endTwo].F) {
                        win = 1;
                }
                if (endTwo < n && i+1 >= a[endTwo].F && endTwo-i >= mx && n-1-endTwo >= a[i].F) {
                        win = 1;
                        type2 = 1;
                }

                // second case : 2 3 1
                if (endTwo2 < n && i+1 >= mx && endTwo2-i >= a[i].F && n-1-endTwo2 >= a[endTwo2].F) {
                        endTwo = endTwo2;
                        win = 1;
                }
                if (endTwo2 < n && i+1 >= a[endTwo2].F && endTwo2-i >= mx && n-1-endTwo2 >= a[i].F) {
                        endTwo = endTwo2;
                        win = 1;
                        type2 = 1;
                }

                if (win) {
                        REP(j, 0, i) {
                                ans[a[j].S] = 1;
                        }
                        REP(j, i+1, endTwo) {
                                ans[a[j].S] = (type2 ? 3 : 2);
                        }
                        rep(j, endTwo+1, n) {
                                ans[a[j].S] = (type2 ? 2 : 3);
                        }
                        break;
                }

        }
        cout << (win ? "YES" : "NO") << el;
        if (win) {
                trav(x, ans) cout << x;
        }
}

int main() {
        faster
        solve();
}