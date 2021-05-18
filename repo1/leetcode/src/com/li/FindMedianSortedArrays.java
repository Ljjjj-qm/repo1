package com.li;

import java.util.Arrays;

/**
 * @program: leetcode
 * @description: 寻找两个正序数组的中位数
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * @author: ZhangQingMin
 * @create: 2021-05-10 09:26
 **/
public class FindMedianSortedArrays {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;

        int[] arr = new int[m + n];

        for (int i = 0; i < m; ++i) {
            arr[i] = nums1[i];
        }
        for (int i = 0; i < n; ++i) {
            arr[m + i] = nums2[i];
        }

        Arrays.sort(arr);

        if ((m + n)%2 == 0) {
            int n1 = arr[(m + n)/2 - 1];
            int n2 = arr[(m + n)/2];

            return (double)(n1 + n2)/2;
        } else {
            return (double)arr[(m + n)/2];
        }
    }

    public static void main(String[] args) {
        int nums1[] = new int[]{1, 2};
        int nums2[] = new int[]{3, 4};
        FindMedianSortedArrays findMedianSortedArrays = new FindMedianSortedArrays();
        double medianSortedArrays = findMedianSortedArrays.findMedianSortedArrays(nums1, nums2);
        System.out.println(medianSortedArrays);
    }


}
