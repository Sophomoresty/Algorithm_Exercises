#include <unordered_set>
using namespace std;
class Solution {
public:
    int get_sum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> res_set;
        int sum;
        while (true) {
            sum = get_sum(n);
            if (sum == 1) {
                return true;
            }
            if (res_set.find(sum) != res_set.end()) {
                return false;
            } else {
                res_set.insert(sum);
            }
            n = sum;
        }
    }
    // 快慢指针法
};