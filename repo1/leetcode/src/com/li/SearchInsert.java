package com.li;

/**
 * @program: leetcode
 * @description: 搜索插入位置
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 你可以假设数组中无重复元素。
 * @author: ZhangQingMin
 * @create: 2021-05-12 10:23
 **/
public class SearchInsert {

    public int searchInsert(int[] nums, int target) {

        int len = nums.length;
        int left = 0, right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

}
