# How to run
	1) Execute "make compileAndExecute" to compile and execute the program
	2) Execute "make compile" to compile the program
	3) Execute "make execute" to execute the program
	3) Execute "make clear" to remove the executable
	3) Execute "make clearAll" to remove all files except the source code
	
# File Structure
The structure of the program is divided into interface files, implementation files, driver file, the makefile and the input text files. The makefile takes care of everything from dynamic linking, compiling to running the program. The driver file contains the main function, which take care of reading from the file and calling other functions to calculate various things like hyperperiod and frame size. The .h interface files and the .c implementation files are self explanatory. 
## main.c
   This is the main file which contains the main function and calculates the frame size
      
## moreMath.h
   This is the header file which contains the function declarations and documentation for the mathematical functions I implemented. Since math.h is a standard library header file, I called mine moreMath.h
   
## moreMath.c
   Contains the implementations for the functions declared in moreMath.h
   
## vectorLL.h
   This is the header file which contains the function declarations and documentation for my vector class for long long integers. I started with a void** element so it could point to any pointer type which in turn would point to the element. This was a compilation disaster and I decided to give up and settle for a long long int* element
   
## vectorLL.c
   Contains the implementations for the functions declared in vectorLL.h
   
## vectorPJ.h
   This is the header file which contains the function declarations and documentation for my vector class for periodicJob structs along with the definition of said struct. I had to implement this since my original idea for a work-around for a template vector didn't work. Despite being almost the same as vectorLL, there were a lot of unique problems because of the element being a struct
   
## vectorPJ.c
   Contains the implementations for the functions declared in vectorPJ.h

## makefile
   contains the functions CompileAndExecute, which does the full compilation process and then executes, Compile which produces an executable from all the files, Execute which executes the executable, clear which removes the executable, and clearAll which removes all the intermediate files and shared objects. Compilation makes sure that the code follows c99 standards and has a few warning flags enabled.

# Features implemented
1) Found out the hyperperiod using LCM

2) Randomized the WCET using current time as seed

3) Found out the utilization, taking into account the random WCET

4) Found out the frame size using the hyperperiod and the various parameters of the jobs.

5) Implemented ADTs for vector classes for long long int and periodicJob and an integer heap

# Note

I tried to implement a Red Black Tree for EDF but there were a lot fo runtime errors. I instead decided to go for a heap. My biggest difficulty was implementing things I've always taken for granted. Second biggest difficulty was the insane amount of segfault and how useless the errors were for fixing them. I wasn't able to use the debugger as it had some issue linking all the libraries. I've always had all my functions in one file and had my faithful debugger for segfaults but this time I had to fix them myself

There were bugs in the red Black tree and a few easy to fix ones in the heap code but I decoupled that code from the rest of the execution and removed it. Running "make" will default to compiling and executing the program and I could find no errors on my WSL: Ubuntu 20.04.4 LTS, using ISO c99 standards
