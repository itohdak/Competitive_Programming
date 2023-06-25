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

bool is_palindrome(string s) {
  return s.size() == 1 || (s.size() == 2 && s[0] == s[1]) || (s.size() == 3 && s[0] == s[2]);
};
void solve() {
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  rep(i, n) {
    if(is_palindrome(S[i])) {
      cout << "YES" << endk;
      return;
    }
  }
  set<string> st2, st3_2, st3_3;
  rep(i, n) {
    if(S[i].size() == 2) {
      {
        string tmp = string("")+S[i][1]+S[i][0];
        if(st2.count(tmp) || st3_2.count(tmp)) {
          cout << "YES" << endk;
          return;
        }
      }
      {
        string tmp = string("")+S[i][0]+S[i][1];
        st2.insert(tmp);
      }
    }
    if(S[i].size() == 3) {
      {
        string tmp = string("")+S[i][2]+S[i][1];
        if(st2.count(tmp)) {
          cout << "YES" << endk;
          return;
        }
        string tmp2 = string("")+S[i][2]+S[i][1]+S[i][0];
        if(st3_3.count(tmp2)) {
          cout << "YES" << endk;
          return;
        }
      }
      {
        string tmp = string("")+S[i][0]+S[i][1];
        st3_2.insert(tmp);
        string tmp2 = string("")+S[i][0]+S[i][1]+S[i][2];
        st3_3.insert(tmp2);
      }
    }
  }
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
