#ifndef MY_ALGO(BRUFORCE)_H_INCLUDED
#define MY_ALGO(BRUFORCE)_H_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>


struct Sorted_Array{
    int V = 0, m, curr_size = 0;//size, median index
    int* arr;
    int current_med = 0;
    long int all_med_sum = 0;
};

struct Sorted_Array* create_array_2(int v){//predetermined size
    Sorted_Array* arry = new Sorted_Array;
    if (v < 0) {std::cout<<"\n ERROR! Invalid array size!\n"; arry->V = 0;  arry->arr = new int[1]; return nullptr;} else
    arry->V = v;
    arry->arr = new int[v+1];
    for (int i = 0; i <= arry->V; ++i){arry->arr[i] = 0;}
    return arry;
}

void move_arr_2(Sorted_Array *&arry, int index){
    if (index >= arry->V) {std::cout<<"\n  ERROR! No elements to move!\n"; return;}
    if (arry->arr[arry->V] != 0) {std::cout<<"\n ERROR! All elements are assigned! Array is full!\n"; return;}
    if (arry->curr_size == arry->V) {std::cout<<"\n ERROR! Array is full!\n"; return;}
    for (int i = arry->curr_size+1; i > index; --i){
            arry->arr[i] = arry->arr[i-1];
    }
    arry->arr[index] = 0;
}

void add_element_and_change_sum_2(Sorted_Array *&arry, int m){
    if (arry->curr_size == arry->V) {std::cout<<"\n Cannot add more elements - array is full!\n"; return;} else {
    if (arry->curr_size == 0) {arry->curr_size = 1; arry->arr[1] = m; arry->current_med = m; arry->all_med_sum += m; return;}
    int i = 1;
    if (arry->arr[1] >= m) {
            move_arr_2(arry, 1);
            arry->arr[1] = m;
    } else {
        while (arry->arr[i] < m && i <= arry->curr_size){
            if (arry->arr[i] < m) ++i;
        }
        if (i <= arry->curr_size) move_arr_2(arry, i);
        arry->arr[i] = m;
    }
    arry->curr_size++;
    if (arry->curr_size % 2 == 0) arry->m = int(arry->curr_size/2); else
    if (arry->curr_size % 2 == 1) arry->m = int(arry->curr_size/2)+1;
    //arr->m = ceil(arr->curr_size / 2);
    arry->current_med = arry->arr[arry->m];
    arry->all_med_sum += arry->current_med;
    }
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
            if (counter > arry->V) {std::cout<<"\n Too many numbers in input file!\n"; break;}
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            add_element_and_change_sum_2(arry, tmp);
            //if (counter < 5) print_arr(arry);
            counter++;
        }
    } else std::cout<<"\n FILE ERROR! \n";
}

#endif // MY_ALGO(BRUFORCE)_H_INCLUDED

/*
struct Sorted_Array* create_array_1(){ //size can change
    Sorted_Array* arr = new Sorted_Array;
    arr->arr = new int[1];
    arr->V = 1;
    return arr;
}

void move_arr_1(Sorted_Array *arr, int index){
    if (index > arr->V) {std::cout<<"\n  ERROR! No elements to move!\n"; return;}
    arr->V++;
    for (int i = arr->V; i > index; --i){
            arr->arr[i] = arr->arr[i-1];
    }
    arr->arr[index] = 0;
}

void add_element_and_change_sum_1(Sorted_Array *arr, int m){
    arr->curr_size++;
    int i = 1;
    while (arr->arr[i] < m && i <= arr->V){
        if (arr->arr[i] < m) ++i; else {
            move_arr_1(arr, i);
            arr->arr[i] = m;
        }
    }
    if (i == arr->V) {
        arr->V++;
        arr->arr[arr->V] = m;
    }
    arr->m = ceil(arr->V / 2);
    arr->current_med = arr->arr[arr->m];
    arr->all_med_sum += arr->current_med;
}
*/
