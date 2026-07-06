#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
typedef pair<int, int> P;
struct cluber
{
    int a, b, c;
    P first, second, third;
    int nowuse;
    explicit cluber()
    {
        a = b = c = 0;
        nowuse = 1;
        first = second = third = make_pair(0, 0);
    }
    void sortabc();
} a[maxn];
int T;
int n;

void input();
void sovle();

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        input();
        sovle();
    }
    return 0;
}

void cluber::sortabc()
{
    vector<P> t;
    t.push_back(make_pair(a, 1)); // lover         cluber_uid
    t.push_back(make_pair(b, 2));
    t.push_back(make_pair(c, 3));
    auto cmp = [](P a, P b) -> bool
    {
        return a.first > b.first;
    };
    sort(t.begin(), t.end(), cmp);
    first = t[0], second = t[1], third = t[2];
    nowuse = first.second;
    // 1 : first
    // 2 : second
    // 3 : third
}

void input()
{
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].sortabc();
    }
}

void sovle()
{
    vector<cluber> club1;
    vector<cluber> club2;
    vector<cluber> club3;

    auto get_now_use_cluber_to_club_uid = [](cluber ce) -> P
    {
        switch (ce.nowuse)
        {
        case 1:
            return ce.first;
        case 2:
            return ce.second;
        case 3:
            return ce.third;
        default:
            return make_pair(-1, -1); // inf
        }
    };

    auto set_now_use = [](cluber &ce, int id) -> void
    {
        ce.nowuse = id;
    };

    auto get_now_use_cluber_to_next_club_uid = [set_now_use](cluber &ce) -> P
    {
        if (ce.nowuse == 1)
        {
            set_now_use(ce, 2);
            // second
            return ce.second;
        }
        if (ce.nowuse == 2)
        {
            set_now_use(ce, 3);
            return ce.third;
        }
        if (ce.nowuse == 3)
        {
            // dont move
            return ce.third;
        }
    };

    auto add_to_club = [&club1, &club2, &club3](cluber ce) -> void
    {
        switch (ce.first.second)
        {
        case 1:
            club1.push_back(ce);
            break;
        case 2:
            club2.push_back(ce);
            break;
        case 3:
            club3.push_back(ce);
            break;
        default:
            break;
        }
    };

    auto cmp_max_cluber_lover = [get_now_use_cluber_to_club_uid](cluber a, cluber b) -> bool
    {
        auto uida = get_now_use_cluber_to_club_uid(a);
        auto uidb = get_now_use_cluber_to_club_uid(b);
        // uid : {loverSUM,cluber_uid}
        if (uida.second != uidb.second)
            return 0;
        return (uida.first > uidb.first);
        // array[1] is max cluber;
    };

    auto cmp_min_cluber_lover = [get_now_use_cluber_to_club_uid](cluber a, cluber b) -> bool
    {
        auto uida = get_now_use_cluber_to_club_uid(a);
        auto uidb = get_now_use_cluber_to_club_uid(b);
        // uid : {loverSUM,cluber_uid}
        if (uida.second != uidb.second)
            return 0;
        return (uida.first < uidb.first);
        // array[1] is min cluber;
    };
    auto get_min_cluber_lover = [cmp_min_cluber_lover](vector<cluber> ce) -> cluber
    {
        sort(ce.begin(), ce.end(), cmp_min_cluber_lover);
        return ce[0];
    };

    auto move_to_other_club = [get_now_use_cluber_to_club_uid, &club1, &club2, &club3, cmp_max_cluber_lover, cmp_min_cluber_lover](cluber ce, int id)
    {
        /*
         * @arg move ce to club + $id   (ce is min)
         */
        // 我真是愈来愈喜欢用lba了
        auto clubuidP = get_now_use_cluber_to_club_uid(ce);
        // P      lover,cluber_uid
        int nowcluberuid = clubuidP.second;
        if (nowcluberuid == 1)
        {
            sort(club1.begin(), club1.end(), cmp_max_cluber_lover);
            club1.pop_back();
            sort(club1.begin(), club1.end(), cmp_min_cluber_lover);
        }
        if (nowcluberuid == 2)
        {
            sort(club2.begin(), club2.end(), cmp_max_cluber_lover);
            club2.pop_back();
            sort(club2.begin(), club2.end(), cmp_min_cluber_lover);
        }
        if (nowcluberuid == 3)
        {
            sort(club3.begin(), club3.end(), cmp_max_cluber_lover);
            club3.pop_back();
            sort(club3.begin(), club3.end(), cmp_min_cluber_lover);
        }
        if (id == 1)
        {
            club1.push_back(ce);
        }
        if (id == 2)
        {
            club2.push_back(ce);
        }
        if (id == 3)
        {
            club3.push_back(ce);
        }
    };

    for (int i = 1; i <= n; i++)
    {
        add_to_club(a[i]);
    }

    int t1_s = club1.size();
    int t2_s = club2.size();
    int t3_s = club3.size();
    int cluber_limit = n / 2; // n can div 2

    sort(club1.begin(), club1.end(), cmp_min_cluber_lover); // todo 2 3
    sort(club2.begin(), club2.end(), cmp_min_cluber_lover);
    sort(club3.begin(), club3.end(), cmp_min_cluber_lover);
    while (t1_s > cluber_limit || t2_s > cluber_limit || t3_s > cluber_limit)
    {
        if (t1_s > cluber_limit)
        {
            auto min_lover_cluber = get_min_cluber_lover(club1);
            auto min_lover_goto_club = get_now_use_cluber_to_next_club_uid(min_lover_cluber);
            auto min_lover_cluber_uid = get_now_use_cluber_to_club_uid(min_lover_cluber);
            move_to_other_club(min_lover_cluber, min_lover_goto_club.second);
        }
        if (t2_s > cluber_limit)
        {
            auto min_lover_cluber = get_min_cluber_lover(club2);
            auto min_lover_goto_club = get_now_use_cluber_to_next_club_uid(min_lover_cluber);
            auto min_lover_cluber_uid = get_now_use_cluber_to_club_uid(min_lover_cluber);
            move_to_other_club(min_lover_cluber, min_lover_goto_club.second);
        }
        if (t3_s > cluber_limit)
        {
            auto min_lover_cluber = get_min_cluber_lover(club3);
            auto min_lover_goto_club = get_now_use_cluber_to_next_club_uid(min_lover_cluber);
            auto min_lover_cluber_uid = get_now_use_cluber_to_club_uid(min_lover_cluber);
            move_to_other_club(min_lover_cluber, min_lover_goto_club.second);
        }
    }
    long long sum = 0;
    for (auto iter : club1)
    {
        auto lover_cluber_inst = get_now_use_cluber_to_club_uid(iter);
        sum += lover_cluber_inst.first;
    }
    for (auto iter : club2)
    {
        auto lover_cluber_inst = get_now_use_cluber_to_club_uid(iter);
        sum += lover_cluber_inst.first;
    }
    for (auto iter : club3)
    {
        auto lover_cluber_inst = get_now_use_cluber_to_club_uid(iter);
        sum += lover_cluber_inst.first;
    }
    cout << sum << endl;
    return;
}
