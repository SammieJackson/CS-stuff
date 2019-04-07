#include "my_algo(bruforce).h"

using namespace std;



void main0(){
    int v = 5;
    struct Sorted_Array* arr = create_array_2(v);

    /*
    for (int i = 1; i <= v; ++i) {
        add_element_and_change_sum_2(arr, v-i);
        print_arr(arr);
        //cout<<endl<<arr->curr_size;
        //cout<<endl<<arr->current_med;
    }
    */

    add_element_and_change_sum_2(arr, 4);
    add_element_and_change_sum_2(arr, 3);
    add_element_and_change_sum_2(arr, 6);
    add_element_and_change_sum_2(arr, 5);
    //for (int i=0; i<5; ++i){cout<<endl<<arr->arr[i];}
    print_arr(arr);
    cout<<"\n\n "<<arr->all_med_sum<<"\n\n";
    delete arr;
}

int main()
{

    int v = 10000;
    struct Sorted_Array* arr = create_array_2(v);
    built_arr(arr);
    //for (int i=1; i<=1; ++i){cout<<endl<<arr->arr[i];}
    //print_arr(arr);
    cout<<"\n\n "<<arr->all_med_sum % 10000<<"\n\n";


    //main0();
    return 0;
}
