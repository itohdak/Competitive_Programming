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
  int n, q; cin >> n >> q;
  vector<int> pos(n+1);
  vector<int> A(n);
  rep(i, n) {
    pos[i+1] = i;
    A[i] = i+1;
  }
  rep(i, q) {
    int x; cin >> x;
    int p1 = pos[x];
    int p2 = (p1 == n-1 ? p1-1 : p1+1);
    int a1 = A[p1];
    int a2 = A[p2];
    swap(A[p1], A[p2]);
    swap(pos[a1], pos[a2]);
  }
  rep(i, n) cout << A[i] << ' ';
  cout << endk;
  return 0;
}
