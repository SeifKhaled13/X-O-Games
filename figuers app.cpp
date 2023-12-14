// File name:A3_SheetPb1_20220053.cpp
// Purpose: to make figures app for only string and text files from local
// Author(s): Osama Eslam Bayomi
// ID(s):20220053
// Section: s2
// Date: 6/12/2023

#include <bits/stdc++.h>

using namespace std;

class LabelGenerator
{
protected:
  string name;
  int num;
  string newName = "";

public:
  LabelGenerator()
  {
    name = "", num = 0;
  }
  LabelGenerator(string name, int num)
  {
    this->name = name;
    this->num = num;
  }
  virtual string nextLabel()
  {
    string s = to_string(num); // make the number into string to be able to add it to the label
    newName = name + s;        // add the label name and then add the number to it
    num++;
    return newName;
  }
};

class FileLabelGenerator : public LabelGenerator
{
protected:
  string fileName;
  int desiredLineNumber = 1;
  int currentLineNumber = 1;

public:
  FileLabelGenerator()
  {
    fileName = "";
    name = "";
    num = 0;
  }
  FileLabelGenerator(string nName, int nNum, string nFileName)
  {
    fileName = nFileName;
    name = nName;
    num = nNum;
  }
  virtual string nextLabel()
  {
    ifstream file("text.txt");
    string line;
    while (currentLineNumber < desiredLineNumber && getline(file, line))
    {
      currentLineNumber++;
    }
    while (getline(file, line))
    {
      string s = to_string(num);
      newName = name + s;
      num++;
      newName += " " + line;
      desiredLineNumber++;
      currentLineNumber = 1;
      return newName;
    }
    return newName;
  }
};

int main()
{
  FileLabelGenerator figureLabels("Figure ", 1, "text.txt");
  cout << "Figure labels: \n";
  for (int i = 0; i < 5; i++)
  {
    cout << figureLabels.nextLabel() << endl;
  }
  LabelGenerator fi("fi", 0);
  for (size_t i = 0; i < 3; i++)
  {
    cout << fi.nextLabel() << " ";
  }
}

// Version : 1.0