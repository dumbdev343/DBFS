# DBFS
**A simple database written in C++**


# What is it? 

Database from Scratch or DBFS for short is one of my first C++ projects I've made since learning the language. It's goal isn't to be a highly trustable database or anything, just a pure project I came up with and wanted to try creating. It's not reliable, doesn't support very much (yet atleast) but it has the features I want it to have.

# Features
- A config file which at the moment only is used for the database file path. 
- Text insertion via the terminal running it
- Reading the updated version of it after database updates
- Reading the most recent version of the database before writing to the database

# Build
I developed this program on an ARM Mac. I have compiled it on an x86 Linux box with no issues, however I cannot guarantee the same for you.
```sh
git clone https://github.com/dumbdev343/DBFS.git
cd DBFS
g++ dbfs.cpp -std=c++17 -o dbfs
```
