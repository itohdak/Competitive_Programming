#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<int> P = {4, 5, 7, 9, 11, 13, 17, 19, 23};
  vector<int> A;
  int l = 0;
  rep(i, P.size()) {
    rep(j, P[i]) {
      if(j == P[i]-1) A.push_back(l);
      else A.push_back(l+j+1);
    }
    l = A.size();
  }
  int m = A.size();
  cout << m << endl;
  for(int a: A) cout << a+1 << ' ';
  cout << endl;
  vector<int> B(m);
  rep(i, m) {
    cin >> B[i];
    B[i]--;
  }
  l = 0;
  vector<ll> R, M;
  rep(i, P.size()) {
    M.push_back(P[i]);
    R.push_back((B[l]-l));
    l += P[i];
  }
  auto [y, z] = crt(R, M);
  cout << y << endl;
  return 0;
}
