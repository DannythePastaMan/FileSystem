#ifndef DISK_H
#define DISK_H

#include <iostream>

struct inode_entry
{
    char name[30];
    char type[1];
    int day, month, year;
    unsigned int dirP[12];
    unsigned int indirP1, indirP2, indirP3;
    unsigned int brother;
};

class Disk
{
public:
    int inode_count;
    Disk();
    void writeDisk(inode_entry, char []);
    void readDisk(inode_entry, char[]);
    void addData(char []);
};

struct DataBlocks
{
    char arr[4096];
    int next;
    int first;
};

struct SuperBlock
{
    unsigned int inodeQuant;
    unsigned int numBlocks;
    unsigned int numFreeBlocks;
};

#endif // DISK_H
