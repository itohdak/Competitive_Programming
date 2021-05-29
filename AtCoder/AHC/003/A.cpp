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

int SIZE = 30;
double init_val = 3000;
vector<vector<double>> EX(SIZE, vector<double>(SIZE, init_val));
vector<vector<double>> EY(SIZE, vector<double>(SIZE, init_val));
vector<double> EXAVE(SIZE, init_val);
vector<double> EYAVE(SIZE, init_val);
vector<vector<int>> ConfX(SIZE, vector<int>(SIZE));
vector<vector<int>> ConfY(SIZE, vector<int>(SIZE));
std::random_device RND;
std::mt19937 MT((int)time(0));
std::uniform_real_distribution<> RAND(0, 1);
std::uniform_real_distribution<> RAND_DELTA(-1, 1);
double SCALE_DELTA = 500; // 1000;
double SCALE_HEURISTIC = 1000; // 1000;
int ASTAR_EPOCH = 1;
double LR = 1.0;
double AVE_FACTOR = 0.0;
double SMOOTH_FACTOR = 0.05;
double SIGMA_GAUSSIAN = 0.45;
int KERNEL_WIDTH = 1;
vector<double> W(2*KERNEL_WIDTH+1);

struct Node {
  int x, y, tx, ty;
  double cost, h;
  Node(int _x, int _y, int _tx, int _ty, double _cost): x(_x), y(_y), tx(_tx), ty(_ty), cost(_cost) {
    // h = sqrt((tx-x)*(tx-x)+(ty-y)*(ty-y));
    h = (abs(tx-x) + abs(ty-y)) * SCALE_HEURISTIC;
  }
public:
  bool operator>(const Node& other) const {
    return cost + h > other.cost + other.h;
  }
  bool operator<(const Node& other) const {
    return cost + h < other.cost + other.h;
  }
};

double gaussian_weight(int dx) {
  return (double)1/(sqrt(2*M_PI)*SIGMA_GAUSSIAN) * exp(-pow(dx, 2)/(2*pow(SIGMA_GAUSSIAN, 2)));
}
void build_gaussian_kernel() {
  double gaussian_weight_sum = 0;
  W.assign(2*KERNEL_WIDTH+1, 0);
  for(int k=-KERNEL_WIDTH; k<=KERNEL_WIDTH; k++) {
    W[k+KERNEL_WIDTH] = gaussian_weight(k);
    gaussian_weight_sum += W[k+KERNEL_WIDTH];
  }
  for(int k=-KERNEL_WIDTH; k<=KERNEL_WIDTH; k++) {
    W[k+KERNEL_WIDTH] /= gaussian_weight_sum;
  }
}

