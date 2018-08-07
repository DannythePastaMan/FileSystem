#ifndef DISK_H
#define DISK_H

#include <iostream>

struct inode_entry
{
    char name[30];
    char type[1];
    int day, month, year;
    unsigned int lvl1, lvl2, lvl3;
    unsigned int dirP[12];
    unsigned int indirP1, indirP2, indirP3;
    unsigned int brother;
};

class Disk
{
public:
    Disk();
    void writeDisk(inode_entry, char []);
    void readDisk(inode_entry, char[]);
    void addData(char []);
    void importFile(std::string );

};

struct DataBlocks
{
    char arr[4092];
    int next;
    int first;
};

struct DBCluster
{
    DataBlocks cluster[100];
};

struct SuperBlock
{
    unsigned int inodeQuant;
    unsigned int numBlocks;
    unsigned int numFreeBlocks;
};

struct BootBlock
{
    unsigned int size[1024];
};


#endif // DISK_H
