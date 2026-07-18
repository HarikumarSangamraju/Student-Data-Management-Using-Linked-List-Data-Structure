# Student Record Management System

A simple command-line Student Record Management System written in C, using a
singly linked list to store records in memory and a flat file
(`student.data`) for persistence.

## Features

| Option | Action                          |
|--------|----------------------------------|
| a / A  | Add a new record                |
| d / D  | Delete a node (by roll no/name) |
| s / S  | Show the list                   |
| m / M  | Modify a record                 |
| v / V  | Save the list to disk           |
| e / E  | Exit (with optional save)       |
| t / T  | Sort the list (by name/marks)   |
| b / B  | Delete all records              |
| r / R  | Reverse the list                |

On startup, the program automatically loads any previously saved records
from `student.data` (see `stud_load.c`).

## Project structure

```
.
├── Makefile
├── student.h            # struct + function prototypes
├── main.c               # menu loop, exit_list(), count()
├── stud_load.c          # loads records from student.data on startup
├── stud_add.c           # add_new()
├── stud_show.c          # show_list()
├── stud_del.c           # delete_a_node()
├── stud_mod.c           # modify()
├── stud_sort.c          # sort_list()
├── stud_reverse.c       # reverse_list()
├── stud_deleteall.c     # delete_all()
├── stud_save.c          # save()
└── README.md
```

## Build

Requires `gcc` and `make`.

```bash
make
```

This produces an executable named `student_record`.

## Run

```bash
./student_record
```

## Clean

```bash
make clean
```

Removes object files, the executable, and `student.data`.

## Data format

Records are stored one per line in `student.data` as plain text:

```
<roll> <name> <marks>
```

Example:

```
1 Asha 88.500000
2 Ravi 76.250000
```

## Known limitations

- `name` is fixed at 19 characters + null terminator (`char name[20]`);
  longer names will overflow.
- Input is read with `scanf`, so names containing spaces are not supported.
- No input validation on numeric fields (e.g. negative marks are accepted).
