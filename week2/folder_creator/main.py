"""
Folder Creator.
Created by Jesse Amarquaye during Industrial Attachment at Ghana Grid Company(GRIDCo).
"""

import os
import sys


def main():
    folders = sys.argv[1:]

    try:
        for folder in folders:
            os.mkdir(folder)
    except Exception as e:
        print(f"Error {e}\nCannot create folder!")


if __name__ == "__main__":
    main()
