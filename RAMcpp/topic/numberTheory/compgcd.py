
line = input()

nums = [int(x) for x in line.split(" ")]

gcd = nums[0]

def computeGcd(a, b):
    if a == 0:
        return b
    return computeGcd(b % a, a)

for i in range(nums[0], nums[1]+1):
    gcd = computeGcd(gcd, i)
    if gcd == 1:
        break

print(gcd)

# 