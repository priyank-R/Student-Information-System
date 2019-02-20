#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

class AddStudentModule
{
    fstream file1;
    ifstream file1i;
    string sub_array[4];
    //String for all the Headers
    string Headers, Headers_Att, Headers_Marks,Headers_Beh;
    string test;
    int intinp;
    string strinp;
    string Class_UID;
    string Class_Add,Att_Add,Marks_Add,Beh_Add;


public:
    AddStudentModule(string CUID)
    {
        //Passing the Class ID for handling individual class files
        Class_UID = CUID;
        Class_Add = "C:/SIS/Classes/"+Class_UID+".csv";
        Att_Add ="C:/SIS/Classes/" + Class_UID + "_Att.csv";
        Beh_Add ="C:/SIS/Classes/" + Class_UID + "_Beh.csv";
        Marks_Add = "C:/SIS/Classes/" + Class_UID + "_Marks.csv";
        //Initializing Headers
        Headers = "GR_NO,UID_Class,First_Name,Last_Name,Mobile,DOB";
        sub_fetcher();

        Headers_Att = "UID_Att,GR_NO,First_Name," + sub_array[0] + "," + sub_array[1] + "," + sub_array[2] + "," + sub_array[3];
        Headers_Marks = "UID_Marks,Exam-Type,GR_NO,First_Name," + sub_array[0] + "," + sub_array[1] + "," + sub_array[2] + "," + sub_array[3];
        Headers_Beh = "UID_Behavior,GR_NO,First_Name," + sub_array[0] + "," + sub_array[1] + "," + sub_array[2] + "," + sub_array[3];

        //Checking whether the file is open or Not, If NOT - Create that file
        //1. ClassName.csv
      file1.open(Class_Add.c_str());
      if(!file1.is_open())
      {
          file1.close();
          file1.open(Class_Add.c_str(),ios::app);
      }
      file1.close();

        //2.ClassName_Att.csv
      file1.open(Att_Add.c_str());
      if(!file1.is_open())
      {
          file1.close();
          file1.open(Att_Add.c_str(),ios::app);
      }
      file1.close();

      //3.ClassName_Marks.csv
      file1.open(Marks_Add.c_str());
      if(!file1.is_open())
      {
          file1.close();
          file1.open(Marks_Add.c_str(),ios::app);
      }
      file1.close();

      //4.ClassName_Beh.csv
      file1.open(Beh_Add.c_str());
      if(!file1.is_open())
      {
          file1.close();
          file1.open(Beh_Add.c_str(),ios::app);
      }
      file1.close();


    }


   void Header_Check(string type)
    {
        string Headers,Address;


        if(type=="Att")
        {
            Address = Att_Add;
            Headers = this->Headers_Att;

        }
        else if(type=="Std")
        {
            Address = Class_Add;
            Headers = this->Headers;
        }
        else if(type=="Marks")
        {
                Address = Marks_Add;
                Headers = this->Headers_Marks;
        }
        else if(type=="Behavior")
        {
            Address = Beh_Add;
            Headers = this->Headers_Beh;
        }
        file1.open(Address.c_str(),ios::in);

        if(file1.is_open())
        {
      //  cout<<"File1 is Open";
        getline(file1,test,'\n');
        file1.close();

            if(strcmp(test.c_str(),Headers.c_str())==0)
            {
                cout<<"\nHeaders Match! You are ready to roll!\n";

            }
            else
            {
             // cout<<test;
              file1.open(Address.c_str(),ios::out);
              cout<<"\nHeaders don't match. \nPlease wait for a moment to let the program create a well structured file...";
              file1 << Headers;
            }
        file1.close();
        }
    }

     void insert_info()
    {

        string testx;
        string sizeinfo;
        stringstream ss;
        string strinparr[3];
        int intinparr[4];
//        int current_Sr_No=0;

        file1.open(Class_Add.c_str(),ios::app);
        if(file1.is_open())
        {
            int choice=1;
            do
            {

                cout<<"\nEnter 1 to insert a new record | Enter 0 to jump to main menu: ";
                cin>>choice;

                    if(choice==1)
                    {

                            cout<<"Please enter GR_No:";
                            cin>>intinparr[0];
                            if(GR_Checker(intinparr[0])==false)
                            {
                                cout<<"The inserted GR number already exists";
                            }
                            else
                            {
                            file1.open(Class_Add.c_str(),ios::app);



                            cout<<"Please enter your first name: ";
                            cin>>strinparr[0];


                            cout<<"Please enter your last name: ";
                            cin>>strinparr[1];



                            cout<<"Please enter your mobile number: ";
                            cin>>strinparr[2];


                            cout<<"Please enter the DAY of Birth [DD] ";
                            cin>>intinparr[1];

                            cout<<"Please enter the MONTH of Birth [MM]: ";
                            cin>>intinparr[2];

                            cout<<"Please enter the YEAR of Birth [YY]: ";
                            cin>>intinparr[3];

                            file1<<"\n";
                            file1 <<intinparr[0]<<","<<Class_UID<<","<<strinparr[0]<<","<<strinparr[1]<<","<<strinparr[2]<<",";
                            file1 <<intinparr[1]<<"/"<<intinparr[2]<<"/"<<intinparr[3];
                            file1.close();

                            }

                        }
                    }while(choice!=0);

           }

        }


