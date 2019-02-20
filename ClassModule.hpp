
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include<iomanip>
#include<regex>
#include<stdio.h>
using namespace std;

class ClassModule
{
    fstream file1;
    ifstream file1i;
    ofstream file1o;
    string Headers,test;
    int intinp;
    string strinp;
    bool strap =true;
    bool HeaderFlag = false;


public:



 //------------------------------------------------CONSTRUCTOR----------------------------------------------------------
    ClassModule()
    {

    //Initialize the value of headers to be checked
      Headers = "Unique_ID_Class,Dept,Sem_No,Section,Sub1,Sub2,Sub3,Sub4";
    //Check whether the file is open or Not
      file1.open("C:/SIS/Class_Master.csv");
      if(!file1.is_open()) //If the file is not available in the desired location, create a new file
      {
          cout<<"File has not been loaded in the memory";
          file1.close();
          file1.open("C:/SIS/Class_Master.csv",ios::app);
    }
      file1.close();
    }

//-----------------------------------------------INSERT_INFORMATION--------------------------------------------------
   int insert_info()
    {
//        bool loopflag = false;
        string testx;
        string sizeinfo;
        stringstream ss;
        string strinparr[8];
//        int current_Sr_No=0;
        int choice;


        file1.open("C:/SIS/Class_Master.csv",ios::app);
        if(file1.is_open())
        {
            cout<<"File is open";



                            cout<<"Please choose a DEPARTMENT:";
                            cout<<"\n1.MCA\n2.BCA";
                            cin>>choice;
                           switch(choice)
                           {
                           case 1:
                            strinparr[0] = "MCA";                           //strinparr[0] -> Department
                            break;
                           case 2:
                            strinparr[0] = "BCA";   //3Bytes
                            break;
                           default:
                            cout<<"Invalid Input!\n";
                            return 1;
                           }


                        cout<<"\nPlease enter the current Semester Number (1,2,3,4,5,6): "; //1Bytes
                        cin>>strinparr[1];                                    //strinparr[1] -> Semester Number




                            cout<<"Please choose a SECTION:";
                            cout<<"\n1.A\n2.B \n3.C \n4. D";
                            cin>>choice;
                           switch(choice)
                           {
                           case 1:                                           //strinparr[2] -> Section Number
                            strinparr[2] = "A"; //1Bytes
                            break;
                           case 2:
                            strinparr[2] = "B";
                            break;
                            case 3:
                            strinparr[2] = "C";
                            break;
                            case 4 :
                            strinparr[2] = "D";
                            break;
                           default:
                            cout<<"Invalid Input!\n";
                            return 1;
                           }


                        //Generating the Unique ID and checking for it in the records using ID_Checker

                        strinparr[3] = strinparr[0] + strinparr[1] + strinparr[2];                  //GENERATING A UNIQUE ID FOR THE CLASS
                        //cout<<"\n\nUnique ID: "<<strinparr[3];
                        file1.close();
                        if(UID_Checker(strinparr[3])==false)
                        {
                            cout<<"\n\nThe Chosen Class"<<strinparr[3]<<" already Exists!";
                        }
                        else
                        {

                                file1.open("C:/SIS/Class_Master.csv",ios::app);

                                cout<<"\nNow please enter the name of the subjects ";
                                cout<<"\nWrite the first three initials of the subject as the name";
                                cout<<"\nFor example, Computer Organization Arithmetic must be written as COA";


                                for(int i=4;i<=7;i++)
                                {
                                    cout<<"\nEnter name of Subject "<<i-3<<": ";
                                    cin>>strinparr[i];
                                }


                                  //*Here is the issue of lines skipping

                               // cout<<"Position of tellp:"<<file1.tellp();
                                file1 <<strinparr[3]<<","<<strinparr[0]<<","<<strinparr[1]<<","<<strinparr[2]<<","<<strinparr[4]<<","<<strinparr[5]<<","<<strinparr[6]<<","<<strinparr[7];
                                file1<<"\n";

                                cout<<"\nClass Successfully Created!";
                                file1.close();
                    }
        }
        remove_Blank_lines();
        return 0;
    }

//------------------------------------------GET_DATA()------------------------------------------------
    int get_data()
    {
        string strarr[100];
        unsigned int choice;

        unsigned int j=1;
        file1i.open("C:/SIS/Class_Master.csv",ios::in);
   //-------- This block of code is written for checking whether the file has any records or not
        int temp = 0;
        while(!file1i.eof())
        {
            getline(file1i,test,'\n');
            temp++;
            if(temp==3)
            {
                break;
            }
        }
        file1i.close();
    //--------
        //If the file has 2 or more lines, it implies that it has records and that it should continue further operations
        if(temp>=3)
        {

            file1i.open("C:/SIS/Class_Master.csv",ios::in);
            getline(file1i,test,'\n');
             cout<<"\nPlease choose any one of the classes provided from the database: \n";
            while(!file1i.eof())
            {
                getline(file1i,test,',');
                if(test.length()!=0)
                {
                    cout<<"\n"<<j<<"."<<test;
                    cout<<"\nLength: "<<test.length();
                    strarr[j] = test;
                    j++;
                }
                getline(file1i,test,'\n');
            }

            cout<<"\nCHOICE: ";
            cin>>choice;
            cout<<"\n\n"<<j;
            if(choice>j-1)
            {
                cout<<"You have made an invalid choice";
                file1i.close();
                this->get_data();
            }
            else
            {
               // return strarr[choice].c_str();
               file1i.close();
            }
        }

        else
        {
            file1i.close();
            cout<<"No Records found in the database";
            return 0;
        }
        return choice;
    }

string get_data(int)
    {
        string strarr[100];
        unsigned int choice;
        unsigned int j=1;
        file1i.close();
        file1i.open("C:/SIS/Class_Master.csv",ios::in);
        int temp = 0;
        while(!file1i.eof())
        {
            getline(file1i,test,'\n');
          //  cout<<"\nLOOP"<<test;
            temp++;
          //  cout<<"\nLOOP"<<temp<<"\n";
            if(temp==3)
            {
                break;
            }
        }
        cout<<"The value of temp is:"<<temp;

        file1i.close();
        if(temp>=2)
        {
            file1i.open("C:/SIS/Class_Master.csv",ios::in);
            cout<<"\nPlease choose any one of the classes provided from the database: \n";
            getline(file1i,test,'\n');

            //Storing all the IDs in strarr
            while(!file1i.eof())
            {
                getline(file1i,test,',');
               if(test!=" " || test!="\n")
               {
                    cout<<"\n"<<j<<"."<<test;
                    strarr[j] = test;
                    j++;
               }

                    getline(file1i,test,'\n');
            }

            cout<<"\nCHOICE: (Enter -1 to jump to the main menu)";
            cin>>choice;
            if(choice==-1)
            {
                return "NULL";
            }
            else if(choice>j-1)
            {
                //cout<<"You have made an invalid choice";
                cout<<"You have made an invalid choice";
                file1i.close();
                this->get_data();
            }

            else
            {
                file1i.close();
                cout<<strarr[choice];
                return strarr[choice].c_str();
            }
        }
        else
        {
             cout<<"\n\nNo Records found in the database";
             return "NULL";
        }
        return "NULL";
    }


