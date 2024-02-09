line = int(input())

def powMod(a, n, mod):
    res = 1
    a = a % mod
    while n:
        if n & 1:
            res = ((res % mod) * (a % mod)) % mod
            n-=1
        else:
            n = n // 2
            a = ((a % mod) * (a % mod)) % mod
    return res

for i in range(line):
    lineN = input()
    nums = [int(x) for x in lineN.split(" ")]
    mod = 1000000007

    a = nums[0]
    b = nums[1]
    n = nums[2]

    def computeGcd(a, b):
        if a == 0:
            return b
        return computeGcd(b % a, a)

    f1 = (powMod(a, n, mod) + powMod(b, n, mod)) % mod

    if a == b:
        print(f1)
    else:
        temp = 1
        maxD = 1
        diff = abs(a-b)
        while temp * temp <= diff:
            if diff % temp == 0:
                if (powMod(a, n, temp) + powMod(b, n, temp)) % temp == 0:
                    maxD = max(maxD, temp)
                secondF = diff / temp
                if (powMod(a, n, secondF) + powMod(b, n, secondF)) % (secondF) == 0:
                    maxD = max(maxD, secondF)
            temp+=1
        print(maxD)
