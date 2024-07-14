#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto &a : x)
#define el "\n"
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

struct Node {
	Node *child[26];
	bool isWord;
	ll depth;
	int ch;
	Node() {
		isWord = 0; depth = 0; ch = -1;
		rep(i, 0, 26) child[i] = NULL;
	}
};

set<Node*> nodes;

void add_word(Node* root, string &word) {
	Node *cur = root;
	nodes.insert(root);
	trav(c, word) {
		if (cur->child[c - 'a'] == NULL) {
			cur->child[c - 'a'] = new Node();
			cur->child[c - 'a']->ch = c - 'a';
		}
		cur = cur->child[c - 'a'];
		nodes.insert(cur);
	}
	cur->isWord = 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n;
	cin >> n;
	
	Node* root = new Node();
	vector<string> words;

	rep(i, 0, n) {
		string word; cin >> word;
		words.pb(word);
		add_word(root, word);
	}
	ll node_count = sz(nodes);

	auto setup = [&](auto &self, Node* v, ll d) -> ll {
		ll mx = d;
		rep(i, 0, 26) {
			if (v->child[i] != NULL) {
				mx = max(self(self, (v->child[i]), d + 1), mx);
			}
		}
		v->depth = mx;
		return mx;
	};
	setup(setup, root, 0);

	vector<char> ans;
	set<Node*> vis;

	auto dfs = [&](auto &self, Node* v) -> void {
		vis.insert(v);
		ll letter = v->ch;
		if (letter != -1) ans.pb(char(letter + 'a'));
		if (v->isWord) {
			ans.pb('P');
		}
		vector<pair<ll, Node*>> nxt;
		rep(i, 0, 26) {
			if (v->child[i] != NULL) {
				nxt.pb(make_pair(v->child[i]->depth, (v->child[i])));
			}
		}
		sort(all(nxt));
		trav(c, nxt) {
			self(self, c.second);		
		}
		if (sz(vis) < node_count) ans.pb('-');
	};
	dfs(dfs, root);

	cout << sz(ans) << el;
	trav(c, ans) cout << c << el;
}


