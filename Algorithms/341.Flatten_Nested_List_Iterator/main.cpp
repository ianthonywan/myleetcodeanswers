/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator 
{
public:
    void iterator_helper(vector<NestedInteger> &nestedList) 
    {
        for(auto iter : nestedList)
        {
            if(iter.isInteger())
            {
                res.push_back(iter.getInteger());
            }
            else
            {
                iterator_helper(iter.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        iterator_helper(nestedList);
    }

    int next() 
    {
        return res[count];
    }

    bool hasNext() 
    {
        size_t size = res.size();
        if(++count < size)
            return true;
        else
            return false;
    }
private:
    vector<int> res;
    int count = -1;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
