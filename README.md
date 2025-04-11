# philosophers

threads = https://www.youtube.com/watch?v=d9s_d28yJq0
mutex = https://www.youtube.com/watch?v=oq29KUy29iQ

make all odd philosophers to sleep at begin of program
1 function that checkes if philosopher is alive or dead, using thread
have a mutex to print printf-->protect buffer

create my own usleep function

- Create a data structure to store all required information about a philosopher

- Create the correct number of philosopher

- Create the correct number of threads

- Create a routine

    What each philosopher has to do ? In which order ?

    Initiate the threads with said routine

Some variables have to be shared between all philosophers so take this into account when creating your data structures.
Routine checklist

   -Create a loop that runs until any of your philosophers die

If you have to loop until any of your philosphers die, it might be a good idea to check in the routine if any of your philosopher has died.

That's basically it. Your philosophers have to do the following things (in order) in the routine.

    Eat

    Sleep

    Think

    Repeat

The most complex thing in this project is to understand how threads work and how you can use mutexes to lock / unlock some values. Once you understood that, you "just" have to make each philosopher eat, sleep and think in a loop. Don't forget to print the logs when the state of your philosophers change.
