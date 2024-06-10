#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;

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

struct chash { // large odd number for C
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};

template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;

int n, m, q;

vector<int> par;
vector<int> big;
vector<fast_set<int>> graph;

int getPar(int node) {
      if (node == par[node]) return node;
      return par[node] = getPar(par[node]);
}

void join(int a, int b) {
      a = getPar(a);
      b = getPar(b);
      // a, b are guaranteed to belong to different states
      // so you can assume that they have different representatives
      if (big[a] < big[b]) swap(a, b);
      par[b] = a;
      big[a] += big[b];
      trav(nem, graph[b]) {
            graph[a].insert(nem);
      }
}

void solve() {
      cin >> n >> m >> q;

      graph.resize(n);
      par.resize(n);
      big.resize(n);

      rep(i, 0, n) {
          par[i] = i;
          big[i] = 1;
      }

      rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].insert(v);
            graph[v].insert(u);
      }

      while(q--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = getPar(u);
            v = getPar(v);
            // check if they distrust each other
            bool works = 1;
            if (big[u] > big[v]) swap(u, v);
            trav(nem, graph[u]) {
                  if (getPar(nem) == v) {
                        // they distrust each other
                        works = 0;
                        break;
                  }
            }
            if (works) {
                  join(u, v);
                  cout << "APPROVE" << el;
            }
            else cout << "REFUSE" << el;
      }
} 

int main() {
      faster
      solve();
}