pair<string, double> Astar(int si, int sj, int ti, int tj) {
  priority_queue<Node, vector<Node>, greater<Node>> q;
  vector<bool> vis(SIZE*SIZE);
  vector<double> dist(SIZE*SIZE, inf);
  vector<int> par(SIZE*SIZE, -1);
  q.push(Node(si, sj, ti, tj, 0));
  dist[si*SIZE+sj] = 0;
  // ほぼダイクストラ
  while(q.size()) {
    auto curNode = q.top(); q.pop();
    int x = curNode.x, y = curNode.y;
    int cur = x*SIZE+y;
    if(vis[cur]) continue;
    if(dist[cur] < curNode.cost) continue;
    if(cur == ti*SIZE+tj) break;
    vis[cur] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    rep(k, 4) {
      int nx = x+dx[k], ny = y+dy[k];
      int ne = nx*SIZE+ny;
      if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
      if(vis[ne]) continue;
      double cost = RAND_DELTA(MT)*SCALE_DELTA;
      if(dx[k] == 1) cost += EX[y][x] + (EXAVE[y] - EX[y][x]) * AVE_FACTOR;
      else if(dx[k] == -1) cost += EX[y][x-1] + (EXAVE[y] - EX[y][x-1]) * AVE_FACTOR;
      else if(dy[k] == 1) cost += EY[x][y] + (EYAVE[x] - EY[x][y]) * AVE_FACTOR;
      else if(dy[k] == -1) cost += EY[x][y-1] + (EYAVE[x] - EY[x][y-1]) * AVE_FACTOR;
      if(dist[ne] > curNode.cost+cost) {
        dist[ne] = curNode.cost+cost;
        par[ne] = cur;
        q.push(Node(nx, ny, ti, tj, curNode.cost+cost));
      }
    }
  }
  // 経路復元
  assert(par[ti*SIZE+tj] != -1);
  string path = "";
  int tmp = ti*SIZE+tj;
  int x = tmp/SIZE, y = tmp%SIZE;
  while(par[tmp] != -1) {
    int diff = tmp-par[tmp];
    if(diff == 1) {
      path += 'R';
      ConfY[x][y-1]++;
      y--;
    } else if(diff == -1) {
      path += 'L';
      ConfY[x][y]++;
      y++;
    } else if(diff == SIZE) {
      path += 'D';
      ConfX[y][x-1]++;
      x--;
    } else if(diff == -SIZE) {
      path += 'U';
      ConfX[y][x]++;
      x++;
    } else {
      assert(false);
    }
    tmp = par[tmp];
  }
  assert(x == si && y == sj);
  reverse(all(path));
  return {path, dist[ti*SIZE+tj]};
}

pair<string, double> build_path(int si, int sj, int ti, int tj) {
  rep(i, SIZE) rep(j, SIZE) {
    ConfX[i][j] = ConfY[i][j] = 0;
  }
  unordered_set<string> st;
  string path;
  double expect = 0;
  rep(i, ASTAR_EPOCH) {
    auto ret = Astar(si, sj, ti, tj);
    path = ret.first;
    expect = expect / (i+1) * i + ret.second / (i+1);
    st.insert(path);
  }
  // cerr << st << endk;
  return {path, expect};
}

int get_boundary(vector<double> expected) {
  double threshold = 0;
  int sz = expected.size()-1;
  vector<double> cum(sz+1);
  rep(i, sz) cum[i+1] = cum[i] + expected[i];
  vector<pair<double, int>> diff;
  REP(i, 1, sz) {
    double mu1 = cum[i]/i, mu2 = (cum[sz]-cum[i])/(sz-i);
    double sigma1 = 0, sigma2 = 0;
    rep(k, i) sigma1 += pow(expected[k]-mu1, 2);
    REP(k, i, sz) sigma2 += pow(expected[k]-mu2, 2);
    double mu = cum[sz]/sz, sigma = (pow(mu1-mu, 2)*i + pow(mu2-mu, 2)*(sz-i)); // クラス間分散
    double _sigma = sigma1 + sigma2; // クラス内分散
    double J = sigma / _sigma;
    diff.push_back({J, i});
  }
  sort(all(diff), greater<pair<double, int>>());
  if(diff[0].first > threshold) {
    return diff[0].second;
  } else {
    return 0;
  }
}

