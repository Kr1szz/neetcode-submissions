class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // set of all unique numbers
        unordered_set<int> numSet(nums.begin(), nums.end());
    //tracking max consecutive seq lengths found
        int maxLength=0;
    //map to store the length of consecutive seq starting from each number
        unordered_map<int, int> sequenceLengths;
//Processing each number and  find consecutive square
        for(int currentNum : nums){
            int nextNum=currentNum;
//keep incrementing while consecutive numebrs exist in set
            while(numSet.count(nextNum)){
                //remove Processed number to avoid reprocessing
                numSet.erase(nextNum);
                nextNum++;
            }
            //calculating length of seq
            int currentSequenceLength=(nextNum-currentNum);
            if(sequenceLengths.count(nextNum)){
                currentSequenceLength+= sequenceLengths[nextNum];
            }
            //store the seq length for starting number
            sequenceLengths[currentNum]=currentSequenceLength;
            maxLength=max(maxLength, sequenceLengths[currentNum]);
        }
        return maxLength;
    }
};