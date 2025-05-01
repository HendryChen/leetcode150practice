// hendry's C++ leetcode
#include "math.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include <charconv>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "includes.h"
// cpluscplus
// geeksforgeeks
// stackoverflow

// test

// dynamic programming (dp):
//  top-down: (0) backtracking
//         - polynomial (confirm de-rank relationship) : X(n) = X(n-1) + X(n-2)
//                                                       f(g(h(x))) = f(g(Y)) +
//                                                       f(k) + a f(X) = min
//                                                       (f(X') , f(X''))  <==
//                                                       decision
//         - implementation
//                       //exception ( function fail => base)
//                       //general (polynomial function)
//
//  bottom-up: (X) not recommended
//         EXCEPTION: de-rank -> direction inheritance: f(g(h(x))) = f(g(Y)),
//         X(n) = X(n-1) + X(n-2)
//                    bottom-up / greedy "may" work
//

// linked list <-> dynamic programming (be careful for complexity issue =>
// solution: memoization)
//     |
// hash table (low complexity => solution: unordered_map)

using namespace std; // define solution space

int main(int argc, char *argv[]) {
  int testID = 10;

  if (argc < 2)
    printf("default test ID %d\n", testID);
  else
    testID = atoi(argv[1]);

  switch (testID) {
  case 0:
    printf("hello world \n");
    break;
  case 1: // pointer
    leetcode_merge_two_vector();
    break;
  case 2:
    leetcode_remove_element();
    break;
  case 3:
    leetcode_remove_duplicate();
    break;
  case 4:
    leetcode_majortyelement();
    break;
  case 5:
    leetcode_vector_rotate();
    break;
  case 6:
    leetcode_max_profit2();
    break;
  case 7:
    // need discuss with VK
    leetcode_jump_game();
    break;
  case 8:
    leetcode_h_index();
    break;
  case 9:
    leetcode_product();
    break;
  case 10:
    leetcode_jump_gameII(); 
    break;
  default:
    printf("not a supported testID : %d\n", testID);
    exit(-1);
  }
}

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    vector<int> nums3;
    int nums1_idx = 0;
    int nums2_idx = 0;

    if (m == 0) {
      nums3 = nums2;
    } else if (n == 0) {
      nums3 = nums1;
    } else {
      while (nums1_idx + nums2_idx < (m + n)) {
        if (nums1_idx >= m) {
          nums3.push_back(nums2[nums2_idx]);
          nums2_idx++;
        } else if (nums2_idx >= n) {
          nums3.push_back(nums1[nums1_idx]);
          nums1_idx++;
        } else if (nums1[nums1_idx] < nums2[nums2_idx]) {
          // printf("nums 1 idx %d val %d\n",nums1_idx,nums1[nums1_idx]);
          nums3.push_back(nums1[nums1_idx]);
          nums1_idx++;
        } else {
          // printf("nums 2 idx %d val %d\n",nums2_idx,nums2[nums2_idx]);
          nums3.push_back(nums2[nums2_idx]);
          nums2_idx++;
        }
      }
    }
    nums1 = nums3;
  }
};

void leetcode_merge_two_vector() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  Solution sol;
  sol.merge(nums1, 3, nums2, 3);

  for (auto it : nums1) {
    printf("nums %d \n", it);
  }
}

class Solution_remove_element {
public:
  int removeElement(vector<int> &nums, int val) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] == val) {
        nums.erase(nums.begin() + i);
      } else {
        i++;
      }
    }
    return nums.size();
  }
};

void leetcode_remove_element() {
  vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;

  Solution_remove_element sol;
  sol.removeElement(nums1, val);

  for (auto it : nums1) {
    printf("nums %d \n", it);
  }
}

class Solution_removeDuplicate {
public:
  int removeDuplicates(vector<int> &nums) {
    unordered_map<int, int> sData;

    int i = 0;
    while (i < nums.size()) {
      if (sData[nums[i]] > 0) {
        nums.erase(nums.begin() + i);
      } else {
        sData[nums[i]]++;
        i++;
      }
    }
    return nums.size();
  }
};

void leetcode_remove_duplicate() {
  Solution_removeDuplicate sol;

  vector<int> nums = {1, 1, 2};
  sol.removeDuplicates(nums);

  for (auto it : nums) {
    printf("nums %d \n", it);
  }
}

class Solution_majortyelement {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> hist;

    for (int i = 0; i < nums.size(); i++) {
      hist[nums[i]]++;

      if (hist[nums[i]] > (nums.size() / 2)) {
        return nums[i];
      }
    }

    return 0;
  }
};

void leetcode_majortyelement() {
  vector<int> nums = {1, 2, 3, 3, 3, 3};
  Solution_majortyelement sol;
  int val;
  val = sol.majorityElement(nums);
  printf("the val is %d \n", val);
}

