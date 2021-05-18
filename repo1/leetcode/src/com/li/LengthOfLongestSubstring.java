package com.li;

import java.util.HashSet;
import java.util.Set;

/**
 * @program: leetcode
 * @description: 无重复字符的最长字串
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * @author: ZhangQingMin
 * @create: 2021-05-09 19:45
 **/
public class LengthOfLongestSubstring {

    public int lengthOfLongestSubstring(String s) {

        // HashSet 集合特点：无序，不允许重复，查找快，线程不安全
        Set<Character> occ = new HashSet<>();
        int n = s.length();
        // rk 为字串的右指针，初始值-1，相当于字符串左边界的左侧
        int rk = -1, ans = 0;

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                occ.remove(s.charAt(i - 1));
            }
            while (rk + 1 < n && !occ.contains(s.charAt(rk + 1))) { // 如果集合中不存在最新的字符，就把它加入集合，并右移右指针
                occ.add(s.charAt(rk + 1));
                ++rk;
            }
            // rk - i + 1 即为字串的长度，使用max函数来判断前后两个字串长度哪个更大
            ans = Math.max(ans, rk - i + 1);
        }
        return ans;
    }


}
