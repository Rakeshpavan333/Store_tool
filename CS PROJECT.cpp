#include <iostream>    // FOR CONSOLE INPUT/OUTPUT FUNCTIONS

#include <stdio.h>     // FOR GETS() AND PUTS() FUNCTIONS

#include <fstream>     // FOR DATA FILE HANDLING (PRODUCTS.DAT,ADMINS.DAT,CUSTOMERS.DAT,SALERECORD.DAT)

#include <windows.h>   // FOR TIME DELAY FUNCTION SLEEP()

#include <stdlib.h>    // FOR SYSTEM("CLS") AND SYSTEM("COLOR") , RANDOM FUNCTIONS

#include <process.h>   // FOR EXIT() FUNCTION

#include <string>      // FOR STRCMP() AND STRCMPI() AND STRLEN() FUNCTIONS

#include <time.h>      // FOR TIME() and NULL USED TO SEED RANDOM FUNCTION

using namespace std;

ifstream fin,finn;

ofstream fout,foutt;

fstream file,filee;

void opendata(){
                     fout.open("Products.dat",ios::app | ios::binary);
                     fout.close();

                     fout.open("Customers.dat",ios::app | ios::binary);
                     fout.close();

                     fout.open("SaleRecord.dat",ios::app | ios::binary);
                     fout.close();

                     fout.open("Admins.dat",ios::app | ios::binary);
                     fout.close();
}

class Product {
                   int pid;

                   int cost;

                   char catg[15];

                   int stock;

                   char pname[20];

                   int discount;

                   void dis(){
                                        cost-=discount;
                   }
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