   void Header_Check()
    {
        file1.open("C:/SIS/Class_Master.csv",ios::in);

        if(file1.is_open())
        {
        cout<<"Class Master is Open\n\n";
        getline(file1,test,'\n');
        file1.close();

            if(strcmp(test.c_str(),Headers.c_str())==0)
            {
                cout<<"\nHeaders Match! You are ready to roll!\n";
            }

            else
            {
              file1.open("C:/SIS/Class_Master.csv",ios::out);
              cout<<"\nHeaders don't match. \n Please wait for a moment to let the program create a well structured file...";
              file1 << Headers;
              file1<<"\n";
            }

            file1.close();

        }
    }


void deleteModule(string ID)
{
    ifstream file1i;
    fstream file1o;
    string sub;

    file1i.open("C:/SIS/Class_Master.csv",ios::in);

    file1o.open("C:/SIS/temp_Class_Master.csv",ios::out);

    while(file1i.eof()==false)
    {

        getline(file1i,test,'\n');  //fetches every line
        sub = test.substr(0,5); //Fetches the first five characters from the whole line (the ClassID)
        if(sub==ID)
        {
            cout<<sub<<" Successfully Deleted from the Database";
            continue;
        }
        else
        {
            file1o<<test;
            file1o<<"\n";
        }
    }
    file1o.close();
    file1i.close();
    remove("C:/SIS/Class_Master.csv");

    //Removing the associated class from the classes directory (Class,Attendance,Marks,Behavior)
    string add[4];
    add[0] = "C:/SIS/Classes/" + ID +".csv";
    add[1] = "C:/SIS/Classes/" + ID +"_Att.csv";
    add[2] = "C:/SIS/Classes/" + ID +"_Marks.csv";
    add[3] = "C:/SIS/Classes/" + ID +"_Beh.csv";
    for(int i=0;i<4;i++)
    {
        remove(add[i].c_str());
    }

    rename("C:/SIS/temp_Class_Master.csv", "C:/SIS/Class_Master.csv");
    file1o.open("C:/SIS/Class_Master.csv",ios::app);
}



private:
     bool UID_Checker(string strinput123)
    {
        int i=0;
        string UID_Store[100];
        string testx,test;


        file1.open("C:/SIS/Class_Master.csv",ios::in);          //opens fstream::ios::in

        getline(file1,test,'\n');



      //The while loop stores all the GR number records inside GR_Store[] Array
        while(!file1.eof())
        {

            getline(file1,test,',');
            UID_Store[i] = test;

            getline(file1,testx,'\n');
            i++;

        }
        //After the entire column of GR_No is fetched inside the Gr_Store[] array, we need to compare every element of the array with the value
        //Given by the user

        for(i=0;i<100;i++)
        {
            if(strcmp(strinput123.c_str(),UID_Store[i].c_str())==0)
            {
                cout<<"The given Class "<<UID_Store[i]<<" already exists";
                return false;
            }
        }
        file1.close();
        return true;


    }

int remove_Blank_lines()            //This function will remove the blank lines every time after the insert_info() function is called
{
    ifstream file1i;
    ofstream file1o;
    int blank_lines=0;
    file1i.open("C:/SIS/Class_Master.csv",ios::in);
    file1o.open("C:/SIS/temp_Class_Master.csv",ios::out);

    while(file1i.eof()!=true)
    {
        getline(file1i,test,'\n');
        if(test.length()==0)
        {
            continue;
            blank_lines++;
        }
        file1o<<test<<"\n";
    }
    file1o.close();
    file1i.close();
    remove("C:/SIS/Class_Master.csv");
    rename("C:/SIS/temp_Class_Master.csv", "C:/SIS/Class_Master.csv");
    return blank_lines;

}





};
