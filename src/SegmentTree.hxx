/// Data_Struct
////Variant 5
////
//// Created on 17.11.2019
//// by student of mech-math faculty
//// KNU named Tarasa Shevchenco
//// Nikiforov Oleksandr

#ifndef DATASTRUCT_SEGMENTTREE_H
#define DATASTRUCT_SEGMENTTREE_H

#include "DataStruct.hxx"
#include <algorithm>


/*                       __SEGMENT TREE__                   */



template <typename data> class SegmentTree: public DataStruct<data>
{
public:
    SegmentTree() = default;
    explicit SegmentTree(UTYPE n);
    explicit SegmentTree(vector<data> v);
    SegmentTree(data*v, UTYPE n);
    bool append(data p);
    long find(data p);
    bool remove(data p);
    data pop();
    bool is_empty();
    void update(data old, data n);
    bool read_console();
    bool read_file();
    bool pop_file();
};

template<typename data>
// returns the number of elements in a full binary tree
SegmentTree<data>::SegmentTree(data *v, UTYPE n)
{
    UTYPE k = find_num_items(n);
    this->items.resize(k, inf); // fill the max value  and resize the field
    UTYPE j = 0;
    for (UTYPE i = k - n; i < k; i++)
    {
        this->items[i] = v[j];
        j++;
    }
    // fill the tree
    for (UTYPE i = k - k/2 - 1; i > 0; i--)
    {
        this->items[i] = min(this->items[2*i], this->items[2*i+1]);
    }
}

template<typename data>
SegmentTree<data>::SegmentTree(UTYPE n)
{
    // resize
    this->items.resize(find_num_items(n), inf);
}

// returns the number of elements in a full binary tree
template<typename data>
SegmentTree<data>::SegmentTree(vector<data> v)
{
    UTYPE n = v.size();
    UTYPE k = find_num_items(n); // fill the max value  and resize the field
    this->items.resize(k, inf);
    UTYPE j = 0;
    for (UTYPE i = k - n; i < k; i++)
    {
        // fill leafs with elements from a vector
        this->items[i] = v[j];
        j++;
    }
    // fill the tree
    for (UTYPE i = k - k/2 - 1; i > 0; i--)
    {
        this->items[i] = min(this->items[2*i], this->items[2*i+1]);
    }
}

// append item  to a tree
template<typename data>
bool SegmentTree<data>::append(data p)
{
    vector<data> n; // create vector
    UTYPE k = this->items.size();
    for (UTYPE i = k - k / 2; i < k; i++)
    {
        if (this->items[i] != inf){
            //delete all items
            n.push_back(this->items[i]);
        }
    }
    // build tree again

    n.push_back(p);
    UTYPE n1 = n.size();
    UTYPE k1 = find_num_items(n1);
    this->items.resize(k1, inf);
    UTYPE j = 0;
    for (UTYPE i = k1 - n1; i < k1; i++)
    {
        this->items[i] = n[j];
        j++;
    }

    for (UTYPE i = k1 - k1/2 - 1; i > 0; i--)
    {
        this->items[i] = min(this->items[2*i], this->items[2*i+1]);
    }

    return true;
}

// returns the index of item, in other way: -1
template<typename data>
long SegmentTree<data>::find(data p)
{
    long index = -1; // -1 as other way
    UTYPE n = this->items.size();
    for (UTYPE i = n - n / 2; i< n; i++)
    {
        // search by leaves
        if (this->items[i] == p)
        {
            // changing index
            index = i;
            break;
        }
    }
    return index;
}

// update old item to a new item
template<typename data>
void SegmentTree<data>::update(data old, data n)
{
    long i = this->find(old); // find the index of old item
    if (i != -1)
    {
        this->items[i] = n; // change and sift
        while (i /= 2)
        {
            // update values
            this->items[i] = min(this->items[2 * i], this->items[2 * i + 1]);
        }
    }
}

template<typename data>
bool SegmentTree<data>::remove(data p)
{
    // remove the item p
    this->update(p, inf); // update it's value to inf
    return true;
}

// find minimum
template<typename data>
data SegmentTree<data>::pop()
{
    // empty check
    if (this->is_empty())
    {
        throw length_error("EMPTY STRUCT!");
    }
    return this->items[1]; // return the root
}

template<typename data>
bool SegmentTree<data>::is_empty()
{
    return 2 > this->items.size();
}

// read from console
template<typename data>
bool SegmentTree<data>::read_console()
{
    string input;

    cout << "Enter the elements of SEGMENT TREE," << "\ntype 'stop' to exit input mode:" << endl;

    vector<data> v;

    // read data
    while (true)
    {
        cin >> input;
        if (input == "stop") break;

        v.push_back(atoi(input.c_str())); //push to vector

    }

    // then identically to constructor
    UTYPE n = v.size();
    UTYPE k = find_num_items(n);
    this->items.resize(k, inf);

    UTYPE j = 0;
    for (UTYPE i = k - n; i < k; i++)
    {
        this->items[i] = v[j];
        j++;
    }

    for (UTYPE i = k - k/2 - 1; i > 0; i--)
    {
        this->items[i] = min(this->items[2*i], this->items[2*i+1]);
    }
    return true;
}

// read from file
template<typename data>
bool SegmentTree<data>::read_file()
{
    ifstream fin(INPUT_FILE);
    string buff;
    vector<data> v;
    while (!fin.eof())
    {
        getline(fin, buff);
        // separate them by 'space'
        char* str = (char*) malloc(sizeof(char) * buff.length());
        char sep[10] = " ";

       for (UTYPE i = 0; i < buff.length(); i++)
       {
            str[i] = buff[i];
        }

       char* istr;
       istr = strtok (str,sep);
       // selection of subsequent parts
        UTYPE i = 0;
        while (istr != NULL)
        {
            v.push_back(atoi(istr));
            // conclusion of the next selected part
            istr = strtok (NULL, sep);
            i++;
        }

    }
    fin.close(); // close the file

    UTYPE n = v.size();
    UTYPE k = find_num_items(n);
    this->items.resize(k, inf);
    UTYPE j = 0;
    for (UTYPE i = k - n; i < k; i++)
    {
        this->items[i] = v[j];
        j++;
    }
    for (UTYPE i = k - k/2 - 1; i > 0; i--)
    {
        this->items[i] = min(this->items[2*i], this->items[2*i+1]);
    }
    return true;
}
/*
 * Explanation:
   * Let's get an array of T [2n - 1]. The root will lie in the first element of the array,
   * and the sons of the i-th vertex will lie in the elements
   * with numbers 2i and 2i + 1 - left and right, respectively.
   * Immediately you can notice the obvious property:
   * T [i] = min (T [2i], T [2i + 1]) for the i-th vertex,
   * which is not a leaf. Sheets, by the way, will lie with this
   * numbering in the elements with numbers from n to 2n - 1.
   */

/*                       __SEGMENT TREE__                   */

#endif //DATASTRUCT_SEGMENTTREE_H