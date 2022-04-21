#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int solution(vector<int> food_times, long long k) {

    long long all_minus = 0;                           // ������ �Ծ�鼭 ���ҵ� �ð�

    priority_queue<p, vector<p>, greater<p>> pq;       // food_times, index

    for (int i = 0; i < food_times.size(); i++)
        pq.push({ food_times[i], i + 1 });

    while (!pq.empty())
    {
        long long cft = pq.top().first - all_minus;    // ���� ���� ���� ���� �ð�
        int idx = pq.top().second;

        if (cft <= 0)
        {
            pq.pop();
            continue;
        }

        long long minustime = cft * pq.size();        // �����ؾ��ϴ� �ð�

        if (k >= minustime)                           // �� �� �� �ִٴ� ���̹Ƿ� pass
        {
            k -= minustime;
            all_minus += cft;
            pq.pop();
            continue;
        }

        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans[k % ans.size()];
    }

    return -1;
}