#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(2*n-2);
  vector<int> id(2*n-2);
  rep(i, 2*n-2) {
    cin >> S[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return S[i].size() > S[j].size();
  });
  auto test = [&](string s) -> pair<bool, string> {
    string ans(2*n-2, ' ');
    for(int i=0; i<2*n-2; i+=2) {
      assert(S[id[i]].size() == S[id[i+1]].size());
      int sz = S[id[i]].size();
      if(s.substr(0, sz) == S[id[i]] && s.substr(n-sz) == S[id[i+1]]) {
        ans[id[i]] = 'P';
        ans[id[i+1]] = 'S';
      } else if(s.substr(n-sz) == S[id[i]] && s.substr(0, sz) == S[id[i+1]]) {
        ans[id[i]] = 'S';
        ans[id[i+1]] = 'P';
      } else {
        return {false, ""};
      }
    }
    return {true, ans};
  };
  bool ok = true;
  string prefix = S[id[0]];
  string suffix = S[id[1]];
  rep(i, n-2) {
    if(prefix[i+1] != suffix[i]) ok = false;
  }
  if(ok) {
    string s = prefix + suffix.back();
    auto ret = test(s);
    if(ret.first) {
      cout << ret.second << endk;
      return 0;
    }
  }
  swap(prefix, suffix);
  {
    string s = prefix + suffix.back();
    auto ret = test(s);
    if(ret.first) {
      cout << ret.second << endk;
      return 0;
    }
  }
  assert(false);
  return 0;
}
