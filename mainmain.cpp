                    #include "C:\Users\Priyank Rupareliya\Desktop\Project\SIS - Using CSV\AddStdModule.hpp"
                    #include "C:\Users\Priyank Rupareliya\Desktop\Project\SIS - Using CSV\ClassModule.hpp"
                    #include<stdlib.h>
                    #include<conio.h>
                    int main()
                    {
                        int choice,sub_choice;
                        ClassModule obx;
                        string Class_ID;
//                        unsigned int choice1;



                        while(1)
                        {
                            system("CLS");
                            cout<<"\nWelcome to the STUDENT INFORMATION SYSTEM";
                            cout<<"\nPlease select any one of the choices from below to continue: ";
                            cout<<"\n\n\t1. ADD A NEW CLASS \n\t2.OPEN EXISTING CLASS\n\t3. Delete a Class\n\t4. Exit";
                            cin>>choice;


                            switch(choice)
                            {
                                case 1:
                                    obx.Header_Check();
                                    obx.insert_info();
                                    getch();
                                    break;


                                case 2:
                                    {


                                    Class_ID = obx.get_data(1);
                                    cout<<Class_ID;
                                    if(Class_ID!="NULL")
                                    {
                                        system("CLS");
                                        cout<<"\nThe program will now be redirected to the database of "<<Class_ID;
                                        AddStudentModule Std_Obj(Class_ID);
                                        cout<<"\n\nPlease choose any one of the options given below:";
                                        cout<<"\n\t\t1.Add New Student\n\t\t2.New Entry\n\t\t3.Update Student Information\n\t\t4.Close Class "<<Class_ID;
                                        cout<<"\n\n\t\tChoice: ";
                                        cin>>sub_choice;
                                        switch(sub_choice)
                                        {
                                            case 1:
                                                Std_Obj.Header_Check("Std");
                                                Std_Obj.insert_info();
                                                getch();

                                                break;
                                            case 2:
                                                system("CLS");
                                                cout<<"\nEntry:";
                                                cout<<"\n\n\t1.Attendance\n\t2.Marks\n\t3.Behavior";
                                                cout<<"\n\nChoice: ";
                                                cin>>sub_choice;
                                                switch(sub_choice)
                                                {
                                                    case 1:
                                                      Std_Obj.Header_Check("Att");
                                                      Std_Obj.insert_info_att();
                                                      getch();

                                                      break;

                                                    case 2:
                                                        Std_Obj.Header_Check("Marks");
                                                        Std_Obj.insert_info_marks();
                                                        getch();

                                                        break;

                                                    case 3:
                                                            Std_Obj.Header_Check("Behavior");
                                                            Std_Obj.insert_info_behavior();
                                                            getch();


                                                    default:
                                                        break;
                                                }

                                            }
                                    }

                                    break;

                                    }




                                case 3:
                                    {
                                        system("CLS");
                                        Class_ID = obx.get_data(1);
                                        if(Class_ID!="NULL")
                                        {
                                            cout<<"\n\nAre you sure you wish to delete the class and all of it's Database from the records ? [Y | N ]";
                                            char choice;
                                            cin>>choice;
                                            if(choice=='Y' || choice=='y')
                                            {
                                              obx.deleteModule(Class_ID);
                                              getch();
                                            }

                                        }
                                        else
                                        {
                                            cout<<"Invalid choice";
                                        }
                                        break;

                                    }


                                case 4:
                                    exit(0);
                                    break;

                                default:
                                    cout<<"\nInvalid CHOICE";
                                    break;

                            }
                        }


}

