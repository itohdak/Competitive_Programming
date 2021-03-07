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

void Manacher(string S, vector<int>& res) {
  int i=0, j=0;
  while(i < S.size()) {
    while(i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
    res[i] = j;
    int k=1;
    while(i-k >= 0 && i+k < S.size() && k+res[i-k] < j) res[i+k] = res[i-k], ++k;
    i += k; j -= k;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  string t;
  rep(i, n) {
    t += s[i];
    if(i != n-1) t += '*';
  }
  vector<int> res(t.size());
  Manacher(t, res);
  vector<vector<int>> cnt(n+1, vector<int>(n));
  rep(i, n) cnt[1][i] = 1;
  REP(len, 2, n+1) {
    deque<int> q;
    int sum = 0;
    rep(i, len/2) {
      q.push_back(s[i] == s[(len+1)/2+i]);
      sum += q.back();
    }
    rep(i, n) {
      // string t = s.substr(i, len);
      // string rev = t;
      // reverse(all(rev));
      // chmax(cnt[len][i], t == rev);
      if(len % 2) {
        if(res[(i+len/2)*2] >= len/2*2+1) chmax(cnt[len][i], 1);
      } else {
        if(res[(i+len/2)*2-1] >= len/2*2) chmax(cnt[len][i], 1);
      }
      // cout << len << ' ' << i << ' ' << sum << endk;
      // cout << q << endk;
      if(sum == len/2) {
        chmax(cnt[len][i], cnt[len/2][i]+1);
      }
      if((len+1)/2+len/2+i < n) {
        sum -= q.front();
        q.pop_front();
        q.push_back(s[len/2+i] == s[(len+1)/2+len/2+i]);
        sum += q.back();
      } else {
        break;
      }
    }
  }
  // cout << res << endk;
  // cout << cnt << endk;
  vector<int> ans(n+1);
  rep(len, n+1) {
    rep(i, n) {
      ans[cnt[len][i]]++;
    }
  }
  for(int i=n-1; i>=0; i--) {
    ans[i] += ans[i+1];
  }
  REP(i, 1, n+1) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
