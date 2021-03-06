#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int getCheckSum(int num, vector<vector<int>> matrix){
  int intermediate = 0;
  string str = to_string(num);
  for(int i = 0; i < str.length(); i++){
    intermediate = matrix[intermediate][str[i] - '0'];
  }
  return intermediate;
}

vector<int> permutations(string data){
  vector<int> permutations;

  for(int i = 0; i < data.length() - 2; i++){
    vector<char> arr;
    for(int j = 0; j < data.length(); j++){
      arr.push_back(data[j]);
    }
    swap(arr[i], arr[i+1]);

    string permutation = "";
    for(int j = 0; j < arr.size(); j++){
      permutation += arr[j];
    }

    permutations.push_back(stoi(permutation));
  }

  return permutations;
}

int main() {
  vector<vector<int>> matrix = {
    {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
    {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
    {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
    {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
    {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
    {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
    {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
    {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
    {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
    {2, 5, 8, 1, 4, 3, 6, 7, 9, 0}
  };

  vector<string> inputData;
  vector<int> outputData;

  //get data
  ifstream inputF;
	inputF.open("input.txt");

  string str;
	while (getline(inputF, str)) {
    inputData.push_back(str);
	}

  inputF.close();

  for(int i = 0; i < inputData.size(); i++){
    if(getCheckSum(stoi(inputData[i]), matrix) == 0){
        outputData.push_back(stoi(inputData[i]));
        continue;
    }
    vector<int> arr = permutations(inputData[i]);
    for(int j = 0; j < arr.size(); j++){
      if(getCheckSum(arr[j], matrix) == 0){
        outputData.push_back(arr[j]);
      }
    }
  }

  ofstream outputF;
  outputF.open("output.txt");

  for(int i = 0; i < outputData.size(); i++){
    outputF << outputData[i] << endl;
  }

  outputF.close();
}
