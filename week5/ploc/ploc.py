"""Python application to print the number of lines of code in a file or folder(project).
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
    
        

if __name__ == "__main__":
    main()
