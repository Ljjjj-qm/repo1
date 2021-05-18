package com.li;

/**
 * @program: leetcode
 * @description: 两数相加
 * 给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0开头。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/add-two-numbers
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @author: ZhangQingMin
 * @create: 2021-05-08 10:08
 **/
public class AddTwoNumbers {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode head = null, tail = null;
        int carry = 0;

        while (l1 != null || l2 != null) {
            int n1 = l1 != null ? l1.val : 0;
            int n2 = l2 != null ? l2.val : 0;
            int sum = n1 + n2 + carry;
            if (head == null) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
            }
            // int 类型相除得到的数也是 int 类型，不会保留任何小数
            carry = sum / 10;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        if (carry > 0) {
            tail.next = new ListNode(carry);
        }

        return head;
    }

    public ListNode addTwoNumbers2(ListNode l1, ListNode l2) {

        ListNode head = new ListNode(-1); // 存放结果的链表头指针，不存放有效数据
        ListNode tail = head; // 移动指针，指向链表中的最后一个有效元素
        int sum = 0; // 存放每个位相加的和
        boolean carry = false; // 进位标志

        while (l1 != null || l2 != null) {

            sum = 0;

            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            if (carry) {
                sum++;
            }
            tail.next = new ListNode(sum % 10);
            tail = tail.next;
            carry = sum >= 10 ? true : false;

        }
        if (carry) {
            tail.next = new ListNode(1);
        }
        return head.next;
    }
}

class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
