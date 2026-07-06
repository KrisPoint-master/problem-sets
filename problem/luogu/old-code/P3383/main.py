def zhishu(n):
    if n < 2:
        return []

    is_prime = bytearray([1]) * ((n + 7) // 8)
    primes = [2]

    def is_prime_check(x):
        return is_prime[x // 8] & (1 << (x % 8))

    def set_c(x):
        is_prime[x // 8] &= ~(1 << (x % 8))

    for i in range(3, n + 1, 2):
        if is_prime_check(i):
            primes.append(i)
        for p in primes:
            if i * p > n:
                break
            set_c(i * p)
            if i % p == 0:
                break
    return primes

def main():
    p = []
    n = m = 0
    a = input()
    a = a.split(' ')
    n = int(a[0])
    m = int(a[1])
    p = zhishu(n)
    for i in range(1,n + 1):
        k = int(input())
        print(p[k-1])

if __name__ == "__main__":
    main()
        
