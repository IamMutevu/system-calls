#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>
#include <unistd.h>
#include <String.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <fstream>
using namespace std;
void createprocess(){     //declaration of create process function 
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    // Start the child process. If not OK...
    if(!CreateProcess("C:\\WINDOWS\\system32\\notepad.exe", // module name.
        NULL,    // Command line.
        NULL,    // Process handle not inheritable.
        NULL,    // Thread handle not inheritable
 FALSE,   // Set handle inheritance to FALSE.
        0,       // No creation flags.
        NULL,    // Use parent's environment block.
        NULL,    // Use parent's starting directory.
        &si,     // Pointer to STARTUPINFO structure.
        &pi)     // Pointer to PROCESS_INFORMATION structure.
    );

}

void getprocessattributes(){        //declaration of the function to call the running process id
	
	
cout<<endl;  //starts here
 //.......start process creation here........................................................................
{  //process attribute
    int b;
 b = GetCurrentProcessId();
cout<<"-----------------------------------------------------------------------------------------------------------------";
   cout<<endl;
    cout << b ;
    cout << "   Is the Process ID" << endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------";
   cout<<endl;
   //Wait until the user confirms

}

}
void terminateprocess()
{
	cout <<"do you want to terminate the process";
	pid_t pid=0;
    std::ifstream ifs("/var/run/httpd.pid", std::ios::in);

    ifs >> pid;
    if(pid)
    
 cout<<"test";
    //end 
	cout<<endl;
	return true;
}
void exitprocess()
{
	cout <<"process exit successfully";
	cout <<endl;
	ExitProcess(0);
	cout <<EXIT_SUCCESS;
}

int main()
{
	int proc;
	cout <<".....................................PROCESS MANAGEMENT.......................................";
	cout <<endl;
	cout<<endl;
	cout <<".......................................BY KEMBOI KELVIN.............................................";
	cout<<endl;
	cout <<"Enter 1 to go to process management MENU:";
	cout<<endl;
	cin>>proc;

 cout <<"Enter 1 to create a process"<<endl;
 cout<<endl;
  cout <<"Enter 2 to get the processid attributes"<<endl;
  cout<<endl;
   cout <<"Enter 3 to terminate the process"<<endl;
   cout<<endl;
    cout <<"Enter 4 to exit the process"<<endl;
    cout<<endl;
 cin>>proc;
 
 if (proc==1){
 createprocess();//calling the function to start the process
	cout<< "process created succcessfully";
	cout<<endl;
	cout<<".................press 1 to go back to menu..............";
	cout<<endl;
	cin>>proc;
 }
 	
else if(proc==2)
{
	
	getprocessattributes();
cout<< "Notepad process id";
cout<<endl;
	
	cout<<endl;
	cin>>proc;

}
else if (proc==3)
{
   terminateprocess();
   cout<<endl;
  
   cout<<endl;	
}
 else if(proc==4)
{
	exitprocess();
	cout<<endl;

	cout<<endl;	
}

else
{
	cout<<"invalid entry";
	cout<<endl;
	
		cout<<endl;
		
}
return main();	//return the program back to main
}