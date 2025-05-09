> 题目及解法来源于代码随想录，本文为记录本人的一些思考
# 数组
----
## 二分查找
https://leetcode.cn/problems/binary-search/  
### 易错点
边界处理：   
- right在一开始的取值是n还是n-1
- while(left ? right) 小于还是小于等于 
- right = middle (- 1)? 是否需要-1
### 解析
需要首先明确**区间**的定义，是左闭右闭还是左闭右开  
根据这个，时刻让区间左闭右开  
以左闭右开为例  
- 右边是开区间，right应该取n
- 进入while循环的应为**合法的区间**
    - 左闭右开下，left不该等于right（[1,1)不合法）
- 当确定middle不是target时，即成为了不可取的值，则right应该为middle

伪代码：  
```
left = 0
right = n
while(left<right){
    mid=(left+right)/2  // 避免溢出的版本：mid=left+(right-left)/2
    if(arr[mid]<target){
        left = mid + 1   // 左闭，mid已确认不是了，所以left不能再取mid
    }else if(arr[mid]>target){
        right = mid  // 右开，right应为不能取到的值
    }else{return mid}
}
return -1
```
---
## 移除元素
https://leetcode.cn/problems/remove-element/
### 方法（基本复杂度为o(N)）
- 直接使用库函数vector的erase等
- 双指针
#### 双指针法（可以删除多个元素）
两个指针slow和fast，使用fast遍历原数组，slow则记录新数组的元素的位置，当不等于target时，
将arr[fast]赋给arr[slow]，（其中fast与slow都在原数组中操作）  
伪代码如下：
```
slow = fast = 0
while(fast < n){
    if(arr[fast]!=target){
        arr[slow++]=arr[fast]
    }
    fast++
}
return slow  // 数组长度（因为跳出循环前slow就++了，所以不需要+1!!!!!）
```
---
## 有序数组的平方
https://leetcode.cn/problems/squares-of-a-sorted-array/  
有正有负的有序数组，返回平方后的数组，且仍有序
### 方法
- 先平方，再快排（大致O(nlogn)）
- 双指针
#### 双指针
对于有序数组，其平方的最大数必然在其两端，所以可以用两个指针从两端遍历到中心  

---
## 长度最小的子数组
https://leetcode.cn/problems/minimum-size-subarray-sum/  
正数数组，找出和大于s的最短子数组
### 方法
- 暴力破解 O(n^2)
- 双指针（滑动窗口）
#### 双指针
暴力破解的优化版中，当j遍历到和大于s时，就可以进入下一次循环了，i++  
为此，进行进一步优化（剪枝）：首先明确哪里计算重复了：  
进入下一次循环时，已经计算了i到j的和，进入下一次循环后，又要从i+1开始累加，**重复计算**  
已知i到j-1的和小于s，i到j的和大于s，则i+1到j-1也小于s，所以*i+1到j-1*的部分已经计算了，只需要计算i+1到j即可  
所以，拿j遍历终止位置，当满足大于s后，再移动起始指针i，之后再移动j···

---
## 区间和
https://kamacoder.com/problempage.php?pid=1070  
给定数组，给出多段区间，分别求区间和
### 方法
- 暴力破解
- 前缀和
#### 前缀和
在暴力破解时，区间可能有重复范围，重复求解。由于是连续的区间，所以只需要求出前缀和S(x)(arr[0]到arr[x]的和)
- S(n) = S(n-1) + arr[n]
- 区间[i,j]的和等于S(j)-S(i-1)
计算前缀和的复杂度为O(n)

---
## 双指针总结
对一道题目，考虑双指针解法时，可以注意方向：  
- 从**左右两端**到中心遍历是否可解决问题
    - 结束条件为left小于等于right
- 往同一方向遍历，一个指针快于另一个
    - 结束条件为快指针遍历至n-1
本质上，都是利用题目的隐藏特征，对**暴力算法的简化**，去除重复运算部分