#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    int n = atoi(argv[1]);
    if (n < 2 || n > 5)
        return 1;
    int len = 4 * n - 1;
    string s1 = "./rush-01 ";
    string s2;
    srand((unsigned) time(NULL));
    FILE *test;
    test = fopen("test.sh", "w");
    vector<char> test1;
    for(int i = 32; i < 127; i++){
        if (i >= 48 && i <= 57)
            continue;
        if (i == 34 || i == 39 || i == 96)
            continue;
        test1.push_back(i);
    }
    vector<char> test2;
    for(int i = 33; i < 127; i++){
        if (i == 34 || i == 39 || i == 96)
            continue;
        test2.push_back(i);
    }
    auto str = [&](int rnd){
        s2 = '\"';
        if (rnd < 3){
            for(int j = 0; j < 8 * n - 1; j++){
                if (j % 2 == 0){
                    if (rnd == 0)
                        s2.push_back((rand()%9) + '0');
                    else if (rnd == 1)
                        s2.push_back(test1[rand()%test1.size()]);
                    else
                        s2.push_back((rand()%n+1) + '0');
                }
                else{
                    if (rnd != 2)
                        s2.push_back(' ');
                    else
                        s2.push_back(test2[rand()%test2.size()]);
                }
            }
        }else {
            int mx;
            while(1){
                mx = rand() % 41;
                if (mx != 8 * n - 1)
                    break;
            }
            for(int j = 0; j < mx; j++){
                if (j % 2 == 0)
                    s2.push_back((rand()%n+1) + '0');
                else
                    s2.push_back(' ');
            }
        }
        s2.push_back('\"');
    };
    for(int k = 0; k < 4; k++){
        str(k);
        fprintf(test ,"%s%s\n", s1.c_str(), s2.c_str());
    }
    fclose(test);
    return 0;
}
