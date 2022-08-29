//  Libraries
//----------------
# include "Task.cpp"
# include "LinearADT/List.cpp"

//  Structs, methods, functions
//--------------------------------
struct Routine
{
    string name;
    List<Task> tasks;

    void runRoutine()
    {
        for (int index = 0; index < tasks.getSize(); index++)
        {
            tasks.search(index).runTask();
        }
    }
};