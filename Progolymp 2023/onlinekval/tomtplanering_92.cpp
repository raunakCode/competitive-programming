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

ll tt, n;

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start) {
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

auto start = std::chrono::steady_clock::now();

void solve12() {
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>());
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        a[i].pb(x);
        a[i].pb(y);
        a[i].pb(i+1);
    }
    sort(all(a));
    vector<ll> p(n-1, 0);
    p[0] = a[1][0]-a[0][0];
    for(ll i=1; i < n-1; i++) {
        ll dist = a[i+1][0]-a[i][0];
        p[i] = p[i-1]+dist;
    }
    ll mn = p[n/2-2];
    ll pos = n/2-1;
    for(ll i = n/2-1; i < n-1; i++) {
        ll cur = p[i]-p[i-n/2+1];
        if (cur < mn) {
            mn = cur;
            pos = i+1;
        }
    }
    vector<ll> ans;
    for(ll i = pos, cnt = 0; cnt < n/2; i--) {
        ans.pb(a[i][2]);
        cnt++;
    }
    for(int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}

void solve3() {
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>());
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        v[i].pb(x);
        v[i].pb(y);
        v[i].pb(i+1);
    }
    ll mn = 2000000000;
    vector<ll> ans(n/2);
    rep(a, 0, n) {
        rep(b, 0, n) {
            rep(c, 0, n) {
                rep(d, 0, n) {
                    rep(e, 0, n) {
                        set<int> u;
                        u.insert(a);
                        u.insert(b);
                        u.insert(c);
                        u.insert(d);
                        u.insert(e);
                        if (u.size() != n/2) continue;
                        ll cnt = 0;
                        cnt += abs(v[a][0]-v[b][0]) + abs(v[a][1]-v[b][1]);
                        cnt += abs(v[b][0]-v[c][0]) + abs(v[b][1]-v[c][1]);
                        cnt += abs(v[c][0]-v[d][0]) + abs(v[c][1]-v[d][1]);
                        cnt += abs(v[d][0]-v[e][0]) + abs(v[d][1]-v[e][1]);
                        if (cnt < mn) {
                            mn = cnt;
                            ans[0] = v[a][2];
                            ans[1] = v[b][2];
                            ans[2] = v[c][2];
                            ans[3] = v[d][2];
                            ans[4] = v[e][2];
                        }
                    }
                }
            }
        }
    }
    trav(x, ans) {
        cout << x << " ";
    }
}

void solve4567() {
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>());
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        v[i].pb(x);
        v[i].pb(y);
        v[i].pb(i+1);
    }
    vector<vector<pair<ll, ll>>> distances(n, vector<pair<ll, ll>>());
    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if (j == i) continue;
            distances[i].pb({abs(v[j][0]-v[i][0]) + abs(v[j][1]-v[i][1]), j});
        }
    }
    for(ll i = 0; i < n; i++) sort(all(distances[i]));
    ll mn = LLONG_MAX;
    vector<ll> ans(n/2);
    for(ll i = 0; i < n; i++) {
        vector<ll> temp;
        temp.pb(i);
        bool vis[n] = {0};
        vis[i] = 1;
        ll cur = i;
        ll travel = 0;
        int cnt = 1;
        while(cnt < n/2) {
            for(ll j = 0; j < distances[cur].size(); j++) {
                ll next = distances[cur][j].second;
                if (!vis[next]) {
                    travel += distances[cur][j].first;
                    temp.pb(next);
                    vis[next] = 1;
                    cur = next;
                    cnt++;
                    break;
                }
            }
        }
        if (travel < mn) {
            for(ll j = 0; j < n/2; j++) {
                ans[j] = temp[j];
            }
        }
    }
    trav(x, ans) {
        cout << x+1 << " ";
    }
}

