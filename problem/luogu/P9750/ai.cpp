#include <iostream>
#include <cmath>
#include <algorithm>

namespace EquationSolver
{

    // 函数 1：最简分数化简并输出
    void print_fraction(long long num, long long den)
    {
        if (num == 0)
        {
            std::cout << 0;
            return;
        }
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        long long g = std::__gcd(std::abs(num), den);
        num /= g;
        den /= g;

        if (den == 1)
        {
            std::cout << num;
        }
        else
        {
            std::cout << num << "/" << den;
        }
    }

    // 函数 2：处理全有理数解的情况
    void solve_rational(long long b, long long s, long long fa)
    {
        print_fraction(-b + s, fa);
        std::cout << "\n";
    }

    // 函数 3：处理无理数解的情况
    void solve_irrational(long long b, long long delta, long long fa, long long s)
    {
        // 1. 输出有理数部分 q1
        if (b != 0)
        {
            print_fraction(-b, fa);
            std::cout << "+";
        }

        // 2. 化简根式：将 sqrt(delta) 化为 k * sqrt(r)
        long long k = 1, r = delta;
        for (long long i = s; i >= 2; i--)
        {
            if (r % (i * i) == 0)
            {
                k = i;
                r /= (i * i);
                break;
            }
        }

        // 3. 计算并输出无理数系数 q2 = k / fa
        long long g = std::__gcd(k, fa);
        long long up = k / g;
        long long down = fa / g;

        if (up != 1)
            std::cout << up << "*";
        std::cout << "sqrt(" << r << ")";
        if (down != 1)
            std::cout << "/" << down;

        std::cout << "\n";
    }

    // 函数 4：核心分流控制
    void solve()
    {
        long long a, b, c;
        std::cin >> a >> b >> c;

        long long delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            std::cout << "NO\n";
            return;
        }

        // 统一符号，确保分母为正，较大解分子取 + 号
        if (a < 0)
        {
            a = -a;
            b = -b;
            c = -c;
        }
        long long fa = 2 * a;

        // 判断是否为完全平方数
        long long s = std::round(std::sqrt(delta));
        if (s * s == delta)
        {
            solve_rational(b, s, fa);
        }
        else
        {
            solve_irrational(b, delta, fa, s);
        }
    }

} // namespace EquationSolver

int main()
{
    // 极致 I/O 优化
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, M;
    if (std::cin >> T >> M)
    {
        while (T--)
        {
            EquationSolver::solve();
        }
    }
    return 0;
}