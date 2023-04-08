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

void solve3() {
    cout << "? 1" << endl;
    cout << flush;
    ll sum = 1;
    vector<ll> cur(n);
    for(ll i = 0; i < n;  i++) {
        cin >> cur[i];
        sum += cur[i];
    } 
    vector<ll> ans = {sum};
    for(ll i = 0; i < n-1; i++) {
        cout << "? " << ans.back()-1 << endl;
        cout << flush;
        vector<ll> u(n);
        for(ll i = 0; i < n; i++) cin >> u[i];
        if (count(all(u), 0) == 1) {
            ans.pb(ans.back()-1);
            continue; 
        }
        //process u, and find next
        multiset<ll> u2;
        multiset<ll> cur2;
        for(ll j = 0; j < n; j++) {
            u2.emplace(u[j]);
            cur2.emplace(cur[j]); 
        }
        // you can always remove n-2 pairs
        while(u2.size() != 2) {
            auto it = u2.begin();
            bool found = 0;
            while(found != 1) {
                auto it2 = cur2.find(*it);
                if (it2 != cur2.end()) {
                    cur2.erase(it2);
                    u2.erase(it);
                    found = 1;
                    continue;
                }
                else it++;
            }
        }
        // check if you can remove another one
        trav(x, u2) {
            if (cur2.count(x) > 0) {
                auto itr = cur2.find(x);
                cur2.erase(itr);
                auto itr2 = u2.find(x);
                u2.erase(itr2);
                break;
            }
        }
        ll curSum = 0;
        if (u2.size() == 1) {
            curSum = *cur2.begin();
        }
        else if (u2.size() == 2) {
            trav(x, u2) {
                curSum += x;
            }
        }
        ll next = ans.back()-curSum;
        ans.pb(next);
    }
    reverse(all(ans));
    cout << "! ";
    for(ll i = 0; i < n; i++) {
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
    cout << flush;
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> n >> t;
        if (n == 1) solve1();
        else if (n == 2) solve2();
        else {
            solve3();
        }
    }
}