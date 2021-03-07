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
  vector<int> X(n), Y(n), R(n);
  int d = 50;
  rep(i, n) {
    cin >> X[i] >> Y[i] >> R[i];
    X[i] *= d;
    Y[i] *= d;
    R[i] *= d;
  }
  set<string> st;
  for(ld x=-30*d; x<=30*d; x++) {
    for(ld y=-30*d; y<=30*d; y++) {
      string s;
      rep(i, n) if((x-X[i])*(x-X[i]) + (y-Y[i])*(y-Y[i]) < R[i]*R[i]) s += char('0'+i);
      st.insert(s);
    }
  }
  cout << st.size() << endk;
  return 0;
}
