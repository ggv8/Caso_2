//  Libraries
//----------------
# pragma once
# include "Task.hpp"
# include "List.hpp"

//  Structs, methods, functions
//--------------------------------
struct Routine
{
    std::string name;
    List<Task> tasks;

    void runRoutine();
};