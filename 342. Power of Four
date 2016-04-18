/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

my first method:

class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        if(num <= 0)
            return false;
        else if(num == 1)
            return true;
        else
        {
            if((num & num - 1) == 0)
                return isPowerOfFour(num>>2);
            else
                return false;
        }
    }
};

method without loop/recursive:

class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        return ((num > 0) && ((num & num - 1) == 0) && (num & 0x55555555L == num))
    }
};
