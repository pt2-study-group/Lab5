/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																				   //
// Author               : pt206																												       //
// Day 				    : 03.06.2019																											   //
// file name            : main.cpp																												   //
//																																				   //
// ------------------------------------------------------------------------------------------------------------------------------------------------//		
// A																																			   //
//              _____           _      _     _ _																								   //
//             /  __ \         | |    | |   (_) |																								   //
//             | /  \/ ___   __| | ___| |    _| |_ ___																							   //
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )																							   //
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/																							   //
//              \____/\___/ \__,_|\___\_____/_|\__\___|																							   //
//																																				   //
//                                                  F i l e																						   //
//																																				   //
// 5. Написать программу, читающую из заданного преподавателем двоичного файла массив чисел типа double,										   //
// формирующую   массив   чисел   типа   float   с   обратными																					   //
// значениями   (f(x)=1/x) и записывающую полученный массив в новый двоичный файл.																   //
//																																				   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	{//В задании написано, что преподаватель даст файл, но мне никто ничего не давал, поэтому я сам его сделал.
		const int TEST_ARRAY_SIZE = 10;
		double startArray[TEST_ARRAY_SIZE];
		
		for (int i = 0; i< TEST_ARRAY_SIZE; i++) {
			startArray[i] = rand();
			cout << startArray[i] << "\t" << rand() << endl;
		}
		char * file = "/root/Рабочий\ стол/five";
		ofstream ofs;
		ofs.open(file, ios::binary | ios::trunc | ios::out);
		ofs.write((char*)startArray, TEST_ARRAY_SIZE * sizeof startArray[0]);
		ofs.close();
	}
	
	{
		char * file = "/root/Рабочий\ стол/five";
		
		ifstream ifs;
		ifs.open(file, ios::binary | ios::in);

		ifs.seekg (0, std::ios::end);
			int size = ifs.tellg()/8 ; cout << "size: " << size << endl;
		ifs.seekg(0,ios::beg);
		
		double * doubleArray = new double[size];
		
		ifs.read((char*)doubleArray, size * sizeof doubleArray[0]);
		ifs.close();
		
		float * floatArray = new float[size];
		for (int i = 0; i < size; i++) {
			floatArray[i] = 1/doubleArray[i];
			cout << 1/doubleArray[i] <<  endl;
		}
		cout << "END" << endl;
		delete[] floatArray;
		delete[] doubleArray;
	}
	return 0;
}