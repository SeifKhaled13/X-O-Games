// File name:A3_SheetPb4_20220053.cpp
// Purpose: to make set template using classes
// Author(s): Osama Eslam Bayomi
// ID(s):20220053
// Section: s2
// Date: 6/12/2023
#include <bits/stdc++.h>
using namespace std;

template <class T>

class Set
{
protected:
  T object;
  deque<T> objectList;
  long long size = objectList.size();

public:
  Set()
  {
    objectList = {};
  }
  void insert(T o)
  {
    // check if the object is found to add it
    auto it = find(objectList.begin(), objectList.end(), o);
    if (it == objectList.end())
      objectList.push_back(o);
    // to sort after each insertion
    sort(objectList.begin(), objectList.end());
    size = objectList.size();
  }
  void erase(T o)
  {
    // to check if the object is found and then delete it
    auto it = find(objectList.begin(), objectList.end(), o);
    if (it != objectList.end())
      objectList.erase(it);
    sort(objectList.begin(), objectList.end());
    size = objectList.size();
  }
  int showSize()
  {
    size = objectList.size();
    return size;
  }
  bool Find(T o)
  {
    // to tell if the object is found
    auto it = find(objectList.begin(), objectList.end(), o);
    if (it != objectList.end())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  T *dynamicArray()
  {
    // allocate dynamic array with the objectList that i made and copy the objects in it
    T *array = new T[size];
    copy(objectList.begin(), objectList.end(), array);
    return array;
  }
};

int main()
{
  Set<string> my;
  my.insert("name");
  my.insert("ahmed");
  my.insert("mohamed");
  cout << my.showSize() << ' ';
  cout << my.Find("name") << endl;
  my.erase("ahmed");
  string *array = my.dynamicArray();
  for (int i = 0; i < my.showSize(); i++)
  {
    cout << array[i] << ' ';
  }
  delete[] array;
}

// Version : 1.0