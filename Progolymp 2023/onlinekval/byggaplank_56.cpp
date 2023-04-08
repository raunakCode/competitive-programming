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

ll n, k;
ll m[100005][20];
vector<ll> a(50005);
ll mxfound = 0;

ll largestRectangleArea(vector<ll> & a) {
  stack < ll > stk;
  stk.push(-1);
  ll max_area = 0;
  for (size_t i = 0; i < a.size(); i++) {
    while (stk.top() != -1 and a[stk.top()] >= a[i]) {
      ll current_height = a[stk.top()];
      stk.pop();
      ll current_width = i - stk.top() - 1;
      max_area = max(max_area, current_height * current_width);
    }
    stk.push(i);
  }
  while (stk.top() != -1) {
    ll current_height = a[stk.top()];
    stk.pop();
    ll current_width = a.size() - stk.top() - 1;
    max_area = max(max_area, current_height * current_width);
  }
  return max_area;
}

void solve3() {
    ll ans = largestRectangleArea(a);
    cout << ans;
}

void solve2() {
    ll mx = a[0]*n;
    if (k >= n-1) {
        cout << mxfound*n;
        return;
    }
    for(ll i = 0; i +k < n; i++) {
        ll cur = (ll)(a[i+k]*(n-i));
        mx = max(mx,cur);
    }
    cout << mx;
}

bool solve1Check(ll pos, ll f, ll s) {
    ll cnt = 0;
    for(ll i = f; i <= s; i++) {
        if (a[i] < pos) {
            cnt++;
            if (cnt > k) {
                return false;
            }
        }
    }
    return true;
} 

void solve1() {
    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            ll curMax = 0;
            ll L = 0, R = 0;
            for(ll pos = i; pos <= j; pos++) {
                R = max(R, a[i]);
            }
            while(L <= R) {
                ll mid = L + (R-L)/2;
                if (solve1Check(mid, i, j)) {
                    curMax = max(curMax, mid);
                    L = mid+1;
                }
                else R = mid-1;
            }
            ll curee = (j-i+1)*curMax;
            mx = max(curee, mx);
        }
    }
    cout << mx;
}

int main() {
    faster
    //cout << fixed << setprecision(10);
    cin >> n >> k;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        mxfound = max(mxfound, a[i]);
    }
    bool flag = 1;
    for(int i = 0; i < n-1; i++) {
        if (a[i] >= a[i+1]) {
            flag = 0;
        }
    }
    if (flag) solve2();
    else if (k == 0) solve3();
    else {
        solve1();
    }

}