                                        dis();



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
                   int getstock(){
                                        return stock;
                   }
                   void setdis(int dis){
                                        discount=dis;
                   }
                   void sold(int qua){
                                        stock-=qua;
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
                     fin.seekg(0,ios::beg);

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

                                  srand(time(NULL));

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

                public:

                    int getspid(){
                                            return spid;
                    }
                    int getquantity(){
                                            return quantity;
                    }

                    void setspid(int id){
                                            spid=id;
                    }
                    void setquantity(int qua){
                                            quantity=qua;
                    }
                    void setpname(char arr[]){
                                            strcpy(spname,arr);
                    }
                    void settotbill(int cost){
                                            totbill=cost * quantity;
                    }
                    void setcid(int cus){
                                            cid=cus;
                    }
                    int getcid(){
                                            return cid;
                    }
                    void showsale(){
                                            cout<<"\n\nThe SOLD PRODUCT NAME : ";
                                            puts(spname);

                                            cout<<"\nThe PRODUCT ID : ";
                                            cout<<spid;

                                            cout<<"\nThe Customer ID of Buyer : ";
                                            cout<<cid;

                                            cout<<"\nThe quantity Sold : ";
                                            cout<<quantity;

                                            cout<<"\nTotal Bill : ";
                                            cout<<totbill;


                    }



};

void displaysale(){
                     finn.open("SaleRecord.dat",ios::in | ios :: binary);

                     sales s;

                     while(finn.read((char*)&s,sizeof(s)))
                                   {
                                       s.showsale();
                                   }
                     finn.clear();
                     fin.close();

}

int special_offer(){
                    srand (time(NULL));
                    int so;

                    Product p;

                    long fp;

                    file.open("Products.dat", ios::in | ios::out | ios::binary);
                    so=(rand()%6);

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

                                         cout<<" \nEnter USERNAME for the ADMIN : ";
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

void automatic_stock__add(){

                               system("cls");

                               system("color 3a");

                               cout<<"\n\n>>>CALCULATING AND ADDING STOCKS<<<<\n";
                               cout<<"PLEASE WAIT .....\n\n";

                               filee.open("Products.dat",ios::in | ios::app | ios::binary );

                               Product p;

                               sales s;

                               int totsale=0;

                               long l=0;

                               finn.open("SaleRecord.dat",ios::in);

                               while(filee.read((char*)&p,sizeof(p)))
                               {
                                   totsale=0;

                                   while(finn.read((char*)&s,sizeof(s)))
                                   {
                                       if(p.getpid()==s.getspid())
                                       {
                                           totsale= totsale + s.getquantity();
                                       }
                                   }

                                   finn.clear();

                                   if(p.getstock()<= 5 && totsale>=10)
                                   {

                                       l=filee.tellg();

                                       p.addstock(totsale+5);

                                       filee.seekp(l-sizeof(p),ios::beg);

                                       filee.write((char*)&p,sizeof(p));

                                       filee.seekp(l,ios::beg);
                                   }

                                   else if (p.getstock()<=15 && totsale>=5)
                                   {
                                       l=filee.tellg();

                                       p.addstock(10);

                                       filee.seekp(l-sizeof(p),ios::beg);

                                       filee.write((char*)&p,sizeof(p));

                                       filee.seekp(l,ios::beg);
                                   }

                                   else if(p.getstock()<=30 && totsale<5)
                                   {
                                       l=filee.tellg();

                                       p.addstock(5);

                                       filee.seekp(l-sizeof(p),ios::beg);

                                       filee.write((char*)&p,sizeof(p));

                                       filee.seekp(l,ios::beg);
                                   }


                               }

                               Sleep(2000);

                               cout<<"\n All the Stocks Have Been Updated Successfully according to their Sales \n";

                               Sleep(2500);

                               finn.clear();

                               filee.clear();

                               finn.close();

                               filee.close();

}

void adminmenu(){
                    int choice;

                    admin_menu:

                    system("cls");

                    system("color 1a");


                    cout<<"\n\n:::::WELCOME TO ADMIN SECTION MAIN MENU:::::\n\n";

                    cout<<"----------------------------------------------------\n";

                    cout<<"\nWHAT WOULD YOU LIKE TO DO : ";

                    cout<<"\n\n 1- ADD NEW PRODUCT";
                    cout<<"\n\n 2- MODIFY PRODUCTS DATA";
                    cout<<"\n\n 3- VIEW SALES RECORDS";
                    cout<<"\n\n 4- ADD NEW ADMIN USER";
                    cout<<"\n\n 5- VIEW CUSTOMER DATA";
                    cout<<"\n\n 6- TO LOGOUT ";

                    cout<<"\n\n ENTER YOUR CHOICE HERE : ";
                    cin>>choice;

                    switch (choice)
                    {
                        case 1 :{

                                   system("cls");

                                   system("color 5a");

                                   cout<< "\n::::ADD PRODUCT SECTION::::\n";

                                   cout<< " ---------------------------\n\n";

                                   addproduct();

                                   Sleep(2000);

                                   goto admin_menu;
                        }

                        case 2 :{
                                   int pid,as,ustock;

                                   long pos,ja;

                                   system("cls");

                                   system("color 4d");

                                   cout<<"\n######PRODUCT MANAGMENT SECTION######\n";

                                   cout<<" --------------------------------------\n\n";

                                   cout<<" PRESS 1-TO VIEW ALL PID,STOCK,NAME\n\n";

                                   cout<<" PRESS 2-FOR MANUAL ADDITION OF STOCK \n\n";

                                   cout<<" PRESS 3-FOR AUTOMATIC STOCK INCREMENT \n\n";

                                   cout<<" ENTER HERE : ";
                                   cin>>as;

                                   cout<<"\n\n";

                                   if(as == 2)
                                   {
                                      filee.open("Products.dat",ios::in | ios::out | ios::binary);

                                      Product P;

                                      cout<< "Enter the PID of the product to add stock manually:";
                                      cin>>pid;

                                      cout<< "\n\nEnter the No. of Units to add : ";
                                      cin>>ustock;

                                      while(filee.read((char*)&P,sizeof(P)))
                                      {
                                          if (P.getpid()== pid)
                                          {

                                              pos=filee.tellg();

                                              P.addstock(ustock);

                                              ja=(pos-(sizeof(P)));

                                              filee.seekp(ja,ios::beg);

                                              filee.write((char*)&P,sizeof(P));

                                              filee.seekp(pos,ios::beg);

                                              filee.clear();

                                              break;
                                          }
                                      }

                                      filee.clear();

                                      filee.close();

                                      cout<<"\n....STOCK ADDED SUCCESFULLY....";

                                      Sleep(2500);

                                      goto admin_menu;


                                   }

                                   else if (as == 3)
                                   {
                                        automatic_stock__add();

                                        goto admin_menu;
                                   }

                                   else if( as == 1)
                                   {

                                       int go;

                                       finn.open("Products.dat",ios::in | ios :: binary);

                                       Product P1;

                                       while(finn.read((char*)&P1,sizeof(P1)))
                                       {

                                           cout<<"\n\n PRODUCT NAME : "<<P1.getpname();

                                           cout<<"\n PRODUCT ID   : "<<P1.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<P1.getstock();
                                       }
                                       finn.clear();

                                       finn.seekg(0,ios::beg);

                                       finn.close();

                                       cout<<"\n THATS ALL\n";

                                       cout<<"\n Press 0 to go back to main menu :";
                                       cin>>go;

                                       if(go == 0)
                                       {
                                           goto admin_menu;
                                       }


                                   }
                        }

                        case 3 :{

                                       system("cls");

                                       system("color 6b");

                                       cout<<"\n\n::::: SALES RECORD :::::\n";
                                       cout<<" ---------------------------\n\n";

                                       displaysale();

                                       int goback;

                                       cout<<"\n Press 0 to go back to main menu : ";
                                       cin>>goback;

                                       if(goback == 0)
                                       {
                                           goto admin_menu;
                                       }
                        }

                        case 4 :{
                                       system("cls");

                                       system("color 3e");

                                       cout<<"\n\n$$$$$$$$ NEW ADMIN ACCOUNT $$$$$$$$\n";
                                       cout<<" --------------------------------------\n\n";

                                       Admin a;

                                       char ch; cin.get(ch);

                                       a.newadmin();

                                       foutt.open("Admins.dat",ios::app | ios::binary);

                                       foutt.write((char*)&a,sizeof(a));

                                       Sleep(500);

                                       cout<<"\n\nNew ADMIN added SUCCESSFULLY...";

                                       foutt.close();

                                       Sleep(2000);

                                       goto admin_menu;


                        }

                        case 5 :{
                                       system("cls");

                                       system("color 4d");

                                       cout<<"\n\n$$$$$$$$ CUSTOMERS RECORD $$$$$$$$\n";
                                       cout<<" --------------------------------------\n\n";

                                       fin.open("Customers.dat",ios::app | ios::binary);

                                       customer c;

                                       while(fin.read((char*)&c,sizeof(c)))
                                       {
                                           c.showcustomer();
                                       }

                                       fin.clear();

                                       fin.close();

                                       int goback;

                                       cout<<"\n Press 0 to go back to main menu : ";
                                       cin>>goback;

                                       if(goback == 0)
                                       {
                                           goto admin_menu;
                                       }

                        }

                        case 6 :{
                                       break ;
                        }

                    }

}
int so;                       // VARIABLE TO STORE TODAYS SPECIAL OFFER

void adminlogin(){
                    system("cls");

                    system("color 3c");

                    char username[15];

                    int password,access=0,times=0;

                    Admin A;

                    fin.open("Admins.dat",ios::in | ios::binary);

                    char ch;

                    cout<<"\n\n*******ADMIN LOGIN PAGE*******\n";
                    cout<<"---------------------------------------\n\n";

                                         again:
                                         fin.clear();
                                         cin.get(ch);
                                         cout<<"\nENTER USERNAME :";
                                         gets(username);
                                         cout<<"\nENTER PASSWORD :";
                                         cin>>password;

                                         fin.seekg(0,ios::beg);



                    while(fin.read((char*)&A,sizeof(A)))
                    {

                        if((strcmp(A.getadmin_user(),username)==0)&&(A.getpass()==password))
                        {
                                          access=1;
                        }
                    }

                    if(access==1)
                    {
                                          cout<<"\n CORRECT...LOGGING IN..";

                                          fin.clear();

                                          fin.seekg(0,ios::beg);

                                          fin.close();

                                          Sleep(1000);

                                          adminmenu();
                    }

                    else
                    {
                                          fin.clear();
                                          fin.seekg(0,ios::beg);

                                          cout<<"\n INCORRECT ..TRY AGAIN \n";

                                          if(times==3){
                                            exit(0);
                                          }

                                          times++;

                                          goto again;
                    }

                        cout<<"\n:: YOU ARE SUCCESSFULLY SIGNED OUT:: \n";
                        Sleep(2500);

}

customer d;  // THE CURRENT LOGGED IN CUSTOMER

void prosearch(){
                        finn.open("Products.dat",ios::in | ios :: binary);

                        Product p;

                        int ch;

                        cout << "Enter : \n";

                        cout << "\t\t 1- To search by product name \n\n";

                        cout << "\t\t 2- To search by product category \n\n";

                        cout << "\t\t 3- To search by ID \n\n";

                        cout << "\t\t 4- To search by cost range \n\n";

                        cout << " Enter Here :";
                        cin  >> ch;

                        switch(ch)
                        {
                        case 1 :
                            char sname[15];

                            cout<< "\n Enter name to search :";

                            char c; cin.get(c);

                            gets(sname);

                            while(finn.read((char*)&p,sizeof(p)))
                            {
                                if (strcmpi(p.getpname(),sname)==0)
                                {
                                           cout<<"\n\n PRODUCT NAME : "<<p.getpname();

                                           cout<<"\n PRODUCT ID   : "<<p.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<p.getstock();

                                           cout<<"\n PRODUCT COST  :"<<p.getcost();
                                }
                            }

                            cout<< "\n\n THATS ALL ! ";

                            finn.clear();

                            Sleep(3000);

                            break;

                        case 2 :

                            char sSname[15];

                            cin.get(c);

                            cout<< "\n Enter category to search :";

                            gets(sSname);

                            while(finn.read((char*)&p,sizeof(p)))
                            {
                                if (strcmpi(p.getcatg(),sSname)==0)
                                {
                                           cout<<"\n\n PRODUCT NAME : "<<p.getpname();

                                           cout<<"\n PRODUCT ID   : "<<p.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<p.getstock();

                                           cout<<"\n PRODUCT COST  :"<<p.getcost();
                                }
                            }

                            cout<< "\n\n THATS ALL ! ";

                            finn.clear();

                            Sleep(3000);

                            break;

                        case 3 :

                            int id;

                            cout<< "\n Enter ID to search :";

                            cin>>id;

                            while(finn.read((char*)&p,sizeof(p)))
                            {
                                if (p.getpid()==id)
                                {
                                           cout<<"\n\n PRODUCT NAME : "<<p.getpname();

                                           cout<<"\n PRODUCT ID   : "<<p.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<p.getstock();

                                           cout<<"\n PRODUCT COST  :"<<p.getcost();
                                }
                            }

                            cout<< "\n\n THATS ALL ! ";

                            finn.clear();

                            Sleep(3000);

                            break;

                        case 4 :

                            int mini,maxi;

                            cout<< "\n Enter Minimum and maximum cost filter to search :";

                            cout<< "\n MINIMUM :";
                            cin>>mini;

                            cout<< "\n MAXIMUM :";
                            cin>>maxi;

                            while(finn.read((char*)&p,sizeof(p)))
                            {
                                if (p.getcost()>=mini && p.getcost()<=maxi)
                                {
                                           cout<<"\n\n PRODUCT NAME : "<<p.getpname();

                                           cout<<"\n PRODUCT ID   : "<<p.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<p.getstock();

                                           cout<<"\n PRODUCT COST  :"<<p.getcost();
                                }
                            }

                            cout<< "\n\n THATS ALL ! ";

                            Sleep(3000);

                            finn.clear();

                            break;


                        }
}
void cusmainmenu(){
                        system("cls");

                        int choice;


                        system("color 2a");

                        cout << "\n\n:::::::::::::::::: WELCOME TO CUSTOMER MAIN MENU ::::::::::::::::\n\n ";

                        //cout<<"\n\nTHIS FEATURE IS NOT YET READY ...PLEASE CONTACT THE ADMIN RAKESH..EXTREMELY SORRY \n\nCONTACT RAKESH";

                        cout << " \n WELCOME MR / MRS "<<d.getname();

                        cout<<"\n TODAY'S SPECIAL OFFER : \n";

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



                        cusmain:

                        cout<<"\n\n What would you like to do : \n\n";

                        cout<< "Press :\n\t\t 1-To View all the products available\n\t\t 2-To search for product\n\t\t 3-To buy products\n\t\t 4-To view past orders\n\t\t 5-To logout \n ";

                        cout<< "\n Enter your choice here :";

                        cin>>choice;

                        switch(choice)
                        {
                            case 1 :
                                       finn.open("Products.dat",ios::in | ios :: binary);

                                       Product P1;

                                       while(finn.read((char*)&P1,sizeof(P1)))
                                       {

                                           cout<<"\n\n PRODUCT NAME : "<<P1.getpname();

                                           cout<<"\n PRODUCT ID   : "<<P1.getpid();

                                           cout<<"\n PRODUCT STOCK: "<<P1.getstock();

                                           cout<<"\n PRODUCT COST  :"<<P1.getcost();
                                       }
                                       finn.clear();

                                       finn.seekg(0,ios::beg);

                                       finn.close();

                                       cout<<"\n THATS ALL\n";

                                       goto cusmain;

                                       break;

                            case 2 :
                                       prosearch();

                                       goto cusmain;

                                       break;

                            case 3 :
                                       int ag,bid,quantity;
                                       long pos;

                                       do {

                                        ag=0;

                                        cout<< " \n\n Enter the ID of the product you want to buy :";
                                        cin>>bid;

                                        cout<< "\n Enter quantity to buy :";
                                        cin>>quantity;

                                        file.open("Products.dat",ios::in | ios :: out | ios :: binary);
                                        Product a;
                                        foutt.open("SaleRecord.dat",ios :: app | ios :: binary);
                                        sales s;

                                        while(file.read((char*)&a,sizeof(a)))
                                        {
                                            if (a.getpid()==bid)
                                            {
                                                pos=file.tellg();

                                                s.setcid(d.getid());

                                                s.setquantity(quantity);

                                                s.setpname(a.getpname());

                                                s.setspid(a.getpid());

                                                s.settotbill(a.getcost());

                                                a.sold(quantity);          // TO UPDATE STOCK OF THE PRODUCT JUST BOUGHT

                                                d.neworder(quantity);

                                                foutt.write((char*)&s,sizeof(s));  // TO WRITE RECORD OF THE SALE INTO THE FILE SALERECORD.DAT

                                                file.seekp((pos-sizeof(a)),ios::beg); // TO WRITE THE UPDATED PRODUCT INTO THE FILE

                                                file.write((char*)&a,sizeof(a));

                                                file.seekp(pos,ios::beg);

                                                break;

                                            }
                                        }

                                        file.clear();

                                        file.close();

                                        foutt.close();

                                        cout<< "\n\nYour Order for "<<quantity<<" x "<<a.getpname()<< " has been Successfully placed >>>";

                                        cout<< "\n Your Receipt :\n\n";

                                        s.showsale();

                                        cout<< "\n\n Your Order will reach your House within 3-4 days :: ";

                                        cout<< "\n\n Press 1 if you want to buy more products :";
                                        cin>>ag;
                                        } while(ag==1);

                                        cout<<" \n::::: Hope You had a Great Time Shopping :::: ";

                                        goto cusmain;

                                        break;

                            case 4 :
                                        sales S;

                                        fin.open("SaleRecord.dat",ios :: in | ios :: binary);

                                        cout<<"\n NUMBER OF PAST ORDERS (BEFORE THIS SESSION):- ";
                                        cout<<d.getorders();
                                        cout<<"\n They are :- \n\n";
                                        while(fin.read((char*)&S,sizeof(S)))
                                        {
                                            if(S.getcid()==d.getid())
                                            {
                                                S.showsale();
                                                cout<<"\n\n";
                                            }
                                        }

                                        fin.clear();

                                        fin.close();

                                        cout<<" \n THATS ALL !!";


                                        goto cusmain;

                                        break;

                            case 5 :
                                        break;




                        }
                        cout<<" \n Logging OUT.....:";
                        Sleep(3000);
}



int main()
{
    opendata();

    char user;

    so=special_offer();

    welcome:

    system("cls");

    system("color 5a");
    cout<<" \n**************************************************************************";

    cout<<"\n************** WELCOME TO SUPER MARKET SOFTWARE ASSISTANCE *****************\n";
    cout<<"**************************************************************************\n";

    cout<<"\n PLEASE KEEP IN MIND THAT THIS PROGRAMIS STILL UNDER DEVELOPMENT..\n...SO SOME FEATURES ARE NOT YET AVAILABLE..\n....PLEASE CONTACT RAKESH\n";

    cout<<"\n TODAY'S SPECIAL OFFER : \n";

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

    cout<<"\n\n\tAND YOU ARE : \n\n";

    cout<<"\t A- ADMIN \n \t C- EXISTING CUSTOMER \n \t N- NEW CUSTOMER ";

    cout<<"\n Enter E to EXIT \n";

    cout<<"\n \nEnter HERE : ";
    cin>>user;

    switch(user)
    {
        case 'A' : {
                       adminlogin();

                       goto welcome;

                       break;
        }

        case 'E' : {
                       break;
        }

        case 'N' : {
                       system("cls");

                       system("color f3");

                       cout<<"\n\n $$$$$$ NEW CUSTOMER REGISTRATION $$$$$$$\n ";

                       //char cm; cin.get(cm);

                       customer c1;
                       c1.setcustomer();

                       cout<<"\n\nYOUR UNIQUE CUSTOMER ID IS :";
                       cout<<c1.getid();

                       cout<<"\n\nYOU CAN USE THIS ID TO LOGIN NEXT TIME ";

                       Sleep(2500);

                       fout.open("Customers.dat",ios::app | ios :: binary);
                       fout.write((char*)&c1,sizeof(c1));

                       fout.close();

                       goto welcome;
        }

        case 'C' :

                       int id;

                       long fp;

                       int access=0,times=0;

                       more:

                       system("cls");

                       system("color 2d");

                       cout<<"\n\n ::::: EXISTING CUSTOMER LOGIN :::::\n";

                       cout<<"\n ENTER YOUR ID : ";
                       cin>>id;

                        filee.open("Customers.dat",ios::in | ios::binary);
                        while(filee.read((char*)&d,sizeof(d)))
                    {

                        if(d.getid()==id)
                        {
                                          fp=filee.tellg();
                                          access=1;
                                          break;
                        }
                    }

                    if(access==1)
                    {
                                          cout<<"\n CORRECT...LOGGING IN..";

                                          filee.clear();

                                          Sleep(1000);

                                          cusmainmenu();

                                          filee.seekp((fp-sizeof(d)),ios::beg);

                                          filee.write((char*)&d,sizeof(d));

                                          filee.seekp(fp,ios::beg);

                                          cout<<"\n HOPE YOU HAD A GREAT EXPERIENCE WITH OUR SOFTWARE ....PLEASE VISIT AGAIN..";

                                          goto welcome;
                    }

                    else
                    {
                                          fin.clear();
                                          fin.seekg(0,ios::beg);

                                          cout<<"\n INCORRECT ..TRY AGAIN \n";

                                          if(times==3){
                                            exit(0);
                                          }

                                          times++;

                                          goto more;
                    }


    }
    Sleep(500);
    cout<<"\n\n::: HOPE YOU HAD A GREAT TIME WITH OUR SOFTWARE ASSISTANCE :::\n";
    cout<<"\n\n\n";

    return 0;
}