class Solution_rotate {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> temp;
    temp = nums;
    for (int i = 0; i < nums.size(); i++) {
      temp[(i + nums.size() + k) % nums.size()] = nums[i];
      printf("dbg temp %d val %d right idx %d \n", i, temp[i],
             (int)((i + nums.size() + k) % nums.size()));
    }
    nums = temp;
  }
};

void leetcode_vector_rotate() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  Solution_rotate sol;
  sol.rotate(nums, 2);
  for (auto &it : nums) {
    printf("val %d \n", it);
  }
}

class Solution_buy_stock2 {
public:
  int maxProfit(vector<int> &prices) {

    //    7, 1, 5, 3, 6, 4
    //          b
    //          s
    int sell = 0, buy = 0;
    int profit = 0;
    int profit_acc = 0;
    for (sell = 0; sell < prices.size(); sell++) {
      profit = prices[sell] - prices[buy];
      if (profit > 0) {
        profit_acc += profit;
        buy = sell;
      } else {
        buy = sell;
      }
    }
    return profit_acc;
  }
};

void leetcode_max_profit2() {
  Solution_buy_stock2 sol;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  printf("the rst is %d \n", sol.maxProfit(prices));
}

class sol_jump_game_base {
public:
  virtual int sol(vector<int> input) { return -1; }
};

/*

  {2, 3, 1, 1, 4}
  {3, 2, 1, 0, 4}
  # general
  f({a, b, c, d, e}) => check if "a" can reach the last index
  => yes, return 1
  => no, f({b, c, d, e}) or f({c, d, e}) , ....
         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^# of a conditions
         any of the above f() can reach the last index

  #exception :
    "a"  == 0 => return (size == 0)?true: false;

  {2, 3, 1, 1, 4}
         s
  
*/

class CJumpGameVKMemo : public sol_jump_game_base {
public:
  int sol(vector<int> input) { 
    int s=0; 
    unordered_map<int, int> memo; //key: index value : res
    return canJump(input, s, memo);   
  }
private:
  int canJump(vector<int>& nums, int s, unordered_map<int, int>& memo){
    int jump = nums[s];
    //exception
    if(jump == 0)
      return (s == nums.size()-1)?1:0;

    //general

    if(s+ jump >= nums.size()) return true;
    int reached = 0;
    for(int i= s+1; i<= s+jump; i++){
      int isJump;
      if(memo.find(i) == memo.end())
      {
        isJump = canJump(nums, i, memo);
        memo[i] = isJump;
      }
      else{
        isJump = memo[i];
      }
      
      if(isJump){
        reached = 1;
        break;
      }      
    }
    return reached;
  }
};


class CJumpGameVK : public sol_jump_game_base {
public:
  // 2 0 0
  int sol(vector<int> input) { 
    int s=0; 
    return canJump(input, s);   
  }
private:
  int canJump(vector<int>& nums, int s){
    int jump = nums[s];   
    //exception
    if(jump == 0)
      return (s == nums.size()-1)?1:0;

    //general   
    if(s+ jump >= nums.size()) return true;
    int reached = 0;
    for(int i= s+1; i<= s+jump; i++){
      if(canJump(nums, i)){
        reached = 1;
        break;
      }
    }   
    return reached;
  }
};

class sol_jump_game_practice: public sol_jump_game_base{
  public:
#if 0
  chain of thought:
  exception:
  input size is 0 -> return true
  general:
  input {2 3 1 1 4}
  if f(a,b,c,d,e) can reach to the end -> 
                  can't reach to the end -> false
                                              -> f(b,c,d,e),f(c,d,e) can reach to the end .......  -> using recursive
#endif
  int sol(vector<int> input) {
    //exception
    if(input.size() == 1)
    {
      return true;
    }

    int jump_num = input[0];
    //general sol
    return derive(input,0);
    
  }
private:
  int derive(vector<int>input,int idx)
  {
    //exception
    if(input[idx] == 0 && (idx < input.size()))
    {
      return false;
    }
    //general 
    int jump_end = input[idx];
    int reach_end = 0;
    printf("idx %d jump_end %d input.size %d \n",idx,jump_end,input.size());
    if(idx + jump_end >= input.size()-1)
    {
      reach_end = true;
    }
    else
    {
      for(int i = 1; i <= jump_end;i++)
      {
        reach_end = derive(input,idx + i);
        if(reach_end)
        {
          break;
        }
      }
    }
    return reach_end;
  }
};

