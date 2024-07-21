# Library Project

## Overview
This project is a simple library management system implemented in C. It includes functionalities for managing books, employees, and users. The system supports operations such as adding, editing, deleting, searching, and displaying books, managing trach (deleted books), pinning books, and user interactions like reserving and viewing books.

## Project Structure
The project consists of the following files:
- `main.c`: Entry point of the program.
- `myLib.c`: Library functions.
- `employee.c`: Employee-related functions.
- `user.c`: User-related functions.
- `*.h`: Header files for declarations.
- `*.txt`: Data files used by the program.

## Setup Instructions
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/library_project.git
    ```
2. Navigate to the project directory:
    ```bash
    cd library_project
    ```
3. Compile the project:
    ```bash
    gcc -o main main.c myLib.c employee.c user.c
    ```
4. Run the program:
    ```bash
    ./main
    ```

## Functions Overview

### `myLib.c` Functions
| Function Name          | Description                                      |
|------------------------|--------------------------------------------------|
| `load_data()`          | Loads data from files.                           |
| `save_data()`          | Saves data to files.                             |
| `init_library()`       | Initializes the library system.                  |
| `cleanup_library()`    | Cleans up resources before exiting.              |

### `employee.c` Functions
| Function Name               | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| `Employee()`                | Main function for employee operations.                       |
| `add_to_file()`             | Adds a new item to a file.                                   |
| `create_book()`             | Creates a new book entry.                                    |
| `add_books()`               | Adds books to the library.                                   |
| `edit_bookName()`           | Edits the name of a book.                                    |
| `edit_authorName()`         | Edits the author name of a book.                             |
| `edit_id()`                 | Edits the ID of a book.                                      |
| `edit_books()`              | Edits book details.                                          |
| `search_bookName()`         | Searches for a book by name.                                 |
| `search_authorName()`       | Searches for a book by author name.                          |
| `search_id()`               | Searches for a book by ID.                                   |
| `search_books()`            | Searches for books.                                          |
| `add_to_trach()`            | Adds a deleted book to the trach.                            |
| `delete_bookName()`         | Deletes a book by name.                                      |
| `delete_authorName()`       | Deletes a book by author name.                               |
| `delete_id()`               | Deletes a book by ID.                                        |
| `delete_books()`            | Deletes books.                                               |
| `dispay_books()`            | Displays books.                                              |
| `display_all_books_in_file()` | Displays all books from the file.                           |
| `display_trach()`           | Displays the trach (deleted books).                          |
| `display_all_books_in_trach()` | Displays all books in the trach.                          |
| `delete_trach_bookName()`   | Deletes a book from the trach by name.                       |
| `delete_trach_authorName()` | Deletes a book from the trach by author name.                |
| `delete_trach_id()`         | Deletes a book from the trach by ID.                         |
| `delete_from_trach()`       | Deletes a book from the trach.                               |
| `pin_book()`                | Pins a book.                                                 |
| `display_pin_books()`       | Displays pinned books.                                       |
| `display_all_pin_books()`   | Displays all pinned books.                                   |
| `check_space()`             | Checks for available space.                                  |

### `user.c` Functions
| Function Name           | Description                          |
|-------------------------|--------------------------------------|
| `User()`                | Main function for user operations.   |
| `DisplayMenu()`         | Displays the user menu.              |
| `ReserveBook()`         | Reserves a book for the user.        |
| `ViewReservedBooks()`   | Views reserved books.                |
| `CheckAvailability()`   | Checks the availability of a book.   |
| `generateRandomNumber()` | Generates a random number.          |

## How to Use
1. Run the program and follow the on-screen instructions.
2. Employees can manage books, trach, and pinned books using the employee functions.
3. Users can reserve and view books using the user functions.

## Contributing
Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
