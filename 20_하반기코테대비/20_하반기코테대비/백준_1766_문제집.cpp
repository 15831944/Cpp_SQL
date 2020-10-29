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
 
    // 0�� indegree �� ���� �켱���� ť�� �ִ´�. 
    for (int i = 1; i <= N; i++) 
        if (!indegree[i]) pq.push(i);
 
    // �켱���� ť�� �̿��Ͽ� ���� ����� ��ȣ�� �տ� �ִ� ��Ҹ� �����´�. 
    // ���� ������ ���� �߿����� ��ȣ�� ���� ���� ������ ���� Ǯ��� �Ǳ� �����̴�. 
    while (!pq.empty()) {
        int now_ = pq.top();
        pq.pop();
        printf("%d ", now_);
        for (auto next : node_vec[now_])
            // ������ ��忡 ����� ������ ���������� indegree�� 
            // ���ҽ��Ѽ� 0�̸� �켱���� ť�� ���� �־��ش�. 
            if (--indegree[next] == 0)
                pq.push(next);
    }
 
    return 0;
}
