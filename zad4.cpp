#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

vector < string > input[200], tab[200];
string tmp;
set < unsigned int > lenght_test;
set < string > anagram_test;
vector < vector < string > > solution_4a, solution_4b;

void load_data()
{
    fstream file;
    file.open("anagram.txt");
    for(int i = 0; i < 200; i ++)
    {
        for(int j = 0; j < 5; j ++)
        {
            file >> tmp;
            input[i].push_back(tmp);
            sort(tmp.begin(), tmp.end());
            tab[i].push_back(tmp);
        }
    }
    file.close();
}

void task_4a()
{
    for(int i = 0; i < 200; i ++)
    {
        lenght_test.clear();
        for(int j = 0; j < 5; j ++)
            lenght_test.insert(tab[i][j].size());
        if(lenght_test.size() == 1)
            solution_4a.push_back(input[i]);
    }
}

void task_4b()
{
    for(int i = 0; i < 200; i ++)
    {
        anagram_test.clear();
        for(int j = 0; j < 5; j ++)
            anagram_test.insert(tab[i][j]);
        if(anagram_test.size() == 1)
            solution_4b.push_back(input[i]);
    }
}

void print_solution()
{
    cout << "Zadanie 4 : \n"
         << "   a)\n";
    for(unsigned int i = 0; i < solution_4a.size(); i ++)
    {
        for(int j = 0; j < 5; j ++)
            cout << "       " << solution_4a[i][j] << " ";
        cout << endl;
    }
    cout << "   b)\n";
    for(unsigned int i = 0; i < solution_4b.size(); i ++)
    {
        for(int j = 0; j < 5; j ++)
            cout << "       " << solution_4b[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    load_data();
    task_4a();
    task_4b();
    print_solution();

    return 0;
}
