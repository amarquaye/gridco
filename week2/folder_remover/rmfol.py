"""
Folder Remover.
Created by Jesse Amarquaye during Industrial Attachment at Ghana Grid Company(GRIDCo).
Thursday, 30th November 2023.
"""

import os
import sys


def main():
    folders = sys.argv[1:]

    try:
        for folder in folders:
            os.rmdir(folder)
    except Exception as e:
        print(f"Error {e}\nCannot remove folder(s)")


if __name__ == "__main__":
    main()
