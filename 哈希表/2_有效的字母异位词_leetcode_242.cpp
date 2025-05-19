#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // 暴力解法
    // 遍历s,t两个数组, 对s中每一个字符, 在t中找到对应的字符, 为了防止重复匹配到已匹配的字符, 需要对匹配的字符进行换值,
    // 因此t需要备份
    bool baoli_isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                // 如果相等的话
                if (s[i] == t[j]) {
                    index++;
                }
            }
        }
        if (index == s.length()) {
            return true;
        } else {
            return false;
        }
    }
    // 只处理小写字母, 而不是unicode编码, 小写字母的ascii码有26个,
    // 所以只需要长度为26的数组, 遍历s,t将每个字符映射到数组的索引, 然后++
    // 如果数组中的值均为2, 则s,t是字母异位词, 有问题,
    // 字符串里面的字符可以重复出现, 也就是出现偶数个才是正确的, 还是有问题,
    // 如果是aa 和bb,也会是偶数, 最好还是要减
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> hash_vec(26);
        for (int i = 0; i < s.length(); i++) {
            hash_vec[s[i] - 'a']++;
            hash_vec[t[i] - 'a']--;
        }
        for (int i = 0; i < hash_vec.size(); i++) {
            if (hash_vec[i] != 0) {
                return false;
            }
        }
        return true;
    }
};