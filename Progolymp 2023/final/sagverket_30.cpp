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

ll n, t;

void solve2() {
    cout << "? " << 1000000000 << endl;
    cout << flush;
    int x1, x2;
    cin >> x1 >> x2;
    cout << "? " << 1 << endl;
    int y1, y2;
    cout << flush;
    cin >> y1 >> y2;
    if (x1 == y1) {
        cout << "! " << 1000000000-x2-x1 << " " << 1000000000-x2 << endl;
        cout << flush;
    }
    else if (x2 == y2) {
        cout << "! " << 1000000000-x2-x1 << " " << 1000000000-x1 << endl;
        cout << flush;
    }
    else if (x1 == y2) {
        cout << "! " << 1000000000-x2-x1 << " " << 1000000000-x2 << endl;
        cout << flush;
    }
    else if (x2 == y1) {
        cout << "! " << 1000000000-x2-x1 << " " << 1000000000-x1 << endl;
        cout << flush;
    }
}

void solve1() {
    cout << "? " << 1000000000 << endl;
    cout << flush;
    int d; cin >> d;
    cout << "! " << 1000000000-d << endl;
    cout << flush;
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> n >> t;
        if (t == 1) solve1();
        else if (t == 2) solve2();
    }
}