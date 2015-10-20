#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;

/************************************************************************
* Class: Exception
*
* Constructors:
*	Exception()
*		m_msg initialized to nullptr
*
*	Exception(char* msg)
*		m_msg initialized to msg
*
*	Exception(const Exception &copy)
*		Copy constructor
*
* Destructor:
*	~Exception()
*		Deletes m_msg
*
* Mutators:
*	Exception& operator= (const Exception& rhs)
*		If the invoking object and rhs are not the same, creates a new
*		Exception that is a copy of rhs
*
* Methods:
*	const char* GetMessage()
*		Returns m_msg
*
*	void SetMessage(char* msg)
*		Sets m_msg to msg
*
*	friend ostream& operator<<(ostream &stream, const Exception &except)
*		Overloaded << operator
*
*************************************************************************/

class Exception
{
public:
	//Default ctor
	Exception();

	//One arg ctor
	Exception(char* msg);

	//Copy ctor
	Exception(const Exception &copy);

	//Destructor
	~Exception();

	//Operator = function
	Exception& operator=(const Exception &rhs);

	//Returns m_msg
	const char* getMessage();

	//Sets m_msg to msg
	void setMessage(char* msg);

	//Operator << function
	friend ostream& operator<<(ostream &stream, const Exception &except);

private:
	char* m_msg;				//The message for the exception
};


#endif



