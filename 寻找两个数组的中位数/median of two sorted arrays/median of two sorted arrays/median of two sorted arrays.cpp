// median of two sorted arrays.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

// Classical binary search algorithm, but slightly different
// if cannot find the key, return the position where can insert the key 
int binarySearch(int A[], int low, int high, int key) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (key == A[mid]) return mid;
		if (key > A[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}

//Notes:
// I feel the following methods is quite complicated, it should have a better high clear and readable solution
double findMedianSortedArrayHelper(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB) {

	// Take the A[middle], search its position in B array
	int mid = lowA + (highA - lowA) / 2;
	int pos = binarySearch(B, lowB, highB, A[mid]);
	int num = mid + pos;
	// If the A[middle] in B is B's middle place, then we can have the result
	if (num == (m + n) / 2) {
		// If two arrays total length is odd, just simply return the A[mid]
		// Why not return the B[pos] instead ? 
		//   suppose A={ 1,3,5 } B={ 2,4 }, then mid=1, pos=1
		//   suppose A={ 3,5 }   B={1,2,4}, then mid=0, pos=2
		//   suppose A={ 1,3,4,5 }   B={2}, then mid=1, pos=1
		// You can see, the `pos` is the place A[mid] can be inserted, so return A[mid]
		if ((m + n) % 2 == 1) {
			return A[mid];
		}

		// If tow arrys total length is even, then we have to find the next one.
		int next;

		// If both `mid` and `pos` are not the first postion.
		// Then, find max(A[mid-1], B[pos-1]). 
		// Because the `mid` is the second middle number, we need to find the first middle number
		// Be careful about the edge case
		if (mid>0 && pos>0) {
			next = A[mid - 1]>B[pos - 1] ? A[mid - 1] : B[pos - 1];
		}
		else if (pos>0) {
			next = B[pos - 1];
		}
		else if (mid>0) {
			next = A[mid - 1];
		}

		return (A[mid] + next) / 2.0;
	}
	// if A[mid] is in the left middle place of the whole two arrays
	//
	//         A(len=16)        B(len=10)
	//     [................] [...........]
	//            ^             ^
	//           mid=7         pos=1
	//
	//  move the `low` pointer to the "middle" position, do next iteration.
	if (num < (m + n) / 2) {
		lowA = mid + 1;
		lowB = pos;
		if (highA - lowA > highB - lowB) {
			return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
		}
		return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
	}
	// if A[mid] is in the right middle place of the whole two arrays
	if (num > (m + n) / 2) {
		highA = mid - 1;
		highB = pos - 1;
		if (highA - lowA > highB - lowB) {
			return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
		}
		return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
	}

}

double findMedianSortedArrays(int A[], int m, int B[], int n) {

	//checking the edge cases
	if (m == 0 && n == 0) return 0.0;

	//if the length of array is odd, return the middle one
	//if the length of array is even, return the average of the middle two numbers
	if (m == 0) return n % 2 == 1 ? B[n / 2] : (B[n / 2 - 1] + B[n / 2]) / 2.0;
	if (n == 0) return m % 2 == 1 ? A[m / 2] : (A[m / 2 - 1] + A[m / 2]) / 2.0;


	//let the longer array be A, and the shoter array be B
	if (m > n) {
		return findMedianSortedArrayHelper(A, m, B, n, 0, m - 1, 0, n - 1);
	}

	return findMedianSortedArrayHelper(B, n, A, m, 0, n - 1, 0, m - 1);
}


int main()
{
	int r1[] = { 1 };
	int r2[] = { 2 };

	int n1 = sizeof(r1) / sizeof(r1[0]);
	int n2 = sizeof(r2) / sizeof(r2[0]);

	printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45, 50 };

	n1 = sizeof(ar1) / sizeof(ar1[0]);
	n2 = sizeof(ar2) / sizeof(ar2[0]);

	printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

	int ar11[] = { 1, 12, 15, 26, 38 };
	int ar21[] = { 2, 13, 17, 30, 45 };

	n1 = sizeof(ar11) / sizeof(ar11[0]);
	n2 = sizeof(ar21) / sizeof(ar21[0]);

	printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

	int a1[] = { 1, 2, 5, 6, 8 };
	int a2[] = { 13, 17, 30, 45, 50 };

	n1 = sizeof(a1) / sizeof(a1[0]);
	n2 = sizeof(a2) / sizeof(a2[0]);

	printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

	int a10[] = { 1, 2, 5, 6, 8, 9, 10 };
	int a20[] = { 13, 17, 30, 45, 50 };

	n1 = sizeof(a10) / sizeof(a10[0]);
	n2 = sizeof(a20) / sizeof(a20[0]);

	printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

	int a11[] = { 1, 2, 5, 6, 8, 9 };
	int a21[] = { 13, 17, 30, 45, 50 };

	n1 = sizeof(a11) / sizeof(a11[0]);
	n2 = sizeof(a21) / sizeof(a21[0]);

	printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

	int a12[] = { 1, 2, 5, 6, 8 };
	int a22[] = { 11, 13, 17, 30, 45, 50 };

	n1 = sizeof(a12) / sizeof(a12[0]);
	n2 = sizeof(a22) / sizeof(a22[0]);

	printf("Median is 11 = %f\n", findMedianSortedArrays(a12, n1, a22, n2));

	int b1[] = { 1 };
	int b2[] = { 2,3,4 };

	n1 = sizeof(b1) / sizeof(b1[0]);
	n2 = sizeof(b2) / sizeof(b2[0]);

	printf("Median is 2.5 = %f\n", findMedianSortedArrays(b1, n1, b2, n2));
	return 0;
}

