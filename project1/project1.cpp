#include "pch.h"

using namespace std;

void testCopyConstructor(Sequence);

int main(){
	
	try
	{
		/* sequence copy test*/
			Sequence data(4);

			data[0] = 100;
			data[1] = 200;
			Sequence data2(data);
			data[0] = 0;
			cout << data2[0] << "  sequence copied successfully?"<<endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	try{
		
			/* sequence assignment operator test*/
			Sequence data(2);

			data[0] = 100;
			data[1] = 200;
			Sequence data2=data;
			data[0] = 0;
			cout << data2[0] << "  sequence assignment  worked successfully?"<<endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	try{
			Sequence data(4);
			
			data[0] = 100;
			data[1] = 200;
			
			cout << "before calling testCopyConstructor: " << data << endl;
			testCopyConstructor(data);
			cout << "after calling testCopyConstructor: " << data << endl;
		
	}
	catch (exception& e)
	{
			cout << "Exception: " << e.what() << endl;
	}
		//this looks like bounce check block 
		{
		/*	Sequence data(4);
			data[5] = 100;*/
		}
		
		
		//push back method test method 
	try{
		
			Sequence data(1);
			data[0] = 0;
			data.push_back(100);
			cout << "is the push back method work" <<data[1]<<endl;
		
	}
	catch (exception& e)
	{
			cout << "Exception: " << e.what() << endl;
	}
		//at member function test method
	try{
			Sequence data(2);
			data[0] = 100;
			cout << "At method works ? " << data.at(0);
			cout << "At method fails?" << data.at(2);
	}
	catch (exception& e)
	{
			cout << "Exception: " << e.what() << endl;
	}

	// pop back member function test method
	try {

			Sequence data(2);
			data[0] = 100;
			data[1] = 200;
			data.pop_back();
			cout << "popback function test" << endl;
			cout << "value at index 0 is" << data[0] << endl;
			cout << "end of popack test" << endl;
			cout << "after pop size reduced from 2 to" << data.size()<<endl;
			cout << "did i get invalid index " << data[1] << endl;
	}
	catch (exception& e){
			cout << "Exception: " << e.what() << endl;
	}


	try {

			Sequence data(2);
			data[0] = 100;
			data[1] = 200;
			cout << "data in front" << data.front()<<endl;
			cout << "data in back" << data.back() << endl;
	}
	catch (exception& e){
			cout << "Exception: " << e.what() << endl;
	}

	try {

			Sequence data(0);
		
			cout << "is sequence empty " << data.empty()<< endl;
			data.push_back(100);
			cout << "is sequence empty " << data.empty() << endl;

	}
	catch (exception& e){

		cout << "Exception: " << e.what() << endl;
	}

	try {

		Sequence data(1);
		data[0] = 1;
		cout << data[0];
		data.clear();
		cout << "hi";
	//	cout << "is sequence clean " << data.empty() << endl;

	}
	catch (exception& e){
		cout << "Exception: " << e.what() << endl;
	}

	try{

		Sequence data(3);
		data[0] = 1;
		data[1] = 1;
		data[2] = 1;
		data.insert(1, 3);
		cout << "data after insert" << data[1]<<endl;
		cout << "data after insert" << data[0]<< "---------- " <<data[1]<< "----- "<<data[2]<<" ------------" <<data[3]<< endl;
		data.insert(0, 3);
		cout << "data after insert" << data[0] << "---------- " << data[1] << "----- " << data[2] << " ------------" << data[3] << " ------------" << data[4] << endl;
		data.insert(4, 3);
		cout << "data after insert" << data[0] << "---------- " << data[1] << "----- " << data[2] << " ------------" << data[3] << " ------------" << data[4] << " ------------" << data[5] << endl;

	}
	catch (exception& e){
		cout << "Exception: " << e.what() << endl;
	}

	try {

		Sequence data(6);
		data[0] = 0;
		data[1] = 1;
		data[2] = 2;
		data[3] = 3;
		data[4] = 4;
		data[5] = 5;
		data.erase(2, 2);
		cout << "data after erase" << data[0] << "---------- " << data[1] << "----- " << data[2] << " ------------" << data[3] << " ------------"  << endl;

	}
	catch (exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
}

void testCopyConstructor(Sequence s)
{
	cout << "inside testCopyConstructor: " << s << endl;
	s[0] = -1;
}