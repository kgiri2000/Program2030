// Program03.cpp
// Kamal Giri


#include "timer.h"
#include "myHashClass.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace::std;
using std::string;

string cleanWord(string word);

int main()
{
	//Class Decleration
	Timer myTimer;
	myHashClass<string> hash1;


	      
	      
	int missed = 0;				
	int successC = 0;		
	int unsuccessC = 0;	
	int matched = 0;				
	int unmatched = 0;			

	ifstream dictFile("dict.txt");                        
	if (!dictFile)                                      
	{
		cerr << "Error finding dictionary file.\nMake sure the file is in the right directory!" << endl;
		dictFile.close();
		dictFile.clear();
	}
	else {
		string dictWord;
		while (dictFile >> dictWord)
		{
			hash1.insert(cleanWord(dictWord));          
		}
		dictFile.close();
		dictFile.clear();
		myTimer.Start();                                      
		ifstream bookFile("book.txt");                        
		if (!bookFile)                       	              
		{
			cerr << "Error finding book file.\nMake sure the file is in the right directory!" << endl;
			bookFile.close();
			bookFile.clear();
		}
		else {
			string bookWord;
			while (bookFile >> bookWord)
			{

				string clean = cleanWord(bookWord);
				if (isalpha(clean[0]))
				{
					int compares = 0;
					if (hash1.find(clean, compares))
					{
						matched++;
						successC = successC + compares;
					}
					else
					{
						unmatched++;
						unsuccessC = unsuccessC + compares;
					}
				}
				else if (!clean.empty())
				{
					missed++;
				}
			}
				myTimer.Stop();
				bookFile.close();
				bookFile.clear();

				ifstream book("book.txt");
				ofstream oFile;
				oFile.open("mispelled.txt");
				string word;

				while (book >> word)
				{
					string clean = cleanWord(word);
					if (isalpha(clean[0]))
					{
						int compares = 0;
						if (!hash1.find(clean, compares))
						{
							oFile << clean << endl;
						}
					}
				}
				bookFile.close();
				bookFile.clear();
				oFile.close();
				oFile.clear();
				// Displaying the output in correct format.
				cout << "dictionary size " << hash1.getSize() << endl;
				cout << "Done Checking and these are the results:" << endl;
				cout << "Finished in time: " << myTimer.Time() << endl;
				cout << "Finished in Milliseconds Time: " << fixed << setprecision(2) << myTimer.TimeMS()<< endl;
				cout << "There are " << matched << " words found in the dictionary" << endl;
				cout << "\t\t" << successC << " compares. Average: " << successC / matched << endl;
				cout << "There are " << unmatched << " words NOT found in the dictionary" << endl;
				cout << "\t\t" << unsuccessC << " compares. Average: " << fixed << setprecision(3) << 1.0 * unsuccessC / unmatched << endl;
				cout << "There are " << missed << " words not checked." << endl;
				
				

		}
	}
	return 0;
}

string cleanWord(string word)                     // Cleanword function
{
	int size = word.length();
	string cleanWord = "";
	char c;
	for (int i = 0; i < size; i++)
	{
		if (isalnum(word[i]) || word[i] == '\'')    // Using the escape sequence for apostrophe
		{
			c = tolower(word[i]);
			cleanWord = cleanWord + c;
		}
	}
	return cleanWord;
}
