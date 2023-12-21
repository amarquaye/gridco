"""
Display Content.
Created by Jesse Amarquaye during Industrial Attachment at Ghana Grid Company(GRIDCo).
"""

import os
import sys


def main():
    file = sys.argv[1]

    if os.path.isfile(file):
        with open(file, "r") as filename:
            contents = filename.read()
        print(contents)
    elif os.path.isdir(file):
        folder = os.listdir(file)

        for files in folder:
            print(files)
    else:
        print("Cannot display contents")


if __name__ == "__main__":
    main()
