ibrary Management System in C
A basic command-line Library Management System written in C, using file handling to manage book records. This system allows users to:

Add new books

Display all books

Issue a book

Return a book

Features
Persistent storage in library.txt

Issue/return functionality with status tracking

Simple and easy-to-use menu interface

Requirements
A C compiler (e.g., GCC)

Works on Windows/Linux/Mac

VSCode (optional)

How to Compile and Run
bash
Copy
Edit
gcc library.c -o library
./library
For Windows:

bash
Copy
Edit
gcc library.c -o library.exe
library.exe

Menu Options
markdown
Copy
Edit
=== Library Management System ===
1. Add Book
2. Display Books
3. Issue Book
4. Return Book
5. Exit

File Structure
bash
Copy
Edit
/project-folder
│
├── library.c         # Main source code
├── library.txt       # Auto-created data file for storing books
├── README.md         # Project documentation
⚠ Notes
library.txt must be in the same directory as the executable

The file is plain text and should not be edited manually

📄 License
This project is licensed under the MIT License.
You are free to use, modify, and distribute it. See the LICENSE file for more details.# librarymanagement
