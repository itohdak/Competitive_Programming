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
  int t; ll n; cin >> t >> n;
  set<int> st;
  for(int i=1; i<=100+t; i++) st.insert(i);
  for(int i=1; i<=100; i++) st.erase((100+t)*i/100);
  vector<int> A(all(st));
  // cout << A << endk;
  int sz = A.size();
  ll m = n/sz;
  int rem = n%sz;
  if(rem == 0) {
    cout << (m-1)*(100+t)+A[sz-1] << endk;
  } else {
    cout << m*(100+t)+A[rem-1] << endk;
  }
  return 0;
}
