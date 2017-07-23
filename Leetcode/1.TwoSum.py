# 给定一个数组和一个结果，返回数组中两数和为结果的数组下标
# 如果使用两层循环会超时，使用hash表则不会
class Solution:
  def twoSum(self, nums, target):
    length = len(nums)
    hashmap = {}
    for i in range(0,length):
      x = nums[i]
      if target - x in hashmap:
        return [hashmap[target -x], i]
      else:
        hashmap[x] = i