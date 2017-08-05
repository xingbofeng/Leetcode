#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;
    while(left < right) {
      bool checkheight = (height[left] < height[right]);
      int minheight = checkheight ? height[left] : height[right];
      int newarea = minheight * (right - left);
      result = (result > newarea) ? result : newarea;
      checkheight ? left++ : right--;
    }
    return result;
  }
};

int main() {
  vector<int> height;
  height.push_back(1);
  height.push_back(2);
  height.push_back(3);
  cout << Solution().maxArea(height) << endl;
  return 0;
}