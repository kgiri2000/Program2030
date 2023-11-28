#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<vector>
#include"timer.h"
#include "BinarySearchTree.cpp"

using namespace std;

string cleanWord(string checkWord);

int main()
{

	//variables declerations
	long long int notcheck = 0;
	long long int matched = 0;
	long long int unmatched = 0;
	Timer tTimer;

	//class initialization
	BinarySearchTree<string> dict;
	ifstream iFile;
	iFile.open("dict.txt");
	if (!iFile) {
		cerr << "Dictionary address is incorrect";
		iFile.close();
		iFile.clear();
	}
	string idata;
	 while(!iFile.eof()) {
		iFile >> idata;
		string clean = cleanWord(idata);
		dict.insert(clean);
	}
	iFile.close();
	iFile.clear();

	//Working with books
	tTimer.Start();
	
	ofstream oFile;
	oFile.open("misspelled.txt");
	ifstream bookFile;
	bookFile.open("book.txt");
	while (!bookFile) {
		cerr << "Book address is incorrect";
		bookFile.close();
		bookFile.clear();
	}
	string bookText;
	char a = '\'';
	while (bookFile) {
		bookFile >> bookText;
		string clean1 = cleanWord(bookText);
		if (clean1.size() != 0) {
			if (!(isalpha(clean1[0]))) {
				notcheck++;
			}
			else if (dict.find(clean1)) {
				matched++;

			}
			else if (!(dict.find(clean1))) {
				unmatched++;
				oFile << clean1 << endl;
			}

		}


	}

	void BinarySearchTree<T> ::remove(T item, BinaryNode<T>*&t)
	bookFile.close();
	bookFile.clear();
	oFile.close(); 
	tTimer.Stop();







	//Printing the results
	
	cout << "dictionary size  "<<dict.getSize() << endl;
	cout << "Done checking and these are the results" << endl;
	cout << "Finished in time:  " << tTimer.Time() << endl;
	cout << "There are " << matched << " words  found in dictionary" << endl;
	cout << "There are " << unmatched << " words not found in dictionary" << endl;
	cout << "Ther are " << notcheck << " words not checked" << endl;











	//dict.prePrint();
	if (dict.find("kamal")) {
		cout << "hello World" << endl;
	}
	else {
		cout << "Fuk!!" << endl;
	}


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