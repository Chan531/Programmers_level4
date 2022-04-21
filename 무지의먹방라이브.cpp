#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int solution(vector<int> food_times, long long k) {

    long long all_minus = 0;                           // 음식을 먹어가면서 감소된 시간

    priority_queue<p, vector<p>, greater<p>> pq;       // food_times, index

    for (int i = 0; i < food_times.size(); i++)
        pq.push({ food_times[i], i + 1 });

    while (!pq.empty())
    {
        long long cft = pq.top().first - all_minus;    // 가장 적은 음식 섭취 시간
        int idx = pq.top().second;

        if (cft <= 0)
        {
            pq.pop();
            continue;
        }

        long long minustime = cft * pq.size();        // 감소해야하는 시간

        if (k >= minustime)                           // 더 돌 수 있다는 뜻이므로 pass
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