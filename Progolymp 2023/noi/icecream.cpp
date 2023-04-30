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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

const int inf = 1e9;

void solve() {
      int n, m, k;
      cin >> n >> m >> k;
      vector<int> a(n);
      rep(i, 0, n) {
            cin >> a[i];
            a[i]--;
      }
      queue<int> fv[m];
      int cnt = 0;
      int ans = 0;
      vector<bool> exist(m, 0);
      set<int> machines;
      set<pii, greater<pii>> next;
      rep(i, 0, n) fv[a[i]].push(i);
      rep(i, 0, n) {
            if (exist[a[i]]) {
                  next.erase(mp(fv[a[i]].front(), a[i]));
            }
            else {
                  ans++;
                  if (cnt < k) {
                        cnt++;
                        exist[a[i]] = 1;
                  }
                  else {
                        pii get = *next.begin();
                        int flavour = get.S;
                        exist[flavour] = 0;
                        next.erase(mp(get.F, flavour));
                        exist[a[i]] = 1;
                  }
            }
            fv[a[i]].pop();
            next.insert(mp((fv[a[i]].size() == 0 ? inf : fv[a[i]].front()), a[i]));
      }
      cout << ans;
} 

int main() {
      faster
      solve();
}