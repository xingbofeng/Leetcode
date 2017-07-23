#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) {
      return 0;
    }
    int number = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == val) {
        number++;
      }
    }
    // 选择排序的方式，把与val不同的值选择到数组开头
    int temp;
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] != val) {
          temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
        }
      }
    }
    return (nums.size() - number);
  }
};

int main() {
  int arri[3] = {12, 12, 123};
  vector<int> arr(arri, arri + 3);
  int length = Solution().removeElement(arr, 12);
  cout << length << endl;
}