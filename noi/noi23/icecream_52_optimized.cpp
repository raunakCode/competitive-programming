#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define trav(a, x) for (auto &a : x)

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
    vector<bool> colors(m+1, 0);
    set<int> machines;
    int ans = 0;
    rep(i, 0, n) {
        if (colors[a[i]] == 1) {
            continue;
        }

        // there is currently no machine with a[i] flavour
        if (machines.size() < k) {
            ans++;
            colors[a[i]] = 1;
            machines.emplace(a[i]);
            continue;
        }

        // all machines are used and have a different flavour
        ans++;
        bool found = 0;
        int far = i;
        int theMachine;
        int toErase, toemplace;
        trav(mc, machines) {
            // if there is machine with this color, but it is never needed again
            if (pos[mc].back() < i) {
                colors[mc] = 0;
                toErase = mc;
                colors[a[i]] = 1;
                toemplace = a[i];
                found = 1;
                break;
            } 

            // if there is a machine with this color, find next time it is used
            int temp;
            int l = 0, r = pos[mc].size()-1;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if (pos[mc][mid] > i) {
                    r = mid-1;
                    temp = mid;
                }  
                else l = mid+1;
            }                  
            int position = pos[mc][temp];
            if (position > far) {
                far = position;
                theMachine = mc;
            }
        }
        if (found) {
            machines.erase(toErase);
            machines.emplace(toemplace);
        }
        else {
            colors[theMachine] = 0;
            machines.erase(theMachine);
            colors[a[i]] = 1;
            machines.emplace(a[i]);
        }
    }
    cout << ans;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}