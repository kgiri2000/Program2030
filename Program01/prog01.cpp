#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<vector>
#include "timer.h"
#include"mylist.cpp"

using namespace std;

string cleanWord(string checkWord);


int main()
{
	myList<string> dict;
	int skipped = 0;
	Timer tTime;

	long long int notcheck=0;
	long long int matched = 0;
	long long int unmatched = 0;
	ifstream iFile;
	iFile.open("dict.txt");
	if (!iFile)
	{
		cerr << "Dictionary address is incorrect." << endl;
		iFile.close();
		iFile.clear();
	}
	string idata;
	while (iFile)
	{
		iFile >> idata;
		string clean = cleanWord(idata);
		dict.insert(clean);
	}

	iFile.close();
	iFile.clear();
	//For the book
	ifstream bookFile;
	ofstream oFile;
	oFile.open("missedword.txt");

	
	bookFile.open("book.txt");
	tTime.Start();
	if (!bookFile) {
		cerr << "Book address incorrrect" << endl;
		bookFile.close();
		bookFile.clear();
	}
	string bookT;
	while (bookFile)
	{
		bookFile >> bookT;
		string clean1 = cleanWord(bookT);
		
		
		if (clean1.size() != 0)
			{
			if (!isalpha(clean1[0]))
			{
				notcheck++;
			}
			else if (dict.findItem(clean1) == true) {
				matched++;
			}
			else if (dict.findItem(clean1) == false) {
					oFile << clean1 << "\n";
					unmatched++;

			}
				
			}
	}
	
	bookFile.close();
	bookFile.clear();
	oFile.close();
	tTime.Stop();

	//Printing the results
	cout << "Dictionary size" << dict.getSize() << endl;
	cout << "Done checking and these are the results" << endl;
	cout << "Finished in time " << tTime.Time() << endl;
	cout << "There are " << matched << " words found in dictionary" << endl;
	cout << dict.getCompares() << " compares. Average: " << dict.getCompares() / matched << endl;
	cout << "There are " << unmatched << " words not checked" << endl;
	cout << dict.getuCompares() << " compares. Average: " << dict.getuCompares() / unmatched << endl;
	cout << "There are " << notcheck << " words not checked" << endl;
	

	return 0;
	
}

string cleanWord(string word)
{
	int size = word.length();
	string cleanWord = "";
	char c;
	for (int i = 0; i < size; i++)
	{
		if (isalpha(word[i]) || word[i] == '\'')  // Using the escape sequence for apostrophe
		{
			c = tolower(word[i]);
			cleanWord = cleanWord + c;
		}
	}
	return cleanWord;
}