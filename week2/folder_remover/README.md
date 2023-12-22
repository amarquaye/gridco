# Folder Remover

## Table Of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Clone The Repo](#clone-the-repo)
  - [Run The Application](#run-the-application)
  - [Note](#note)
- [Contributing](#contributing)

## Introduction

Folder remover is an application written in Python by Jesse Amarquaye during Industrial Attachment at Ghana Grid Company(GRIDCo).
The purpose of this application is to remove unwanted folders and save precious space(memory).

## Getting Started

To run the application you first have to clone the repo.

### Clone The Repo

Run this _command_:

```bash
git clone https://github.com/amarquaye/gridco.git
```

Then change directory into the folder:

```bash
cd gridco/week2/folder_remover
```

### Run the application

To run the application you just have to use this approach.
Type python rmfol.py followed by any number of arguments.
Just make sure that the arguments you enter are valid folder-names and also make sure that they are empty since the application only removes or deletes emply folders only.

Like this:

```bash
python rmfol.py <folder-to-remove>
```

Or if you want to remove multiple folders:

```bash
python rmfol.py <folder1> <folder2> <folder3> <folder...>
```

### Note

The application is case-sensitive so **folder** is not the same as **Folder** or **FOLDER**.

## Contributing

You can contribute to this project by either one of these methods:

- Creating an issue, so we fix or make corrections to make this project better.
- Fork the repo and make a pull request.
- Or you can just email me via [mail](mailto:engineeramarquaye@gmail.com)
