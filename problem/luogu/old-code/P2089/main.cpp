#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;cin >> n;
    int count = 0;  
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3;j++){
            for(int k = 1; k <= 3;k++){
                for(int l = 1; l <= 3;l++){
                    for(int m = 1; m <= 3;m++){
                        for(int b = 1; b <= 3;b++){
                            for(int c = 1; c <= 3;c++){
                                for(int d = 1; d <= 3;d++){
                                    for(int e = 1; e <= 3;e++){
                                        for(int f = 1; f <= 3;f++){
                                            if(i+j+k+l+m+b+c+d+e+f == n){
                                                count ++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } 
                }
            }
        }
    }
    cout << count << endl;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3;j++){
            for(int k = 1; k <= 3;k++){
                for(int l = 1; l <= 3;l++){
                    for(int m = 1; m <= 3;m++){
                        for(int b = 1; b <= 3;b++){
                            for(int c = 1; c <= 3;c++){
                                for(int d = 1; d <= 3;d++){
                                    for(int e = 1; e <= 3;e++){
                                        for(int f = 1; f <= 3;f++){
                                            if(i+j+k+l+m+b+c+d+e+f == n){
                                                cout << i << " " <<
                                                j << " " << 
                                                k << " " << 
                                                l << " " <<
                                                m << " " <<
                                                b << " " <<
                                                c << " " <<
                                                d << " " <<
                                                e << " " <<
                                                f << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } 
                }
            }
        }
    }
    return 0;
}
