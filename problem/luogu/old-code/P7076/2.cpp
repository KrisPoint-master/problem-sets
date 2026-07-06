#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef unsigned long long ull; // 处理k<=64的情况，用ull存储位信息

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, k;
    cin >> n >> m >> c >> k;

    // 1. 存储当前饲养的动物（去重，题目已保证a_i互不相同）
    unordered_set<ull> existing_animals;
    for (int i = 0; i < n; ++i)
    {
        ull a;
        cin >> a;
        existing_animals.insert(a);
    }

    // 2. 记录每个bit p对应的饲料q（p->q映射）
    vector<int> bit_to_feed(k, -1); // bit_to_feed[p] = q，-1表示无对应饲料
    for (int i = 0; i < m; ++i)
    {
        int p, q;
        cin >> p >> q;
        bit_to_feed[p] = q; // 题目保证q互不相同，无需处理冲突
    }

    // 3. 计算当前已使用的bit（existing_animals中所有动物的置位）
    vector<bool> used_bits(k, false);
    for (ull a : existing_animals)
    {
        for (int p = 0; p < k; ++p)
        {
            if (a & (1ULL << p))
            { // 检查第p位是否为1
                used_bits[p] = true;
            }
        }
    }

    // 4. 计算当前需要购买的饲料（required_feeds）
    unordered_set<int> required_feeds;
    for (int p = 0; p < k; ++p)
    {
        if (used_bits[p] && bit_to_feed[p] != -1)
        { // 该bit被使用且有对应饲料
            required_feeds.insert(bit_to_feed[p]);
        }
    }

    // 5. 暴力遍历所有可能的动物x（0~2^k-1），统计可新增的数量
    ull total_possible = (1ULL << k);             // 总动物数：2^k
    ull existing_count = existing_animals.size(); // 当前饲养数
    ull ans = 0;

    for (ull x = 0; x < total_possible; ++x)
    {
        // 跳过已饲养的动物
        if (existing_animals.count(x))
        {
            continue;
        }

        // 检查x的所有置位p对应的饲料是否都在required_feeds中
        bool can_add = true;
        for (int p = 0; p < k; ++p)
        {
            if (x & (1ULL << p))
            { // x的第p位为1
                int q = bit_to_feed[p];
                if (q != -1 && !required_feeds.count(q))
                { // 该bit有对应饲料且未被要求
                    can_add = false;
                    break;
                }
            }
        }

        if (can_add)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}