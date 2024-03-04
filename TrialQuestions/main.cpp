#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// COMPLETE THIS FUNCTION
void process(int number, string numbers[], int size) {
    vector<int> positive;
    vector<int> negative;
    for(int i=0; i < size; i++) {
        if(stoi(numbers[i]) >= 0){
            positive.push_back(stoi(numbers[i]));
        }else{
            negative.push_back(stoi(numbers[i]));
        }
    }
    vector<int> result;
    for(int i = 0; i < positive.size(); i++){
        result.push_back(positive[i]);
    }
    for(int i = 0; i < negative.size(); i++){
        result.push_back(negative[i]);
    }

    for(auto i : result){
        cout << i << " " ;
    }
}

// You do not need to edit any code below this line
int main() {
    int size = 6;
    string numbers[] = {"20", "10", "80", "-2", "-4", "1"};
    process(size, numbers, size);
}