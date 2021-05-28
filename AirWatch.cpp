#include "Model/ApplicationData.h"
#include "Display/HMIManager.h"
#include "Services/UserServices.h"
#include "Services/ApplicationServices.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Fetch Data directory from the arguments
    string dataDirectory = "Dataset/";
    if (argc > 1)
    {
        dataDirectory = argv[1];
    }
    
    // Import data from central and local server
    ApplicationServices::importData(dataDirectory);

    // Launch the display
    HMIManager hmi;
    hmi.loginMenu();

    // At the end of execution, save local data and clean up
    ApplicationServices::saveData();
    ApplicationServices::cleanup();

    return 0;
}