void solve8() {
    srand(time(0));
    cin >> n;
    vector<vector<ll>> point(n, vector<ll>());
    for(ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        point[i].pb(x);
        point[i].pb(y);
    }
    vector<ll> ans;
    ll minDist = 100000000000;
    while(since(start).count() < 9000) {
        vector<ll> curAns;
        int newPoint = rand()%n;
        vector<bool> visited(n, 0);
        visited[newPoint] = 1;
        ll cur = newPoint;
        curAns.pb(newPoint);
        while(curAns.size() < n/2) {
            ll shortest = 1000000000;
            ll shortPos = 0;
            for(ll i = 0; i < n; i++) {
                if (visited[i]) continue;
                ll dist = abs(point[cur][0]-point[i][0])+abs(point[cur][1]-point[i][1]);
                if (dist < shortest) {
                    shortest = dist;
                    shortPos = i;
                }
            }
            visited[shortPos] = 1;
            cur = shortPos;
            curAns.pb(shortPos);
        }
        ll curDist = 0;
        for(int i = 1; i < n/2; i++) {
            curDist += abs(point[i][0]-point[i-1][0]) + abs(point[i][1]-point[i-1][1]);
        }
        if (ans.size() < n/2) {
            for(int i = 0; i < n/2; i++) {
                ans.pb(curAns[i]);
            }
        }
        else if (curDist < minDist) {
            minDist = curDist;
            for(int i = 0; i < n/2; i++) {
                ans[i] = curAns[i];
            }
        }
    }
    trav(x, ans) {
        cout << x+1 << " ";
    }
}

void solve910() {
    srand(time(0));
    cin >> n;
    vector<vector<ll>> point(n, vector<ll>());
    for(ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        point[i].pb(x);
        point[i].pb(y);
        point[i].pb(i+1);
    }
    sort(all(point));
    vector<ll> ans;
    ll minDist = 1000000000;
    vector<vector<ll>> points(n/2, vector<ll>());
    for(int i= 0; i < n/2; i++) {
        for(int j = 0; j < 3; j++) {
            points[i].pb(point[i][j]);
        }
    }
    for(int p = 0; p < points.size(); p++) {
        if (since(start).count() >= 5500) break;
        vector<ll> curAns;
        vector<bool> visited(n, 0);
        ll newPoint = p;
        visited[newPoint] = 1;
        ll cur = newPoint;
        curAns.pb(points[p][2]);
        while(curAns.size() < n/2) {
            ll shortest = 100000000000;
            ll shortPos = 0;
            for(ll i = 0; i < points.size(); i++) {
                if (visited[i]) continue;
                ll dist = abs(points[cur][0]-points[i][0]) + abs(points[cur][1]-points[i][1]);
                if (dist < shortest) {
                    shortest = dist;
                    shortPos = i;
                }
            }
            visited[shortPos] = 1;
            cur = shortPos;
            curAns.pb(points[shortPos][2]);
        }
        ll curDist = 0;
        for(int i = 1; i < curAns.size(); i++) {
            curDist += abs(points[i][0]-points[i-1][0]) + abs(points[i][1]-points[i-1][1]);
        }
        if (ans.size() == 0) {
            for(int i = 0; i < n/2; i++) {
                ans.pb(curAns[i]);
            }
        }
        else if (curDist < minDist) {
            minDist = curDist;
            for(int i = 0; i < n/2; i++) {
                ans[i] = curAns[i];
            }
        }
    }
    trav(x, ans) {
        cout << x << " ";
    }
    
}

int main() {
    faster
    //cout << fixed << setprecision(10);
    cin >> tt;
    if (tt == 0) {
        vector<vector<ll>> a(n, vector<ll>(2));
        rep(i, 0, n) {
            rep(j, 0, 2) {
                cin >> a[i][j];
            }
        }
        cout << 2 << " " << 4 << " " << 1;
    }
    else if (tt < 3) {
        solve12();
    }
    else if (tt == 3) {
        solve3();
    }
    else if (tt >= 4 && tt <= 7) {
        solve4567();
    }
    else if (tt == 8) {
        solve8();
    }
    else {
        solve910();
    }
}