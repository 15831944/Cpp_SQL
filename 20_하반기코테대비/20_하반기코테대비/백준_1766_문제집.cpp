#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
const int MXN = 32e3;
 
int main() {
    int N, M, indegree[MXN + 1] = { 0 };
    vector<int> node_vec[MXN + 1];
    priority_queue<int, vector<int>, greater<int> > pq;
 
    // init
    scanf("%d%d", &N, &M);
    for (int m_idx = 0 ; m_idx < M; m_idx++) {
        int from_, to_;
        scanf("%d%d", &from_, &to_);
        node_vec[from_].push_back(to_);
        indegree[to_]++;
    }
 
    // 0인 indegree 를 먼저 우선순위 큐에 넣는다. 
    for (int i = 1; i <= N; i++) 
        if (!indegree[i]) pq.push(i);
 
    // 우선순위 큐를 이용하여 가장 노드의 번호가 앞에 있는 요소를 가져온다. 
    // 현재 가능한 노드들 중에서는 번호가 가장 적은 문제를 먼저 풀어야 되기 때문이다. 
    while (!pq.empty()) {
        int now_ = pq.top();
        pq.pop();
        printf("%d ", now_);
        for (auto next : node_vec[now_])
            // 현재의 노드에 연결된 에지의 도착지들의 indegree를 
            // 감소시켜서 0이면 우선순위 큐에 집어 넣어준다. 
            if (--indegree[next] == 0)
                pq.push(next);
    }
 
    return 0;
}
