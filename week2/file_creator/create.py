""" Python program to create an empty file just like the touch command in UNIX-based systems 

    Created by Jesse Amarquaye on Tuesday, 28th November, 2023
    
"""

import sys


def main():
    """ Usage : 'create testfile.txt'
        >>>
        Creates a empty file with the same name as 'testfile.txt'
    """
    try:
        filename = sys.argv[1]

        with open(f"{filename}", "w") as myfile:
            myfile.write("")

    except Exception as e:
        print(f"Error {e}")


if __name__ == "__main__":
    main()
