#include "bits/stdc++.h"
 
#define el "\n"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sq(x) (x)*(x)
#define pb push_back
#define popb pop_back
#define mp make_pair
#define Cint(x) x-'0'
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
    int a, n;
    cin >> a >> n;
    int b[n];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    sort(b, b+n);
    int l = 0, r = n-1;
    while(l < r) {
        if (b[l]*b[r] >= a) {
            l++;
            r--;
            cnt++;
        }
        else if (b[l]*b[r] < a) {
            l++;
        }
    }
    cout << cnt;
}
 
int main() {
    faster
    //cout << fixed << setprecision(10);
    int tt = 1;
    while(tt--) {
        solve();
    }
} 