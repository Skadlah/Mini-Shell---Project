MiniShell - A Simple Linux-like Shell
Overview
MiniShell is a basic Linux-like shell created in C to simulate the key functionalities of a command-line interface, similar to the Bash shell. Developed as part of my learning journey, this project covers process management, job control, signal handling, piping, input/output redirection, and environment variable management. It demonstrates how a shell works internally and provides a foundation for building more advanced shells.

This project was developed as part of my coursework at Emertxe, with a focus on Linux internals, process control, and system calls.

Features
Process Management:

fork() creates new processes, and exec() replaces the current process with a new program.

Parent processes wait for the child to finish execution using waitpid().

Supports background jobs using & symbol.

Command Parsing:

Parses user commands by tokenizing the input string and handling multiple arguments.

Supports commands like cd, pwd, and exit natively.

Handles user-defined and system commands.

Piping:

Supports piping (|), where the output of one command is used as the input of another.

Allows chaining multiple commands together via pipes.

Redirection:

Supports input and output redirection (>, >>, <).

Redirects standard output to files or takes input from files.

Signal Handling:

Handles signals like SIGINT (Ctrl+C) and SIGTSTP (Ctrl+Z) to control child processes.

Custom signal handling ensures smooth process termination and background job management.

Job Control:

Supports background job control. Jobs can be run asynchronously in the background using the & symbol.

Tracks and displays background jobs with their status.

Environment Variables:

Implements basic environment variable handling (e.g., $PATH) for locating system executables.

nstallation
To run MiniShell, clone the repository and compile the source code.

Clone the repository:

bash

git clone https://github.com/yourusername/minishell.git
cd minishell
Compile the code:

You can compile the shell using the gcc compiler:

bash

gcc -o minishell minishell.c
Run the shell:

After compilation, run the shell using:

bash

./minishell
You should now see the prompt where you can start entering commands.

Usage
Once the shell is running, you can interact with it using the following features:

Running a simple command:

bash

$ ls -l
Running a command in the background:

bash

$ ./my_program &
Piping commands:

bash

$ cat file.txt | grep "keyword" | sort
Redirection:

Output redirection to a file:

bash

$ echo "Hello, World!" > output.txt
Input redirection from a file:

bash

$ cat < input.txt
Built-in commands:

cd: Change the directory.

bash

$ cd /path/to/directory
pwd: Print the current working directory.

bash

$ pwd
exit: Exit the shell.

bash

$ exit
Advanced Features
Job Control:

You can run commands in the background by appending & to the command.

bash

$ sleep 10 &
Background jobs can be tracked and listed, and can also be brought to the foreground.

Custom Command Support:

You can add new commands by extending the MiniShell functionality.

Supports any executable command present in the system's $PATH.

Signal Handling:

Ctrl+C: Terminates the current foreground process.

Ctrl+Z: Suspends the current foreground process, which can then be resumed in the background.

Environment Variables:

$PATH is used to search for executable files in directories.

You can modify and add environment variables during the session.

Example Sessions
Command Execution:
bash

$ pwd
/home/user/minishell
$ ls -l
Using Pipes:
bash

$ cat file.txt | grep "keyword" | sort
Redirecting Output to a File:
bash

$ echo "Hello World" > hello.txt
$ cat hello.txt
Hello World
Using Background Jobs:
bash

$ sleep 10 &
[1] 12345
$ jobs
[1] 12345 Running sleep 10 &
$ fg %1
Challenges & Learnings
Process Synchronization: Handling the synchronization of processes between the parent and child to ensure correct execution of background jobs and handling signals like Ctrl+C.

Signal Handling: Implementing custom signal handlers for system signals, particularly SIGINT and SIGTSTP, was a challenging yet rewarding part of the project.

Redirection and Pipes: Implementing file redirection and piping between commands required managing file descriptors efficiently using dup2() and pipe().

Job Control: Managing background jobs and allowing users to interact with them via simple commands like fg and jobs was a great learning experience for process control.

Contributing
Feel free to fork this project, submit issues, or create a pull request with improvements! Contributions are always welcome.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Created and Devoloped By - Shreyas Kadlag
Linux Documentation: For insights into process management, signal handling, and shell operations.

