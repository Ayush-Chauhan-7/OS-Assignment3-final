In this part we implemented our own small kernel module. 
The task of the module is to read the entries of the process task_struct corresponding to any
given process (supplied as input via command line argument) and prints the
values of the following field: pid, user id, process group id (pgid) and command
path.
The system module used to take input from the command line was: module_param
After making we load the module into the system using : insmod ./kdm.ko pid=(pid number)
To remove the module from system use: rmmod ./kdm.ko