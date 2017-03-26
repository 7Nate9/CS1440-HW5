//
// Created by Stephen Clyde on 3/4/17.
//
// TODO: implement State class functionality
//Done

#include "State.h"

State::State(const std::string data[]) : Region(StateType, data)
{
    validate();
}

//End of To Do