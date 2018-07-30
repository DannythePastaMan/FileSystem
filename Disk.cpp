
#include "Disk.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int pos = 0;

Disk::Disk()
{

}

void Disk::writeDisk(dataTyping File_Entry, char name[30])
{
    ofstream disk(name, ios::binary | ios::out | ios::app);
    strcpy(File_Entry.type, "");
    strcpy(File_Entry.name, "");
    File_Entry.day = -1;
    File_Entry.month = -1;
    File_Entry.year = -1;
    disk.write(reinterpret_cast<char*>(&File_Entry), sizeof(dataTyping));
    disk.close();

}

void Disk::readDisk(dataTyping File_Entry, char name[30])
{
    ifstream disk(name, ios::in | ios::binary);
    disk.seekg(0, ios::beg);
    int size = sizeof(dataTyping);
    disk.read(reinterpret_cast<char *>(&File_Entry), sizeof(dataTyping));

    while(!disk.eof())
    {
        cout << File_Entry.name << endl;
        cout << File_Entry.type << endl;
        cout << File_Entry.day << "/";
        cout << File_Entry.month << "/";
        cout << File_Entry.year << endl;
        disk.read(reinterpret_cast<char *>(&File_Entry), sizeof(dataTyping));
    }

    disk.close();
}

void Disk::addData(char name[30])
{
    fstream disk(name, ios::in | ios::out | ios::binary | ios::app);
    disk.seekp((pos) * sizeof(dataTyping), ios::beg);
    dataTyping dt;

    cout << "Ingrese nombre del archivo: ";
    cin >> dt.name;

    cout <<"Ingrese tipo de data: ";
    cin >> dt.type;

    cout << "Day: ";
    cin >> dt.day;

    cout << "Month: ";
    cin >> dt.month;

    cout << "Year: ";
    cin >> dt.year;

    disk.write(reinterpret_cast<char *>(&dt), sizeof(dataTyping));
    cout << "Archivo guardado en el disco!" << endl;

    disk.close();
    pos++;

}






