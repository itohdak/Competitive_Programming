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

void solve() {
  string a, s; cin >> a >> s;
  string b;
  int i = a.size()-1, j = s.size()-1;
  while(i >= 0) {
    int a_ = a[i]-'0';
    if(j < 0) {
      cout << -1 << endk;
      return;
    }
    int s_ = s[j]-'0';
    if(s_ >= a_) {
      int b_ = s_ - a_;
      b += char('0'+b_);
      j--;
    } else {
      if(j-1 < 0) {
        cout << -1 << endk;
        return;
      }
      s_ += (s[j-1]-'0') * 10;
      int b_ = s_ - a_;
      if(b_ >= 10 || b_ < 0) {
        cout << -1 << endk;
        return;
      }
      b += char('0'+b_);
      j -= 2;
    }
    i--;
  }
  while(j >= 0) b += s[j--];
  int k = 0;
  reverse(all(b));
  while(k < b.size() && b[k] == '0') k++;
  cout << b.substr(k) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
