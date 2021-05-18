package com.li;

/**
 * @program: leetcode
 * @description: 二分查找
 * 给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/binary-search
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @author: ZhangQingMin
 * @create: 2021-05-10 17:19
 **/
public class Search {

    public int search(int[] nums, int target) {

//        int mid = nums.length / 2 - 1;
//
//        while (nums[mid] < target || nums[mid] == target) {
//            if (nums[mid] == target) {
//                return mid;
//            }
//            mid = mid / 2;
//
//            if (mid == 0 && nums[mid] != target) {
//                return -1;
//            }
//        }
//
//        while (nums[mid] > target || nums[mid] == target) {
//            if (nums[mid] == target) {
//                return mid;
//            }
//            mid = mid / 2 + mid;
//
//            if (mid == nums.length || nums[mid] != target) {
//                return -1;
//            }
//        }
//        return -1;

        int len = nums.length;

        int left = 0;
        int right = len - 1;
        // target在[left, right]区间内

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        int[] arr =  new int[] {-1, 0, 3, 5, 9, 12};

        Search search = new Search();

        int search1 = search.search(arr, 9);

        System.out.println(search1);
    }


}
