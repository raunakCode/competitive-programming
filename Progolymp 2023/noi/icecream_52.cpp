#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)

int n, m, k;
vector<int> a;

void solve() {
    cin >> n >> m >> k;
    map<int, vector<int>> pos;
    rep(i, 0, n) {
        int x; cin >> x;
        a.pb(x);
        pos[a[i]].pb(i);
    }
    vector<bool> machines(m+1, 0);
    int cnt = 0;
    int ans = 0;
    rep(i, 0, n) {
        if (machines[a[i]] == 1) {
            continue;
        }
        // there is currently no machine with a[i] flavour
        if (cnt < k) {
            ans++;
            cnt++;
            machines[a[i]] = 1;
        }
        else {
            // all machines are used and have a different flavour
            ans++;
            bool found = 0;
            int far = i;
            int theMachine;
            REP(j, 1, m) {
                // if there is no machine with this color, continue
                if (machines[j] == 0) continue;

                // if there is machine with this color, but it is never needed again
                if (pos[j].back() < i) {
                    machines[j] = 0;
                    machines[a[i]] = 1;
                    found = 1;
                    break;
                } 

                // if there is a machine with this color, find next time it is used
                int temp;
                int l = 0, r = pos[j].size()-1;
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    if (pos[j][mid] > i) {
                        r = mid-1;
                        temp = mid;
                    }  
                    else l = mid+1;
                }                  
                int position = pos[j][temp];
                if (position > far) {
                    far = position;
                    theMachine = j;
                }
            }
            if (!found) {
                machines[theMachine] = 0;
                machines[a[i]] = 1;
            }
        }
    }
    cout << ans;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}