//该方法的核心是将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是第(m + n) / 2小的数。所以只要解决了第k小数的问题，原问题也得以解决。
//
//首先假设数组A和B的元素个数都大于k / 2，我们比较A[k / 2 - 1]和B[k / 2 - 1]两个元素，这两个元素分别表示A的第k / 2小的元素和B的第k / 2小的元素。
//这两个元素比较共有三种情况：>、<和 = 。

//如果A[k / 2 - 1]<B[k / 2 - 1]，这表示A[0]到A[k / 2 - 1]的元素都在A和B合并之后的前k小的元素中。换句话说，A[k / 2 - 1]不可能大于两数组合并之后的第k小值，所以我们可以将其抛弃。

//当A[k / 2 - 1]>B[k / 2 - 1]时存在类似的结论。

//当A[k / 2 - 1] = B[k / 2 - 1]时，我们已经找到了第k小的数，也即这个相等的元素，我们将其记为m。由于在A和B中分别有k / 2 - 1个元素小于m，所以m即是第k小的数。(这里可能有人会有疑问，如果k为奇数，则m不是中位数。这里是进行了理想化考虑，在实际代码中略有不同，是先求k / 2，然后利用k - k / 2获得另一个数。)
//
//	通过上面的分析，我们即可以采用递归的方式实现寻找第k小的数。此外我们还需要考虑几个边界条件：
//     如果A或者B为空，则直接返回B[k - 1]或者A[k - 1]；
//     如果k为1，我们只需要返回A[0]和B[0]中的较小值；
//     如果A[k / 2 - 1] = B[k / 2 - 1]，返回其中一个；
//  最终实现的代码为：


//double findKth(int a[], int m, int b[], int n, int k)
//{
//	//always assume that m is equal or smaller than n
//	if (m > n)
//		return findKth(b, n, a, m, k);
//	if (m == 0)
//		return b[k - 1];
//	if (k == 1)
//		return min(a[0], b[0]);
//	//divide k into two parts
//	int pa = min(k / 2, m), pb = k - pa;
//	if (a[pa - 1] < b[pb - 1])
//		return findKth(a + pa, m - pa, b, n, k - pa);
//	else if (a[pa - 1] > b[pb - 1])
//		return findKth(a, m, b + pb, n - pb, k - pb);
//	else
//		return a[pa - 1];
//}
//
//class Solution
//{
//public:
//	double findMedianSortedArrays(int A[], int m, int B[], int n)
//	{
//		int total = m + n;
//		if (total & 0x1)
//			return findKth(A, m, B, n, total / 2 + 1);
//		else
//			return (findKth(A, m, B, n, total / 2)
//				+ findKth(A, m, B, n, total / 2 + 1)) / 2;
//	}
//};