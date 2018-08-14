#include <iostream>
#include "Disk.h"

using namespace std;

int main(){
    Disk d;
    int opc = 0;
    inode_entry dt;
    
do{    
    cout << "-|-|-|-|-|-File System-|-|-|-|-|-\n      by Daniel Zavala~" << endl;
    char name2[30] = "ROOT.bin";

    cout << "Available commands: \n1. mkdir\n2. ls(only works for System.bin)\n3. Create disk." << endl;
    cout << "Choose command: ";
    cin >> opc;

    switch (opc){
        case 1:{
            d.addData(name2);
            break;
        }
        case 2:{
            d.readDisk(dt, name2);
            break;
        }
        case 3:{
            d.writeDisk(dt, name2);
            break;
        }
        default:{
            break;
        }
    }    
  }while(opc != -1);
}