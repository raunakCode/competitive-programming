#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define popb pop_back
#define mp make_pair
#define sq(a) (a)*(a)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::pair<int,int> pi;
const ll template_size_array = 1e6 + 16318;

using namespace std;

int main()
{
    faster
    int n,x, a,b,r,e; cin >> n;
    map<int,int> times;
    for(int i = 0; i < n; i++) {
        set<int> uniq;
        cin >> x;
        for(int j = 0; j < x; j++) {
            cin >> a >> b;
            for(int k = a; k <= b; k++) {
                uniq.insert(k);
            }
        }
        set<int>::iterator it = uniq.begin();
        while (it != uniq.end()) {
            times[*it]++;
            it++;
        }
    }
    int highest = 0;
    map<int, int>::iterator ip = times.begin();
    while (ip != times.end())
    {
        r = ip->first;
        e = ip->second;
        if (e > highest ) highest = e;
        ip++;
    }
    cout << highest;

    return 0;
}
