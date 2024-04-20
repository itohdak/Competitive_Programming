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
  string s; cin >> s;
  int n = s.size();
  map<int, int> mp;
  vector<int> q;
  rep(i, n) {
    if(s[i] == '(') {
      q.push_back(i);
    } else if(s[i] == ')') {
      mp[q.back()] = i;
      q.pop_back();
    } else {
      if(q.size() % 2) {
        if('a' <= s[i] && s[i] <= 'z') {
          s[i] = char('A'+(s[i]-'a'));
        } else {
          s[i] = char('a'+(s[i]-'A'));
        }
      }
    }
  }
  string ans(n, '_');
  vector<int> A, B;
  int a = 1;
  int b = 0;
  rep(i, n) {
    if(s[i] == '(') {
      A.push_back(a);
      B.push_back(b);
      a = -a;
      b = b-(mp[i]+i)*a;
    } else if(s[i] == ')') {
      a = A.back();
      b = B.back();
      A.pop_back();
      B.pop_back();
    } else {
      ans[a*i+b] = s[i];
    }
    // cout << ans << endk;
  }
  rep(i, n) {
    if(ans[i] == '_') continue;
    cout << ans[i];
  }
  cout << endk;
  return 0;
}
