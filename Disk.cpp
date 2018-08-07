
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

void Disk::writeDisk(inode_entry File_Entry, char name[30])
{
    ofstream disk(name, ios::binary | ios::out | ios::app);
    strcpy(File_Entry.type, "");
    strcpy(File_Entry.name, "");
    File_Entry.day = -1;
    File_Entry.month = -1;
    File_Entry.year = -1;
    disk.write(reinterpret_cast<char*>(&File_Entry), sizeof(inode_entry));
    disk.close();

}

void Disk::readDisk(inode_entry File_Entry, char name[30])
{
    ifstream disk(name, ios::in | ios::binary);
    disk.seekg(0, ios::beg);
    int size = sizeof(inode_entry);
    disk.read(reinterpret_cast<char *>(&File_Entry), sizeof(inode_entry));

    while(!disk.eof())
    {
        cout << File_Entry.name << endl;
        cout << File_Entry.type << endl;
        cout << File_Entry.day << "/";
        cout << File_Entry.month << "/";
        cout << File_Entry.year << endl;
        cout << endl;
        disk.read(reinterpret_cast<char *>(&File_Entry), sizeof(inode_entry));
    }

    disk.close();
}

void Disk::addData(char name[30])
{
    fstream disk(name, ios::in | ios::out | ios::binary | ios::app);
    disk.seekp((pos) * sizeof(inode_entry), ios::beg);
    inode_entry dt;
    SuperBlock sb;
    BootBlock bb;
    DBCluster dbc;
    DataBlocks db;

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

    disk.write(reinterpret_cast<char *>(&dt), sizeof(inode_entry));
    disk.write(reinterpret_cast<char *>(&sb), sizeof(SuperBlock));
    disk.write(reinterpret_cast<char *>(&bb), sizeof(BootBlock));
    disk.write(reinterpret_cast<char *>(&dbc), sizeof(DBCluster));
    disk.write(reinterpret_cast<char *>(&db), sizeof(DataBlocks));

    cout << "Data Saved" << endl;

    disk.close();
    pos++;

}