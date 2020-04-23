# Linux-Shell
A shell in C 
## Commands taken by shell:
### INTERNAL COMMANDS:
#### 1. cd:
This command is used to change the directory. cd directory
will change the directory to the desired one.
#### 2. pwd:
This displays the present working directory of the shell.
3. history:
This displays the all the previous commands entered by the
user.
#### 4. echo:
This command is used to print. echo -E prints the entire line
eliminating spaces or tabs. echo * prints all files and
directory in current directory.
#### 5. exit:
It is used to exit from the shell.
### EXTERNAL COMMANDS:
#### 1. ls:
The shell has an option of ls, ls -l, and ls -lh.
ls provides list of files in the current directory. ls -l provides
the same in long list format. ls -lh provides list of files in list
long format with readable size.
#### 2. Date:
It displays the current date. date -u displays date and time in
UTC format.
#### 3. Cat:
cat filename displays the the file whose name is given.cat
name filename displays the details of name in filename.
#### 4. rm:
rm filename removes the file from the directory. rm -f removes
the file forcibly and does not prompt before removing.
#### 5. mkdir:
mkdir name makes a directory in the current directory with the
given name.
## Assumptions:
- User would not use tab to display the entire name of the file and
directory.
- The user is aware about the spacing in commands.
## Errors:
- Used fork() and wait() command so that the child process completes
before starting the parent process.
- Spacing was handled by creating a pointer of pointers to store the
details.
