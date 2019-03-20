#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct stFAIL{
    int idx;
    double failpercent;
}stFAIL;

bool prior(stFAIL a, stFAIL b){
    if(a.failpercent == b.failpercent){
        return a.idx < b.idx;
    }
    return a.failpercent > b.failpercent;
}

vector<int> solution(int N, vector<int> stages) {
    vector<stFAIL> v;  
    int st[502] = {0, };
    vector<int> answer;
    double sucess = (double) stages.size();

    for(int i = 0; i < stages.size(); i++){
        st[stages[i]]++;
    }

    for(int i = 1; i <= N; i++){
        double fail = (double) st[i]; // i 스테이지 클리어하지 못한 플레이어

        double percent_fail = fail / sucess;
        stFAIL tmp;
        tmp.idx = i;
        tmp.failpercent = percent_fail;
        v.push_back(tmp);
        if(sucess - fail > 0)
            sucess -= fail;  

    }

    sort(v.begin(), v.end(), prior);

    for(int i = 0; i < v.size(); i++){
        //printf("%d %lf %d\n", v[i].idx, v[i].failpercent, st[i+1]);
        answer.push_back(v[i].idx);
    }

    return answer;
}
