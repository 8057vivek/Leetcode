class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        map1 = dict()

        for num in nums:
            map1[num] = map1.get(num, 0) + 1
        
        for value in map1.values():
            if(value%2!=0):
                return False
        return True
            
        