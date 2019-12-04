/// Data_Struct
////Variant 5
////
//// Created on 17.11.2019
//// by student of mech-math faculty
//// KNU named Tarasa Shevchenco
//// Nikiforov Oleksandr

#ifndef PROJECT_DATASTRUCT_H
#define PROJECT_DATASTRUCT_H


#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include "../src/common.h"


#define INPUT_FILE "../tests/input.txt"
#define OUTPUT_FILE "../tests/output.txt"

using namespace std;


const UTYPE inf = INT_MAX;


/*                          __Data_Struct__                       */

template <typename data> class DataStruct
{

public:
    DataStruct() = default;
    explicit DataStruct(UTYPE n){};
    explicit DataStruct(vector<data> v){};
    DataStruct(data* v, UTYPE n){}; //
    ~DataStruct(); //

    void print(); // output the items to console. separate by 'space'
    bool is_item_present(data p); // true if  item present in data struct


    virtual bool append(data p) = 0; // append  to items
    virtual long find(data p) = 0; // find index in items, returns -1 if  is not present
    virtual bool remove(data p) = 0; // delete item from struct
    virtual data pop() = 0; // return min of items
    virtual bool is_empty() = 0; // return true if the struct is empty

protected:
    vector<data> items; // field - vector of items in data struct

};

template<typename data>
void DataStruct<data>::print()
{
    for (UTYPE i = 0; i < items.size(); i++)
    {
        // output
        cout << items[i] << " ";
    }
    cout << endl;

}

template<typename data>
bool DataStruct<data>::is_item_present(data p)
{
    return find(p) != -1; // present if it's index not equals to -1
}

template<typename data>
DataStruct<data>::~DataStruct()
{
    this->items.clear();
}

/*
 * Explanation:
   * abstract class DataStruct
   * interface for data structures Heap and SegmentTree
   */




/*                          __Data_Struct__                       */


#endif //PROJECT_DATASTRUCT_H