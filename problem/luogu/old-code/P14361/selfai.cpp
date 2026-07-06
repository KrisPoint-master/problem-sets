#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
typedef pair<int, int> P; // {满意度, 部门编号}

struct cluber
{
    int a, b, c;
    P first, second, third;
    int nowuse; // 1:第一志愿, 2:第二志愿, 3:第三志愿

    cluber()
    {
        a = b = c = 0;
        nowuse = 1;
        first = second = third = {0, 0};
    }

    void sortabc()
    {
        vector<P> t;
        t.push_back({a, 1});
        t.push_back({b, 2});
        t.push_back({c, 3});
        // 满意度从大到小排
        sort(t.begin(), t.end(), [](P x, P y)
             { return x.first > y.first; });
        first = t[0];
        second = t[1];
        third = t[2];
        nowuse = 1;
    }
} a[maxn];

int T, n;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].sortabc();
    }
}

void sovle()
{
    vector<cluber> club[4]; // 用数组存 1,2,3 部门，方便处理

    // 获取当前正在使用的满意度P
    auto get_now_use_cluber_to_club_uid = [](cluber ce) -> P
    {
        if (ce.nowuse == 1)
            return ce.first;
        if (ce.nowuse == 2)
            return ce.second;
        return ce.third;
    };

    // 比较函数：用于踢出“损失最小”的人
    // 损失定义 = 当前满意度 - 下一志愿满意度
    auto cmp_loss = [&](cluber x, cluber y) -> bool
    {
        P curX = get_now_use_cluber_to_club_uid(x);
        P nextX = (x.nowuse == 1) ? x.second : x.third;
        int lossX = curX.first - nextX.first;

        P curY = get_now_use_cluber_to_club_uid(y);
        P nextY = (y.nowuse == 1) ? y.second : y.third;
        int lossY = curY.first - nextY.first;

        return lossX > lossY; // 损失小的排在后面，方便 pop_back
    };

    // 初始：所有人进第一志愿
    for (int i = 1; i <= n; i++)
    {
        club[a[i].first.second].push_back(a[i]);
    }

    int limit = n / 2;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i <= 3; i++)
        {
            if (club[i].size() > limit)
            {
                changed = true;
                // 按损失从大到小排，踢掉损失最小的人（末尾）
                sort(club[i].begin(), club[i].end(), cmp_loss);

                while (club[i].size() > limit)
                {
                    cluber seeker = club[i].back();
                    club[i].pop_back();

                    // 转向下一志愿
                    if (seeker.nowuse < 3)
                    {
                        seeker.nowuse++;
                        P next = get_now_use_cluber_to_club_uid(seeker);
                        club[next.second].push_back(seeker);
                    }
                }
            }
        }
    }

    long long total = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (auto &c : club[i])
        {
            total += get_now_use_cluber_to_club_uid(c).first;
        }
    }
    cout << total << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        input();
        sovle();
    }
    return 0;
}