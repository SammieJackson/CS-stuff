#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

struct Sorted_Array{
    int m, curr_size = 0;//size, median index
    int* arr;
};

struct Sorted_Array* create_array_2(int v){//predetermined size
    Sorted_Array* arry = new Sorted_Array;
    if (v < 0) {std::cout<<"\n ERROR! Invalid array size!\n"; arry->arr = new int[1]; return nullptr;} else
    arry->arr = new int[v+1];
    for (int i = 0; i <= v; ++i){arry->arr[i] = 0;}
    return arry;
}

void move_arr_2(Sorted_Array *&arry, int index){
    for (int i = arry->curr_size+1; i > index; --i){
            arry->arr[i] = arry->arr[i-1];
    }
    arry->arr[index] = 0;
}

void add_element_0(Sorted_Array *&arry, int m){

}

void add_element_2(Sorted_Array *&arry, int m){
    if (arry->curr_size == 0) {arry->curr_size = 1; arry->arr[1] = m; return;}
    int i = 1;
    if (arry->arr[1] > m) {
            move_arr_2(arry, 1);
            arry->arr[1] = m;
    } else
    if(arry->arr[1] == m) {return;} else
    {
        while (arry->arr[i] <= m && i <= arry->curr_size){
            if (arry->arr[i] == m) return;
            if (arry->arr[i] < m) ++i;
        }
        if (i <= arry->curr_size) move_arr_2(arry, i);
        arry->arr[i] = m;
    }
    arry->curr_size++;
}

void print_arr(Sorted_Array *arry){
    std::cout<<"\n";
    for (int i = 1; i<=arry->curr_size; ++i){std::cout<<" "<<arry->arr[i];}
}

void built_arr(Sorted_Array *&arry){
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_Median.txt", std::ios::in);
    if (file.good()){
        std::string str;
        int counter=0;
        while (getline(file, str)){
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            add_element_2(arry, tmp);
            //if (counter < 5) print_arr(arry);
            counter++;
        }
    } else std::cout<<"\n FILE ERROR! \n";
}

#endif // ARRAY_H_INCLUDED
