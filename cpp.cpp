#include <iostream>
#include <vector>
#include <string>

std::vector<int> TwoSum(std::vector<int>& nums, int target){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }

    }
    return {};
}

std::vector<int> bubbleSort(std::vector<int>& nums){
    for(int i = 0; i < nums.size(); i++ ){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] > nums[j]){
                std::swap(nums[i], nums[j]);

            }
        }
        
    }
    return nums;
}

int fib(int x){
    if(x <= 1){
        return x;
    }
    return(fib(x-1) - fib(x-2));
}


std::string compressString(std::string str){
    int count = 1;
    std::string compressedString = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == str[i+1] )
            count++;
            
            else{
                compressedString += str[i] + std::to_string(count);
                count = 1;
            }
    }
    return compressedString;
}

void decompressString(){
    std::string str = compressString("aaabbbcc");
    std::string decompressedString = "";
    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];
        i++;
        int count = str[i] - '0';
        for (int j = 0; j < count; j++) {
            decompressedString += ch;
        }
    }
    std::cout << decompressedString << std::endl;
}



int main(){

}