class sol_jump_game_practice_memo: public sol_jump_game_base{
public:
  int sol(vector<int> nums)
  {
    int idx = 0;
    unordered_map<int,int> memo;
    return derive(nums,idx,memo);
  }
private:
  int derive(vector<int> nums,int idx,unordered_map<int,int> &memo)
  {
    //exception
    printf("enter idx %d, \n ",idx);
    if(nums.size() == 1)
    {
      return true;
    }
    if(nums.size() == 0)
    {
      return false;
    }
    if(nums[idx] == 0)
    {
      //printf("enter nums[idx] is 0 \n ");
      return idx >= nums.size() - 1? 1:0;
    }
    //general 
    //end condition
    //1 1 0
    int can_jump = 0;
    if(idx + nums[idx] >= nums.size() -1)
    {
      //printf("enter idx %d nums[idx] %d \n ",idx,nums[idx]);
      return true;
    }
    else
    {
      for(int i = 1; i <= nums[idx] ;i++)
      {
        //printf("enter idx %d nums[idx] %d i %d \n ",idx,nums[idx],i);
       if(memo.find(idx+i) == memo.end())
       {
          can_jump = derive(nums,idx+i,memo);
          memo[idx+i] = can_jump;
       }
       else
       {
          can_jump = memo[idx+i];
       }
        if(can_jump)
        {
          break;
        }
      }
    }
    return can_jump;
  }
};

class sol_jump_game : public sol_jump_game_base {
public:
  int sol(vector<int> input) {
    int end_goal = input.size() - 1;
    int end = input[0];
    int temp = 0;
    int jump_suc = 0;

    for (int i = 0; i < end; i++) {
      temp = i + input[i];
      printf("i %d temp %d,end %d end goal %d \n", i, temp, end, end_goal);
      if (temp >= end) {
        end = temp;
        if (end >= end_goal) {
          jump_suc = 1;
          break;
        }
      }
    }

    return jump_suc;
  }
};

class sol_jump_game_greedy : public sol_jump_game_base {
public:
  int sol(vector<int> nums) {
    //exception
    if(nums.size() == 0)
    {
      return false;
    }
    if(nums.size() == 1)
    {
      return true;
    }
    
    //general 
    int prior = nums.size() -1;//2
    int end = nums.size() -1;// 2
    int jump_suc = 0;
    // 2 0 0
    // p  
    //     e
    for(int i = nums.size()-1;i > 0;i--)
    {
        prior-=1;
        printf("i %d nums[i] %d prior %d end %d \n",i,nums[i],prior,end);
        if(prior + nums[prior] >= end)
        {
          end = prior;
        }
    }
    if(end == prior)
    {
       jump_suc = 1;
    }
    return jump_suc;
  }
};

void leetcode_jump_game() {
  vector<int> input = {0};
  //                       s
  //                         e
  sol_jump_game jump_game_sol;
  CJumpGameVK jumGameVK;
  CJumpGameVKMemo jumpGameVKMemo;
  sol_jump_game_practice jumGameVKpractice;
  sol_jump_game_greedy jumpgamegreedy;
  
  sol_jump_game_base *sol;
  //sol = &jump_game_sol;
  //sol = &jumGameVK;
  //sol = &jumpGameVKMemo;
  sol = &jumpgamegreedy;

  input = {2, 3, 1, 1, 4};
  printf("rst %d (ans: 1) \n", sol->sol(input));

  input = {3, 2, 1, 0, 4};
  printf("rst %d (ans: 0) \n", sol->sol(input));

  input = {2,0,0};
  printf("rst %d (ans: 1) \n", sol->sol(input));
}

class sol_jump_gameII_base {
public:
  virtual int sol(vector<int> input) { return -1; }
};

//still coding
//problem facing: my thinking is to record each step and find the minimum step, however, still struggle of 
//find a way to record each step.
class sol_jump_gameII_hendry: public sol_jump_gameII_base{
public:
  int sol(vector<int> nums)
  {
    int idx = 0;
    unordered_map<int,int> memo;
    unordered_map<int,int> memo_cnt;
    //ini
    memo_cnt[0] = 0;
    return derive(nums,idx,memo,memo_cnt);
  }
private:
  int derive(vector<int> nums,int idx,unordered_map<int,int> &memo,unordered_map<int,int> &memo_cnt)
  {
    // 1 1 0 
    // f(a,b,c,d) -> a can reach d -> yes, return 1 : these layer cnt = 1
    //                              \ No,a can only reach  f(b,c,d) or f(c,d) can reach d: need maintain a map, these layer cnt = 2
    //exception
   
    printf("enter idx %d, \n ",idx);
    if(nums.size() == 1)
    {
      return 1;
    }
    if(nums.size() == 0)
    {
      return 0;
    }
    if(nums[idx] == 0)
    {
      //printf("enter nums[idx] is 0 \n ");
      return 0;
    }
    //general 
    //end condition
    //2 1 0
    int can_jump = 0;
    int jump_step = 0;
    if(idx + nums[idx] >= nums.size() -1)
    {
      printf("enter idx %d nums[idx] %d memo_cnt[%d] %d size %d \n ",idx,nums[idx],idx,memo_cnt[idx],nums.size());
      memo[idx] = 1;
      
      memo_update_min(memo_cnt, idx, nums.size()-1);
      
      //printf("memo_cnt[nums.size()-1] %d \n ",memo_cnt[nums.size()-1]);
      
      return memo_cnt[nums.size()-1];
    }
    else
    {
      for(int i = 1; i <= nums[idx] ;i++)
      {
        printf("enter idx %d nums[idx] %d i %d memo_cnt[idx] %d \n ",idx,nums[idx],i,memo_cnt[idx]);
        
        memo_update_min(memo_cnt, idx, idx+i);
       
       if(memo.find(idx+i) == memo.end())
       {
          memo_cnt[idx+i] = derive(nums,idx+i,memo,memo_cnt);
          can_jump = memo_cnt[idx+i];
       }
       else
       {
          can_jump = memo[idx+i];
       }
       if(can_jump)
       {
          jump_step = memo_cnt[idx+i];
          break;
       }
      }
    }
    if(can_jump > 0)
    {
      return jump_step;
    }
    else
    {
      return 0;
    }
  }

