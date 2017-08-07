/**
 * 反复轮换，找到数组中重复的数字
 * 因为数字都是在0到n-1之间的
 * 从开始开始遍历，一旦扫描到数字m，看m和下标是否相等，如果相等，则继续扫描
 * 如果不相等，则把m和数组第m项互换，再看是否相等，如果还不相等，则继续互换
 * 一旦遇到相等，则说明该数字重复，入队，继续扫描
 * 最后队列中的就是重复的
 * 也可以直接数组去重或者hashmap
 * @param  {Array} array 数组
 * @return {Array}       重复的数字数组
 */
function duplicate(array) {
  let result = [];
  for (let i = 0; i < array.length; i++) {
    while (array[i] !== i) {
      if (array[i] === array[array[i]]) {
        result.push(array[i])
        break;
      }
      let temp = array[i];
      array[i] = array[temp];
      array[temp] = temp;
    }
  }
  return result;
}

console.log(duplicate([2, 3, 1, 0, 2, 5, 3]));