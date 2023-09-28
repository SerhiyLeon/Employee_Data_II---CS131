// P5 - Employee Data
// Serhiy Leonchyk
// This Program Will Read input of Employee Data from a file
// And it will then Sort the Employee Data into order from
// most Hours Worked to least Hours worked
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct Employee {
string name;
int total = 0;
vector <int> hours;
};
int OpenReadFile(vector<Employee>& empInfo);
void SortInfo(vector<Employee> empInfo);
int main() {
vector <Employee> empInfo;
vector<Employee*> empPtr;
int totalEmp = 0;
totalEmp = OpenReadFile(empInfo);
SortInfo(empInfo);
}
int OpenReadFile(vector<Employee>& empInfo)
{
fstream fin;
int totalEmp;
fin.open("empdata3.txt");
fin >> totalEmp;
empInfo.resize(totalEmp);
int* Employee = new int[7];
for (int i = 0; i < totalEmp; ++i)
{
fin >> empInfo.at(i).name;
for (int j = 0; j < 7; ++j)
{
fin >> Employee[j];
empInfo.at(i).hours.push_back(Employee[j]);
empInfo.at(i).total += Employee[j];
}
}
delete[]Employee;
return totalEmp;
}
void SortInfo(vector<Employee> empInfo) {

vector <Employee*> empPtr;
empPtr.resize(empInfo.size());
int mostHours = empInfo.at(0).total;
int leastHours = empInfo.at(0).total;
int currOutput;
int numIterations = empInfo.size();
Employee tempVar;
for (int i = 0; i < empInfo.size(); ++i) {
if (empInfo.at(i).total > mostHours) {
mostHours = empInfo.at(i).total;
}
}
for (int i = 0; i < empInfo.size(); ++i) {
if (empInfo.at(i).total < leastHours) {
leastHours = empInfo.at(i).total;
}
}
currOutput = mostHours;
cout << left << setw(16) << "Name: " << right << setw(3) << "S" << setw(4) <<
"M";
cout << setw(4) << "T" << setw(4) << "W" << setw(4) << "T" << setw(4) << "F";
cout << setw(4) << "S" << setw(7) << "TTL\n";
cout << "-------------------------------------------------\n";
while (numIterations != 0) {
for (int i = 0; i < empInfo.size(); ++i) {
if (empInfo.at(i).total == currOutput) {
cout << left << setw(17) << empInfo.at(i).name << " ";
for (int j = 0; j < 7; ++j) {
cout << setw(4) << empInfo.at(i).hours[j];
}
cout <<empInfo.at(i).total << " " << endl;
--numIterations;
}
}
--currOutput;
}
}
