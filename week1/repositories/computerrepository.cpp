#include "computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

ComputerRepository::ComputerRepository()
{
    fileName = constants::DATA_FILE_NAME;
}

