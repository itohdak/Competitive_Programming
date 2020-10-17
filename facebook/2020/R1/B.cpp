#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll solve(ifstream& fin) {
  ll n, m, k, s; fin >> n >> m >> k >> s;
  vector<ll> P(n); rep(i, k) fin >> P[i];
  ll pparam[4]; rep(i, 4) fin >> pparam[i];
  vector<ll> Q(m); rep(i, k) fin >> Q[i];
  ll qparam[4]; rep(i, 4) fin >> qparam[i];
  REP(i, k, n) {
    ll a = pparam[0], b = pparam[1], c = pparam[2], d = pparam[3];
    P[i] = (a*P[i-2]+b*P[i-1]+c)%d+1;
  }
  sort(all(P));
  REP(i, k, m) {
    ll a = qparam[0], b = qparam[1], c = qparam[2], d = qparam[3];
    Q[i] = (a*Q[i-2]+b*Q[i-1]+c)%d+1;
  }
  sort(all(Q));
  auto test = [&](ll k) {
                int t = 0;
                rep(i, n) {
                  ll rem = k;
                  if(Q[t] < P[i]) {
                    ll dist = P[i]-Q[t];
                    if(dist+s > rem) return false;
                    rem -= dist+s;
                    t++;
                    while(t < m && Q[t] < P[i] && s <= rem) {
                      rem -= s;
                      t++;
                    }
                    if(t == m) return true;
                    if(Q[t] < P[i]) continue;
                    if(rem < dist) continue;
                    rem -= dist;
                  }
                  ll tmp = P[i];
                  while(t < m && Q[t]-tmp+s <= rem) {
                    rem -= Q[t]-tmp+s;
                    tmp = Q[t];
                    t++;
                  }
                  if(t == m) return true;
                }
                return false;
              };
  ll ok = longinf, ng = 0;
  while(ok-ng>1) {
    ll mid = (ok+ng)/2;
    (test(mid) ? ok : ng) = mid;
  }
  return ok;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream fin("/home/itohdak/facebook/2020/R1/input/dislodging_logs_validation_input.txt");
  ofstream fout("/home/itohdak/facebook/2020/R1/output/dislodging_logs_validation_output.txt");
  int t; fin >> t;
  rep(i, t) {
    fout << "Case #" << i+1 << ": ";
    fout << solve(fin) << endk;
  }
  return 0;
}
