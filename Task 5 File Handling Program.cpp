/*Task 5 File Handling Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
  Name: X-Nardo
  Surname: Madondile
  Occupation: Programming Agent
  Rank: General
  Place of Work: Skhotheni Empire University of Artifitial and Criminal Intellegence
  For More Info on How to Become a Programming Lord Contact Me at This Phone Number: 0646621730
  If My Phone Goes to Voicemail Then SORRY!!!....Try Again Next Year....
*/
#include <fstream>
#include<math.h>
#include <iostream>
using namespace std;

void loadVoltageValue_Vrl(double supplyVoltage_E, double seriesResistor_R, double loadResistance_RL[], int size)
{
	double loadVoltageValue_Vrl[20];

	ofstream fout;
	fout.open("file1.txt", ios::out); // Open the first file in write mode.

	if (!fout)
	{
		cout << "ERROR OPENING FILE!!!...."; // Display this message if the file cannot be accessed.
		exit(1);
	}
	else { 

		// Print out this message to the screen if no errors occured while trying to open the file.
		cout << "File write operation performed successfully!!!....\n" << endl;

		// Write all your results in table format to the file1.txt file.
		fout << "---------------------------------------" << endl;
		fout << "Load Resistance RL Load\t\tVoltage Vrl" << endl;
		fout << "---------------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			loadVoltageValue_Vrl[i] = loadResistance_RL[i] * supplyVoltage_E / seriesResistor_R + loadResistance_RL[i];
			fout << loadResistance_RL[i] << "\t\t\t\t\t\t\t" << loadVoltageValue_Vrl[i] << endl;
		}
		fout << "---------------------------------------" << endl;

		fout.close();
	}

}

double loadPower_Prl(double supplyVoltage_E, double seriesResistor_R, double loadResistance_RL[], int size)
{
	double loadPower = 0.0; // Initialise the loadPower variable.

	for (int i = 0; i < size; i++)
	{
		loadPower = pow(supplyVoltage_E, 2) / seriesResistor_R + loadResistance_RL[i];
	}

	return loadPower;
}

double loadCurrent_Irl(double supplyVoltage_E, double seriesResistor_R, double loadResistance_RL[], int size)
{
	// Initialise both the loadCurrent and the loadPower variables.
	double loadCurrent = 0.0;
	double loadPower = 0.0;

	for (int i = 0; i < size; i++)
	{
		// Calculate for the load power.
		loadPower = pow(supplyVoltage_E, 2) / seriesResistor_R + loadResistance_RL[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		// Calculate for the load current.
		loadCurrent = sqrt(loadPower / seriesResistor_R + loadResistance_RL[i]);
	}

	return loadCurrent;
}

int main()
{
	double supplyVoltage_E = 0.0;
	double seriesResistor_R = 0.0;
	double loadResistance_RL[20] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
	double loadPower;
	double loadCurrent;
	char Option = ' ';

	while (Option != 'd')
	{
		cout << "\nPlease enter a letter of your choice out of the following options:\n" << endl;
		cout << "(a) Enter the values of the circuit elements, ie supply voltage, E and series resistor, R." << endl;
		cout << "(b) Calculate for the different load resistance, RL values the corresponding load voltage, Vrl values." << endl;
		cout << "(c) Calculate for the different load resistance, RL values the corresponding load current, Irl and the load power, Prl." << endl;
		cout << "(d) EXIT THE PROGRAM!!!....\n" << endl;
		cin >> Option;

		if (Option == 'a')
		{
			// Prompt the user for the values of the supply voltage E and series resistor R.
			cout << "Enter the value of the supply voltage, E: ";
			cin >> supplyVoltage_E;
			cout << "Enter the value of the series resistor, R: ";
			cin >> seriesResistor_R;
		}

		if (Option == 'b')
		{
			// Call the load voltage function.
			loadVoltageValue_Vrl(supplyVoltage_E, seriesResistor_R, loadResistance_RL, 20);
		}

		if (Option == 'c')
		{
			ofstream fout;
			fout.open("file2.txt", ios::out); // Open the second file in write mode.

			if (!fout)
			{
				cout << "ERROR OPENING FILE!!!...." << endl; // Display this error message if the file cannot be accessed.
				exit(1);
			}
			else{

				// Print out this message to the screen if no errors occured while trying to open the file.
				cout << "\nFile write operation performed successfully!!!...." << endl;

				loadPower = loadPower_Prl(supplyVoltage_E, seriesResistor_R, loadResistance_RL, 20);
				loadCurrent = loadCurrent_Irl(supplyVoltage_E, seriesResistor_R, loadResistance_RL, 20);

				// Write all your results in table format to the file1.txt file.
				fout << "----------------------------------------------------------------------" << endl;
				fout << "Load Resistance RL\t\t\tLoad Current Irl\t\t\tLoad Power Prl" << endl;
				fout << "----------------------------------------------------------------------" << endl;
				for (int i = 0; i < 20; i++)
				{
					fout << loadResistance_RL[i] << "\t\t\t\t\t\t\t" << loadCurrent << "\t\t\t\t\t\t" << loadPower << endl;
				}
				fout << "----------------------------------------------------------------------" << endl;

				fout.close();
			}
		}

		if (Option == 'd')
		{
			// Provides the only point of exit from the program.
			cout << "-------------------------YOU'VE JUST EXITED THE PROGRAM!!!...-------------------------" << endl;
		}
	}
	
	return 0;
}

