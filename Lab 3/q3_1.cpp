#include <iostream>
using namespace std;
int main()
{
    int r, c;
    int size = 0;
    cout << "Enter Rows : ";
    cin >> r;
    cout << "Enter Columns : ";
    cin >> c;
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "\nThe matrix you entered : ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j];
            if (arr[i][j] != 0)
            {
                size++;
            }
        }
        cout << endl;
    }
    cout << "\nNumber of non zero values : ";
    cout << size << endl;
    // cout<< "\n ";
    cout << "\nSparse Matrix : " << endl;
    // sparse matrix
    int s_arr[size][3];
    int q = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 0)
            {
                s_arr[q][0] = i;
                s_arr[q][1] = j;
                s_arr[q][2] = arr[i][j];
                q++;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << s_arr[i][j];
        }
        cout << endl;
    }
    cout << "\nTranspose : " << endl;
    // transpose
    int m[size][3];
    int a = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (s_arr[j][1] == i)
            {
                m[a][1] = s_arr[j][0];
                m[a][0] = s_arr[j][1];
                m[a][2] = s_arr[j][2];
                a++;
            }
        }
        // cout << endl;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m[i][j];
        }
        cout << endl;
    }
}