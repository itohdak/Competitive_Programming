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
  string s; cin >> s;
  string t; cin >> t;
  int i = 0, j = 0;
  string ans;
  int cnt = 0;
  while(i < s.size() || j < t.size()) {
    if(i == s.size()) {
      if(t[j] == '(') {
        ans += '(';
        cnt++;
        j++;
      } else {
        if(cnt) {
          ans += ')';
          cnt--;
          j++;
        } else {
          ans += "()";
          j++;
        }
      }
    } else if(j == t.size()) {
      if(s[i] == '(') {
        ans += '(';
        cnt++;
        i++;
      } else {
        if(cnt) {
          ans += ')';
          cnt--;
          i++;
        } else {
          ans += "()";
          i++;
        }
      }
    } else {
      if(s[i] == '(' && t[j] == '(') {
        ans += '('; cnt++;
        i++; j++;
      } else if(s[i] == ')' && t[j] == ')') {
        if(cnt) {
          ans += ')';
          cnt--;
          i++; j++;
        } else {
          ans += "()";
          i++; j++;
        }
      } else if(s[i] == '(') {
        if(i+1 < s.size() && s[i+1] == ')') {
          ans += "()";
          i+=2; j++;
        } else if(cnt && j+1 < t.size() && t[j+1] == '(') {
          ans += ")(";
          i++; j+=2;
        } else {
          ans += "()";
          i++; j++;
        }
      } else if(t[j] == '(') {
        if(j+1 < t.size() && t[j+1] == ')') {
          ans += "()";
          i++; j+=2;
        } else if(cnt && i+1 < s.size() && s[i+1] == '(') {
          ans += ")(";
          i+=2; j++;
        } else {
          ans += "()";
          i++; j++;
        }
      }
    }
  }
  ans += string(cnt, ')');
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
