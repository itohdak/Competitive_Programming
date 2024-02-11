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
  string s; cin >> s;
  string x; cin >> x;
  set<int> st;
  rep(i, 10) if(i) st.insert(i);
  reverse(all(s));
  reverse(all(x));
  rep(i, n) {
    if(x[i] == 'T') {
      set<int> nextSt;
      rep(j, 10) nextSt.insert(j);
      rep(j, 10) {
        if(!st.count((j*10+(s[i]-'0'))%7)) nextSt.erase(j);
        if(!st.count((j*10)%7)) nextSt.erase(j);
      }
      st = nextSt;
    } else {
      set<int> nextSt;
      rep(j, 10) {
        if(st.count((j*10+(s[i]-'0'))%7)) nextSt.insert(j);
        if(st.count((j*10)%7)) nextSt.insert(j);
      }
      st = nextSt;
    }
  }
  cout << (st.count(0) ? "Aoki" : "Takahashi") << endk;
  return 0;
}
