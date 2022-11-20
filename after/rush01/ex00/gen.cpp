#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end() 

int	my_factorial(int nb){
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * my_factorial(nb - 1));
}

int main(int argc, char **argv){
    int n = atoi(argv[1]);
    if (n < 2 || n > 5)
        return 1;
    int factn = my_factorial(n);
    vector<int> p(n);
    iota(all(p), 1);
    vector<vector<int>> perm(factn, vector<int>(n));
    int i = 0;
    do{
        for(int j = 0; j < n; j++){
            perm[i][j] = p[j];
        }
        i++;
    } while (next_permutation(all(p)));
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<vector<int>>> ans;
    vector<int> dfscursor(factn+1);
    auto check_before_height = [&](int per, int depth) -> int {
        for(int j = 0; j < n; j++){
            for(int i = 0; i < depth; i++){
                if (grid[i][j] == perm[per][j])
				    return 0;
            }
        }
        return 1;
    };
    auto array_decide = [&](int per, int depth) -> int {
        if (!check_before_height(per, depth))
		    return 0;
        for(int j = 0; j < n; j++){
            grid[depth][j] = perm[per][j];
        }
        return 1;
    };
    auto dfs = [&](auto f, int depth) -> void {
        if (depth == n){
		    ans.push_back(grid);
            return;
        }
        int i = 0;
        for(int i = 0; i < factn; i++){
            if (array_decide(i, depth)){
                dfscursor[depth + 1] = i;
                f(f, depth + 1);
            }
        }
        return ;
    };
    dfs(dfs, 0);
    string s1 = "./rush-01 ";
    string s2;
    srand((unsigned) time(NULL));
    vector<int> rule(n * 4);
    FILE *test;
    test = fopen("test.sh", "w");
    auto colup_decide = [&](){
        for(int j = 0; j < n; j++){
            int old = 0;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if (old < grid[i][j]){
                    old = grid[i][j];
                    cnt++;
                }
            }
            rule[j] = cnt;
        }
    };
    auto coldown_decide = [&](){
        for(int j = 0; j < n; j++){
            int old = 0;
            int cnt = 0;
            for(int i = n - 1; i >= 0; i--){
                if (old < grid[i][j]){
                    old = grid[i][j];
                    cnt++;
                }
            }
            rule[j + n] = cnt;
        }
    };
    auto rowleft_decide = [&](){
        for(int i = 0; i < n; i++){
            int old = 0;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if (old < grid[i][j]){
                    old = grid[i][j];
                    cnt++;
                }
            }
            rule[i + 2 * n] = cnt;
        }
    };
    auto rowright_decide = [&](){
        for(int i = 0; i < n; i++){
            int old = 0;
            int cnt = 0;
            for(int j = n - 1; j >= 0; j--){
                if (old < grid[i][j]){
                    old = grid[i][j];
                    cnt++;
                }
            }
            rule[i + 3 * n] = cnt;
        }
    };
    auto str = [&](){
        colup_decide();
        coldown_decide();
        rowleft_decide();
        rowright_decide();
        s2 = '\"';
        for(int j = 0; j < 4 * n; j++){
            s2.push_back(rule[j] + '0');
            if (j == 4 * n - 1)
                s2.push_back('\"');
            else
                s2.push_back(' ');
        }
    };
    grid = ans[rand() % ans.size()];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", grid[i][j], (j != n -1) ? ' ' : '\n');
        }
    }
    str();
    fprintf(test ,"%s%s\n", s1.c_str(), s2.c_str());
    fclose(test);
    return 0;
}
