#we would have to access to the main first in order to compile it
#Then, the way this is going to be compile it is going to be like: g++ main.cpp ../classes/*.cpp taking in count that the user is within file named "main". The file will be run as "./a.out", and the the following data from the csv files should be save on a "name_of_thefile".out

#Go the the file Input_out.txt to see a better illustration of all the data saved from the CSV files
#The files are going to be write it in the main where passenger and reservation is.

## Airport Data Saver 
 The goal of this project was to build a program that reads data from a CSV file and organizes it into a new file based on its independent variable. I used hash tables as the main data structure and was able to successfully implement the solution. The program read the title of a CSV file, opens it up and grabs each one of the variables and stores it onto a txt file. It indexes on a format where it is easy to read.  
## Language 
  C++ 
## How to Run 
  - compile the main.cpp and all the functions and classes stores within the classes folder, the user needs to be within the main folder <BR>
    - g++ main.cpp ../classes/*.cpp
  - Once the program compiles, type the following to run the code
    - "./a.out"
  - You will be prompt to type the name of the file and a "name_of_the_file".out will be created it
  - To have a better illustration of the data you can go to Input_out.txt and all the data should be saved.  



