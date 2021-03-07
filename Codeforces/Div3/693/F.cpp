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

bool solvePart(map<ll, vector<int>>& mp) {
  if(mp.size()%2) {
    return false;
  }
  vector<ll> A;
  for(auto ele: mp) A.push_back(ele.first);
  for(int i=0; i<A.size(); i+=2) {
    if(!(((A[i+1]-A[i])+mp[A[i]][0]+mp[A[i+1]][0])%2)) {
      return false;
    }
  }
  return true;
}
void solve() {
  ll n; int m; cin >> n >> m;
  vector<ll> R(m), C(m);
  map<ll, vector<int>> mp;
  rep(i, m) {
    cin >> R[i] >> C[i];
    R[i]--; C[i]--;
    R[i] = 1-R[i];
    mp[C[i]].push_back(R[i]);
  }
  map<ll, vector<int>> mpPart;
  for(auto ele: mp) {
    if(ele.second.size() == 2) {
      if(!solvePart(mpPart)) {
        cout << "NO" << endk;
        return;
      }
      mpPart.clear();
    } else {
      mpPart[ele.first] = ele.second;
    }
  }
  cout << (solvePart(mpPart) ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
