#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//prerelease mode
//#define PRERELEASE

struct STUDENT_DATA
{
	string firstname;
	string lastname;

	//email only available in prerelease ver.
#ifdef PRERELEASE
	string email;
#endif

};

int main()
{
	//announce which version is running
#ifdef PRERELEASE
	cout << "Running in pre-release mode" << endl;
#else
	cout << "Running in standard mode" << endl;
#endif

	fstream newfile;
	vector<STUDENT_DATA> students;
#ifdef PRERELEASE
	newfile.open("C:\\Users\\Mason\\Downloads\\StudentData_Emails.txt", ios::in); //open the emails file
#else
	newfile.open("C:\\Users\\Mason\\Downloads\\StudentData.txt", ios::in); //open the data file
#endif

	//reading the file and saving the names in the vectors
	if (newfile.is_open())
	{
		string studentnames;
		while (getline(newfile, studentnames)) //read each line in the file
		{
			stringstream ss(studentnames);
			string first;
			string last;
			int firstiteration = 0;
			STUDENT_DATA student;

			//parse each line
			while (!ss.eof())
			{
				if (firstiteration == 0) //if it's the first word in the string...
				{
					getline(ss, last, ','); 
					student.lastname = last;
				}
				else if (firstiteration == 1) //if it's not the first word in the string...
				{
					getline(ss, first, ',');
					student.firstname = first;
#ifdef PRERELEASE
					//do nothing, don't push_back yet
#else
					students.push_back(student); //put student in vector
#endif
				}
#ifdef PRERELEASE
				else if (firstiteration == 2)
				{
					string emails;
					getline(ss, emails, ',');
					student.email = emails;
					students.push_back(student);
				}
#endif
				firstiteration ++; //after it has run once, set it to false
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
#ifdef PRERELEASE
		//print this in debug prerelease
		cout << students[i].lastname << " ";
		cout << students[i].email << endl;
#else
		//print this in standard debug
		cout << students[i].lastname << endl;
#endif
	}
#endif

}