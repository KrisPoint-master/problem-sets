#include <bits/stdc++.h>
using namespace std;

long long dword_6103 = 0x0BEADDEEF;

char cipher[1000005];

int main(int argc, const char **argv, const char **envp)
{

    int i;     // [rsp+8h] [rbp-38h]
    time_t v5; // [rsp+10h] [rbp-30h]
    time_t v6; // [rsp+20h] [rbp-20h]
    time_t v7; // [rsp+28h] [rbp-18h]

    v6 = time(0LL);
    v5 = v6;
    v7 = time(0LL);
    for (i = 0; i < 2592000; ++i)
    {
        v7++;
        if (v7 != v5 + 1)
            exit(2);
        srand(v7 + dword_6103 - v6);
        cipher[i % 128] ^= rand();
        cipher[i % 17] ^= rand();
        v5 = v7;
    }
    // puts(cipher);
    for (int i = 0; i < strlen(cipher); i++)
    {
        cout << (int)cipher[i] << ",";
    }

    return 0;
}