#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

  using namespace std;

  string clear_word(const auto&str ){
      string newword;

      for (char c:str){
        if(isalpha(c)||c==' '){
            newword += c;
        }
      }
  return newword;
  }


void make_freq_table(ifstream & file){
    string s;
    vector <string>keys;
    map <string,int> words;

    //get every wordin vector of string

    while (file>> s) {
        keys.push_back(s);
    }


    //count&clear words
    for( auto &word :keys){
        word=clear_word(word);

        words[word]++;

    }
    //clear vector of string
    keys.clear();


        // print frequancey table
        cout<< "key"<<"\t "<<"  value \n";
        for(auto it :words){
        cout <<it.first<<"    "<< it.second<<endl;
        }
    }






int main() {
    //get file name
    string n;
    cout<<"enter file name"<<endl;
    cin>>n;

    //open file
    ifstream file;
    file.open(n+".txt" , ifstream ::in);

    if(file.is_open()) cout<<"opend \n";
    else cout<<"cant reach this file \n";
    //call fun
    make_freq_table(file);

    //close file
    file.close();

}
