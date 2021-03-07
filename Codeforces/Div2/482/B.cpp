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
  ll n; cin >> n;
  vector<string> S(3); rep(i, 3) cin >> S[i];
  vector<int> score(3);
  auto calc = [&](string s) {
    map<char, int> cnt;
    for(char c: s) cnt[c]++;
    int ret = min((ll)s.size(), n);
    for(auto ele: cnt) {
      if(ele.second + n <= s.size()) chmax(ret, ele.second + n);
      else chmax(ret, s.size() - (ele.second + n + s.size()) % 2);
      if(ele.second != s.size()) {
        if(ele.second + (n-1) <= s.size()) chmax(ret, ele.second + (n-1));
        else chmax(ret, s.size() - (ele.second + (n-1) + s.size()) % 2);
      } else {
        if(ele.second + (n-3) <= s.size()) chmax(ret, ele.second + (n-3));
        else chmax(ret, s.size() - (ele.second + (n-3) + s.size()) % 2);
      }
    }
    return ret;
  };
  rep(i, 3) score[i] = calc(S[i]);
  // cout << score << endk;
  int mx = -1;
  vector<int> mxId;
  rep(i, 3) {
    if(score[i] > mx) {
      mxId = vector<int>();
      mxId.push_back(i);
      mx = score[i];
    } else if(score[i] == mx) {
      mxId.push_back(i);
    }
  }
  vector<string> name = {"Kuro", "Shiro", "Katie"};
  if(mxId.size() > 1) {
    cout << "Draw" << endk;
  } else {
    cout << name[mxId[0]] << endk;
  }
  return 0;
}
