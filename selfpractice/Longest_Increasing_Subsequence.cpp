#include <vector>
#include <algorithm>
#include <iostream>

int longest_increasing_subsequence(std::vector<long long>& nums) {
    std::vector<int> dp;
    for (int i = 0; i < nums.size(); i++) {
        auto it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
        if (it == dp.end()) {
            dp.push_back(nums[i]);
        } 
        else {
            *it = nums[i];
        }
    }
    return dp.size();
}

int main(){
    std::vector<long long> nums;
    int n; std::cin >> n;
    for (int i = 0; i < n; i++){
        long long tmp;
        std::cin >> tmp;
        nums.push_back(tmp);
    }
    std::cout << longest_increasing_subsequence(nums);
}