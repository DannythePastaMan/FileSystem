#include <iostream>
#include "Disk.h"

using namespace std;

int main()
{
    Disk d;
    dataTyping dt;
    char name2[30] = "System.bin";

    //d.writeDisk(dt, name2);
    d.addData(name2);
    d.readDisk(dt, name2);
}