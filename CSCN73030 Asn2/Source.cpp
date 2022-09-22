#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct STUDENT_DATA
{
	string firstname;
	string lastname;
};

int main()
{
	fstream newfile;
	vector<STUDENT_DATA> students;
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
			STUDENT_DATA student;

			//parse each line
			while (!ss.eof())
			{
				if (firstiteration) //if it's the first word in the string...
				{
					getline(ss, last, ','); 
					student.lastname = last;
				}
				else //if it's not the first word in the string...
				{
					getline(ss, first, ',');
					student.firstname = first;
					students.push_back(student); //put student in vector
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

#ifdef _DEBUG
	//only do this in debug mode
	for (int i = 0; i < 33; i++)
	{
		cout << students[i].firstname << " ";
		cout << students[i].lastname << endl;
	}
#endif

}