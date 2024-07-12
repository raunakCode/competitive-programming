#include <bits/stdc++.h>
#include "combo.h"
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto &a : x)
#define pb push_back
//#define dbg(x) cout << #x << " = " << x << endl
#define dbg(x) 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
string guess_sequence(int N) {
	ll n = N;
	vector<char> l = {'A', 'B', 'X', 'Y'};
 
	int coin;
	auto query = [&](string q) -> void {
		coin = press(q);
	};
 
	string s;
	query("AB");
	if (coin) {
		query("A");
		s = (coin ? "A" : "B");
	}
	else {
		query("X");
		s = (coin ? "X" : "Y");
	}
	char st = s[0];
	if (n == 1) return s;
	
	vector<char> chars;
	trav(c, l) if (c != st) chars.pb(c);
 
	assert(sz(chars) == 3);

	rep(i, 0, n-2) {
		shuffle(all(chars), rnd);
		string cur = "";
		cur += s;
		cur += chars[0];
		rep(j, 0, sz(chars)) {
			cur += s;
			cur += chars[1];
			cur += chars[j];
		}
		query(cur);
		if (coin == sz(s)) s += chars[2];
		else if (coin == sz(s) + 1) s += chars[0];
		else s += chars[1];
	}

	shuffle(all(chars), rnd);
	rep(i, 0, sz(chars) - 1) {
		string cur = s;
		cur += chars[i];
		query(cur);
		if (coin == sz(s) + 1) {
			return cur;
		}
	}
	return (s + chars[2]);
}

