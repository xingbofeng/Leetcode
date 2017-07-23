# 判断回文数，只需要计算该数倒过来的数，看是否与原数相等
class Solution(object):
    def isPalindrome(self, x):
      if x < 0:
        return False
      elif x == 0:
        return True
      else :
        prenum = x
        reverse = 0
        while x != 0:
          y = x % 10
          x = int(x / 10)
          reverse = y + 10 * reverse
        return reverse == prenum