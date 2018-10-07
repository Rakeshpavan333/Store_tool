#include <iostream>

#include <stdio.h>

#include <fstream>

#include <windows.h>

#include <stdlib.h>

#include <conio.h>

#include <process.h>

#include <string>



using namespace std;


ifstream fin,finn;

ofstream fout,foutt;

fstream file,filee;

void opendata(){
                    fout.open("Product.dat",ios::out | ios::binary);
fout.close();

fout.open("Customers.dat",ios::out | ios::binary);
fout.close();

fout.open("SaleRecord.dat",ios::out | ios::binary);
fout.close();

fout.open("Admins.dat",ios::out | ios::binary);
fout.close();
}

class Product {
                   int pid;

                   int cost;

                   char catg[15];

                   int stock;

                   char pname[20];

                   int discount;
      public :

                   void setproduct(){
                                        cout<<" \nEnter An ID For The Product : ";
                                        cin>>pid;

                                        char ch; cin.get(ch);

                                        cout<<" \nEnter Product Category : ";
                                        gets(catg);

                                        cout<<" \nEnter Product Name : ";
                                        gets(pname);

                                        cout<<" \nEnter The Product Cost per Unit : ";
                                        cin>>cost;

                                        cout<<" \nEnter the initial Discount on the product : ";
                                        cin>>discount;

                                        cout<<" \nEnter The Product Stock Available : ";
                                        cin>>stock;



                }

                   void showproduct(){

                                        cout<<" \nProduct Name : ";
                                        puts(pname);

                                        cout<<" \nProduct Category : ";
                                        cout<<catg;

                                        cout<<" \nThe Product ID : ";
                                        cout<<pid;

                                        cout<<" \nThe Product Cost per Unit : ";
                                        cout<<cost;

                                        cout<<" \nThe Product Stock Available : ";
                                        cout<<stock;
                   }

                   int getpid(){
                                        return pid;
                   }

                   char* getpname(){
                                        return pname;
                   }

                   char* getcatg(){
                                        return catg;
                   }

                   int getcost(){
                                        return cost;
                   }
                   void addstock(int add){
                                        stock+=add;
                   }
                   void setdis(int dis){
                                        discount=dis;
                   }

};

void addproduct(){
                     fout.open("Products.dat",ios::app | ios::binary);

                     Product P;

                     char a='y';

                     system("color 5f");

                     while(a=='y'||a=='Y')
                     {
                         P.setproduct();

                         fout.write((char*)&P,sizeof(P));

                         cout<<"\nDo Yo Wish to Add More Products (Y/N) : ";
                         cin>>a;

                     }

                     cout<<"\n The Product Has been Added Successfully \n ";
                     cout<<"Hope You Had A Great Time \n\n\n ";

                     fout.close();
}

void seeproduct(){

                     fin.open("Products.dat",ios::in | ios::binary);

                     Product P;

                     while(fin.read((char*)&P,sizeof(P)))
                     {
                         P.showproduct();
                     }

                     fin.clear();

                     fin.close();
}

class customer{
                     char cname[15];

                     int cid;

                     char ccity[15];

                     char cstate[10];

                     char clocality[15];

                     int past_orders;

                 public:

                     customer(){
                                  srand(99999);
                                  cid=(rand()%1000)+10;
                                  past_orders=0;
                     }

                    void setcustomer(){
                                        char ch;cin.get(ch);

                                        cout<<"\n Enter Name : ";
                                        gets(cname);

                                        cout<<"\n Enter your Address :";

                                        cout<<"\n State : ";
                                        cin.get(ch); gets(cstate);

                                        cout<<"\n City : ";
                                        cin.get(ch); gets(ccity);

                                        cout<<"\n Locality(Local Area you live) : ";
                                        cin.get(ch); gets(clocality);


                    }

                    int getorders(){
                                         return past_orders;
                     }

                    char* getname(){
                                         return cname;
                      }

                    int getid(){
                                         return cid;
                    }

                    int neworder(int x){
                                         past_orders+=x;
                    }

                    void showcustomer(){
                                         cout<<"\n Name of Customer : ";
                                         puts(cname);

                                         cout<<"\n Unique Customer ID : ";
                                         cout<<cid;

                                         cout<<"\n Customer Address : ";
                                         cout<<clocality<<", "<<ccity<<", "<<cstate;

                                         cout<<"\n Number of Past Orders : ";
                                         cout<<past_orders;

                     }

};

class sales{
                    int totbill;

                    int spid;

                    char spname[15];

                    int cid;

                    int quantity;

};

