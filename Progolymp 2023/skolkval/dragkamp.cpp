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
    ll s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    rep(a, 0, s1+1) {
        rep(b, 0, s2+1) {
            rep(c, 0, s3+1) {
                rep(d, 0, s4+1) {
                    if ((a+2*b+3*c+4*d) == s1-a+2*(s2-b)+3*(s3-c)+4*(s4-d) && a+b+c+d == s1+s2+s3+s4-a-b-c-d) {
                        cout << a << " " << b << " " << c << " " << d;
                        return;
                    }
                }
            }
        }
    }
}
 
int main() {
    faster
    int tt = 1;
    while(tt--) {
        solve();
    }
}