    void insert_info_att()
    {
         string strinparr[4];
         string GR,crap,Name;
        // string sub_array[4];
         string Att_UID;
         fstream file1,file2;
         char Ch[4];
         int count=1;


        system("CLS");
        cout<<"\nPlease enter today's date: ";

        cout<<"\n\n\t\tPlease enter the DAY [DD] ";
        cin>>strinparr[1];

        cout<<"\n\t\tPlease enter the MONTH [MM]: ";
        cin>>strinparr[2];

        cout<<"\n\t\tPlease enter the YEAR  [YY]: ";
        cin>>strinparr[3];

        //Creating a Unique ID of Attendance [DATE]

        Att_UID = strinparr[1] + strinparr[2] + strinparr[3];
         system("CLS");
        cout<<"Atendance UID is: "<<Att_UID;

        cout<<"DATE: "<<strinparr[1]<<"/"<<strinparr[2]<<"/"<<strinparr[3]<<"/";



        //Fetching all the GR Numbers and Names from CLASS.csv
         file1.open(Att_Add.c_str(),ios::app);
        file2.open(Class_Add.c_str(),ios::in);
        getline(file2,test,'\n');

        while(file2.eof()==false)
        {
         getline(file2,GR,',');
         getline(file2,crap,','); //Skipping the UID
         getline(file2,Name,',');

         cout<<"\n"<<count<<". "<<GR<<" "<<Name;
         for(int x=0;x<=3;x++)
         {
            cout<<"\nSubject: "<<sub_array[x]<<" Enter P|A: ";
            cin>>Ch[x];
            if(Ch[x]=='p')
            {
                Ch[x]='P';
            }else if(Ch[x]=='a')
            {
                Ch[x]='A';
            }
         }

         //Inserting the entire Record inside "Class_Att.csv"

         file1<<"\n"<<Att_UID<<","<<GR<<","<<Name<<",";
         file1<<Ch[0]<<",";
         file1<<Ch[1]<<",";
         file1<<Ch[2]<<",";
         file1<<Ch[3]<<",";

         getline(file2,crap,'\n');
        }

    }

    void insert_info_marks()
    {
        int choice;
        string exam_type;
        cout<<"\nPlease choose from any one of the Below Given Exams:";
        cout<<"\n\n\t\t1.Mid Semester (30 Marks) \n\t2.Finals (100 Marks)";
        cin>>choice;
        if(choice==1)
        {
            exam_type="MID";
        }
        else if(choice==2)
        {
            exam_type="FIN";
        }
        else
        {
            cout<<"Invalid Exam Type!";
            insert_info_marks();
            system("CLS");
        }


         string GR,crap,Name;
         string Marks_UID;
         fstream file1,file2;
         int Marks[4];
         int count=1,temp;
         bool flag=false;


        system("CLS");


        //Creating a Unique ID of Marks [Exam_Type + Class_ID]

        Marks_UID = exam_type + Class_UID;
        system("CLS");
        cout<<"Marks UID is: "<<Marks_UID;



        //Fetching all the GR Numbers and Names from CLASS.csv
         file1.open(Marks_Add.c_str(),ios::app);
        file2.open(Class_Add.c_str(),ios::in);
        getline(file2,test,'\n');
        cout<<"[Mid Sem: Marks Out Of 30][Finals: Marks Out Of 100]";

        while(file2.eof()==false)
        {
         getline(file2,GR,',');
         getline(file2,crap,','); //Skipping the UID
         getline(file2,Name,',');

         cout<<"\n"<<count<<". "<<GR<<" "<<Name;
         for(int x=0;x<=3;x++)
         {
            if(flag==true)
            {
                x=temp;
                flag=false;
            }
            cout<<"\nSubject: "<<sub_array[x]<<" Enter Marks ";
            cin>>Marks[x];
           if(choice==1)
           {
               if(Marks[x]>30)
               {
                   cout<<"Invalid Marks. 0>=Value<= 30";
                   temp = x;
                   flag = true;
                   continue;
               }
           }
           else
           {
               if(Marks[x]>100)
               {
                  cout<<"Invalid Marks. 0>=Value<= 100";
                   temp = x;
                   flag = true;
                   continue;
               }
           }
         }

         //Inserting the entire Record inside "ClassName_Marks.csv"

         file1<<"\n"<<Marks_UID<<","<<exam_type<<","<<GR<<","<<Name<<",";
         file1<<Marks[0]<<",";
         file1<<Marks[1]<<",";
         file1<<Marks[2]<<",";
         file1<<Marks[3]<<",";

         getline(file2,crap,'\n');
        }


    }

