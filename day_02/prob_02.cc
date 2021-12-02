#include <iostream>
#include <fstream>
#include <cstring>

struct position {
    int x {};
    int y {};
    int aim {};
};

void read_file_into_struct(std::ifstream &f, position &pos);

int main(){
    std::ifstream input_file;
    position sub_position;
    read_file_into_struct(input_file, sub_position);

    std::cout << sub_position.y * sub_position.x << std::endl;

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
                pos.y += distance * pos.aim;
                break;
            case 'd':
                pos.aim += distance;
                break;
            case 'u': 
                pos.aim -= distance;
                break;
            default: 
                break;
        };
    }
}