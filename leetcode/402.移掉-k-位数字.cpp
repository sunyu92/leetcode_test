/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:

//Main Logic is compare 2 adjacent elements, 2 cases:-
//1)  If the first element is less than or equal then increment i
//2) if first element is greater then remove that element
//Note:- edigits between pipes are into consideration. 
//       4 4 4 | 5  3|
//here 5 and 3 are compared so delete 5 now the point is that 4 is also greater than 3 so if k is still greater than 0 then compare 4 and 3 and delete 4 that's why set i-- after deletion


	//Function to remove leading zeroes if any
    void removeLeadingZeroes(string &num) {
        while(num.length() > 0 && (num.compare(0, 1, "0") == 0)) {              //simple checking the first digit in num, until it is not 0 remove first digit
            num.erase(num.begin()+0);
        }
    }
	//function to remove from the end of num if after iterating, k is still left
    void removeLeftOver(string &num, int k) {
        int i;
        i = num.length() - k;
        num.erase(num.begin()+i, num.end());
    }
    
    string removeKdigits(string num, int k) {
        int i = 0;
        while((i < num.length()-1) && (k>0)) {                  //iterating until we have not traversed string completely or k > 0
		//if num = "12" then num[i] = 1 and num[i+1] = 2 so if k = 1 then check 1 and 2 if 1 is less then 1 than don't remove it 
            if(num[i] <= num[i+1])                            
                i++;
			//if num = "21" then num[i] = 2 and num[i+1] = 1 so if k = 1 then check 1 and 2 if 2 is greater than 1 then  remove it 
            else
            {
                num.erase(num.begin()+i);
                k--;
                if(i > 0)                                 //if i != 0 then the previous element before the deleted element may or may not be greater than next one so decrement i to compare them
                    i--;
            }
        }
		//if k is left then remove the left over from left as an example "222222"
		//in this case above loop will not erase any digit so this condition will remove from end k digits
        if(k!=0)
            removeLeftOver(num, k);
		//remove trailing zeroes
        if(num.compare(0,1,"0") == 0)          //string compare function having arguments starting index, number of characters and other string i.e. str1.compare(starting_index, number_of_characters, str2)
            removeTrailingZeroes(num);
        if(num == "")
            return "0";
        return num;
    }
// @lc code=end

