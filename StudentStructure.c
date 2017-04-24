#include <stdio.h>
#include <stdlib.h>

struct student{
	char studentFirstName[ 20 ];
	char studentLastName[ 20 ];
	long studentNumber;
	unsigned int studentFinalGrade;
	unsigned int studentMidtermGrade;
	struct student* nextStudentPointer;
};

void printStudentInformation( struct student* studentPointer );

int main( void )
{
	struct student firstStudent = { "Azim", "Kuruca", 349345, 100, 100 };
	struct student secondStudent = { "Serdar", "Cida", 34560, 100, 100 };
	struct student thirdStudent = { "Recai", "Ataman", 34234, 100, 100 };

	firstStudent.nextStudentPointer = &secondStudent;
	secondStudent.nextStudentPointer = &thirdStudent;
	printStudentInformation( &firstStudent );
}

void printStudentInformation( struct student* studentPointer )
{
	struct student* currentStudentPointer = studentPointer;
	if( currentStudentPointer == NULL )
	{
		printf( "the student list is empty...\n" );
	}
	else
	{
		int studentCounter = 1;
		while( currentStudentPointer != NULL )
		{
			printf( "student id %d\t Student Name %s\n", studentCounter, currentStudentPointer->studentFirstName );
			studentCounter++;
			currentStudentPointer = currentStudentPointer->nextStudentPointer;
		}
	}
}
