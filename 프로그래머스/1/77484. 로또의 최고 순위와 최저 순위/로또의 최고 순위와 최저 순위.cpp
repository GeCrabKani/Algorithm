#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    const int max_rank = 6;
    int zero_count = count(lottos.begin(), lottos.end(), 0);
    vector<int> matches;

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    set_intersection(lottos.begin(), lottos.end(),
        win_nums.begin(), win_nums.end(),
        back_inserter(matches));

    int best = matches.size() + zero_count == 0 ? 1 : matches.size() + zero_count;
    int worst = matches.size() == 0 ? 1 : matches.size();
    
    answer.push_back(max_rank - best + 1);
    answer.push_back(max_rank - worst + 1);

    return answer;
}