bool update_expect(int si, int sj, int ti, int tj, string path, double response, double expected) {
  int x = si, y = sj;
  double delta = (response - expected) / expected * LR;
  for(char c: path) {
    if(c == 'D') {
      EX[y][x] += delta * EX[y][x] * ConfX[y][x] / ASTAR_EPOCH;
      x++;
    } else if(c == 'U') {
      EX[y][x-1] += delta * EX[y][x-1] * ConfX[y][x-1] / ASTAR_EPOCH;
      x--;
    } else if(c == 'R') {
      EY[x][y] += delta * EY[x][y] * ConfY[x][y] / ASTAR_EPOCH;
      y++;
    } else if(c == 'L') {
      EY[x][y-1] += delta * EY[x][y-1]* ConfY[x][y-1] / ASTAR_EPOCH;
      y--;
    }
  }
  // cerr << get_boundary(EY[17]) << ' ' << EY[17] << endk;
  vector<vector<double>> EXtmp(SIZE, vector<double>(SIZE, 0));
  vector<vector<double>> EYtmp(SIZE, vector<double>(SIZE, 0));
  rep(i, SIZE) rep(j, SIZE) {
    int boundary_x = 0; // get_boundary(EX[i]);
    int boundary_y = 0; // get_boundary(EY[i]);
    for(int k=-KERNEL_WIDTH; k<=KERNEL_WIDTH; k++) {
      if(j < boundary_x) {
        EXtmp[i][j] += EX[i][min(min(max(j+k, 0), SIZE-1), boundary_x-1)] * W[k+KERNEL_WIDTH];
      } else {
        EXtmp[i][j] += EX[i][max(min(max(j+k, 0), SIZE-1), boundary_x)] * W[k+KERNEL_WIDTH];
      }
      if(j < boundary_y) {
        EYtmp[i][j] += EY[i][min(min(max(j+k, 0), SIZE-1), boundary_y-1)] * W[k+KERNEL_WIDTH];
      } else {
        EYtmp[i][j] += EY[i][max(min(max(j+k, 0), SIZE-1), boundary_y)] * W[k+KERNEL_WIDTH];
      }
    }
  }
  // rep(i, SIZE) rep(j, SIZE) {
  //   if(j == 0) {
  //     EXtmp[i][j] = EX[i][j]*(1-SMOOTH_FACTOR)+EX[i][j+1]*SMOOTH_FACTOR;
  //   } else if(j == SIZE-1) {
  //     EXtmp[i][j] = EX[i][j]*(1-SMOOTH_FACTOR)+EX[i][j-1]*SMOOTH_FACTOR;
  //   } else {
  //     EXtmp[i][j] = EX[i][j]*(1-2*SMOOTH_FACTOR)+EX[i][j+1]*SMOOTH_FACTOR+EX[i][j-1]*SMOOTH_FACTOR;
  //   }
  //   if(j == 0) {
  //     EYtmp[i][j] = EY[i][j]*(1-SMOOTH_FACTOR)+EY[i][j+1]*SMOOTH_FACTOR;
  //   } else if(j == SIZE-1) {
  //     EYtmp[i][j] = EY[i][j]*(1-SMOOTH_FACTOR)+EY[i][j-1]*SMOOTH_FACTOR;
  //   } else {
  //     EYtmp[i][j] = EY[i][j]*(1-2*SMOOTH_FACTOR)+EY[i][j+1]*SMOOTH_FACTOR+EY[i][j-1]*SMOOTH_FACTOR;
  //   }
  // }
  rep(i, SIZE) rep(j, SIZE) {
    EX[i][j] = EXtmp[i][j];
    EY[i][j] = EYtmp[i][j];
  }
  rep(i, SIZE) rep(j, SIZE) {
    if(j != SIZE-1) EXAVE[i] += EX[i][j];
    if(i != SIZE-1) EYAVE[j] += EY[j][i];
  }
  rep(i, SIZE) {
    EXAVE[i] /= SIZE;
    EYAVE[i] /= SIZE;
  }
  assert(x == ti && y == tj);
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  build_gaussian_kernel();
  rep(t, 1000) {
    int si, sj, ti, tj; cin >> si >> sj >> ti >> tj;
    auto [path, exp] = build_path(si, sj, ti, tj);
    cout << path << endl;
    ll res; cin >> res;
    update_expect(si, sj, ti, tj, path, res, exp);
    // if(t && t%100==0) {
    //   LR -= 0.005;
    // }
    // LR -= 0.001;
    // LR *= 0.9998;
  }
  rep(i, SIZE) {
    cerr << "   ";
    rep(j, SIZE) cerr << round(EY[i][j]) << "  ";
    cerr << endk << endk;
    rep(j, SIZE) cerr << round(EX[j][i]) << "  ";
    cerr << endk << endk;
  }
  return 0;
}
