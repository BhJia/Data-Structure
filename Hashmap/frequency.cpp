#include<bits/stdc++.h>
using namespace std;

//找出数组中任意一个重复的数字:哈希表存放次数,只要次数大于一就输出
int findRepeatNumber(vector<int> &nums)
{
    map<int, int> m;
    for (auto x : nums)
    {
        m[x]++;
        if (m[x] > 1)
            return x;
    }
    return 0;
}

//存在重复元素:排序后哈希表存放次数，同时只要次数大于一就输出
bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    map<int, int> m;
    for (auto x : nums)
    {
        m[x]++;
        if (m[x] > 1)
            return true;
    }
    return false;
}

//存在重复元素2：是否存在重复元素且下标之差不大于k
// 方法：哈希表存放下标，碰到重复元素判断下标之差即可
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(nums[i]) && abs(i - m[nums[i]]) <= k)
            return true;
        m[nums[i]] = i;
    }
    return false;
}

//找出数组中只出现一次的唯一一个数字:哈希表存放次数，再次遍历表找到次数为1的数
int singleNumber(vector<int> &nums)
{
    map<int, int> m;
    for (auto x : nums)
        m[x]++;
    for (auto a : m)
        if (a.second == 1)
            return a.first;
    return 0;
}

// 数组中唯一元素的和
int sumOfUnique(vector<int> &nums)
{
    int sum = 0;
    map<int, int> m;
    for (auto i : nums)
        m[i]++;
    for (auto p : m)
        sum += p.second == 1 ? p.first : 0;
    return sum;
}

//找出数组第一个不重复字符，返回字符
char firstUniqChar(string s)
{
    map<char, int> m;
    for (auto i : s)
        m[i]++;
    for (auto i : s)
    {
        if (m[i] == 1)
            return i;
    }
    return ' ';
}

// 找出字符串第一个不重复的字符并返回索引
int firstUniqCharIndex(string s)
{
    map<char, int> m;
    for (char ch : s)
        m[ch]++;
    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
            return i;
    }
    return -1;
}

//找出数组前k个高频元素:哈希表存放次数，元素去重放入数组并按次数降序排序,输出前K个元素组成的数组
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m;
    for (auto x : nums)
        m[x]++;
    vector<int> res;
    for (auto x : m)
        res.push_back(x.first);
    sort(res.begin(), res.end(), [&](int &a, int &b) { return m[a] > m[b]; });
    return vector<int>(res.begin(), res.begin() + k);
}

//在t中找有多少个s中的元素：哈希表记录s元素次数,遍历t,出现表中元素答案+1
int numJewelsInStones(string s, string t)
{
    map<char, int> m;
    int ans = 0;
    for (char c : s)
        m[c]++;
    for (char ch : t)
        ans += m.count(ch) ? 1 : 0;
    return ans;
}

// 错误的集合:集合s包含1到n的整数,但其中一个整数被替换成了另一个,找到被替换的整数和重复的整数
// 思路：哈希表先初始化后记录次数,找到次数为2和0的即可
vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> res(2);
    map<int, int> m;
    for (int i = 1; i <= nums.size(); i++)
        m[i] = 0;
    for (auto i : nums)
        m[i]++;
    for (auto p : m)
    {
        if (p.second > 1)
            res[0] = p.first;
        if (p.second == 0)
            res[1] = p.first;
    }
    return res;
}

//有多少小于当前数字的数字：给定数组,对于每一个数字,求小于该数字的数字个数
//思路：1、用哈希表m记录次数 2、对每个数字去重放入数组res 3、对res降序排序
// 4、暴力遍历res并用哈希表m1记录小于该数字的数字个数   5、遍历原数组对每个数在m1查找小于它的数的个数并放入ans数组
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> res, ans;
    map<int, int> m, m1;
    for (int x : nums)
        m[x]++;
    for (auto p : m)
        res.push_back(p.first);
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = i + 1; j < res.size(); j++)
            m1[res[i]] += m[res[j]];
    }
    for (int x : nums)
        ans.push_back(m1[x]);
    return ans;
}

//拼写单词：给定词汇表words和字母表chars，求出词汇表中所有可以用字母表中字母组合成的单词的长度之和
//思路：双哈希表：遍历words数组,判断每个单词每个字母出现次数是否超过chars哈希表中该字母出现次数
int countCharacters(vector<string> &words, string chars)
{
    int res = 0;
    map<char, int> m;
    for (char ch : chars) //记录字母表中字母出现次数
        m[ch]++;
    for (auto x : words) //遍历词汇表
    {
        bool flag = true;
        if (x.size() > chars.size()) //如果单词长度比字母表字母多直接跳过
            continue;
        map<char, int> m1; //定义临时哈希表记录每个单词每个字母出现次数
        for (auto y : x)
        {
            m1[y]++;
            if (!m.count(y) || m1[y] > m[y]) //如果有字母在字母表中没出现或者次数超过了说明不成立
                flag = false;
        }
        res += flag ? x.size() : 0;
    }
    return res;
}

//找不同：给定字符串s,t,找出t比s多的唯一一个字符
//先哈希记录t的字符个数,然后遍历s减去s字符次数,剩下的就是答案
char findTheDifference(string s, string t)
{
    char x = 'a'; //x可以任意
    map<char, int> m;
    for (auto i : t)
        m[i]++;
    for (auto i : s)
        m[i]--;
    for (auto i : m)
    {
        if (i.second == 1)
            x = i.first;
    }
    return x;
}

