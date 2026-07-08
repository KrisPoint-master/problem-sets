# P9974 [USACO23DEC] Candy Cane Feast B 笔记

## 题意简述

N 头奶牛（初始高度 $h_i$），M 根糖果棒（长度 $L_j$）。按顺序处理每根糖果棒：

- 所有奶牛按 $1 \dots N$ 顺序轮流吃
- 糖果棒悬挂在空中，底部初始为 0，吃掉的部**不会下沉**
- 奶牛 $i$ 当前高度 $h_i$，只能吃到 $[0, h_i]$ 区间内的部分
- 设当前已吃掉的最低位置为 $last$，若 $h_i \le last$ 则吃不到
- 否则吃掉 $\min(h_i, L_j) - last$，身高增加相同数值，$last$ 更新为 $\min(h_i, L_j)$

输出每头奶牛的最终高度。

## 暴力模拟的坑

### 1. 类型溢出

$h_i, L_j \le 10^9$，$N, M \le 2 \times 10^5$，最终高度可达 $2 \times 10^{14}$，必须用 `long long`。

### 2. if 分支未重置剩余长度

```cpp
// ❌ 错误：奶牛吃掉全部剩余后，now_candy_long 未置零
if (sub > now_candy_long) {
    last_prev = now_candy_long;
    height[i] += now_candy_long;
    // 缺少 now_candy_long = 0;
}

// ✅ 正确
if (sub > now_candy_long) {
    height[i] += now_candy_long;
    now_candy_long = 0;
    continue;
}
```

否则后续奶牛仍能看到 `now_candy_long > 0`，继续从 else 分支吃到"幻影糖果"。

## 剪枝 / 优化

### 核心观察

每根糖果棒的处理中，$last$ 从 0 开始，**严格单调递增**（只涨不跌）。一旦 $last \ge L_j$（或等价地 `now_candy_long == 0`），后续奶牛不可能再吃到任何东西，应**立即跳出**。

```cpp
for (int i = 1; i <= n; i++) {
    if (now_candy_long == 0) break;  // 糖果已空，后面的奶牛不用看了
    // ... 正常处理
}
```

### 为什么暴力加这个剪枝就能过？

关键：**第一头奶牛的指数增长**。

- 第一头奶牛总是 $last = 0$ 开始吃，吃掉 $\min(h_1, L_j) = h_1$（若 $h_1 < L_j$），身高**翻倍**
- 后续每次它作为第一个吃糖者，身高都会翻倍
- 初始 $h_1 \ge 1$，最多 $\log_2(10^9) \approx 30$ 轮后 $h_1 \ge 10^9$，任何糖果棒都能一口吃完
- 因此只有前 $\sim 30$ 根糖果棒需要遍历多只奶牛，此后每根只处理第一头就结束

其他奶牛同理：一旦被前面的"记录奶牛"超过，就会永远被跳过。

### 复杂度

- 每头奶牛有效吃糖次数 $O(\log V)$，$V = 10^9$
- 总吃糖事件数 $O(N \log V + M)$
- $N, M = 2 \times 10^5$ 时完全可过

### 其他小优化

- 去掉 `eat()` 里无用的 `new long long[max_n]` 分配（每次调用 O(N) 分配 + 释放，纯浪费）
- 用 `'\n'` 而非 `' '` 分隔输出（已做）
