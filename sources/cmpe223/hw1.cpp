/*
 * Created on Thurs Dec 29 2022
 *
 * iltan caner
 * Student No: 22109906
 */

#define ENABLE_SAMPLE

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_CARS 100

struct date
{
    int day, month, year;
};

struct car
{
    int ID;
    char owner_name[20], owner_surname[20], model[20];
    struct date reg_date, ns_date;
    char phone_number[20]; // Since the size of the phone number was not specified in the question, I set it to 20 just like other char arrays
} car_directory[MAX_CARS];

int num_cars = 0;

void add_car()
{
    if (num_cars >= MAX_CARS)
    {
        cout << "Error: car directory is full." << endl;
        return;
    }

    cout << "Enter car ID: ";
    cin >> car_directory[num_cars].ID;

    cout << "Enter owner name: ";
    cin >> car_directory[num_cars].owner_name;

    cout << "Enter owner surname: ";
    cin >> car_directory[num_cars].owner_surname;

    cout << "Enter car model: ";
    cin >> car_directory[num_cars].model;

    cout << "Enter registration date (dd mm yyyy): ";
    cin >> car_directory[num_cars].reg_date.day >> car_directory[num_cars].reg_date.month >> car_directory[num_cars].reg_date.year;

    cout << "Enter next service date (dd mm yyyy): ";
    cin >> car_directory[num_cars].ns_date.day >> car_directory[num_cars].ns_date.month >> car_directory[num_cars].ns_date.year;

    cout << "Enter phone number: ";
    cin >> car_directory[num_cars].phone_number;

    num_cars++;
}

void delete_car()
{
    int ID;
    cout << "Enter car ID: ";
    cin >> ID;

    bool found = false;
    for (int i = 0; i < num_cars; i++)
    {
        if (car_directory[i].ID == ID)
        {
            found = true;
            for (int j = i; j < num_cars - 1; j++)
            {
                car_directory[j] = car_directory[j + 1];
            }
            num_cars--;
            break;
        }
    }

    if (!found)
    {
        cout << "Error: car with ID " << ID << " not found." << endl;
    }
}

void list_cars()
{
    for (int i = 0; i < num_cars; i++)
    {
        cout << "ID: " << car_directory[i].ID << endl
             << "Owner name: " << car_directory[i].owner_name << " " << car_directory[i].owner_surname << endl
             << "Model: " << car_directory[i].model << endl
             << "Registration date: " << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month << "/" << car_directory[i].reg_date.year << endl
             << "Next service date: " << car_directory[i].ns_date.day << "/" << car_directory[i].ns_date.month << "/" << car_directory[i].ns_date.year << endl
             << "Phone number: " << car_directory[i].phone_number << endl
             << endl;
    }
}

