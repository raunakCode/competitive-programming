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

void solve() {
    double I;
    cin >> I;
    cout << fixed << setprecision(10);
    double a[30];
    for(int i = 0; i < 30; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 30; i++) {
        double cur = I;
        I = max(I + a[i], I + (a[i]*I)/100);
    }
    cout << I;
} 

int main() {
    faster
    solve();
}