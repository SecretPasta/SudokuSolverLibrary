# SudokuSolverLibrary
This is the Sudoku Solving Algorithm I wrote in a previous repository but as a separate library to be used in the future.
This code has also been modified to fit Google's C++ Coding style.(With some exceptions)

How to set it up in Visual Studio:

You need to include the headers with the declarations of the stuff in the static library,
and you need to link the executable against the static library.
In Visual Studio, that means adding the place where the static library is to the "additional library directories"
in project settings>linker>general, and add the name of the static library to "additional dependancies" in project settings>linker>input
You'll probably also want to add the directory where the header in question lives to the project's "include directories",
in project settings>VC++ Directories

https://discord.com/channels/349857236656324608/349857717445459968/1056286699073851464
