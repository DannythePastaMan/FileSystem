#ifndef DISK_H
#define DISK_H

#include <iostream>

struct dataTyping
{
    char name[30];
    char type[1];
    int day, month, year;
    double size = sizeof(dataTyping);

};

class Disk
{
public:
    Disk();
    void writeDisk(dataTyping, char []);
    void readDisk(dataTyping, char[]);
    void addData(char []);

};

#endif // DISK_H