    void insert_info_behavior()
    {
         string strinparr[4];
         string GR,crap,Name;
        // string sub_array[4];
         string Beh_UID;
         fstream file1,file2;
         unsigned int Scale[4];
         int count=1,temp;
         bool flag=false;


        system("CLS");
        cout<<"\nPlease enter today's date: ";

        cout<<"\n\n\t\tPlease enter the DAY [DD] ";
        cin>>strinparr[1];

        cout<<"\n\t\tPlease enter the MONTH [MM]: ";
        cin>>strinparr[2];

        cout<<"\n\t\tPlease enter the YEAR  [YY]: ";
        cin>>strinparr[3];

        //Creating a Unique ID of Attendance [DATE]

        Beh_UID = strinparr[1] + strinparr[2] + strinparr[3];
        system("CLS");
        cout<<"Behavior UID is: "<<Beh_UID;

        cout<<"DATE: "<<strinparr[1]<<"/"<<strinparr[2]<<"/"<<strinparr[3]<<"/";
        cout<<"\n**Behavior Scale is 1---10 [1 Being the lowest][10 Being the highest]**";



        //Fetching all the GR Numbers and Names from CLASS.csv
         file1.open(Beh_Add.c_str(),ios::app);
        file2.open(Class_Add.c_str(),ios::in);
        getline(file2,test,'\n');

        while(file2.eof()==false)
        {
         getline(file2,GR,',');
         getline(file2,crap,','); //Skipping the UID
         getline(file2,Name,',');

         cout<<"\n"<<count<<". "<<GR<<" "<<Name;
         for(int x=0;x<=3;x++)
         {
            if(flag==true)
            {
                x=temp;
                flag=false;
            }
            cout<<"\nSubject: "<<sub_array[x]<<" Enter Behavior : ";
            cin>>Scale[x];
            if(Scale[x]>10 || Scale[x]<1)
               {
                   cout<<"Invalid Scale. 1>=Value<=10";
                   temp = x;
                   flag = true;
                   continue;
               }

           }

         //Inserting the entire Record inside "Class_Beh.csv"

         file1<<"\n"<<Beh_UID<<","<<GR<<","<<Name<<",";
         file1<<Scale[0]<<",";
         file1<<Scale[1]<<",";
         file1<<Scale[2]<<",";
         file1<<Scale[3]<<",";

         getline(file2,crap,'\n');
        }

    }


    bool GR_Checker(int intinput123)
    {
        int i=0;
        int Gr_Store[100];
        string testx;

        file1.close();
        file1.open(Class_Add.c_str(),ios::in);
        getline(file1,test,'\n');



      //The while loop stores all the GR number records inside GR_Store[] Array
        while(!file1.eof())
        {

            getline(file1,test,',');
            stringstream ss(test);
            ss >> Gr_Store[i];
           // cout<<" "<<i<<" "<<Gr_Store[i]<"\n";
            getline(file1,test,'\n');
            //getline(file1,test,',');
            i++;

        }
        //After the entire column of GR_No is fetched inside the Gr_Store[] array, we need to compare every element of the array with the value
        //Given by the user

        for(i=0;i<100;i++)
        {
            if(intinput123 == Gr_Store[i])
            {
                cout<<"The given GR number "<<Gr_Store[i]<<" already exists";
                return false;
            }
        }
        file1.close();
        return true;

    }

private:
    void sub_fetcher()  //Sub Fetcher will fetch all the subjects of the chosen class and store it in sub_array[4]
    {
        fstream file1;
        string crap;
        file1.open("C:/SIS/Class_Master.csv",ios::in);

        getline(file1,crap,'\n');
        while(file1.eof()==false)
        {
            getline(file1,crap,',');
            if(strcmp(crap.c_str(),Class_UID.c_str())==0)
            {

                getline(file1,crap,',');
                getline(file1,crap,',');
                getline(file1,crap,',');

                getline(file1,crap,',');
                sub_array[0]=crap;  //Fetches the first subject
                cout<<"\nSubject 1: "<<sub_array[0];

                 getline(file1,crap,',');
                sub_array[1]=crap;        //Second Subject
                cout<<"\nSubject 2: "<<sub_array[1];

                 getline(file1,crap,',');
                sub_array[2]=crap;        //Third Subject
                cout<<"\nSubject 1: "<<sub_array[2];

                 getline(file1,crap,'\n');
                sub_array[3]=crap;      //Fourth Subject
                cout<<"\nSubject 1: "<<sub_array[3];
                cout<<sub_array[3];

                break;
            }
            getline(file1,crap,'\n');
        }

        file1.close();

    }

};
