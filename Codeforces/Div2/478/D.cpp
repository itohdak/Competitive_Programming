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
  int n; ll a, b; cin >> n >> a >> b;
  vector<ll> X(n), Vx(n), Vy(n);
  map<ll, vector<int>> mp1;
  map<pair<ll, ll>, vector<int>> mp2, mp3;
  map<pair<ll, pair<ll, ll>>, vector<int>> mp4;
  rep(i, n) {
    cin >> X[i] >> Vx[i] >> Vy[i];
    mp1[a*Vx[i]-Vy[i]].push_back(i);
    mp2[{a*Vx[i]-Vy[i], Vx[i]}].push_back(i);
    mp3[{a*Vx[i]-Vy[i], Vy[i]}].push_back(i);
    mp4[{a*Vx[i]-Vy[i], make_pair(Vy[i], Vy[i])}].push_back(i);
  }
  // cout << mp1 << endk;
  // cout << mp2 << endk;
  // cout << mp3 << endk;
  // cout << mp4 << endk;
  ll ans = 0;
  for(auto ele: mp1) ans += 1LL * ele.second.size() * (ele.second.size()-1) / 2;
  for(auto ele: mp2) ans -= 1LL * ele.second.size() * (ele.second.size()-1) / 2;
  cout << 2 * ans << endk;
  return 0;
}
