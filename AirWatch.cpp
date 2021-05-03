#include <iostream>
using namespace std;

#include "Database/DBManager.h"

int main(int argc, char const *argv[])
{

    DBManager dbManager;
    dbManager.importCentralServerData();

    return 0;
}
