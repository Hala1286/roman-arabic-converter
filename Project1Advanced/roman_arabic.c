/*
Program:Roman Arabic Numerals Convertor 
Programmer: Hala Hammad
Purpose:This program converts Arabic numerals to Roman And Roman numerals to Arabic.
Date:Jan 18,2020.
*/
#include<ctype.h>
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
# include<string.h>
# include<math.h>
/*declare some variables
*/
//define some variables to use it in the main.
#define CAPACITY 1000u
char u_input[CAPACITY];
int  len;
double arabicNumber;
int countArabic = 0;
int countroman = 0;
bool isArabic;
bool isRoman;
int i;
double arNum;
int j;
char romanNumber;



/*
MethodName: romanToArabic().
Accepts:  A string which represents the Roman Number. 
Returns:  A Double value which is the equivalent Arabic Number.
Date:     Jan 27,2020.

*/
//Calculate the Roman Number to have its equivalent Arabic number .
double romanToArabic(char romArray[])
{
    //declare some variables
    int length = strlen(romArray);
    double previousValue;
    double currentValue = 0;
     double answer = 0.0;
    bool thousand = false;
    bool isApostophus = false;
    double numOfBackCs = 0.0;
    double numOfCs = 0.0;

    for (j=(len-1); j>= 0; j--)
    {
         previousValue = currentValue;
        switch (romArray[j])
        {
        case 'I': currentValue = 1;
        break;
        case 'V': currentValue = 5;
            break;
        case 'X': currentValue = 10;
            break;
        case 'L': currentValue = 50;
            break;
        case 'C': currentValue = 100;
            break;
        case 'D': currentValue = 500;
            break;
        case 'M': currentValue = 1000;
            break;
        case 'S': currentValue = 0.5;
            break;
        case '.': currentValue = 0.083333;
            break;
        case '_':  thousand = true;
                  currentValue = 0;
        case '-':  thousand = true;
                  currentValue = 0;
            //answer+=currentValue;
            break;
        case ')':
            isApostophus = true;

            break;
        default: break;

        }//end switch

        //set data to calculate in apostophus system. 
        if (isApostophus == true)
        {
            if (romArray[j] == 'I')
            {
                currentValue = 0;
                answer += currentValue;
            }
            if (romArray[j] == 'C')
            {
                numOfCs++;
                currentValue = 0;
                answer += currentValue;
            }
            if (romArray[j] == ')')
            {
                numOfBackCs++;
                currentValue = 0;
                answer += currentValue;
            }
        }//end if

        //calculate vinculum system 
        else
        {
            if (thousand == false)
            {
                if ((currentValue > previousValue) || (currentValue == previousValue))
                {
                    answer += currentValue;
                }//end if
                else
                {
                    answer -= currentValue;
                }//end else
            }

            //to count the number of thousnands which are followed by- or_.
            else if (thousand == true)
            {
                if ((romArray[j]!='_' )&&(romArray[j]!='-'))
                {
                    if ((currentValue > previousValue) || (currentValue == previousValue))
                    {

                        answer += (currentValue * 1000);
                    }//end if
                    else
                    {
                        answer -= (currentValue * 1000);
                    }//end else
                }
            }
        }//end else
    }//end for
    //calculate apostrophus notation 
        if (isApostophus == true)
        {
            if (numOfBackCs == numOfCs)
            {
                answer += 1000 * pow(10, (numOfCs - 1));
            }
            else if (numOfBackCs > numOfCs)
            {
                if (numOfCs == 0)

                {
                    answer += 500 * pow(10, ((numOfBackCs - numOfCs) - 1));
                }
                else
                {
                    answer += 500 * pow(10, ((numOfBackCs - numOfCs) - 1)) + pow(10, numOfCs + 2);
                }
            }
        }

        return answer;
    }
    /*
MethodName: smallArabicToRoman().
Accepts:   A double number which represents the Arabic Numbers. 
Returns:   Does not return ant value .Its is void method.
Date:      Jan 27,2020.
    
    
    */
    
    //Calculate the Arabic Number to have its equivalent Roman number .

    //calculate numbers less than 4000
    void smallArabicToRoman(double arabNumber)
    {
        while (arabNumber > 0)
        {
            
                if (arabNumber >= 1000)
                {
                    printf("M");               
                    arabNumber -= 1000;
                }
                else if (arabNumber >= 900)
                {
                    printf("CM");
                    arabNumber -= 900;
                }
                else if (arabNumber >= 500)
                {
                    printf("D");
                    arabNumber -= 500;
                }
                else if (arabNumber >= 400)
                {
                    printf("CD");
                    arabNumber -= 400;
                }
                else if (arabNumber >= 100)
                {
                    printf("C");
                    arabNumber -= 100;
                }
                else if (arabNumber >= 90)
                {
                    printf("XC");
                    arabNumber -= 90;
                }
                else if (arabNumber >= 50)
                {
                    printf("L");
                    arabNumber -= 50;
                }

                else if (arabNumber >= 40)
                {
                    printf("XL");
                    arabNumber -= 40;
                }
                else if (arabNumber >= 10)
                {
                    printf("X");
                    arabNumber -= 10;
                }
                else if (arabNumber >= 9)
                {
                    printf("IX");
                    arabNumber -= 9;
                }

                else if (arabNumber >= 5)
                {
                    printf("V");
                    arabNumber -= 5;
                }
                else if (arabNumber >= 4)
                {
                    printf("IV");
                    arabNumber -= 4;
                }
                else if (arabNumber >= 1)
                {
                    printf("I");
                    arabNumber -= 1;
                }

                else if (arabNumber >= 0.5)
                {
                    printf("S");
                    arabNumber -= 0.5;
                }
                else if (arabNumber >= 0.083333)
                {
                    printf(".");
                    arabNumber -= 0.083333;
                }
                else if (arabNumber < 0.083333)
                    arabNumber = 0;

        }//end while

    }//end function
