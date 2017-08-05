#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); ++k) {
      if (nums[k] > 0) {
        break;
      }
      int target = -nums[k];
      int i = k + 1, j = nums.size() - 1;
      while(i < j) {
        if (nums[i] + nums[j] == target) {
          res.insert({nums[k], nums[i], nums[j]});
          while(i < j && nums[i] == nums[i + 1]) {
            ++i;
          }
          while(i < j && nums[j] == nums[j - 1]) {
            --j;
          }
          ++i;
          --j;
        } else if (nums[i] + nums[j] < target) {
          ++i;
        } else {
          --j;
        }
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
};

int main() {
  int array[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> nums(array, array + 6);
  cout << Solution().threeSum(nums).size() << endl;
  return 0;
}