int special_offer(){
                    int so;
                    Product p;
                    long fp;

                    file.open("Product.dat", ios::in | ios::out | ios::binary);
                    so=(rand()%5);

                    while(file.read((char*)&p,sizeof(p)))
                    {
                        if( so == 0 )
                        {
                            if(strcmpi(p.getcatg(),"Food")==0)
                             {
                               fp=file.tellg();

                               p.setdis((p.getcost()/10));

                               file.seekp(fp-sizeof(p),ios::beg);

                               file.write((char*)&p,sizeof(p));

                               file.seekp(fp,ios::beg);
                             }
                        }
                        else if ( so == 1)
                        {
                            if(strcmpi(p.getcatg(),"Electronics")==0)
                             {
                               fp=file.tellg();

                               p.setdis(((p.getcost()*15)/100));

                               file.seekp(fp-sizeof(p),ios::beg);

                               file.write((char*)&p,sizeof(p));

                               file.seekp(fp,ios::beg);

                             }
                        }
                        else if( so == 2)
                        {
                            if(strcmpi(p.getcatg(),"Sports")==0)
                             {
                               fp=file.tellg();

                               p.setdis((p.getcost()/20));

                               file.seekp(fp-sizeof(p),ios::beg);

                               file.write((char*)&p,sizeof(p));

                               file.seekp(fp,ios::beg);
                             }
                        }
                        else if ( so == 3)
                        {
                            if(strcmpi(p.getcatg(),"Entertainment")==0)
                             {
                               fp=file.tellg();

                               p.setdis((p.getcost()/5));

                               file.seekp(fp-sizeof(p),ios::beg);

                               file.write((char*)&p,sizeof(p));

                               file.seekp(fp,ios::beg);
                             }
                        }

                    }

                    file.clear();

                    file.close();

                    return so;
}

class Admin {
                    char Admin_name[15];
                    char user_name[15];
                    int password;

                public:

                    void newadmin(){

                                         cout<<" \nEnter the name of the new ADMIN : ";
                                         gets(Admin_name);

                                         cout<<" \nEnter USEARNAME for the ADMIN : ";
                                         gets(user_name);

                                         cout<<" \nEnter a PASSWORD for the ADMIN : ";
                                         cin>>password;

                    }

                    char* getadmin_name(){
                                         return Admin_name;
                    }

                    char* getadmin_user(){
                                         return user_name;
                    }

                    int getpass(){
                                        return password;
                    }
};

void adminmenu(){
                    system("cls");

                    cout<<"\n\n:::::WELCOME TO ADMIN SECTION MAIN MENU:::::\n\n";
                    cout<<"\nWhat Would You like to Do : ";

}

void adminlogin(){
                    system("cls");

                    char username[15];

                    int password,access=1,times=0;

                    Admin A;

                    file.open("Admin.dat",ios::in | ios::out | ios::binary);

                    char ch; cin.get(ch);

                    cout<<"\n\n*******ADMIN LOGIN PAGE*******\n";
                    cout<<"---------------------------------------\n\n";


                                         A.newadmin();
                                         file.write((char*)&A,sizeof(A));

                                         again:
                                         cin.get(ch);
                                         cout<<"\nENTER USERNAME :";
                                         gets(username);
                                         cout<<"\nENTER PASSWORD :";
                                         cin>>password;



                    while(file.read((char*)&A,sizeof(A)))
                    {

                        if((strcmp(A.getadmin_user(),username)==0)&&(A.getpass()==password))
                        {
                                          access=1;
                        }
                    }

                    if(access==1)
                    {
                                          cout<<"\n CORRECT...LOGGING IN..";
                                          Sleep(1000);
                                          adminmenu();
                    }

                    else
                    {
                        if(times==3)
                        {
                                          exit(0);
                        }

                                          cout<<"\n INCORRECT ..TRY AGAIN ";

                                          times++;

                                          goto again;
                    }

                    file.clear();

                    file.close();

}


int main()
{
    opendata();
    int so;
    char user;

    cout<<"\n**************WELCOME TO SUPER MARKET SOFTWARE ASSISTANCE*****************\n";

    cout<<"\n TODAY'S SPECIAL OFFER : \n";

    so=special_offer();

    switch(so){

                    case 0 : {
                                cout<<"\n 10% DISCOUNT ON FOOD ITEMS";
                                    break;
                             }

                    case 1 : {
                                cout<<"\n 15% DISCOUNT ON ELECTRONIC ITEMS ";
                                    break;
                             }

                    case 2 : {
                                cout<<"\n 5% DISCOUNT ON SPORTS ITEMS ";
                                    break;
                             }

                    case 3 : {
                                cout<<"\n 20% DISCOUNT ON ENTERTAINMENT";
                                    break;
                             }
                    default : {
                                cout<<"\n NO SPECIAL OFFER ";
                                     break;
                              }

  }

    cout<<"\n\tAND YOU ARE : \n";

    cout<<"\t A- ADMIN \n \t C- EXISTING CUSTOMER \n \t N- NEW CUSTOMER ";

    cout<<"\n Enter HERE : ";
    cin>>user;

    switch(user)
    {
        case 'A' : {
                       adminlogin();
                       break;
        }

    }


    return 0;
}