//判断数组中每个数的出现次数是否唯一
//方法:双哈希,先用m记录arr中每个数次数,再用n记录出现次数的序列每个数的次数,大于1则重复
bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> m;
    for (auto i : arr)
        m[i]++;
    map<int, int> n;
    for (auto i : m)
    {
        n[i.second]++;
        if (n[i.second] > 1)
            return false;
    }
    return true;
}

// 好数对个数：a[i]==a[j]&&i<j 为一个好数对
// 思路：一个数次数大于一,那么该数构成的好数对个数为C(n,2);
int numIdenticalPairs(vector<int> &nums)
{
    int sum = 0;
    map<int, int> m;
    for (auto i : nums)
        m[i]++;
    for (auto i : m)
        sum += i.second > 1 ? i.second * (i.second - 1) / 2 : 0;
    return sum;
}

// 气球的最大数量：给定字符串text,用text的字母尽可能多的拼凑出'balloon'字符串，求最多能拼出多少个？
// 方法：双哈希表
// STL语法补充：min_element(v.begin(),v.end())返回的是区间最小值的指针而非值
int maxNumberOfBalloons(string text)
{
    map<char, int> m;
    vector<int> tmp;
    for (char ch : text) //哈希表记录字符串中字符出现次数(常规操作了)
        m[ch]++;
    string s = "balloon";  
    map<char, int> m1;  //另一个哈希表记录balloon字符串中字符出现次数
    for (auto i : s)
        m1[i]++;
    for (auto i : s) //遍历哈希表2,对于表中每一个字符，如果text字符串中该字符的数量不足以拼凑balloon就返回0
    {
        if (m[i] < m1[i])  
            return 0;
        tmp.push_back(m[i] / m1[i]); //否则将表1中该字符数量比上表2中该字符数量加入数组
    }   
    //这里很细节,因为balloon中o和l都是重复的,下一步要通过比较每个字符的次数找到最小次数代表能拼凑出几个balloon
    // 如果直接将表1中该字符数量加入数组那么显然o和l都是明显偏多的，会影响比较,这样比一下相当于将o和l的数量变为1
    return *min_element(tmp.begin(), tmp.end()); //返回最小次数作为拼凑个数
}

//气球最大数量扩展题:给定字符串text和s,用text的字母尽可能拼凑出s字符串,求最多能拼出多少个？(思路完全一致)
int maxNumber(string text,string s)
{
    map<char, int> m;
    vector<int> tmp;
    for (char ch : text)
        m[ch]++;
    map<char, int> m1;
    for (auto i : s)
        m1[i]++;
    for (auto i : s)
    {
        if (m[i] < m1[i])
            return 0;
        tmp.push_back(m[i] / m1[i]);
    }
    return *min_element(tmp.begin(), tmp.end());
}

// 根据字符出现的频率排序：将给定字符串字符按出现频率降序排序
string frequencySort(string s)
{
    string ans;
    map<char, int> m;
    for (auto i : s)  
        m[i]++;
    vector<pair<char, int>> temp;
    for (auto p : m)
        temp.push_back(p);
    sort(temp.begin(), temp.end(), [&](pair<char, int> &a, pair<char, int> &b) {
        return a.second > b.second;
    });
    for (auto i : temp)
    {
        for (int j = 0; j < i.second; j++)
            ans.push_back(i.first);
    }
    return ans;
}

// 前k个高频单词：返回给定数组前k个高频单词,频率相同按字典序升序
vector<string> topKFrequent(vector<string> &words, int k)
{
    vector<string> res;
    map<string, int> m;
    for (auto i : words)
        m[i]++;
    vector<pair<string, int>> temp;
    for (auto i : m)
        temp.push_back(i);
    sort(temp.begin(), temp.end(), [&](pair<string, int> &a, pair<string, int> &b) {
        return a.second > b.second || (a.second == b.second && a.first.compare(b.first) < 1);
    });
    for (int i = 0; i < k; i++)
        res.push_back(temp[i].first);
    return res;
}

//给定一个字符串，找到所有在字符串中重复出现的子串
vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> res;
    map<string, int> m;
    for (int i = 0; i < s.size() - 9; i++)
        if (++m[s.substr(i, 10)] == 2) //注意不能是>1，否则如果一个子串重复好几次会都加入数组
            res.push_back(s.substr(i, 10));
    return res;
}

// 多数元素：找到数组中出现次数大于n/2的元素
int majorityElement(vector<int> &nums)
{
    int res = 0;
    map<int, int> m;
    for (auto i : nums)
        m[i]++;
    for (auto p : m)
        if (p.second > nums.size() / 2)
            res = p.first;
    return res;
}

// 等价数对：给定一个数对构成的数组,如果数对的两个数相同，就说两个数对等价(不需要考虑顺序),返回等价数对的个数
// 思路：遍历数组，把每个数对排序，然后放到哈希表中，遍历哈希表，n个相同的数对等价个数为C(n,2);
int numEquivDominoPairs(vector<vector<int>> &d)
{
    int cnt = 0;
    map<vector<int>, int> m;
    for (auto i : d)
    {
        sort(i.begin(), i.end());
        m[i]++;
    }
    for (auto p : m)
        cnt += p.second * (p.second - 1) / 2;
    return cnt;
}

// 幸运数：数在数组出现频次和值相等则为幸运数，找出最大的幸运数
int findLucky(vector<int> &arr)
{
    map<int, int> m;
    for (auto i : arr)
        m[i]++;
    sort(arr.begin(), arr.end(), [&](int &a, int &b) { return a > b; });
    for (auto i : arr)
        if (m[i] == i)
            return i;
    return -1;
}