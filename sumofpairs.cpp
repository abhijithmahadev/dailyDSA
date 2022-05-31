// Given an array of N integers and number S
// return a pair from the array whose sums upto S

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> num_array, int sum){
    // Declare the data structures
    unordered_set<int> num_set;
    vector<int> result_pair;

    for( int i = 0; i < num_array.size(); i++){
        int compliment = sum - num_array[i];
        // if compliment elementis found add to result pair and return
        if (num_set.find(compliment) != num_set.end()){
            result_pair.push_back(num_array[i]);
            result_pair.push_back(compliment);
            return result_pair;
        }
        // else add element to the set
        else{
            num_set.insert(num_array[i]);
        }
    }
}


int main(){

    // Define the array as a vector 
    vector<int> num_array{10, 5, 2, 3, -6, 9, 11};
    int sum = 4;

    auto num_pair = pairSum(num_array, sum);
    if(num_pair.size() != 0){
        cout << num_pair[0] << " " << num_pair[1] << endl;
    }
    else{
        cout << " No such pair";
    }
}