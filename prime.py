
def countPrimes(n):
       if n < 2:           # n < 2, no primes
          return 0

       A = [True] * n    # default value all True, we just need A[2] to A[n - 1].
       ans = []
       for i in range(2, int(n ** 0.5) + 1):
           if A[i]:
              for j in range(i ** 2, n, i):
                  A[j] = False
       ans = [i for i in range(len(A)) if(A[i])]
       return sum(A) - 2,ans[2:]   # remove A[0] and A[1] since 0 and 1 are not primes

print(countPrimes(1000*5000))

