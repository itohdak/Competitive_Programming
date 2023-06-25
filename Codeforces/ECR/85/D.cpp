#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<int> ans;
int two[] = {1, 2, 1};
int three[] = {1, 2, 1, 3, 2, 3, 1};
void add(ll n, ll l, ll r, int c) {
  if(n == 2) {
    REP(i, l-1, r) ans.push_back(two[i]+c);
    return;
  } else if(n == 3) {
    REP(i, l-1, r) ans.push_back(three[i]+c);
    return;
  }
  ll begin = (n-2)*(n-3)+1+(n-1)*2;
  if(r <= (n-1)*2) {
    if(l%2==0) ans.push_back(l/2+1+c);
    REP(i, (l+1)/2, r/2+1) {
      ans.push_back(1+c);
      ans.push_back(i+1+c);
    }
    if(r%2) ans.push_back(1+c);
  } else if(l > begin) {
    if((l-begin)%2==0) {
      if((l-begin)/2 == n-2) ans.push_back(1+c);
      else ans.push_back((l-begin)/2+2+c);
    }
    REP(i, (l-begin+1)/2, (r-begin)/2+1) {
      ans.push_back(n+c);
      if(i == n-2) ans.push_back(1+c);
      else         ans.push_back(i+2+c);
    }
    if((r-begin)%2) ans.push_back(n+c);
  } else {
    if(l%2==0) ans.push_back(l/2+1+c);
    REP(i, (l+1)/2, n) {
      ans.push_back(1+c);
      ans.push_back(i+1+c);
    }

    add(n-2, 1, (n-2)*(n-3)+1, c+1);

    REP(i, 1, (r-begin)/2+1) {
      ans.push_back(n+c);
      if(i == n-2) ans.push_back(1+c);
      else         ans.push_back(i+2+c);
    }
    if((r-begin)%2) ans.push_back(n+c);
  }
}
void solve() {
  ll N, l, r;
  cin >> N >> l >> r;
  ans = vector<int>();
  add(N, l, r, 0);
  for(int i: ans) cout << i << ' ';
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
