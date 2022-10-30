#include <iostream>

using namespace std;

int main()
{
    string word, word1, output;
    bool finished = false;
    bool isY = false;

    cin >> word;

    for (int i = 0; i < 7; i++)
    {
        isY = false;
        output = "";
        cin >> word1;

        if (word == word1)
        {
            cout << "WINNER"
                 << "\n";
            return 0;
        }
        else
        {
            if (i == 6){
                        cout << "LOSER\n";
                        return 0;
                    } 
            for (int i = 0; i < 5; i++)
            {
                isY = false;
                if (word[i] == word1[i])
                {
                    output += "G";
                }
                else
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (word[j] == word1[i])
                        {
                            output += "Y";
                            isY = true;
                            j = 5;
                        }
                    }
                    if (!isY)
                    {
                        output += "X";
                    }
                }
            }
        }
        cout << output << "\n";
    }

    cout << "LOSER"
         << "\n";
    return 0;
}