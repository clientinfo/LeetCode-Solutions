# 7. Reverse Integer

Difficulty: **Hard**

Given two sorted arrays `array_number_one` and `array_number_two` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

----------------------------------------------------------------

**Example 1:**

**Input:** array_number_one = [1,3], array_number_two = [2]

**Output:** 2.00000

**Explanation:** merged array = [1,2,3] and median is 2.

----------------------------------------------------------------

**Example 2:**

**Input:** array_number_one = [1,2], array_number_two = [3,4]

**Output:** 2.50000

**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 ----------------------------------------------------------------

**Constraints:**

- `array_number_one.length == m`
- `array_number_two.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= array_number_one[i], array_number_two[i] <= 10^6`
