/*
 * Created on Thurs Dec 29 2022
 *
 * iltan caner
 * Student No: 22109906
 */

#include <iostream>
#include <string>

using namespace std;

void create_file();
void copy_file();
void copy_without_spaces();
void merge_files();

int main()
{
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1- Create file" << endl;
        cout << "2- Copy file" << endl;
        cout << "3- Copy without spaces" << endl;
        cout << "4- Merge files" << endl;
        cout << "5- Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_file();
            break;
        case 2:
            copy_file();
            break;
        case 3:
            copy_without_spaces();
            break;
        case 4:
            merge_files();
            break;
        case 5:
            cout << "Okay. See you next time";
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}

void create_file()
{
    string file_name;
    cout << "Enter the name of the file to create: ";
    cin >> file_name;

    FILE *file = fopen(file_name.c_str(), "w");
    if (file != NULL)
    {
        cout << "File created successfully" << endl;
        fclose(file);
    }
    else
    {
        cout << "Error creating file" << endl;
    }
}

void copy_file()
{
    string source_file_name;
    cout << "Enter the name of the source file: ";
    cin >> source_file_name;

    string destination_file_name;
    cout << "Enter the name of the destination file: ";
    cin >> destination_file_name;

    FILE *source_file = fopen(source_file_name.c_str(), "r");
    if (source_file == NULL)
    {
        cout << "Error opening source file" << endl;
        return;
    }

    FILE *destination_file = fopen(destination_file_name.c_str(), "w");
    if (destination_file == NULL)
    {
        cout << "Error opening destination file" << endl;
        return;
    }

    char c;
    while ((c = fgetc(source_file)) != -1)
    {
        fputc(c, destination_file);
    }
    cout << "File copied successfully" << endl;

    fclose(source_file);
    fclose(destination_file);
}

void copy_without_spaces()
{
    string source_file_name;
    cout << "Enter the name of the source file: ";
    cin >> source_file_name;

    string destination_file_name;
    cout << "Enter the name of the destination file: ";
    cin >> destination_file_name;

    FILE *source_file = fopen(source_file_name.c_str(), "r");
    if (source_file == NULL)
    {
        cout << "Error opening source file" << endl;
        return;
    }

    FILE *destination_file = fopen(destination_file_name.c_str(), "w");
    if (destination_file == NULL)
    {
        cout << "Error opening destination file" << endl;
        return;
    }

    char c;
    while (fscanf(source_file, "%c", &c) == 1)
    {
        if (c != ' ')
        {
            fprintf(destination_file, "%c", c);
        }
    }
    cout << "File copied without spaces successfully" << endl;

    fclose(source_file);
    fclose(destination_file);
}

void merge_files()
{
    string source_file_name1;
    cout << "Enter the name of the first source file: ";
    cin >> source_file_name1;

    string source_file_name2;
    cout << "Enter the name of the second source file: ";
    cin >> source_file_name2;

    string destination_file_name;
    cout << "Enter the name of the destination file: ";
    cin >> destination_file_name;

    FILE *source_file1 = fopen(source_file_name1.c_str(), "r");
    if (source_file1 == NULL)
    {
        cout << "Error opening first source file" << endl;
        return;
    }

    FILE *source_file2 = fopen(source_file_name2.c_str(), "r");
    if (source_file2 == NULL)
    {
        cout << "Error opening second source file" << endl;
        return;
    }

    FILE *destination_file = fopen(destination_file_name.c_str(), "w");
    if (destination_file == NULL)
    {
        cout << "Error opening destination file" << endl;
        return;
    }

    char c;
    while (fscanf(source_file1, "%c", &c) == 1)
    {
        fprintf(destination_file, "%c", c);
    }
    while (fscanf(source_file2, "%c", &c) == 1)
    {
        fprintf(destination_file, "%c", c);
    }

    cout << "Files merged successfully" << endl;

    fclose(source_file1);
    fclose(source_file2);
    fclose(destination_file);
}