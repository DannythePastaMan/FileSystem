
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
    SuperBlock sb;
    DataBlocks db;
    
    ofstream disk(name, ios::binary | ios::out | ios::app);
    
    if(!disk)
    {
        cout << "Disco no pudo abrir." << endl;
    }

    disk.write(reinterpret_cast <char *>(&sb), sizeof(SuperBlock));

    cout << "Ingrese la cantidad de entradas que desea: ";
    cin >> inode_count;

    sb.inodeQuant = -1;
    sb.numBlocks = -1;
    sb.numFreeBlocks = -1;
    db.next = -1; 
    db.first = -1;

    File_Entry.day = -1;
    File_Entry.brother = -1;
    File_Entry.indirP1 = -1;
    File_Entry.indirP2 = -1;
    File_Entry.indirP3 = -1;
    File_Entry.month = -1;
    File_Entry.year = -1;

    for (int i = 0; i < inode_count; i++)
    {
        disk.write(reinterpret_cast <char *>(&File_Entry), sizeof(inode_entry));

        for(int i = 0; i < inode_count * 33308; i++)
        {
            disk.write(reinterpret_cast <char *>(&db), sizeof(DataBlocks));
        }
    }
    
    cout << "Entradas disponibles: " << inode_count << endl;
    disk.close();

}

void Disk::readDisk(inode_entry File_Entry, char name[30])
{
    ifstream disk(name, ios::in | ios::binary);
    disk.seekg(0, ios::beg);
    disk.read(reinterpret_cast<char *>(&File_Entry), sizeof(inode_entry));

    while(disk.tellg() < sizeof(disk))
    {
        cout << File_Entry.name << endl;
        cout << File_Entry.type << endl;
        cout << File_Entry.day << "/";
        cout << File_Entry.month << "/";
        cout << File_Entry.year << endl;
        cout << endl;
    }

    disk.close();
}

void Disk::addData(char name[30])
{
    fstream disk(name, ios::in | ios::out | ios::binary | ios::app);

    disk.seekp((pos) * sizeof(inode_entry), ios::beg);

    inode_entry dt;

    cout << "Ingrese nombre de la data: ";
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

    cout << "Data Saved" << endl;

    inode_count --;

    cout << "Espacios diponibles: " << inode_count << endl;

    if(inode_count == 0)
    {
        cout << "Sin espacio" << endl;
        return; 
    }

    disk.close();
    pos++;

}