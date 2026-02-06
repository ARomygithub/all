from typing import List
from sortedcontainers import SortedList

class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:
        ct = (len(nums) * (len(nums) + 1)) // 2
        med = (ct + 1) // 2
        s = sorted(set(nums))
        mp = {val: idx for idx, val in enumerate(s)}
        id = len(s)
        l, r = 1, id
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            oset = SortedList()
            last = [-1] * id
            now = 0
            for i, num in enumerate(nums):
                cur = mp[num]
                if last[cur] != -1:
                    oset.remove(last[cur])
                last[cur] = i
                oset.add(last[cur])
                ls = 0 if len(oset) - (mid + 1) < 0 else (oset[len(oset) - (mid + 1)]+1)
                now += i - ls + 1
            if now >= med:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans

# Example usage:
sol = Solution()
# nums = [3,4,3,4,5]
# nums = [4,3,5,4]
from random import *
nums = []
mxn = 100000
# szi = randint(1,mxn)
szi = mxn
for i in range(szi):
    nums.append(randint(1,mxn))
print(sol.medianOfUniquenessArray(nums))