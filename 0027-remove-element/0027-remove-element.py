class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        # k is the index where the next element not equal to val should be placed.
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k