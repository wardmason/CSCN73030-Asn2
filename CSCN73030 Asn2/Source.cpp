#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	fstream newfile;
	vector<string> firstnames;
	vector<string> lastnames;
	newfile.open("C:\\Users\\Mason\\Downloads\\StudentData.txt", ios::in); //open the file

	//reading the file and saving the names in the vectors
	if (newfile.is_open())
	{
		string studentnames;
		while (getline(newfile, studentnames)) //read each line in the file
		{
			stringstream ss(studentnames);
			string first;
			string last;
			bool firstiteration = true;
			
			//parse each line
			while (!ss.eof())
			{
				if (firstiteration) //if it's the first word in the string...
				{
					getline(ss, last, ','); 
					lastnames.push_back(last); //put the last name in the vector 
				}
				else //if it's not the first word in the string...
				{
					getline(ss, first, ',');
					firstnames.push_back(first); //put the first name in the vector
				}

				firstiteration = false; //after it has run once, set it to false
			}
		}
		newfile.close();
	}
	else
	{
		cout << "failed to open file" << endl;
		return 1;
	}

	for (int i = 0; i < 33; i++)
	{
		cout << firstnames[i] << " ";
		cout << lastnames[i] << endl;
	}

}