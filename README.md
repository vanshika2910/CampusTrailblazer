# CampusTrailblazer

## Introduction
The Campus Management System is a C program that allows users to manage student records using file handling. It provides functionalities to add, delete, search, and display student information.

## Features
- Add Student: Allows users to add student records by entering their details such as name, roll number, and department.
- Delete Student: Enables users to delete a student record based on their roll number.
- Search Student: Allows users to search for a student record by their roll number and displays the student's details if found.
- Display All Students: Displays all the student records present in the file.

## File Handling
The program utilizes file handling concepts to store and retrieve student records. It uses a files named "cafeteria.txt" ,"visitor.txt" ,"hostel.txt"  to store the records. Each record is stored on a separate line, and the fields are separated by a delimiter.

## Building and Running the Program
1. Make sure you have a C compiler (such as GCC) installed on your system.
2. Download the source code files for the program.
3. Open a terminal or command prompt and navigate to the directory containing the source code files.
4. Compile the program using the following command:
gcc CampusTrailblazer.c -o CampusTrailblazer
5. Run the compiled program using the following command:
./CampusTrailblazer


## Usage
Once the program is running, you can use the menu options to perform various operations on student records. The options include:
1. Add Student: Enter the student's details to add a new record.
2. Delete Student: Enter the roll number of the student to delete their record.
3. Search Student: Enter the roll number to search for a specific student record.
4. Display All Students: View all the student records stored in the file.

## Note
- The program assumes that the "cafeteria.txt" ,"visitor.txt" ,"hostel.txt" files exist in the same directory as the program executable.
- Ensure that the file has proper read and write permissions.

## Contributions
Contributions to the CampusTrailblazer are welcome. If you find any issues or have ideas for improvements, please submit them to the repository or make a pull request.

## License
The Campus Management System is open-source and distributed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to modify and use the code according to your needs.
