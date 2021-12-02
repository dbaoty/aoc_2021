#include <iostream>
#include <fstream>
#include <cstring>

struct position {
    int x {};
    int y {};
};

void read_file_into_struct(std::ifstream &f, position &pos);

int main(){
    position sub_position {};
    std::ifstream input_file;
    read_file_into_struct(input_file, sub_position);

    int final_depth = sub_position.y * sub_position.x;
    std::cout << final_depth << std::endl;

    return 0;
}

void read_file_into_struct(std::ifstream &f, position &pos){
    f.open("input.txt", std::ifstream::in);
    int distance {};
    char direction {};

    std::string line;
    while(std::getline(f, line)){
        direction = line.front();
        char *temp = &line.back();
        distance = atoi(temp);
        switch(direction){
            case 'f':
                pos.x += distance;
                break;
            case 'd':
                pos.y += distance;
                break;
            case 'u': 
                pos.y -= distance;
                break;
            default: 
                break;
        };
    }
}