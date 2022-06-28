#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> read_input(int, int);
vector<int> read_numbers(int);
bool process(int, int, vector<string>, vector<int> &);
void generate_output(int, vector<int>, bool);

int main()
{
    int num_ofrows, num_ofstages;
    vector<string> rows;
    vector<int> numbers;
    bool error;

    cout << "Enter the number of the rows : ";
    cin >> num_ofrows;
    cout << "\nEnter the number of the stages : ";
    cin >> num_ofstages;
    cout << endl;

    rows = read_input(num_ofrows, num_ofstages);
    numbers = read_numbers(num_ofrows);

    error = process(num_ofrows, num_ofstages, rows, numbers);

    generate_output(num_ofrows, numbers, error);

    system("pause");
    return 0;
}

// az vorodi ghereftan
vector<string> read_input(int n, int m)
{
    vector<string> ar;

    for (int i = 0; i < n; ++i)
    {
        string a1, a2;
        cout << "Enter " << i + 1 << "th row \n";
        cin >> a1;

        a2 = a1.substr(0, m);

        ar.push_back(a2);
    }

    return ar;
}

vector<int> read_numbers(int n)
{
    vector<int> inp;

    for (int i = 0; i < n; i++)
    {
        int b;

        cout << "Enter a number : \n";
        cin >> b;
        inp.push_back(b);
    }
    return inp;
}

// faraiand moratab sazi

bool process(int n, int m, vector<string> ar, vector<int> &inp)
{
    // behine nist
    bool err;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            err = false;
            if (ar[i][j] != '-')
            {
                if (ar[i][j] < 'a' || ar[i][j] > 'z')
                {
                    // cout << "Invalid Network\n";
                    err = true;
                }
                if (!err)
                    for (int k = i + 1; k < n; k++)
                    {
                        int cnt = 0;
                        if (ar[i][j] == ar[k][j])
                        {
                            cnt++;
                            if (inp[i] > inp[k])
                            {
                                char temp = inp[i];
                                inp[i] = inp[k];
                                inp[k] = temp;
                            }
                        }
                        if (cnt > 1)
                        {
                            cout << "Invalid Network\n";
                            err = true;
                            return err;
                        }
                    }
            }
        }
    }
    return err;
}

// natije

void generate_output(int n, vector<int> inp, bool err)
{
    bool flag = false;
    if (!err)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (inp[i] > inp[i + 1])
            {
                cout << "Not sorted\n";
                flag = true;
            }
        }
        if (!flag)
            cout << "Sorted\n";
    }
}