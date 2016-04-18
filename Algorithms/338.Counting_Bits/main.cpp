/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:

You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?
*/

class Solution {
public:
    int x = 1;
    vector<int> countBits(int num) 
    {
        vector<int> res;
        int temp;
        if(num < 0)
            return res;
        res.push_back(0);
        
        for(auto i = 1; i <= num; ++i)
        {
            if(i == x)
            {
                temp = x;
                x = x << 1;
            }
            if((i & 1) == 1)
                res.push_back(res[i - 1] + 1);
            else
                res.push_back(res[i - temp] + 1);

        }
    }
};
