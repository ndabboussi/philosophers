# philosophers

📜 Rules of the Simulation

    Philosophers' Actions:
        A philosopher can think, take forks, eat, or sleep.
        To eat, a philosopher must pick up both forks (left and right).

    Simulation Parameters:
        number_of_philosophers: Total number of philosophers (and forks).
        time_to_die: Time (in ms) a philosopher can live without eating.
        time_to_eat: Time (in ms) it takes for a philosopher to eat.
        time_to_sleep: Time (in ms) a philosopher spends sleeping.
        [number_of_times_each_philosopher_must_eat] (optional): If provided, the simulation stops when all philosophers have eaten this many times.

    Parameters Rules:
        The number_of_philosophers must not exceed 200.
        All the times values must not be bellow 60 ms.
        All the arguments given to the program must be strictly positive and numeric values.

    Philosopher Death:
        If a philosopher does not eat within time_to_die, they die, and the simulation ends. The message must be displayed within 10 ms after a philo dies. (first argument in the printed message)

    No Deadlocks:
        The program must ensure that no deadlocks occur during the simulation.

    No Data Races
        Ensure that the thread accessing a data does not conflict with another thread.



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



 valgrind --tool=helgrind 

 Aussi pour les petites astuces on va dire. Il faut que tu choisisses un systeme pour tes philosphers et leur fourchette. Le plus courrant c est d avoir un seul array de mutex fork. Il va falloir que tes philosophers, selon qu il soit pair ou impair commence par prendre une fourchette differente (certains la gauche d autres la droite) pour eviter les deadlocks. Il va aussi certainement te falloir un thread supplementaire qui est un manager ou un butler et qui sert a monitorer les autres philosphers pour verifier qu ils sont vivants (manger dans les temps) et qu ils n ont pas encore manges suffisamment de fois et qui arrete le programme s ils ont finis ou si qqn meurt

Regarde des codes github pour gerer le temps, il va falloir regarder un truc genre ft_utime pour avoir ton temps en millisecondes de facons precise (fait gaffe valgrind ralenti ton programme et donc fausse les temps donc faut run sans valgrind aussi)

Et enfin il surement que tu assignes un petit temps au fait de dormir part exemple pcq en fait dans le sujet il n y a que le temps pour manger, hors le fait d avoir un temps de dormir ou un temps de decallage au debut de ta loop pour certains philo va faciliter la synchronisation (pour ca tu peux bidouiller et essayer des trucs et regarder le resultat sur le vizualizer, moi j ai du mettre un temps de sommeil je crois)

ah et  protege bien les cas ou il n y a pas de philo et ou il n y a qu un seul philo !


 make && ./philo 2 600 200 200 3