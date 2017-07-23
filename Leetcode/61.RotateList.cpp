#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *initList() {
  int n; // 多少项
  printf("输入共多少个节点：");
  scanf("%d", &n);
  struct ListNode *headNode, *currentNode, *preNode;
  headNode = NULL;
  int eachData; // 输入data值
  for (int i = 1; i <= n; ++i) {
    printf("输入第%d个节点的值：", i);
    scanf("%d", &eachData);
    currentNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    currentNode->val = eachData;
    currentNode->next = NULL;
    if (headNode == NULL) {
      // 第一次把head指向第一个节点
      headNode = currentNode;
    } else {
      // 第2~n次，把上一个节点的next指针指向当前节点
      preNode->next = currentNode;
    }
    // 保存当前节点上下文，下一次使用
    preNode = currentNode;
  }
  return headNode;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (head == NULL) {
    return NULL;
  }
  if (k == 0) {
    return head;
  }
  struct ListNode** p = &head, *q = head, *a;
  a = (struct ListNode *)malloc(sizeof(struct ListNode));
  for (int i = 0; i < k; i++) {
    q = q->next;
    if (q == NULL) {
      k = k % (i + 1);
      i = -1;
      q = *p;
    }
  }
  if (q == *p) {
    return *p;
  }
  while (q->next != NULL) {
    p = &((*p)->next);
    q = q->next;
  }
  a = (*p)->next;
  q->next = head;
  (*p)->next = NULL;
  return a;
}

void printList(struct ListNode *headNode) {
  struct ListNode *currentNode = headNode;
  printf("链表内容为：");
  while (currentNode != NULL) {
    printf("->%d", currentNode->val);
    currentNode = currentNode->next;
  }
  printf("\n");
}

int main() {
  struct ListNode *headNode;
  // 初始化链表
  printf("初始化链表1\n");
  headNode = initList();
  printList(headNode);
  printList(rotateRight(headNode, 200));
  return 0;
}