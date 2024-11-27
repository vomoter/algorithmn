/*
 * @Author: YiFu
 * @Date: 2024-09-15 21:49:01
 * @LastEditors: YiFu
 * @LastEditTime: 2024-09-15 21:49:20
 * @FilePath: \Graph\link.cpp
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* intersection(ListNode* head1, ListNode* head2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val < head2->val) {
            head1 = head1->next;
        } else if (head1->val > head2->val) {
            head2 = head2->next;
        } else { // 找到相同元素
            // 创建一个新节点并添加到交集中
            tail->next = new ListNode(head1->val);
            tail = tail->next;

            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return dummy.next; // 返回交集链表的头节点
}

// 辅助函数，用于插入节点到链表
void insert(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

// 辅助函数，用于打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list1 = nullptr;
    insert(list1, 4);
    insert(list1, 2);
    insert(list1, 1);

    ListNode* list2 = nullptr;
    insert(list2, 5);
    insert(list2, 4);
    insert(list2, 2);
    
    // 假设已经排序的链表，实际使用中需要先对链表排序
    ListNode* result = intersection(list1, list2);
    
    std::cout << "Intersection: " << std::endl;
    printList(result);

    // 释放内存（如果有需要）
    system("pause");
    return 0;
}
