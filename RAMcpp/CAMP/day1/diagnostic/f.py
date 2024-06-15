

def isPossible(t, s, k):
    if t > 2 * k:
        return False

    fhL = min(t, k)
    
    fh = (fhL * (1 + fhL)) / 2
    sh = 0
    
    if t > k:
        sh = t - k - 1
        sh = (sh * (k + (k - sh-1)))/2
    
    return s >= fh + sh

def cost(t, s, k):
    if t > 2 * k:
        return -1

    fhL = min(t, k)
    
    fh = (fhL * (1 + fhL)) / 2
    sh = 0
    
    if t > k:
        sh = t - k + 1
        sh = (sh * (k + (k - sh + 1)))/2
    
    return fh + sh

def solve():
    ln = input()
    k = int(ln.split(" ")[0])
    x = int(ln.split(" ")[1])
    # print(k, x)
    # return
    
    l = 0
    r = 1e18+4
    
    if k==1:
        print(1)
        return
    
    while l < r:
        m = int(l + (r - l)/2)
        if (isPossible(m, x, k)):
            l = m
        else:
            r = m-1
            
        if r - l == 1:
            if isPossible(r, x, k):
                l = r
            else:
                r = l
    # print("Exited loop")  
    if l + 1 < 2 * k and cost(l, x, k) < x:
        print(l+1)
    else:
        print(l)


t = int(input())

for i in range(t):
    # print(i)
    solve()
