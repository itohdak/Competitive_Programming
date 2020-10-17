#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<ll> A(N); rep(i, N) cin >> A[i];
  int Q; cin >> Q;
  while(Q--) {
    int t; cin >> t;
    if(t == 1) {
      int l, r; ll x;
      cin >> l >> r >> x; l--; r--;

    } else {
      int l, r;
      cin >> l >> r; l--; r--;
    }
  }
  return 0;
}
