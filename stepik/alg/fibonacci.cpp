#include <cassert>
#include <iostream>
#include <cstdint>
#include <vector>

class Fibonacci final {
 public:
  static int get_remainder(int64_t n, int m) {
    assert(n >= 1);
    assert(m >= 2);
    int f[2] = {0, 1};
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        f[i%2] = f[0] + f[1];
        f[i%2] = f[i%2] % m;
        v.push_back(f[i%2]);
        if(f[i%2] == 1 && f[(i-1)%2] == 0)
            break;
    }
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    if(f[n%2] == 1 && f[(n-1)%2] == 0)
        return v[n%(v.size() - 2)];
    else
        return f[n%2];
  }
  static int get(int n) {
    assert(n >= 0);
    int f[2] = {0, 1};
    for(int i = 2; i <= n; i++)
        f[i%2] = f[0] + f[1];
    n = f[n%2];
    return n;
  }
};

int main() {
  int64_t n;
  //int m;
  std::cin >> n;
  std::cout << Fibonacci::get(n) << std::endl;
  //std::cout << Fibonacci::get_remainder(n, m) << std::endl;
  return 0;
}
