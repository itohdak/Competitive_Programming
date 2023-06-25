#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  auto count = [&](string s) {
    int i = 0;
    int ret = 0;
    while(i + 4 <= s.size()) {
      if(s.substr(i, 4) == "haha") ret++;
      i++;
    }
    return ret;
  };
  int n; cin >> n;
  map<string, pair<ll, pair<string, string>>> cnt;
  rep(i, n) {
    string a, op;
    cin >> a >> op;
    if(op == "=") {
      string b, op2, c;
      cin >> b >> op2 >> c;
      assert(op2 == "+");
      auto [cntb, pb] = cnt[b];
      auto [cntc, pc] = cnt[c];
      int len1 = min((int)(pb.first + pc.first).size(), 3);
      int len2 = min((int)(pb.second + pc.second).size(), 3);
      string s1 = (pb.first + pc.first).substr(0, len1);
      string s2 = (pb.second + pc.second).substr((pb.second + pc.second).size()-len2, len2);
      cnt[a] = {cntb + cntc + count(pb.second + pc.first), {s1, s2}};
    } else {
      assert(op == ":=");
      string b;
      cin >> b;
      int len = min((int)b.size(), 3);
      cnt[a] = {count(b), {b.substr(0, len), b.substr(b.size()-len, len)}};
    }
    if(i == n-1) cout << cnt[a].first << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
