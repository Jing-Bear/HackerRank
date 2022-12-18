#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) 
{
    // The middle number must be a 5
    int cost = abs(s[1][1] - 5);
    int min = 100;
    
    vector<int> pattern = {8, 1, 6, 7, 2, 9, 4, 3};
    vector<int> original = {s[0][0], s[0][1], s[0][2], s[1][2], s[2][2], s[2][1], s[2][0], s[1][0]};
    
    for(int i = 0; i < pattern.size(); i += 2)
    {
        int counter = 0;
        for(int j = 0; j < original.size(); j++)
        {
            counter += abs(original[j] - pattern[(j + i) % 8]);
        }
        if(counter < min)
        {
            min = counter;
        }
        
        counter = 0;
        for(int j = 0; j < original.size(); j++)
        {
            counter += abs(original[(original.size() - 2 - j) % 8] - pattern[(j + i) % 8]);
        }
        if(counter < min)
        {
            min = counter;
        }
    }
    
    
    return cost + min;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
