#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0;
    int p = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (deliveries[i] != 0 || pickups[i] != 0) {
            int cnt = 0;
            while (d < deliveries[i] || p < pickups[i]) {
                cnt++;
                d += cap;
                p += cap;
            }
            d -= deliveries[i];
            p -= pickups[i];
            answer += (long long)((i + 1) * cnt * 2);
        }
    }

    return answer;
}

int main() {
    long long result = 0;
    int cap = 4;
    int n = 5;
    vector<int> deliveries = { 1, 0, 3, 1, 2 };
    vector<int> pickups = { 0, 3, 0, 4, 0 };

    result = solution(cap, n, deliveries, pickups);

    return 0;
}
