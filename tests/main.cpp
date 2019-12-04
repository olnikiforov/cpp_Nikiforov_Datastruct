/// Data_Struct
////Variant 5
////
//// Created on 17.11.2019
//// by student of mech-math faculty
//// KNU named Tarasa Shevchenco
//// Nikiforov Oleksandr

#include "../src/SegmentTree.hxx"
#include "../src/Heap.hxx"


/*                      __TESTS__                       */


string test_SegmentTree(bool console_inp)
{
    SegmentTree<int> sTree;
	if (console_inp) sTree.read_console(); // input from console
	else sTree.read_file(); // input from file

	sTree.append(-65); // test append
	sTree.append(10);
	sTree.remove(-65); // test remove

	if (sTree.is_empty())
	{
		// test is_empty()
		throw logic_error("TEST ERROR");
	}

	if (!sTree.is_item_present(10))
	{
		// test is_item_present()
		throw logic_error("TEST ERROR");
	}

	sTree.update(10, 20); // test update

	string _output = "Test SegmentTree: " + to_string(sTree.pop());

	return _output;
}


string test_Heap(bool console_inp)
{
	Heap<int> s;
	if (console_inp)
	{
		s.read_console(); // input from console
	}
	else
	{
		s.read_file(); // input from file
	}

	s.append(-65); // test append
	s.append(10);
	s.remove(-65); // test remove

	if (s.is_empty())
	{
		// test is_empty()
		throw logic_error("TEST ERROR");
	}

	if (!s.is_item_present(10))
	{

		// test is_item_present()
		throw logic_error("TEST ERROR");
	}

    string _output = "Test Heap: " + to_string(s.pop());

	return _output;
}


int main()
{
	// test

	_clear(); // clear output files

	bool console_in, console_out;
	cout << "hello! enter the way you want test:" << endl;
    cout << "-- -- 1 : CONSOLE INPUT METHOD\n" <<
            "-- -- 0 : FILE INPUT METHOD\n";
    cout << "Your choice for input: ";
    cin >> console_in;
    cout << "\n-- -- 1 : CONSOLE OUTPUT METHOD\n" <<
            "-- -- 0 : FILE OUTPUT METHOD\n";
    cout << "Your choice for output: ";
	cin >> console_out;

	string heapTest = test_Heap(console_in);
	string segmentTreeTest = test_SegmentTree(console_in);


    if (console_out)
    {
        cout << heapTest << endl << segmentTreeTest;
    }
    else
    {
        ofstream file_out(OUTPUT_FILE);
        file_out << heapTest << endl << segmentTreeTest;;
    }

	if (!heapTest.empty() && !segmentTreeTest.empty())
	{
		cout << endl << "that's done! congratulations!" << endl;
	}

	return 0;
}

/*                      __TESTS__                       */