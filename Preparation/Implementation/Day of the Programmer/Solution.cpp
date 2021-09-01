#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const int PROGRAMMER = 256;
const int JAN_TO_AUG = 243;

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    int days = JAN_TO_AUG;
    
    //Determine what calendar is used
    bool julian = year <= 1917;
    //Determine if it's a leap year
    bool leap = (julian && year % 4 == 0) || (!julian && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)));
    
    //Account for days in leap year
    if(leap)
    {
        days ++;
    }
    //Account for loss of days during calendar switch 
    if(year == 1918)
    {
        days -= 13;
    }
    
    return to_string(PROGRAMMER - days) + ".09." + to_string(year);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
