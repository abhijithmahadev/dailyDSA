// Given a set of integers and a value Sum , find out the 
// triplets which add upto the sum. Print out all the triplets
// in non decreasing sequence breadthwise and also length wise

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > tripletsum(vector<int> num_array, int sum){
    // Sort the array
    sort(num_array.begin(), num_array.end());

    // Initialize the result vector
    vector<vector<int> > total_result;

    for( int i = 0; i < num_array.size(); i++){
        int start_pointer = i + 1;
        int end_pointer = num_array.size() - 1;
        int compliment = sum - num_array[i];
        //cout << start_pointer << " " << end_pointer <<" " << i << endl;

        while(start_pointer < end_pointer){
            if ( num_array[start_pointer] + num_array[end_pointer] == compliment){
                // Push to result vector
                total_result.push_back({num_array[i], num_array[start_pointer], num_array[end_pointer]});
                start_pointer = start_pointer + 1;
                end_pointer = end_pointer - 1;
            }
            else if (num_array[start_pointer] + num_array[end_pointer] < compliment){
                start_pointer = start_pointer + 1;
            }
            else if (num_array[start_pointer] + num_array[end_pointer] > compliment){
                end_pointer = end_pointer - 1;
            }
        } 
    }
    return total_result;
}

int main(){
    vector<int> num_array{15, 1, 4, 6, 3, 7, 9, 8, 2, 5};
    int sum = 18;
    auto result = tripletsum(num_array, sum);
    
    for ( auto element : result){
        for ( auto number : element){
            cout << number << ",";
        }
        cout << endl;
    }

}