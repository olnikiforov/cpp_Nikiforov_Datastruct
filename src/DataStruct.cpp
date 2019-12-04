/// Data_Struct
////Variant 5
////
//// Created on 17.11.2019
//// by student of mech-math faculty
//// KNU named Tarasa Shevchenco
//// Nikiforov Oleksandr

#include "DataStruct.hxx"


UTYPE find_num_items(UTYPE n)
{
    // returns the number of elements in a complete binary tree in which n sheets
    UTYPE value = 1;
    while (value < n)
    {
        value *=2; // the nearest degree 2 is greater than or equal to n
    }
    return 2 * value; // returns 2 * n
}

bool _clear()
{
    // clear the log and the output files

    ofstream _file_out(OUTPUT_FILE);
    _file_out.clear();
    _file_out.close();

    return true;
}