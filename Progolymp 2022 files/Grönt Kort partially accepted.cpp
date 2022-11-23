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
/*
bool primeCheck(int n) {
    if (n < 2) return false;
    for(int x = 2; x*x <= n; x++) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}


//function for finding the index of a vector int, instead use the indexes in an array
int findIndex(vi k, int val) {
    vi::iterator it = find(k.begin(), k.end(), val);
    if (it != k.cend()) {
        return distance(k.begin(), it);
    }
    else return -1;
}


int countDigits(long long n) {
    return int(log10(n) + 1);
}
vi factors(int n) {
    vi f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.pb(x);
            n/=x;
        }
    }
    if (n > 1) f.pb(n);
    return f;
} */

int main()
{
    faster
    //freopen("ride.in", "r", stdin);
    //freopen("ride.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    ll n, m; cin >> n >> m;
    ll cnt = 0;
    if (m == 0) {
        if (n%2==0) {
            cnt += 2;
        }
        else if (n%2==1) {
            cnt += 3;
        }
    }
    else if (n == 2) {
        if (m%2==0) {
            cnt += 2 + m/2;
        }
        else if (m%2==1) {
            cnt += 3 + m/2;
        }
    }
    else if (n == 3) {
        cnt += 3;
        m -= 3;
        if (m%3 == 0) {
            cnt += m/3;
        }
        else if (m%3 != 0) {
            cnt += m/3 + 1;
        }
    }
    else if (n > 3) {
        if (m%n == 0) {
            cnt += m/n;
        }
        else if (m%n != 0) {
            cnt += m/n + 1;
        }
        if (n%2 == 0) {
            cnt += 2;
        }
        else if (n%2 != 0) {
            cnt += 3;
        }
    }
    cout << cnt*10;
    return 0;
}