/*
MethodName: bigArabicToRoman().
Accepts   : A double number which represents the Arabic Numbers that are greater than or equal 4000.
Returns : Does not return ant value.Its is void method.
Date :   Jan 27, 2020.
*/

//calculate numbers more than 4000
    void bigArabicToRoman(double bigArabNumber)
    {
           unsigned int numberOfThousands ;
                    numberOfThousands=(unsigned)bigArabNumber / 1000;
                    smallArabicToRoman(numberOfThousands);
                    printf("_");
                    double restOfNumber = bigArabNumber- (long long)numberOfThousands*1000;
                    smallArabicToRoman(restOfNumber);  //invoking smallArabicToRoman() to continue counting the numbers below 4000

    }//end function





int main()
{
	do
	{
        //declare and initialize 
		countArabic = 0;
		countroman = 0;
		isArabic = false;
		isRoman = false;
        char ch;
        len = 0;
        memset(u_input,'\0', CAPACITY);
		// Prompt the user to input a number AND Read the user input and determine if it is Roman Number or Arabic Number
		printf("Insert the number :  ");
	

        while(scanf_s("%c",&ch, 1)!=0 && !isspace(ch) && ch!=EOF) {
            u_input[len++] = toupper(ch);
        }


		if (len > 0)
		{
			for (i = 0; i < len; ++i)
			{
				if ((isspace(u_input[i]) == 0) && (isdigit(u_input[i]) == 0) && u_input[i] != '.')
				{
                    u_input[i] = toupper(u_input[i]);
					countroman++;
                    if (u_input[i] == '\n')
                       continue;
                }
				else if (isdigit(u_input[i]) != 0)

					countArabic++;
            }
            
			if (u_input[0]== 'Q'&& u_input[1] == 'U'&& u_input[2] == 'I'&& u_input[3] == 'T')
			{
				return 0;
			}

			 if (countroman == 0)
			{
				arabicNumber = atof(u_input);
				isArabic = true;

			}
			else if (countArabic == 0)
			{
                 isRoman = true;
	
			}
            //if the number is Arabic invoke the method to calculate the equivalent Roman Number
			if (isArabic == true)
			{
                if (arabicNumber < 4000)
                {
                    printf("%g is ", arabicNumber);
                    smallArabicToRoman(arabicNumber);
                }
                else if (arabicNumber >= 4000)
                    
                {
                    printf("%g is ", arabicNumber);
                    bigArabicToRoman( arabicNumber);

                }
			}

            //if the number is Roman invoke the method to calculate the equivalent Arabic Number

            else if (isRoman == true)
            {

			
                arNum=romanToArabic(u_input);
                  

                  
                printf("%s is %.10g",u_input, arNum);
			}
            printf("\n");
		}
	}while (1);
	return 0;
}