#include <cstdlib>
#include<chrono>
#include<iostream>

class Timer{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us =
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }
private:
    const clock_t::time_point start_;
};

int main()
{
    char* matrix1 = (char*)malloc(1000000*sizeof(char));
    char* matrix2 = (char*)malloc(1000000*sizeof(char));
    char* summatrix = (char*)malloc(1000000*sizeof(char));
    char n = 0;
    for(int i = 0; i < 1000; i++)
    {
      for(int j = 0; j < 1000; j++)
      {
        *(matrix1 + 1000*i + j) = n;
        *(matrix2 + 1000*i + j) = n + 1;
        n++;
      }
    }
    char c;
    Timer t;
    for(int i = 0; i < 1000; i++)
    {
      for(int j = 0; j < 1000; j++)
      {
        *(summatrix + 1000*i + j) = *(matrix1 + 1000*i + j) + *(matrix2 + 1000*i + j);
      }
    }
    c = *(summatrix + 999999);
    return 0;
}
