"""
File Remover
Created by Jesse Amarquaye during Industrial Attachment at Ghana Grid Company(GRIDCo)
Thursday, 30th November 2023.
"""

import os
import sys


def main():
    filename = sys.argv[1:]

    try:
        for file in filename:
            os.remove(file)
    except Exception as e:
        print(f"Error {e}\n{filename} is not a file!")


if __name__ == "__main__":
    main()
