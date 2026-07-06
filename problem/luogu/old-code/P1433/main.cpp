#include<bits/stdc++.h>
using namespace std;
const int N = 16;  
int n;             
double res = 1000000.0;   
double dis[N][N];

struct point {
    double x, y;
} a[N];

int per[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

double calc_dis(double x1,double y1,double x2,double y2){
    return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 - y2)));
}

int main() {
    a[0].x = 0, a[0].y = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            double x1 = a[i].x, y1 = a[i].y, x2 = a[j].x, y2 = a[j].y;
            dis[j][i] = dis[i][j] = calc_dis(x1,y1,x2,y2);
        }

    double MIN = 100000;
    do {
        double s = dis[0][per[0]];
        for (int i = 0; i < n - 1; i++) s += dis[per[i]][per[i + 1]];
        MIN = min(MIN, s);
    } while (next_permutation(per, per + n)); // C++ STL 排列

    cout << fixed << setprecision(2) << MIN << endl;
    return 0;
}
