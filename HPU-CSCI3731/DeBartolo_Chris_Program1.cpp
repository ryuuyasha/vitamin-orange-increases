/*
   Program by: Chris DeBartolo
   FileName: DeBartolo_Chris_Program1.cpp

   Program description: This program prompts the user to enter their name and 
     weight in kilograms (kg), then outputs the equivalent weight in pounds 
	 (lbs).  All weight output is formatted to 2 decimal places.

   Input: 
     User's name
	 User's weight in kg

   Algorithm:
     Display program welcome and introduction
	 FOR eternal loop
	   Set alphabetic flag to true
	   Display request for user's name
	   Read user's name
	   FOR 0 to string size
	     IF current character !alphabetic and !space and !dash THEN
		   Set alphabetic flag to false
		 END IF
	   END FOR
	   IF alphabetic flag is false THEN
	     Exit eternal loop
	   END IF
	   Display error message
	 END FOR 
	 FOR eternal loop
	   Display request for weight in kilograms
	   Read user input
	   IF input is numerical and greater than 0 THEN
	     Exit eternal loop
	   END IF
	   Display error message
	 END FOR
	 Calculate user's weight in pounds
	 Display line of asterisks
	 Display user's name
	 Display user's weight in kg
	 Display user's weight in lbs
	 Display line of asterisks

   Output: 
     User's name
	 User's weight in kgs (to 2 decimal places) 
	 User's weight in lbs (to 2 decimal places) 

   Originality: I, Chris DeBartolo, worked alone on this and it is my 
     original work.

   Program test output: 
   RUN #1
   Welcome!

   This program will take your name and weight in
   kilograms then calculate your weight in pounds.

   Please enter your name: Ann Huntington-Smith

   Please enter your weight in kilograms: seventy
   Please use digits to enter a number greater than 0.

   Please enter your weight in kilograms: 70

   *********************************************************************

   Name: Ann Huntington-Smith

   Weight in kilograms: 70.00

   Weight in pounds: 154.00

   *********************************************************************
   END RUN#1.


   RUN #2
   Welcome!

   This program will take your name and weight in
   kilograms then calculate your weight in pounds.

   Please enter your name: Bob Johnson 3

   Only letters, spaces, and dashes are allowed.
   Please enter your name: Bob Johnson III

   Please enter your weight in kilograms: -1
   Please use digits to enter a number greater than 0.

   Please enter your weight in kilograms: 76.456

   *********************************************************************

   Name: Bob Johnson III

   Weight in kilograms: 76.46

   Weight in pounds: 168.20

   *********************************************************************
   END RUN#2


   RUN #3
   Welcome!

   This program will take your name and weight in
   kilograms then calculate your weight in pounds.

   Please enter your name: Charlie's

   Only letters, spaces, and dashes are allowed.
   Please enter your name: Charlie

   Please enter your weight in kilograms: 0
   Please use digits to enter a number greater than 0.

   Please enter your weight in kilograms: 82.79

   *********************************************************************

   Name: Charlie

   Weight in kilograms: 82.79

   Weight in pounds: 182.14

   *********************************************************************
   END RUN#3
*/
#include <iomanip>  
#include <iostream>
#include <string>

using namespace std;

int main() {
	bool checkAlphabetic;
	const double CONVERSION_KG_TO_LB = 2.2;
	double weightKg = 0;
	double weightLb = 0;
	unsigned int i = 0;
	string userName, stars;

	// Set decimal precision to 2 places.
	cout << fixed << showpoint << setprecision(2);

	cout << "Welcome!" << endl;
	cout << "\nThis program will take your name and weight in" << endl;
	cout << "kilograms then calculate your weight in pounds.\n" << endl;

	for (;;) {
		checkAlphabetic = true;
		cout << "Please enter your name: ";
		getline(cin, userName);
		// Check that every character is a letter, space, or hyphen.
		for (i = 0; i < userName.size(); i++) {
			if (!isalpha(userName[i]) && (userName[i]!=' ') && 
				(userName[i]!='-')) 
				checkAlphabetic = false;
		}
		if (checkAlphabetic == true) 
			break;
		cin.clear();
		cerr << "\nOnly letters, spaces, and dashes are allowed." << endl;
	}

	for (;;) {
		cout << "\nPlease enter your weight in kilograms: ";
		cin >> weightKg;
		// Check if input to double was successful and that weightKg is above 0.
		if (cin.good() && (weightKg > 0))
			break;
		cin.clear();
		// Ignore remaining input through the end of the line.
		cin.ignore(INT_MAX, '\n');
		cerr << "Please use digits to enter a number greater than 0." << endl;
	}
	weightLb = weightKg * CONVERSION_KG_TO_LB;
	for (i = 0; i < 70; i++) {
		stars += "*";
	}
	cout << "\n" << stars << endl;
	cout << "\nName: " << userName << endl;
	cout << "\nWeight in kilograms: " << weightKg << endl;
	cout << "\nWeight in pounds: " << weightLb << endl;
	cout << "\n" << stars << endl;
	return 0;
}