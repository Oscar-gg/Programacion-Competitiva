#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d;
    if (a <= c)
    {
        while (a <= c)
        {
            if (a + b <= c)
            {
                a = a + b;
                e = a;
            }
            else
            {
                e = c;
                break;
            }

            if (c - d >= a)
            {
                c = c - d;
                e = c;
            }
            else
            {
                e = a;
                break;
            }
        }
        cout << e << endl;
    }
    else
        cout << a << endl;
    return 0;
}