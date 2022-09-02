//  Libraries
//----------------
# include "headers/Routine.hpp"

//  Structs, methods, functions
//--------------------------------
void Routine::runRoutine()
{
    for (int index = 0; index < tasks.getSize(); index++)
    {
        Task task = tasks.search(index);
        task.runTask();
    }
}