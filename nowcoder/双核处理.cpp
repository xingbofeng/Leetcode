/**
 * 一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
 * 假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。
 * n个任务可以按照任意顺序放入CPU进行处理，
 * 现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。
 * 典型的0-1背包问题
 */
#include <iostream>
#include <vector>
#include <algorithm> // 封装C++常用算法的头文件
using namespace std;

int main() {
  int n; // 输入共有多少个任务
  cin >> n;
  vector<int> vec(n, 0);
  int sum = 0;
  // vec存放的是背包中物品的重量表
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    vec[i] = tmp / 1024; // 节省时间，因为输入的都是1024的倍数，否则超时
    sum += vec[i]; // 转化为sum/2的背包问题
  }
  // dp[i][n] 表示将i件物品(有体积，且不可分割)装进容量为n的背包中，可装物品的最大体积
  // 共有n个数，所以下标为n+1
  // 声明一个n项的的二维数组
  vector< vector<int> > dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    dp[i].resize(sum / 2 + 1); // resize作用是更改容器容量
  }
  /**
   * 背包问题：n个物品，背包总重量为sum/2，物品重量表为vec。
   * 第一行全是0，从第二行开始循环
   */
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= sum / 2; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= vec[i] && dp[i][j] < dp[i][j - vec[i]] + vec[i]) {
        dp[i + 1][j] = dp[i][j - vec[i]] + vec[i];
      }
    }
  }
  // 核处理时间为两个背包的较大值
  int res = max(dp[n][sum / 2], sum - dp[n][sum / 2]);
  cout << res * 1024 << endl;
  return 0;
}