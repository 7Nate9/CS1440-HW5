//
// Created by Stephen Clyde on 3/4/17.
//

#include "County.h"

// TODO: Implement functionality of County class
//Done
County::County(const std::string data[]): Region(CountyType, data)
{
    validate();
}

//End of To Do