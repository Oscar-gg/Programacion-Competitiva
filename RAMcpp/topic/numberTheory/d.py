line = int(input())

for i in range(line):
    lineN = input()
    nums = [int(x) for x in lineN.split(" ")]

    gcd = nums[0]

    def computeGcd(a, b):
        if a == 0:
            return b
        return computeGcd(b % a, a)

    print(computeGcd(nums[0], nums[1]))

# 