void search_car_id() // Using simple linear search algorithm
{
    int ID;
    cout << "Enter car ID: ";
    cin >> ID;

    bool found = false;
    for (int i = 0; i < num_cars; i++)
    {
        if (car_directory[i].ID == ID)
        {
            found = true;
            cout << "ID: " << car_directory[i].ID << endl
                 << "Owner name: " << car_directory[i].owner_name << " " << car_directory[i].owner_surname << endl
                 << "Model: " << car_directory[i].model << endl
                 << "Registration date: " << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month << "/" << car_directory[i].reg_date.year << endl
                 << "Next service date: " << car_directory[i].ns_date.day << "/" << car_directory[i].ns_date.month << "/" << car_directory[i].ns_date.year << endl
                 << "Phone number: " << car_directory[i].phone_number << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Error: car with ID " << ID << " not found." << endl;
    }
}

void search_car_name() // Using simple linear search algorithm
{
    char name[20];
    cout << "Enter owner name: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < num_cars; i++)
    {
        if (strcmp(car_directory[i].owner_name, name) == 0)
        {
            found = true;
            cout << "ID: " << car_directory[i].ID << endl
                 << "Owner name: " << car_directory[i].owner_name << " " << car_directory[i].owner_surname << endl
                 << "Model: " << car_directory[i].model << endl
                 << "Registration date: " << car_directory[i].reg_date.day << "/" << car_directory[i].reg_date.month << "/" << car_directory[i].reg_date.year << endl
                 << "Next service date: " << car_directory[i].ns_date.day << "/" << car_directory[i].ns_date.month << "/" << car_directory[i].ns_date.year << endl
                 << "Phone number: " << car_directory[i].phone_number << endl;
        }
    }

    if (!found)
    {
        cout << "Error: car with owner name " << name << " not found." << endl;
    }
}

void update_car()
{
    int ID;
    cout << "Enter car ID: ";
    cin >> ID;

    bool found = false;
    for (int i = 0; i < num_cars; i++)
    {
        if (car_directory[i].ID == ID)
        {
            found = true;
            cout << "Enter new owner name: ";
            cin >> car_directory[i].owner_name;

            cout << "Enter new owner surname: ";
            cin >> car_directory[i].owner_surname;

            cout << "Enter new car model: ";
            cin >> car_directory[i].model;

            cout << "Enter new registration date (dd mm yyyy): ";
            cin >> car_directory[i].reg_date.day >> car_directory[i].reg_date.month >> car_directory[i].reg_date.year;

            cout << "Enter new next service date (dd mm yyyy): ";
            cin >> car_directory[i].ns_date.day >> car_directory[i].ns_date.month >> car_directory[i].ns_date.year;

            cout << "Enter new phone number: ";
            cin >> car_directory[i].phone_number;
            break;
        }
    }

    if (!found)
    {
        cout << "Error: car with ID " << ID << " not found." << endl;
    }
}

void sort_id() // Using basic Bubble Sort algorithm
{
    for (int i = 1; i < num_cars; i++)
    {
        for (int j = 0; j < num_cars - i; j++)
        {
            if (car_directory[j].ID > car_directory[j + 1].ID)
            {
                struct car temp = car_directory[j + 1];
                car_directory[j + 1] = car_directory[j];
                car_directory[j] = temp;
            }
        }
    }
}

void sort_name()
{
    for (int i = 1; i < num_cars; i++)
    {
        for (int j = 0; j < num_cars - i; j++)
        {
            if (strcmp(car_directory[j].owner_name, car_directory[j + 1].owner_name) > 0)
            {
                struct car temp = car_directory[j + 1];
                car_directory[j + 1] = car_directory[j];
                car_directory[j] = temp;
            }
        }
    }
}

int main()
{
#ifdef ENABLE_SAMPLE
    car_directory[0] = {19, "iltan", "caner", "cpp", {15, 2, 2003}, {15, 2, 2023}, "+905391145720"};
    car_directory[1] = {10, "altan", "caner", "bmw", {6, 5, 2010}, {6, 5, 2023}, "-"};
    car_directory[2] = {2, "asya", "caner", "porsche", {1, 6, 2020}, {1, 6, 2023}, "-"};
    car_directory[3] = {38, "ferhat", "caner", "lada samara", {5, 6, 1984}, {5, 6, 2023}, "+905466885719"};
    num_cars = 4;
#endif

    while (true)
    {
        cout << endl
             << "Menu:" << endl
             << "1- Add a new car to directory" << endl
             << "2- Delete a car from the directory" << endl
             << "3- List available cars in the directory" << endl
             << "4- Search a car:" << endl
             << "   A - Search according to car id" << endl
             << "   B - Search according to owner_name" << endl
             << "5- Update car information" << endl
             << "6- Sort according to car id" << endl
             << "7- Sort according to owner_name" << endl
             << "8- Quit" << endl;

        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 1)
        {
            add_car();
        }
        else if (option == 2)
        {
            delete_car();
        }
        else if (option == 3)
        {
            list_cars();
        }
        else if (option == 4)
        {
            char suboption;
            cout << "Enter suboption: ";
            cin >> suboption;

            if (suboption == 'A')
            {
                search_car_id();
            }
            else if (suboption == 'B')
            {
                search_car_name();
            }
            else
            {
                cout << "Error: invalid suboption." << endl;
            }
        }
        else if (option == 5)
        {
            update_car();
        }
        else if (option == 6)
        {
            sort_id();
        }
        else if (option == 7)
        {
            sort_name();
        }
        else if (option == 8)
        {
            break;
        }
        else
        {
            cout << "Error: invalid option." << endl;
        }
    }

    return 0;
}