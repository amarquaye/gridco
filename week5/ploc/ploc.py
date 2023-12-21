"""Python application to print the number of lines of code in a file.
Created by Jesse Amarquaye.
"""
import os
import sys


def main():
    filename = sys.argv[1]

    if os.path.isfile(filename):
        with open(filename, "r") as file:
            content = file.readlines()

        print(f"{filename} has  {len(content)} lines of code.")
    elif os.path.isdir(filename):
        print(f"{filename} is a folder.\nPloc only works on files!")
    else:
        print(f"Sorry, cannot read {filename}.")


if __name__ == "__main__":
    main()
