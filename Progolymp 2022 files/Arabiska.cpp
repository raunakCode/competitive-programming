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
    int n; cin >> n;
    string s = "";
    string p;
    for(int l = 0; l < n; l++) {
        cin >> p;
        s += p;
        if(l!=n-1) s+=" ";
    }
    vi k;
    for(int i = 0; i < s.size()-2; i++) {
        if ((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y') && (s[i+1]!='a'&&s[i+1]!='e'&&s[i+1]!='i'&&s[i+1]!='o'&&s[i+1]!='u'&&s[i+1]!='y'&&s[i+1]!=' ') && (s[i+2]!='a'&&s[i+2]!='e'&&s[i+2]!='i'&&s[i+2]!='o'&&s[i+2]!='u'&&s[i+2]!='y'&&s[i+2]!=' ')) {
            k.pb(i);
        }
    }
    reverse(k.begin(), k.end());
    for(int j = 0; j < k.size(); j++) {
        s.erase(s.begin()+k[j]);
    }
    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}
