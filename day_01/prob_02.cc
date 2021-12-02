#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int get_result(const std::vector<int> &inputs){
    size_t vsz = inputs.size();
    int wsz = 3;
    int num_increases = 0;

    if(vsz < wsz) return 1;

    int prev = 0;
    for(int i = 0; i < wsz; i++)
        prev += inputs[i];
    int curr = prev;

    for(int i = wsz; i < inputs.size(); i++){
        curr += inputs[i] - inputs[i - wsz];
        if(curr > prev) num_increases += 1;
        prev = curr;
    }

    return num_increases;
}

void read_file_into_vector(std::ifstream &f, std::vector<int> &vec){
    std::string line {""};
    int to_push {0};
    f.open("input.txt", std::ifstream::in);
    while(std::getline(f, line)){
        to_push = stoi(line);
        vec.push_back(to_push);
    }

    f.close();
}

int main(){
    std::vector<int> test_inputs {};
    std::ifstream input_txt;
    read_file_into_vector(input_txt, test_inputs);
    std::cout << get_result(test_inputs) << std::endl;
    return 0;
}