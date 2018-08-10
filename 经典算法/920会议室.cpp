/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool isless(const Interval &r1, const Interval &r2)
    {
    	return r1.start < r2.start;
    }

    bool canAttendMeetings(vector<Interval> &intervals) {
    	// Write your code here
    	int size = intervals.size();
    	sort(intervals.begin(), intervals.end(), isless);
    	for (int i = 0; i < size - 1; i++)
    		if (intervals[i].end > intervals[i + 1].start)
    			return false;
    	return true;
    }
};


// 用map进行排序，遍历map时，使用迭代器，只能++
 bool canAttendMeetings(vector<Interval> &intervals) {
    	// Write your code here
    	if(intervals.empty())
    	    return true;
    	int size = intervals.size();
    	map<int, int> my;
    	for (int i = 0; i < size; i++)
    		my[intervals[i].start] = intervals[i].end;
    	auto it = my.begin(), itB = my.begin();
    	it++;
    	
    	for (; it != my.end(); it++)
    	{
    		if (itB->second > it->first)
    			return false;
    		itB++;
    	}
    	return true;
    }
