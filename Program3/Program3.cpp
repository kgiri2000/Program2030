#include<iostream>
#include<string>
#include "myHashClass.cpp"
#include<fstream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include"timer.h"

using namespace std;
string cleanWord(string unclean);

int main() {

	//Class objects
	myHashClass<string> hash1;
	Timer tTimer;

	//valriables decleration and initilization
	int matched = 0;
	int unmatched = 0;
	int notchecked = 0;
	int successC = 0;
	int unsuccessC = 0;
	

	//storing the dict 
	ifstream mydict;
	mydict.open("dict.txt");
	if (!mydict) {
		cerr << "Can't Open the file" << endl;
		mydict.close();
		mydict.clear();
		return 0;

	}
	string ddata;
	while (mydict >> ddata) {
		string clean = cleanWord(ddata);
		hash1.insert(clean);
		
	}

	//Reading book
	ifstream mybook;
	ofstream oFile;
	oFile.open("mispelled.txt");
	mybook.open("book.txt");
	if (!mybook) {
		cout << "Can't Open the file" << endl;
		mybook.close();
		mybook.clear();
	}

	//Working with books
	tTimer.Start();
	string bookText;
	while (mybook >> bookText) {
		string bclean = cleanWord(bookText);
		if (isalpha(bclean[0])) {
			int compares = 0;
			if (hash1.find(bclean, compares)) {
				matched++;
				successC +=compares;
			}
			else if (!(hash1.find(bclean, compares))) {
				oFile << bclean;
			}
			else {
				unmatched++;
				unsuccessC += compares;
			}
		}
		else if (!(bclean.empty())) {
			notchecked++;

		}
	}
	mybook.close();
	mybook.clear();
	oFile.close();
	tTimer.Stop();


	//Output
	cout << "dictionary size " << hash1.getSize() << endl;


	return 0;
}


string cleanWord(string unclean)
{
	int size = unclean.length();
	string cleanWord = "";
	char c;
	for (int i = 0; i < size; i++)
	{
		if (isalpha(unclean[i]) || unclean[i] == '\'')  // Using the escape sequence for apostrophe
		{
			c = tolower(unclean[i]);
			cleanWord = cleanWord + c;
		}
	}
	return cleanWord;
}