/**
 *  Author: yurzhang
 *  Date: 2022/06/18
 *    以小根堆为例
 */
#include <stdio.h>

#define N 105          // 堆中元素数量上限
#define INF 1073741823 // 代表无穷大，搞一个比较大但是别溢出的数就行

int heap[N << 1]; // 堆
int val[N];       // 堆中元素的值
int tot;          // 堆中当前元素数量

void init() { // 初始化堆，需要在使用堆前执行
  val[0] = INF;
}

void update(int pos, int value) { // 辅助函数
  int now = N + pos;
  heap[now] = value;
  while (now != 1) {
    if (val[heap[now]] < val[heap[now ^ 1]])
      heap[now >> 1] = heap[now];
    else heap[now >> 1] = heap[now ^ 1];
    now >>= 1;
  }
}

void insert(int value) { // 往堆中插入元素
  val[++ tot] = value;
  update(tot, tot);
}

void pop() { // 弹出堆顶元素
  update(heap[1], 0);
}

int top() { // 取堆顶（小根堆即为最小值）
  return val[heap[1]];
}

int main() {
  init();

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x;
    scanf("%d", &x);
    insert(x);
  }
  pop();
  pop();
  printf("%d\n", top());
  return 0;
}