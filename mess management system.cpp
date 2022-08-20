#include <iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#define line cout<<endl;
using namespace std;

int main();
void show_data(int searchkey);     //function used to show data to end-user.
void get_data(int i);           //function used to obtain data from end-user.
void search_student(int searchkey);
void add_student();      //This function is used to add record of new student.
void edit_student(int idnumber);   //function is used to edit existing record. 
int ts;

struct student    //Structure student is made to store student attributes.
{ 
  int IDno; 
  char name[30];
  char hostel[15];
  char mobile[15];
  int dues;
  int meals;
  char email[20];
};

student rec[50];  //This is basic array of defined structure to sore data.
main(){
	system("CLS");
  system("color B0");
  int choice;   //int variable used to determine which operation user want to do.
  int idnumber;   //int variable used to record ID number whih user want to edit.
  int searchkey;  //int variable to store student roll_no by which user can search.
  
 
  cout<<"Enter The Total strength of Mess : ";line
  cin>>ts;

 while(ts--)
 {
	cout<<"\t\t\t\t            WELCOME         ";line
	cout<<"\t\t\t\t ************************** ";line
	cout<<"\t\t\t\t ************************** ";line
	cout<<"\t\t\t\t Mess Managment System."<<endl;
  	cout<<"\t\t University OF Engineering and Technology Peshawar "; line

  cout<<"\n\t\tWhat do you want to do?";line
  cout<<"\t\t----------------------"; line
  cout<<"\t\t\t 1-Add a student"; line 
  cout<<"\t\t\t 2-Edit student";line
  cout<<"\t\t\t 3-Find ";line
  cout<<"\t\t\t 4-Close";line
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: ";
  
  
  	cin>>choice;
  	switch(choice)
 		{
   	case 1:         //If user presses 1 then student adding module would be displayed.
    	add_student();
    	break;
    
	case 2:         //If there are no records in array then it will ask the user to input records first.
    if(rec[0].IDno==0)
   	{
     cout<<"Please Add sudents first."<<endl;
     system("pause");
    main();
   	}
   else         //If records are present in array then it will show table.
  	 { 
     	line
     	cout<<"--------------------------------------------------------------------------------";line
    	 cout<<"---------------------------Student record Table---------------------------------";line
     	cout<<"--------------------------------------------------------------------------------"; line
     	cout<<"ID   "<<"Id No   "<<"Name      "<<"Hostel \t Cell no.      "<<"Dues          "<<"Meals eaten\n\n";
    	 cout<<"--------------------------------------------------------------------------------"<<endl; 

   		 for(int i=0;i<=ts;i++)
   			 {
     		 show_data(i);     //funtion is called with index value to show data.
     	}

    	 cout<<"--------------------------------------------------------------------------------"<<endl;
    	 cout<<"Which ID number your want to edit: ";
   
     	cin>>idnumber;            //Asking the user at which ID he wants to make a change.
       
       	if(idnumber>ts || idnumber<0)  //Validating the ID number.
    		{      
        	  cout<<"\nInvalid ID Number."; line
      	 	}
        	 else
   			 {
         		 edit_student(idnumber);    //Passing ID number to Edit Function.
      	 		}
  	 }
    break;
   
  case 3:
    if(rec[0].IDno==0)     //If no record exist then ask the user o enter records first.
  	 {   
     	cout<<"Please Add sudents first."; line
     	system("pause");
    	 main();         //Return to main so user can input new record.
   	 }
   	 
   	  else
   {
     cout<<"Enter ID number of student you want to search: ";
     cin>>searchkey;     //roll_no as the search key can be entered by user.
     search_student(searchkey);}
     break;
      case 4:
   		 return 0;        //Terminating the records.
    	break;
    	
		   default:         //Default value for ivalid Input. 
    	cout<<"Invalid number.";line
    	system("pause");
  		main();
		}
	}
	return 0;
}

	void get_data(int i)        //Function for receiving data from user and populatiing the variables with values.
	{   
  		cout<<"Enter student ID number : ";line
  		cin>>rec[i].IDno;
  		cout<<"Enter student name: ";line
  		cin>>rec[i].name;
 		 cout<<"Enter student's Hostel name: ";line
  		cin>>rec[i].hostel;
  		cout<<"Enter student's cell phone number: ";line
  		cin>>rec[i].mobile;
  		cout<<"Enter student's dues: ";line
  		cin>>rec[i].dues;
  		cout<<"Enter student's no of meals eaten: ";
  		cin>>rec[i].meals;
  		cout<<"Enter student's Email: ";
  		cin>>rec[i].email;
	}
		void show_data(int searchkey)      //Function for showing data on the screen.
	{    
 		 int i=searchkey;
  		cout<<i<<"    ";
  		cout<<rec[i].IDno<<"   ";
  		cout<<rec[i].name<<"     ";
  		cout<<rec[i].hostel<<"\t";
  		cout<<rec[i].mobile<<"   ";
  		cout<<rec[i].dues<<"   ";
  		cout<<rec[i].meals<<"\n\n";
	}



void add_student()         //This function is used to add record of new student.
{    
  for(int i=0;i<=ts;i++)
 {
    get_data(i);          //Loop was processed 5 times to get input for 5 students.
  }
  system("CLS");
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"ID.\tID no.\tName\tHostel.\tmobile no.\tDues.\tMeals eaten\n\n";
  cout<<"--------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<=ts;i++)
 {
    show_data(i);        //Loop was processed for 5 times to show obtained records.
  }
  cout<<"---------------------------------Thanks ----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  system("pause");

  main();          //Return to main function to again show menu.
}

	void edit_student(int idnumber)     //function is used to edit existing record.
	{  
  		for(int i=0;i<=ts;i++)       //Loop is started.
 		{  
   			if(idnumber==i)       //Through loop every value is compared with search term.
  			{         
    	cout<<"\nExisted information about this record.\n\n";
    	cout<<"---------------------------------------------------------------------------------"<<endl;
    	cout<<"ID.\tId no.\tName\tHostel.\tmobile no.\tDues.\tMeals eaten\n\n";
    	cout<<"--------------------------------------------------------------------------------"<<endl;
    	show_data(i);       //Load information for existing record.
    	cout<<"\n\nEnter new data for above shown record.\n\n";
    	get_data(i);         //Inputing data for that specific record.
    	cout<<"\n\nRecord updated successfully."<<endl;
    
   		 system("pause");
    	main();           //Return to main function.
   		
		   	}
  		}
	}
	
	void search_student(int i){
	 	 
	 	 	cout<<"\nExisted information about this record.\n\n";
    	cout<<"--------------------------------------------------------------------------------"<<endl;
    	cout<<"ID   "<<"IDno   "<<"Name      "<<"Hostel\t mobile no.      "<<"Dues       "<<"Meals Eaten\n\n";
    	cout<<"--------------------------------------------------------------------------------"<<endl;
  		cout<<i<<"    ";
  		cout<<rec[i].IDno<<"   ";
  		cout<<rec[i].name<<"     ";
  		cout<<rec[i].hostel<<"\t";
  		cout<<rec[i].mobile<<"\t";
  		cout<<rec[i].dues<<"\t";
  		cout<<rec[i].meals<<"\n\n";
	 }