# Anthony Vigil
# CS210 Programming Languages

import re
import string
import os.path
from os import path

# For callProcedure("CountItems")
# Calls function CountItems
# Returns list from text file as output

def CountItems():

    # Open text file and read it
    textfile = open("CS210_Project_Three_Input_File.txt", "r")

    # Variable that holds words in list, library
    library = dict()

    # Reads each line from file
    for line in textfile:

        # Remove spaces or lines
        line = line.strip()

        # Put all letters lowercase
        text = line.lower()
        
        # Scans if text are in library variable
        if text in library:

            # Scans number of appearances and adds by one
            library[text] = library[text] + 1

        # Else if not in library, set equal to one
        else:
           
            # Set equal to one
            library[text] = 1
    
    # Print all from library
    for key in list (library.keys()):
        print(key.capitalize(), ":", library[key])

    # Close the file
    textfile.close()


# Call function CountFreq
# callIntFunc("CountFreq", findItem)
# Output: Returns the number of time the item was on list

def CountFreq(findItem):

    # Changes user input to lowercase to scan file
    findItem = findItem.lower()

    # Open text file
    textfile = open("CS210_Project_Three_Input_File.txt", "r")

    # Variable to track number of items
    countWords = 0

    # Scan each line in text file
    for line in textfile:

        # Remove spaces or lines
        line = line.strip()

        # Changes to lowercase to scan
        text = line.lower()
        
        # If text equals the user input, add one
        if text == findItem:

            # Adds one to variable
            countWords += 1

    # Returns value and stores
    return countWords

    #Close opened file
    textfile.close()



# Calls function FreqHistogram
# callProcedure("FreqHistogram")
# Output: Document frequency.dat showing frequency of item
# Return: frequency.dat

def FreqHistogram():

    # Read text file
    textfile = open("CS210_Project_Three_Input_File.txt", "r")

    # Create a new file named frequency.dat
    freq = open("frequency.dat", "w")

    # Library variable to store words
    library = dict()

    # Scans each line in text file
    for line in textfile:

        # Removes spaces or lines
        line = line.strip()

        # Changes to lowercase 
        text = line.lower()
        
        # Scans for appearance of word in library
        if text in library:

            # Adds one to text if appeared
            library[text] = library[text] + 1

        # If not in library, make text equal to one
        else:

            # Set text equal to one
            library[text] = 1

    # Print each value in library
    for key in list (library.keys()):

        # Formatted to show word with a new line
        freq.write(str(key.capitalize()) + " " + str(library[key]) + "\n")

    #Close the opened files
    textfile.close()
    freq.close()