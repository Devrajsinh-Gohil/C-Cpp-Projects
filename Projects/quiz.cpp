#include <iostream>
#include <string>
using namespace std;

int Calculate;
int Sum;
class Quiz
{
private:
	string Ques;
	string Ans1;
	string Ans2;
	string Ans3;
	string Ans4;
	int Right_Answer;
	int marks;

public:

	void VALUES(string, string,
				string, string,
				string, int, int);


	void ASK();
};


int main()
{
	cout << "\n\n\t\t\t\tQUIZ ZONE"
		<< endl;
	cout << "\nTO START PRESS ENTER "
		<< "QUIZ... " << endl;

	// Input
	cin.get();

	string Name;
	int Age;

	// Input the details
	cout << "Enter your name?"
		<< endl;
	cin >> Name;
	cout << endl;

	cout << "Your age"
		<< endl;
	cin >> Age;
	cout << endl;

	string Respond;
	cout << "Ready for the Quiz"
		<< " the Quiz " << Name
		<< "? yes/no" << endl;
	cin >> Respond;

	if (Respond == "yes") {
		cout << endl;
		cout << "Best of Luck!" << endl;
	}
	else {
		cout << "Thank you!" << endl;
		return 0;
	}


	Quiz A;
	Quiz B;
    Quiz C;
	Quiz D;
	Quiz E;
	Quiz F;
	Quiz G;
	Quiz H;
	Quiz I;
	Quiz J;

	A.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	B.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	C.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	D.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	E.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	F.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	G.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	H.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	I.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);
	J.VALUES("Question : ", "Answer 1",
				"Answer 2", "Answer 3",
				"Answer 4", 3, 10);

	A.ASK();
	B.ASK();
	C.ASK();
	D.ASK();
	E.ASK();
	F.ASK();
	G.ASK();
	H.ASK();
	I.ASK();
	J.ASK();

	// Display the Sum score
	cout << "Total score = " << Sum
		<< "out of 100" << endl;

	// Display the results

	// If the player pass the quiz
	if (Sum >= 70) {
		cout << "CONGRATULATION!!! You have passed the"
			<< " quiz!" << endl;
	}

	// Otherwise
	else {
		cout << "SORRY! You failed the quiz."
			<< endl;
		cout << "Better luck next time."
			<< endl;
	}
	return 0;
}

// Function to set the values of
// the questions
void Quiz::VALUES(
	string q, string a1,
	string a2, string a3,
	string a4, int ca, int pa)
{
    Ques = q;
	Ans1 = a1;
	Ans2 = a2;
	Ans3 = a3;
	Ans4 = a4;
	Right_Answer = ca;
	marks = pa;
}

// Function to ask questions
void Quiz::ASK()
{
	cout << endl;

	// Print the questions
	cout << Ques << endl;
	cout << "1. " << Ans1 << endl;
	cout << "2. " << Ans2 << endl;
	cout << "3. " << Ans3 << endl;
	cout << "4. " << Ans4 << endl;
	cout << endl;

	// Display the answer
	cout << "What is your answer?(in number)"
		<< endl;
	cin >> Calculate;

	// If the answer is correct
	if (Calculate == Right_Answer) {
		cout << endl;
		cout << "Correct !" << endl;

		// Update the correct score
		Sum = Sum + marks;
		cout << "Score = " << marks
			<< " out of "
			<< marks
			<< "!" << endl;
		cout << endl;
	}

	// Otherwise
	else {
		cout << endl;
		cout << "Wrong !" << endl;
		cout << "Score = 0"
			<< " out of "
			<< marks
			<< "!" << endl;
		cout << "Correct answer = "
			<< Right_Answer
			<< "." << endl;
		cout << endl;
	}
}