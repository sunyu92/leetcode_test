/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
  queue<int> inQueue;     // 输入队列
  queue<int> outQueue;    // 输出队列
  /** 初始化数据结构 */
  MyStack() {
  }
  /** 把值推入栈 */
  void push(int x) {
    inQueue.push(x);            // 将一个值推进输入队列
    while(!outQueue.empty()){   // 把输出队列中的给输入队列
      inQueue.push(outQueue.front());
      outQueue.pop();
    }
    queue<int> tmp = inQueue;   // 再把输入队列的还给输出队列
    inQueue = outQueue;
    outQueue = tmp;
    // while(!inQueue.empty()){   // 再把输入队列的还给输出队列
    //   outQueue.push(inQueue.front());
    //   inQueue.pop();
    // }
  }
  /** 移除栈顶元素 */
  int pop() {
    if(outQueue.empty()){   // 输出队列为空，return 0
      return 0;
    }
    int a = outQueue.front();   // 获取顶部
    outQueue.pop();             // 输出队列推出
    return a;
  }
  /** 获取栈顶元素 */
  int top() {
    if(outQueue.empty()){   //输出队列为空，return 0
      return 0;
    }
    return outQueue.front();    // 获取输出队列顶部
  }
  /** 查看队列是否为空 */
  bool empty() {
    return outQueue.empty();    // 判断输入队列是否为空
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

