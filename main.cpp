/*
All rights reserved to the programmer --> Abdulrahman Ahmed .
Contact us : My telegram --> https://t.me/KAJOIQ .
             My discord --> kajoiq .
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

void agecalculator();
void caesar_cipher();
void input();
void searchname();
void searchage();
void searchsalary();
void quit();
void displayall();
void search();
void deleteFile();
void editFile();


// main function.
int main()
{
  int ch1;
  int ch2;
  do
    {
      cout << "\n1-Age calculator";
      cout << "\n2-Caesar cipher";
      cout << "\n3-Database programme";
      cout << "\n4-Exit";
      cout << "\nChoose --> ";   cin >> ch1;
      switch(ch1)
        {
          case 1:  
              agecalculator();
            break;
          case 2:
              caesar_cipher();
            break;
          case 3:
				cout << "\n1.Input a new name" << endl;
				cout << "2.Search database for employee" << endl;
				cout << "3.Clear Log" << endl;
				cout << "4.Edit file" << endl;
				cout << "5.Exit Program" << endl;
        cout << "Choose --> ";
				cin >> ch2;
				
				switch (ch2){
				       case 1:
				            input();
				            break;
				       case 2:
				            search();
				            break;
				       case 3:
				            deleteFile();
				            break;
				       case 4:
				            editFile();
				            break;
				       case 5:
				            quit();
				            break;
				            
				       cin.get();
				       }
            break;
          case 4: 
            cout << "\nThank's for using my program:)\n";
            break;
          
          default:
              cout << "\nPlease select valid option.\n";
            break;
        }
    }while(ch1!=4);
  
  return 0;
}



// age calculator function.
void agecalculator()
{
  int years,born,year,month,week,day,hour,minute,second;
  
  cout << "\nPlease, Choose the current year : ";  cin >> years;
  cout << "\nPlease, Enter your born : ";  cin >> born;
  year = years - born ;
  cout << "The age is --> " << year << " (in years)";
  month = year * 12 ;
  cout << "\nThe age is --> " << month << " (in months)";
  week = month * 4;
  cout << "\nThe age is --> " << week << " (in weeks)";
  day = week * 7;
  cout << "\nThe age is --> " << day << " (in days)";
  hour = day * 24;
  cout << "\nThe age is --> " << hour << " (in hours)";
  minute = hour * 60;
  cout << "\nThe age is --> " << minute << " (in minutes)";
  second = minute * 60;
  cout << "\nThe age is --> " << second << " (in seconds)";
  cout << endl;
}
// end age calculator function.


// caesar cipher text function.
void caesar_cipher()
{
  string crypt_text = "khoor l dp ndmr"; 
  for(int i=0 ; i<75 ; i++)
    {
      for(int j=0 ; j<crypt_text.length() ; j++)
        {
          if(crypt_text[j] != ' ')
          {
            char normal_text = char (int(crypt_text[j]+i-97)%26 +97);
            cout << normal_text;
          }
          else
          {
            cout << ' ';
          }
        }
      cout << endl;
    }
}
// end caesar cipher text function.


// begin database.
// editFile function.
void editFile()
{
	 string name, input, newName,decision;
	 int age;
	 double salary;
	 ifstream employee("newemployee.txt");
	 if (!employee.eof())
		{
			employee >> name >> age >> salary;
		}
	 
	 cout << "Enter the name of the employee:";
	 cin >> input;

 if (input == name)
 {
     
     cout << name << ' ' << age << ' ' << salary << endl;
     cout << "Is this the correct employee[y][n]:";
     cin >> decision;
     if (decision == "y"){
     cout << "Enter the new name:";
     cin >> newName;
     name = newName;      
           } 
            
     employee.close();
     }
    
     ofstream employee2("newemployee.txt", ios::app);
     employee2 << name << ' ' << age << ' ' << salary << endl;
     employee2.close();
 main();
     }
// end editFile function.

     
     
// input function.
void input()
{       
 string name;
 int age; 
 long int salary;
 ofstream newemployee("newemployee.txt", ios::app);
 cout << "Enter the new employee's name" << endl;
 cin >> name;
 cin.sync();
 cout << "Enter the employee's age." << endl;
 cin >> age;
 
 cout << "Enter the employee's yearly salary" << endl;
 cin >> salary;

        
 newemployee << name << ' ' << age << ' ' << salary << endl;     
 newemployee.close(); 
 main();
     }
// end input function.
  
     
     
// searchname function.
void searchname()
{
     ifstream employee("newemployee.txt");
     string name;
     string str, line;
     int age, offset;
     long int salary;
     cout << "Enter the emplyee's name:";
     cin >> str;
              
     while (employee >> name >> age >> salary){  
           if (str == name){
     cout << "Employee found" << endl;
     cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
     cout << "---------------" << endl;     
     cout << name << ' '<< age << ' ' << "$" <<  salary << endl;
     }
     }

            
     while (employee >> name ){
                 if (str != name){
                 cout << "Nobody under that name exists" << endl;     
                      
                      }
                      }
     main();  
 }
// end searchname function.

 
 
// searchage function.
void searchage()
 {
     ifstream employee("newemployee.txt");
     string name;
     int age ;
     int fage;
     long int salary;
     cout << "Enter the age of an employee:";
     cin >> fage;
     while (employee >> name >> age >> salary){
           if (fage == age){
                    cout << "Employee(s) found" << endl;
                    cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
                    cout << "---------------" << endl;
                    cout << name << ' ' << age << ' ' << "$" << salary << endl;
                    }
                    }
     while (employee >> age){      
           if (fage != age){
                    cout << "No employee(s) found"<< endl;
                    
                    
                    }  
           }
           cin.get();
           main();
  }
// end searchage function.

  

// searchsalary function.
void searchsalary()
{
     ifstream employee ("newemployee.txt");
     string name;
     int age ;
     long int salary;
     long int fsalary;
     cout << "Enter an employee's salary:";
     cin >> fsalary;
     while (employee >> name >> age >> salary){
           if (fsalary == salary ){
                       cout << "Employee found"<< endl;
                       cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
                       cout << "---------------" << endl;
                       cout << name << ' ' << age << ' ' << "$" << salary << endl;;
                       
                       }
                       }
     while (employee >> salary){
            if (fsalary != salary){
                cout << "No employee(s) found" << endl;
                }
           }
     cin.get();
     main();
 }
// end searchsalary function.

 
// quit function.
void quit()
{
 cout << "Thank you for using the database program :)" << endl;
 cin.get();
     } 
// end quit function.

     

// displayall function.
void displayall()
{
     ifstream employee("newemployee.txt");
     int age;
     long int salary;
     string name;
     cout << "Entire employee database"<< endl;
     cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
     cout << "---------------" << endl;
     while (employee >> name >> age >> salary){
     cout << name << ' ' << age << ' ' << "$" << salary << endl ;
     }
     cin.get();
     main();
     
     }
// end displayall function.
  
     
     
// search function.
void search()
{
     int age;
     string name;
     long double salary;
     int choice2;
     
     cout << "1.Search by name" << endl;
     cout << "2.Search by age" << endl;
     cout << "3.Search by salary" << endl;
     cout << "4.Display all employees" << endl;
     cout << "5.Back" << endl;
     cout << "6.Exit program" << endl;
     cin >> choice2;
     
     switch (choice2){
            case 1:
                 searchname();
                 break;
            case 2:
                 searchage();
                 break;
            case 3:
                 searchsalary();
                 break;
            case 4:
                 displayall();
                 break;
            case 5:
                 main();
                 break;
            case 6:
                 quit();
                 break;
                 }
                
            }
// end search function.

          
		  
// deleteFile function.
void deleteFile()
{
     string decision;
     cout << "Are you sure?[Y]es[N]o" << endl;
     cin >> decision;
     if (decision == "y"){
     ofstream employee("newemployee.txt");
     cout << "Successfully Completed!" << endl;
     employee.close();
     main();
     }
     else{
          main();
          }
}
// end deleteFile function.