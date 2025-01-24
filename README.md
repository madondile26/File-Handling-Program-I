# Task 5 File Handling Program

## Overview

The **Task 5 File Handling Program** is a C++ application designed to handle circuit analysis by calculating and storing load voltage, load current, and load power values for various load resistances. The results are saved in text files for future reference and analysis.

## Features

- **Circuit Element Input:**
  - Users can input supply voltage (E) and series resistor (R).
- **Load Voltage Calculation:**
  - Calculates the load voltage for different resistance values and stores the results in a file.
- **Load Current and Power Calculation:**
  - Computes the load current and power for different resistances and logs them into another file.
- **File Handling:**
  - Outputs results in a well-structured tabular format to `file1.txt` and `file2.txt`.
- **User-Friendly Menu:**
  - Provides an interactive menu with options to enter circuit values, perform calculations, and exit.

## How to Run the Program

1. **Compile the program:**

   ```bash
   g++ Task5_FileHandling.cpp -o circuit_calculator
   ```

2. **Run the executable:**

   ```bash
   ./circuit_calculator
   ```

3. **Follow the on-screen menu options:**

   - Enter circuit parameters.
   - Perform calculations.
   - View results stored in output files.

## Menu Options

1. Enter circuit element values (supply voltage, series resistor).
2. Calculate and store load voltage values.
3. Calculate and store load current and power values.
4. Exit the program.

## Input Validations

- Ensures numerical inputs for voltage, resistance, and current.
- Checks for correct file operations and handles errors appropriately.
- Prevents invalid input by using input validation loops.

## Sample Output

Example file content after calculations:

```
---------------------------------------
Load Resistance RL	Voltage Vrl
---------------------------------------
10			5.45
20			6.78
---------------------------------------
```

## Technologies Used

- C++
- File Handling (`fstream`)
- Mathematical Operations (`math.h`)
- Standard I/O (`iostream`)

## Future Improvements

- Add error logging for better debugging.
- Introduce graphical user interface (GUI) for better visualization.
- Implement database storage for better data management.

---

Thank you for using the Task 5 File Handling Program!

