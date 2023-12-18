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

ll n, q;
vector<pll> players;
vector<pll> opponent;
vector<vector<bool>> combo;

void rec(ll many, vector<bool> cur) {
    if (many == 4) {
        combo.pb(cur);
        cur[many] = 1;
        combo.pb(cur);
    }
    else {
        rec(many+1, cur);
        cur[many] = 1;
        rec(many+1, cur);
    }
}

void solve11() {
    ll asum = 0, dsum = 0;
    trav(x, players) {
        asum += x.F;
        dsum += x.S;
    }
    ll w = 0, d = 0, l = 0;
    trav(x, opponent) {
        if (asum > x.S) w++;
        else d++;
    }
    cout << w << " " << d << " " << l;
}

void solve20() {
    vector<ll> Players;
    Players.resize(players.size());
    ll asum = 0;
    for(ll i = 0; i < players.size(); i++) {
        Players[i] = players[i].S-players[i].F; 
        asum += players[i].F;
    }
    sort(all(Players), greater<ll>());
    vector<ll> psum(n);
    ll sum = 0;
    for(int i  = 0; i < n; i++) {
        sum += Players[i];
        psum[i] = sum;
    }
    ll w = 0, d = 0, l = 0;
    trav(x, opponent) {
        bool win = 0;
        bool draw = 0;
        ll catchup = x.F-asum;
        int last = -1;
        for(int i = 0; i < Players.size(); i++) {
            if (Players[i] >= 0) last = i;
        } 
        if (psum[last] > catchup) win = 1;
        else if (psum[last] == catchup) draw = 1;
        if (win) w++;
        else if (draw) d++;
        else l++;
    }
    cout << w << " " << d << " " << l;

}

void solve16() {
    vector<bool> cur(n);
    rec(0, cur);
    ll w = 0, d = 0, l = 0;
    trav(x, opponent) {
        ll best = -1;
        trav(c, combo) {
            ll attack = 0;
            ll def = 0;
            for(int i = 0; i < n; i++) {
                if (c[i] == 1) {
                    attack += players[i].F;
                }
                else def += players[i].S;
            }
            ll mGoal = max((ll)0, attack-x.S);
            ll uGoal = max((ll)0, x.F - def);
            if (mGoal > uGoal) best = max((ll)1, best);
            if (mGoal == uGoal) best = max((ll)0, best);
            else best = max((ll)-1, best);
        }
        if (best == 1) w++;
        else if (best == 0) d++;
        else l++;
    }
    cout << w << " " << d << " " << l;
}

int main() {
    faster
    int test = 1;
    for(int tc = 1; tc <= test; tc++) {
        cin >> n;
        for(ll i = 0; i < n; i++) {
            pll cur;
            cin >> cur.F >> cur.S;
            players.pb(cur);
        }
        cin >> q;
        opponent.resize(q);
        bool can11 = 1;
        bool can20 = 1;
        for(ll i = 0; i < q; i++) {
            cin >> opponent[i].F >> opponent[i].S;
            if (opponent[i].F > 0) can11 = 0;
            if (opponent[i].S > 0) can20 = 0;
        }
        
        if (n <= 5) {
            solve16();
        }
        else if (can11) solve11();
        else if (can20) solve20(); 
        else cout << 0 << " " << 0 << " " << n;
    }
}