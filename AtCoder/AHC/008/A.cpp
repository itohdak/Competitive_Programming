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

#define MAP_SIZ 30
#define PET_MAX 20
#define HUM_MAX 10
int N, M;
int px[PET_MAX], py[PET_MAX], pt[PET_MAX];
int hx[HUM_MAX], hy[HUM_MAX];
int tx[HUM_MAX], ty[HUM_MAX];
bool pet[MAP_SIZ][MAP_SIZ];
queue<pair<int, int>> Q;

pair<int, int> d(string s) {
  int dx = 0, dy = 0;
  for(char c: s) {
    switch(c) {
    case 'U':
      dx--;
      break;
    case 'D':
      dx++;
      break;
    case 'R':
      dy++;
      break;
    case 'L':
      dy--;
      break;
    case '.':
      break;
    default:
      exit(1);
    }
  }
  return {dx, dy};
}

void input1() {
  cin >> N;
  rep(i, N) {
    cin >> px[i] >> py[i] >> pt[i];
    px[i]--; py[i]--;
  }
  cin >> M;
  rep(i, M) {
    cin >> hx[i] >> hy[i];
    hx[i]--; hy[i]--;
  }
}

void input2() {
  rep(i, MAP_SIZ) rep(j, MAP_SIZ) pet[i][j] = false;
  rep(i, N) {
    string s;
    cin >> s;
    auto [dx, dy] = d(s);
    px[i] += dx;
    py[i] += dy;
    pet[px[i]][py[i]] = true;
    // if(i == 7) cerr << px[i]+1 << ' ' << py[i]+1 << endk;
  }
  // cerr << endk;
}

tuple<char, int, int> decide_direction(int hx_, int hy_, int tx_, int ty_) {
  // (hx_, hy_): where you are now
  // (tx_, ty_): where you want to place a barrier
  cerr << tx_ << ' ' << ty_ << endl;
  int flag = 0;
  if(tx_+1 < MAP_SIZ) {
    tx_++;
  } else {
    ty_++;
    flag = 1;
  }
  if(tx_ < hx_) {
    return {'U', -1, 0};
  } else if(tx_ > hx_) {
    return {'D', 1, 0};
  } else if(ty_ < hy_) {
    return {'L', 0, -1};
  } else if(ty_ > hy_) {
    return {'R', 0, 1};
  } else {
    if(flag == 1) return {'l', 0, 0};
    else          return {'u', 0, 0};
  }
}

bool is_blocked(int x, int y) {
  int dx[] = {0, -1, 0, 1, 0};
  int dy[] = {0, 0, 1, 0, -1};
  rep(k, 5) {
    int nx = x+dx[k], ny = y+dy[k];
    if(nx < 0 || nx >= MAP_SIZ || ny < 0 || ny >= MAP_SIZ) continue;
    if(pet[nx][ny]) return true;
  }
  return false;
}

void output() {
  string out(M, '.');
  auto [c, dx, dy] = decide_direction(hx[0], hy[0], tx[0], ty[0]);
  out[0] = c;
  hx[0] += dx;
  hy[0] += dy;
  if(c == 'u' || c == 'l') {
    if(is_blocked(tx[0], ty[0])) {
      out[0] = '.'; // wait
    } else {
      auto [nx, ny] = Q.front(); Q.pop();
      tx[0] = nx, ty[0] = ny;
    }
  }
  cout << out << endl;
}

void init() {
  tx[0] = 12, ty[0] = 13;
  for(int i=12; i<=15; i++) Q.push({i, 13});
  for(int j=12; j>=0; j--) Q.push({15, j});
  for(int j=12; j<=15; j++) Q.push({17, j});
  for(int i=18; i<=29; i++) Q.push({i, 15});
  for(int i=18; i<=29; i++) Q.push({i, 15});
  for(int i=18; i>=16; i--) Q.push({i, 17});
  for(int j=18; j<=29; j++) Q.push({16, j});
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  input1();
  init();

  rep(_, 300) {
    output();
    input2();
  }

  return 0;
}
