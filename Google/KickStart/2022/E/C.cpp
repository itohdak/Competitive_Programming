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
bool is_palindrome(string s) {
  string t = s;
  reverse(all(t));
  return t == s;
}
bool judge(vector<int>& res, int start, int end) {
  int center = start + end;
  return 2*end-1 < center+res[center];
}
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t;
  rep(i, n) {
    t += '.';
    t += s[i];
  }
  t += '.';
  vector<int> res(t.size());
  Manacher(t, res);
  auto is_perfect_palindrome = [&](int i) {
    return judge(res, 0, i) && judge(res, i, n);
  };
  REP(i, 1, n+1) {
    if(is_perfect_palindrome(i)) {
      string ans = s.substr(0, i);
      reverse(all(ans));
      cout << ans << endk;
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
