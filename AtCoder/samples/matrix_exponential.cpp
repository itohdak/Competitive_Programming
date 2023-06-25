#include "header.hpp"

template<typename T>
vector<vector<T>> matmul(vector<vector<T>>& A,
                         vector<vector<T>>& B) {
  assert(A[0].size() == B.size());
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<T>> ret(n, vector<T>(l));
  rep(i, n) rep(k, l) rep(j, m) (ret[i][k] += A[i][j] * B[j][k]) %= mod;
  return ret;
}

template<typename T>
struct MatExp {

  vector<vector<T>> _trans;
  int _n;
  vector<vector<vector<T>>> M;
  int size = 60;

  MatExp(vector<vector<T>> trans): _trans(trans) {
    assert(_trans.size() == _trans[0].size());
    _n = _trans.size();
    init();
  }

  void init() {
    M.assign(size, vector<vector<T>>(_n, vector<T>(_n)));
    copy(all(_trans), M[0].begin());
    for(int i=1; i<size; i++) {
      M[i] = matmul(M[i-1], M[i-1]);
    }
  }

  vector<vector<T>> build(ll k) {
    vector<vector<T>> ret(_n, vector<T>(_n));
    rep(i, _n) ret[i][i] = 1;
    rep(i, size) {
      if((k>>i)&1) ret = matmul(ret, M[i]);
    }
    return ret;
  }
};
