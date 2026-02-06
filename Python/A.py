import bisect
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        a = [(v,i) for i,v in enumerate(nums)]
        a.sort()
        for idx,(v,i) in enumerate(a):
            print(v, i)
            idx2 = bisect.bisect_left(a, (target-v,0))
            if(idx2==idx):
                idx2 +=1
            if(idx2<len(a) and a[idx2][0]==target-v):
                ans = [i,a[idx2][1]]
                return ans

# TC 1
nums1 = [3,2,3]
target = 6
sol = Solution()
ans = sol.twoSum(nums1,target)
print(ans)