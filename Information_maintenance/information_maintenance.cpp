#include<windows.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	int j;
		cout<<"tasks that can be performed under Information Maintainance include :\n";
		cout<<"**********************************************************\n";
		cout<<"1. Sleep a process and get its sleep time\n";
		cout<<"2. Get current process ID in a sublime text\n";
		cout<<"3. Get system date\n";
		cout <<"4. Get Time\n";
		cout <<"5. System ShutDown\n";
		cout <<"6. LogOff\n";

			
		cout<<"**********************************************************\n";
		cout<<"which is your choice?\n";
		cin>>j;
				
			
			
			switch(j)
		{
		
		  case 1:
		    {
				//FILETIME ftime,fsys,fuser;
				SYSTEMTIME stime;
			// how the sleep() function works
			int i,i2;
			 GetSystemTime(&stime);
		
			
			i=stime.wSecond;
			std::cout<<"\nTime before sleeping:"<<i;
		    Sleep(2000);// 2sec=2000 millisecs;
		    GetSystemTime(&stime);

		    i2=stime.wSecond;
		     std::cout<<"\nTime after sleeping:"<<i2;
			std::cout<<"\nThe program sleep time is :"<<i2-i<<endl<<endl;
			getchar() ;//in milliseconds

			
		   };
		   break; 
	   	case 2:
			{
				DWORD id=GetCurrentProcessId();//the getCurrentprocessid ()  takes no  parameter
				char buf[sizeof(DWORD)*8+1];
				ulltoa(id,buf,2);
				ofstream f("D:\abi.txt");
				f<<id;
				cout<<id<<endl;
		   }; 
		   break;
		   case 3:
		   {
		   		char date[9];
	            _strdate(date);
	            cout << date << endl;	
		   }
		   break;
	   case 4:
	   {
	   	time_t now = time(0);
				char * dt = ctime(&now);
				cout << dt;
	   }
	  	   break;
	   case 5:
	   {
	   	system("shutdown -s -t 10");

	   }
	   	   break;
	   case 6:
	   {
	  WINUSERAPI BOOL WINAPI ExitWindowsEx(UINT,DWORD);
	   }
	   
}
			
		//	{break;	};
		
		int x;
			

do{
	cout<<" DO YOU WANT TO CONTINUE? \n\t";
	cout<<"1.Yes\n\t";
	cout<<"2.No";
	cout<<"\n\t";
	cin>>x;
	
	if (x==1){
		 main();
	}
}
while (x == 1);
	
/*	
	else if(x==2){
		exit(0);
				
	} else {|
		cout<<"Invalid choice, Choose again";
		 main();
		
	}
*/	
} 