 void memo_update_min(unordered_map<int,int> &memo_cnt,int idx,int next_idx)
 {
   if(memo_cnt.find(next_idx) == memo_cnt.end())
     {
       memo_cnt[next_idx] = memo_cnt[idx]+1;
     }
     else
     {
       if(memo_cnt[next_idx] > memo_cnt[idx]+1)
       {
         memo_cnt[next_idx] = memo_cnt[idx]+1;
       }
     }
 }
};

void leetcode_jump_gameII() {
  vector<int> input = {0};
  //                       s
  //                         e
  sol_jump_gameII_hendry jump_gameII_sol;
  

  sol_jump_gameII_base *sol;
  //sol = &jump_game_sol;
  //sol = &jumGameVK;
  //sol = &jumpGameVKMemo;
  sol = &jump_gameII_sol;

  //input = {2, 3, 1, 1, 4};
  //printf("rst %d (ans: 1) \n", sol->sol(input));

  //input = {3, 2, 1, 0, 4};
  //printf("rst %d (ans: 0) \n", sol->sol(input));

  input = {2,1,1,0};
  printf("gameII rst %d (ans: 2) \n", sol->sol(input));
}

class sol_h_index {
public:
  int hIndex(vector<int> &citations) {
    //{3,0,6,1,5};
    //0 1 3 5 6
    //        ^
    //    3 2 1
    //1 1 3
    //exception
    if(citations.size() == 1)
    {
      return citations[0] >= 1 ? 1:0;
    }
    if(citations.size() == 0)
    {
      return 0;
    }
    sort(citations.begin(), citations.end(),[](int &l, int &r) { return l < r; });
    for (int j = 0; j < citations.size(); j++) {
      printf("%d \n", citations[j]);
    }
    int cnt = 1;
    int cite_num = 0;
    for (int i = citations.size() - 1; i >= 0; i--) {
      printf("i %d cnt %d cite_num %d \n",i ,cnt,cite_num);
      if (citations[i] >= cnt ) 
      {
        cnt++;
        cite_num++;
      }
      else
      {
        break;
      }
    }

    return cite_num;
  }
};

void leetcode_h_index() {
  sol_h_index sol_hidx;
  vector<int> citations = {1,3,1};
  //{3,0,6,1,5};
  // 0 1 3 5 6
  // 6 5 3 1 0
  //{1,3,1}
  // 1 1 3
  // 3 1 1
  printf("the rst is %d \n", sol_hidx.hIndex(citations));
}

class RandomizedSet_openai {
private:
  std::unordered_map<int, int> valToIndex;
  std::vector<int> values;

public:
  void RandomizedSet() {
    srand(time(nullptr)); // Seed for randomness
  }

  bool insert(int val) {
    if (valToIndex.count(val))
      return false;

    values.push_back(val);
    valToIndex[val] = values.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!valToIndex.count(val))
      return false;

    int index = valToIndex[val];
    int lastVal = values.back();

    values[index] = lastVal;
    valToIndex[lastVal] = index;

    values.pop_back();
    valToIndex.erase(val);

    return true;
  }

  int getRandom() {
    int randomIndex = std::rand() % values.size();
    return values[randomIndex];
  }
};

class solution_product {
public:
  vector<int> product_sol(vector<int> &nums) {
    vector<int> rst = {0};
    return rst;
  }
};

void leetcode_product() {
  vector<int> nums{1, 2, 3, 4};
  solution_product sol;
  vector<int> rst = sol.product_sol(nums);
}