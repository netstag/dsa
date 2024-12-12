#include <iostream>
using namespace std;
struct student
{
    int rollno;
    string name;
    double sgpa;
};
void bubblesortRollno(student arrStudent[], int n)
{
    cout << "Roll number wise list of students:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arrStudent[j].rollno > arrStudent[j + 1].rollno)
            {
                student temp = arrStudent[j];
                arrStudent[j] = arrStudent[j + 1];
                arrStudent[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Roll no." << arrStudent[i].rollno << "       Name:" << arrStudent[i].name << "       SGPA:" << arrStudent[i].sgpa << endl;
    }
}
void insertionSortAlphabetically(student arrStudent[], int n)
{
    cout << endl;
    cout << "List of students Alphabetically:" << endl;
    for (int i = 1; i < n; i++)
    {
        student key = arrStudent[i];
        int j = i - 1;
        while (j >= 0 && arrStudent[j].name > key.name)
        {
            arrStudent[j + 1] = arrStudent[j];
            j--;
        }
        arrStudent[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {

        cout << "Name:" << arrStudent[i].name << "         Roll no." << arrStudent[i].rollno << "       SGPA:" << arrStudent[i].sgpa << endl;
    }
}
int Partition(student arrStudent[], int si, int ei)
{
    int i = si - 1;
    float pivot = arrStudent[ei].sgpa;
    for (int j = si; j < ei; j++)
    {
        if (arrStudent[j].sgpa <= pivot)
        {
            i++;
            swap(arrStudent[i], arrStudent[j]);
        }
    };
    i++;
    swap(arrStudent[i], arrStudent[ei]);
    return i;
}

void quickSort(student arrStudent[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int pivotIdx = Partition(arrStudent, si, ei);
    quickSort(arrStudent, si, pivotIdx - 1);
    quickSort(arrStudent, pivotIdx + 1, ei);
}
void displayTopTenBySGPA(student arrStudent[], int n)
{
    cout << endl;
    quickSort(arrStudent, 0, n - 1);
    cout << "Top 10 Students by SGPA:" << endl;
    for (int i = 5; i < 15; i++)
    {
       

        cout << "SGPA:" << arrStudent[i].sgpa << "        Name:" << arrStudent[i].name << "        Roll no." << arrStudent[i].rollno << endl;
    }
}

// searchsgpa
void sgpaSearch(student arrStudent[])
{
    cout << endl;
    double xsgpa;
    cout << "Enter the sgpa:";
    cin >> xsgpa;
    bool found;
    for (int i = 0; i < 15; i++)
    {
        if (xsgpa == arrStudent[i].sgpa)
        {
            cout << arrStudent[i].name << " have " << arrStudent[i].sgpa << " SGPA." << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "SGPA not found.";
    }
}

bool binarySearchName(student arrStudent[])
{
    cout << endl;
    cout << endl;
    string name;
    cout << "Enter the name :";
    cin >> name;
    cout << endl;
    int start = 0, end = 14;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (name == arrStudent[mid].name)
        {
            cout << "The name of student is " << arrStudent[mid].name << endl
                 << "Roll no. of stydent is " << arrStudent[mid].rollno << endl
                 << "The SGPA of student is " << arrStudent[mid].sgpa;
            return true;
        }
        else if (name > arrStudent[mid].name)
        {
            start = mid + 1;
        }
        else
            (end = mid - 1);
    }
    cout << "Student does not exist in database!!";
    return false;
}

int main()
{
    student arrStudent[15] = {
        {3, "Prajwal", 9.56},
        {1, "Ram", 9.07},
        {2, "Shyam", 9.11},
        {4, "Shrikant", 9.44},
        {5, "Damodar", 9.22},
        {6, "Mangesh", 9.43},
        {7, "Jagdish", 9.47},
        {9, "Pranesh", 9.77},
        {8, "Raj", 10},
        {11, "Tushar", 10},
        {10, "Vivek", 9.8},
        {12, "Harsh", 9.2},
        {14, "Sarvesh", 9.31},
        {13, "Sachin", 9.76},
        {15, "Karan", 9.92},
    };
    bubblesortRollno(arrStudent, 15);

    insertionSortAlphabetically(arrStudent, 15);

    displayTopTenBySGPA(arrStudent, 15);

    sgpaSearch(arrStudent);

    binarySearchName(arrStudent);
}