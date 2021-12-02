#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int get_result(const std::vector<int> &inputs){
    int curr {0};
    int prev {0};
    int num_increases {0};

    for(int i = 0; i < inputs.size() - 1; i++){
        prev = inputs[i];
        curr = inputs[i + 1];
        if(curr > prev) num_increases += 1;
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