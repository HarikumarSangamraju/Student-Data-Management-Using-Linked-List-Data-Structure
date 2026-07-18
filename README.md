# Student Record Management System

A **menu-driven, C command-line application** for managing student records â€” built on a singly linked list, with file-based persistence and a clean, modular codebase.

---

## Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Data Model](#-data-model)
- [Design Decisions](#-design-decisions)
- [Build Instructions](#-build-instructions)
- [Usage](#-usage)
- [Menu Reference](#-menu-reference)
- [Persistence Format](#-persistence-format)
- [Possible Improvements](#-possible-improvements)
- [Connect With Me](#-connect-with-me)

---

## Overview

This project implements a **Student Record Management System** entirely in C, without any external libraries or database engine. Records â€” roll number, name, and marks â€” are stored in a **singly linked list** in memory during runtime, and can be saved to / loaded from a flat file (`student.data`) so data survives across program runs.

The codebase is split into small, single-responsibility source files (one function/feature per file), making it easy to navigate, extend, or plug into a build system.

---

## Features

- **Add** a new student record
- **Show** all records in tabular form
- **Modify** a record â€” search by roll number, name, or marks
- **Delete** a single record by roll number or name
- **Delete all** records at once
- **Sort** the list by name or by marks (bubble sort)
- **Reverse** the entire list
- **Save** records to disk on demand
- **Auto-load** saved records on startup
- **Exit** with an explicit choice to save or discard changes

---

## Project Structure

```
.
â”œâ”€â”€ Makefile          # Build configuration
â”œâ”€â”€ student.h         # Struct definition + function prototypes
â”œâ”€â”€ main.c            # Entry point, menu loop, exit_list(), count()
â”œâ”€â”€ stud_load.c       # load_list()     â€” loads student.data on startup
â”œâ”€â”€ stud_add.c        # add_new()       â€” inserts a new record
â”œâ”€â”€ stud_show.c       # show_list()     â€” displays all records
â”œâ”€â”€ stud_del.c        # delete_a_node() â€” deletes one record
â”œâ”€â”€ stud_mod.c        # modify()        â€” edits an existing record
â”œâ”€â”€ stud_sort.c       # sort_list()     â€” sorts by name/marks
â”œâ”€â”€ stud_reverse.c    # reverse_list()  â€” reverses the list
â”œâ”€â”€ stud_deleteall.c  # delete_all()    â€” clears the list
â”œâ”€â”€ stud_save.c       # save()          â€” writes list to disk
â”œâ”€â”€ README.md
â”œâ”€â”€ LICENSE
â””â”€â”€ .gitignore
```

Every `.c` file includes `student.h`, which centralizes the shared `sll` (singly linked list) struct and all function prototypes â€” this is the single source of truth for the module's public interface.

---

## Data Model

Each student record is represented as a node:

```c
typedef struct stu {
    int   roll;       // Unique roll number
    char  name[20];   // Student name (max 19 chars + null terminator)
    float marks;      // Marks / score
    struct stu *nxt;  // Pointer to the next node
} sll;
```

The list is referenced through a single head pointer (`sll *hptr`), initialized to `NULL` and passed by reference (`sll **`) to any function that may change what the head points to (add, delete, delete-all, reverse).

---

## Design Decisions

This section documents the *intentional* behavior baked into the system â€” useful context for anyone reading or extending the code.

### 1. Automatic, gap-filling roll numbers
Roll numbers are **not** manually entered â€” they're auto-assigned by `add_new()`:
- If the list is empty, the new record becomes roll `1`.
- If the first record isn't roll `1` (e.g., it was deleted), the new record is inserted at the head as roll `1`.
- Otherwise, the list is walked to find the **first gap** in the roll sequence (e.g., `1, 2, 4` â†’ gap at `3`) and the new record is inserted there.
- If no gap exists, the record is appended with `roll = last roll + 1`.

This keeps roll numbers dense and reusable instead of ever-increasing, at the cost of an O(n) scan on every insert.

### 2. In-place sorting, not pointer re-linking
`sort_list()` uses a **bubble sort** that swaps node *contents* (`roll`, `name`, `marks`) rather than re-linking `nxt` pointers. This is simpler to reason about but means node *identity* (memory address) does not track a particular student after a sort.

### 3. Array-assisted list reversal
`reverse_list()` temporarily stores all node pointers in a dynamically allocated array (`sll **a`), then re-links `nxt` pointers in reverse order. This trades O(n) extra memory for a straightforward, easy-to-verify reversal algorithm.

### 4. Explicit save vs. auto-load asymmetry
- **Saving is manual** â€” the user must press `v/V` (or choose "save & exit") to persist data.
- **Loading is automatic** â€” `load_list()` runs once at program startup and silently does nothing if `student.data` doesn't exist yet (first run).

This mirrors a typical "open file â†’ edit â†’ explicit save" workflow rather than auto-saving every change.

### 5. Menu is case-insensitive
Every menu option accepts both upper and lower case (`A`/`a`, `D`/`d`, etc.) by normalizing input with a simple `+= 32` ASCII shift.

### 6. Search-before-modify pattern
`modify()` never edits blindly â€” for name/marks-based searches, it first **lists all matching records**, then asks the user to specify the exact roll number to edit. This avoids accidentally modifying the wrong record when names or marks aren't unique.

### 7. Modular, one-feature-per-file layout
Rather than one large `main.c`, each menu action lives in its own translation unit. This keeps diffs small, makes the Makefile's dependency rule (`%.o: %.c student.h`) trivial, and mirrors how the project would scale if features were added or removed.

---

## Build Instructions

**Requirements:** `gcc` and `make` (Linux/macOS/WSL recommended).

```bash
# Clone or download the project, then:
make
```

This compiles all source files and links them into an executable named `student_record`.

To remove build artifacts and the runtime data file:

```bash
make clean
```

---

## Usage

```bash
./student_record
```

You'll be greeted with a menu. Enter the corresponding letter (case-insensitive) and follow the prompts.

```
________________________________
| **** STUDENT RECORD MENU **** |
|  --------------------------   |
| a/A : Add new record          |
| d/D : Deleat a node           |
| s/S : Show the list           |
| m/M : Modify a record         |
| v/V : Save                    |
| e/E : Exit                    |
| t/T : Sort the list           |
| b/B : Delate all the records  |
| r/R : Reverse the list        |
---------------------------------
```

---

## Menu Reference

| Key | Action |
|---------|----------------------------------------------------------------|
| `a`/`A` | Add a new student record (name + marks; roll is auto-assigned) |
| `d`/`D` | Delete a record by roll number or name |
| `s`/`S` | Show all records in a table |
| `m`/`M` | Modify a record (search by roll, name, or marks) |
| `v`/`V` | Save the current list to `student.data` |
| `e`/`E` | Exit â€” choose "Save & Exit" or "Exit without saving" |
| `t`/`T` | Sort the list by name or by marks |
| `b`/`B` | Delete all records |
| `r`/`R` | Reverse the order of the list |

---

## Persistence Format

Records are stored as **plain text**, one record per line, in `student.data`:

```
<roll> <name> <marks>
```

**Example:**

```
1 Asha 88.500000
2 Ravi 76.250000
4 Meera 91.000000
```

This human-readable format makes it easy to inspect, back up, or edit the data outside the application if needed.

---

## Possible Improvements

- Switch to `fgets` + parsing for names containing spaces.
- Add input validation (marks range, non-empty names).
- Replace bubble sort with a more efficient sorting algorithm for large datasets.
- Add unit tests for core list operations.
- Support CSV export for easier integration with spreadsheets.

---

## Connect With Me

-GitHub: (https://github.com/HarikumarSangamraju)
- LinkedIn: [https://www.linkedin.com/in/hari-kumar-66b6382bb?utm_source=share_via&utm_content=profile&utm_medium=member_android]([)
