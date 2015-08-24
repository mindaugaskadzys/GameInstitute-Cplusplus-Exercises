#include <fstream>
#include <iostream>
#include <string>
#include "Wizard.h"
#include "Point.h"

using namespace std;

void main()
{
	//Ex 8.5.1 - Line Count
	/*string fileName;
	cout << "Enter a text file: ";
	cin >> fileName;
	ifstream fileStream(fileName);
	
	if (fileStream) {
		int lineCount = 0;
		string line;
		while (!fileStream.eof()) {
			getline(fileStream, line);
			lineCount++;
		}
		cout << fileName << " contained " << lineCount << " lines." << endl;
		fileStream.close();
	}
	else {
		cout << "Could not open " << fileName << "." << endl;
	}*/

	//Ex 8.5.2.1 - Rewrite 8.1 and 8.2 programs to use binary IO
	//Program 8.1 - Saving data to text files
	// Create wizards with specific data.
	/*Wizard wiz0("Gandalf", 25, 100, 10);
	Wizard wiz1("Loki", 50, 150, 12);
	Wizard wiz2("Magius", 10, 75, 6);
	// Create a stream which will transfer the data from
	// our program to the specified file "wizdata.tex".
	ofstream outFile("wizdata.bin", ios_base::binary);
	// If the file opened correctly then call save methods.
	if (outFile)
	{
		// Dump data into the stream.
		wiz0.save(outFile);
		wiz1.save(outFile);
		wiz2.save(outFile);
		// Done with stream--close it.
		outFile.close();
	}

	//Program 8.2 - Loading data from text files
	// Create some 'blank' wizards, which we will load
	// data from file into.
	Wizard wiz3;
	Wizard wiz4;
	Wizard wiz5;
	// Output the wizards before they are loaded.
	cout << "BEFORE LOADING..." << endl;
	wiz3.print();
	wiz4.print();
	wiz5.print();
	// Create a stream which will transfer the data from
	// the specified file "wizdata.txt" to our program.
	ifstream inFile("wizdata.bin", ios_base::binary);
	// If the file opened correctly then call load methods.
	if (inFile)
	{
		wiz3.load(inFile);
		wiz4.load(inFile);
		wiz5.load(inFile);
		inFile.close();
	}
	// Output the wizards to show the data was loaded correctly.
	cout << "AFTER LOADING..." << endl;
	wiz3.print();
	wiz4.print();
	wiz5.print();*/

	//Ex 8.5.2.2 - Rewrite programs 8.3 and 8.4 using text IO
	//Program 8.3 - saving binary data to file
	// Create 8 points to define a unit cube.
	/*Point3 cube[8];
	cube[0] = Point3(-1.0f, -1.0f, -1.0f);
	cube[1] = Point3(-1.0f, 1.0f, -1.0f);
	cube[2] = Point3(1.0f, 1.0f, -1.0f);
	cube[3] = Point3(1.0f, -1.0f, -1.0f);
	cube[4] = Point3(-1.0f, -1.0f, 1.0f);
	cube[5] = Point3(-1.0f, 1.0f, 1.0f);
	cube[6] = Point3(1.0f, 1.0f, 1.0f);
	cube[7] = Point3(1.0f, -1.0f, 1.0f);
	// Create a stream which will transfer the data from
	// our program to the specified file "pointdata.tex".
	// Observe how we add the binary flag modifier
	// ios_base::binary.
	ofstream outFile("pointdata.txt");
	// If the file opened correctly then save the data.
	if (outFile)
	{
		// Dump data into the stream in binary format.
		// That is, stream the bytes of the entire array.
		for (int i = 0; i < 8; i++) {
			outFile << cube[i].mX << " " << cube[i].mY << " " << cube[i].mY << endl;
		}
		// Done with stream--close it.
		outFile.close();
	}*/

	//Program 8.4 - Loading binary data from file
	Point3 cube[8];
	cout << "BEFORE LOADING..." << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << "cube[" << i << "] = ";
		cout << "(";
		cout << cube[i].mX << ", ";
		cout << cube[i].mY << ", ";
		cout << cube[i].mZ << ")" << endl;
	}
	// Create a stream which will transfer the data from
	// the specified file "pointdata.txt" to our program.
	// Observe how we add the binary flag modifier
	// ios_base::binary.
	ifstream inFile("pointdata.txt");
	// If the file opened correctly then call load methods.
	if (inFile)
	{
		// Stream the bytes in from the file into our
		// program array.
		for (int i = 0; i < 8; i++) {
			inFile >> cube[i].mX;
			inFile >> cube[i].mY;
			inFile >> cube[i].mZ;
		}
		// Done with stream--close it.
		inFile.close();
	}
	// Output the points to show the data was loaded correctly.
	cout << "AFTER LOADING..." << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << "cube[" << i << "] = ";
		cout << "(";
		cout << cube[i].mX << ", ";
		cout << cube[i].mY << ", ";
		cout << cube[i].mZ << ")" << endl;
	}
}