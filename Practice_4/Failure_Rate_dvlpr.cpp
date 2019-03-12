
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define SIZE 1000

using namespace std;

typedef struct node
{
	double r;
	int n;
	node(int n, double r):n(n), r(r){}
}node;

int arrive[SIZE];
int fail[SIZE];

void init(void)
{
    memset(arrive, 0, sizeof(arrive));
    memset(fail, 0, sizeof(fail));
}

void setArriveFail(vector<int> &stages, int n)
{
	int len = stages.size();
	for(int i=0; i<len; i++){
		int cur = stages[i];
		for(int j=1; j<=cur; j++){
			arrive[j]++;
		}
		fail[cur]++;
	}
}

void setRate(int n, vector<node> &rate)
{
	for(int i=1; i<=n; i++){
        if(arrive[i] == 0){
            rate.push_back(node(i, 0));
            continue;
        }
		rate.push_back(node(i, (double)fail[i]/(double)arrive[i]));
	}
}

bool compare(const node &n1, const node &n2)
{
    if(n1.r == n2.r){
        return (n1.n < n2.n);
    }
	return (n1.r > n2.r);
}

void sorting(vector<node> &rate)
{
	sort(rate.begin(), rate.end(), compare);
}

void print(vector<node> &rate, vector<int> &answer)
{
	int len = rate.size();
	for(int i=0; i<len; i++){
		answer.push_back(rate[i].n);
	}
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    init();
	setArriveFail(stages, N);
	vector<node> rate;
	setRate(N, rate);
	sorting(rate);
	print(rate, answer);
    return answer;
}

