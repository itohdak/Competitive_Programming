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
  set<ll> sel, ser;
  rep(i, N) ser.insert(A[i]);
  ll mn = longinf;
  rep(i, N) {
    ser.erase(A[i]);
    if(!sel.empty() && !ser.empty()) {
      if(*sel.begin() < A[i] && *ser.begin() < A[i]) {
        mn = min(A[i]+*sel.begin()+*ser.begin(), mn);
      }
      auto itrl = sel.lower_bound(A[i]+1);
      auto itrr = ser.lower_bound(A[i]+1);
      if(itrl != sel.end() && itrr != ser.end()) {
        mn = min(A[i]+*itrl+*itrr, mn);
      }
    }
    sel.insert(A[i]);
  }
  cout << (mn==longinf ? -1 : mn) << "\n";
  return 0;
}
