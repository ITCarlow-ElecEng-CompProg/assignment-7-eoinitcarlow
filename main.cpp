/*Eoin Finlay
  PolCart Conversion
  18 Oct 2017*/


//Preprocessor Directives
#include <iostream>
#include <math.h>

using namespace std;

//Function Declarations
int main(void);

//Main Function
int main()
{
    //Variable declarations
    char userChoice;

    //Local Function Declarations
    void cart2pol(void);
    void pol2cart(void);
    char menu(void);

    //do while loop, continue while user choice is not q
    do
    {
        userChoice = menu(); //calling menu function

        switch(userChoice)//switch case statement to run menu
        {
            case 'p': cart2pol();//calling cart2pol function
                      break;

            case 'c': pol2cart();//calling pol2cart function
                      break;

            case 'q': cout << "\n\nGoodbye" << endl;//exiting program
                      break;

            default:  cout << "\n\nInvalid Selection" << endl;
                      break;
        }
    }
    while (userChoice != 'q');

    return 0;
}

//menu function
char menu(void)
{
    //Variable declarations
    char choice;

    //Displaying menu options to user and returning choice
    cout << "\nChoose from one of the following options" <<
    "\n\nPress p for cartesian to polar conversion" <<
    "\nPress c for polar to cartesian conversion" <<
    "\nPress q to quit the program \n\n" << endl;

    cin >> choice;

    return choice;
}

//cart2pol function
void cart2pol(void)
{
    /**< variable declarations */
    double x, y, mag, angle;
    double *mag_ptr, *angle_ptr;

    /**< function prototypes */
    void cart2polCalculation(double, double, double *, double *);

    //assigning pointers to an address
    mag_ptr = &mag;
    angle_ptr = &angle;

    cout << "\n\nEnter Cartesian value for x: ";
    cin  >> x;
    cout << "\n\nEnter Cartesian value for y: ";
    cin  >> y;

    cart2polCalculation(x, y, mag_ptr, angle_ptr);//calling function for calculation

    cout << mag << " < " << angle << endl;//displaying results

    return;

}

//cart2pol calculation function
void cart2polCalculation(double xVal, double yVal, double *mptr, double *aptr)
{
    //assigning pointer value to an equation
    *mptr = sqrt(pow(xVal,2.0) + pow(yVal, 2.0));
    *aptr = atan2(yVal,xVal);

    return;
}

//pol2cart function
void pol2cart(void)
{
    //local variable declarations
    double r, ang, x, y;
    double *x_ptr, *y_ptr;

    //declaring pol2cart calculation locally
    void pol2cartCalculation(double, double, double *, double *);

    //assigning pointers to an address
    x_ptr = &x;
    y_ptr = &y;

    //prompting user to enter values
    cout << "\n\nEnter value for the magnitude: ";
    cin >> r;
    cout << "\n\nEnter value for the angle: ";
    cin >> ang;

    //calling pol2cart calculation function
    pol2cartCalculation(r, ang, x_ptr, y_ptr);

    //displaying result
    cout << x << "+" << y << "j" <<endl;

    return;
}

//pol2cart calculation function header
void pol2cartCalculation(double r, double ang, double *x_ptr, double *y_ptr)
{
  //changing pointer value by way of an equation
  *x_ptr = r * cos(ang);
  *y_ptr = r * sin(ang);

  return;
}






