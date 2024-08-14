#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

struct myhash {
    static uint64_t fxn(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator ()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return fxn(x + FIXED_RANDOM);
    }
};

string getPattern(vector<ll> &v) {
	char curr = 'a';
	string pattern;
	unordered_map<ll, char, myhash> mark;

	for (auto i : v) {
		if (mark.find(i) == mark.end()) {
			mark[i] = curr++;
		}

		pattern.pb(mark[i]);
	}

	return pattern;
}

int main() {

	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll tcase = 1;
	cin >> tcase;

	for (ll T = 1; T <= tcase; T++) {
		ll n;
		cin >> n;
		vector<ll> v(n);

		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}

		string basePattern = getPattern(v);

		ll q;
		cin >> q;

		while (q--) {
			string s;
			cin >> s;

			ll siz = s.size();
			vector<ll> temp(siz);

			for (ll i = 0; i < siz; i++) {
				temp[i] = s[i];
			}
			
			cout << (getPattern(temp) == basePattern ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
