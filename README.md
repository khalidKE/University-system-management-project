# FCAI System

This is a C++ project for managing student registrations, lab information, subjects, professors, library operations, and worker data within an academic institution.

## Features

- **Student Management:** Register new students, display student information.
- **Lab Management:** Add new labs, display existing labs.
- **Subject Management:** Add new subjects, display subjects.
- **Professor Management:** Display a list of professors.
- **Library Operations:** Add students, books, borrow and return books.
- **Worker Management:** Add, edit, delete, and display worker information.
- **Admin Panel:** Admin login for managing various aspects of the system.

## Classes Overview

### `user`
A base class representing a user with basic information.

### `Student` (Inherits from `user`)
Handles student-specific data and operations including registration and displaying student details.

### `FCAI`
Handles admin login and user login functionalities.

### `Labs`
Manages lab information such as name, number, capacity, and enrollment.

### `Subject`
Manages subject details including subject name and professors.

### `Professors`
Displays a list of professors.

### `University` (Inherits from `Professors`)
Manages students, subjects, and labs within the university.

### `Library`
Handles library operations including adding students, books, borrowing, and returning books.

### `Worker`
Manages worker data including adding, editing, deleting, and displaying workers.

## Usage
1- **Admin Login**
- Admin credentials: Username: fcai, Password: 123
- Admin can manage students, labs, subjects, professors, and workers.

2- **Student Login**
- Student credentials: Username: khalid, Password: 123
- Students can view their information, borrow and return books.

3- **Worker Management**
- Add, edit, delete, and display worker information.

4- **Library Management**
- Manage student and book information.
- Borrow and return books.
