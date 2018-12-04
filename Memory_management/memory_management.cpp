//  Sample output:
//  There is       51 percent of memory in use.
//  There are 2029968 total KB of physical memory.
//  There are  987388 free  KB of physical memory.
//  There are 3884620 total KB of paging file.
//  There are 2799776 free  KB of paging file.
//  There are 2097024 total KB of virtual memory.
//  There are 2084876 free  KB of virtual memory.
//  There are       0 free  KB of extended memory.

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

// Use to convert bytes to KB
#define DIV 1024

// Specify the width of the field in which to print the numbers. 
// The asterisk in the format specifier "%*I64d" takes an integer 
// argument and uses it to pad and right justify the number.
#define WIDTH 7

int main()
{
	int y;
	int x;
  cout<<"\nYou can do the following under Memory Management\n\n";
  cout<<"=================================================================\n";
  cout<<"\t1. View percentage Memory in use.\n";
  cout<<"\t2. View physical Memory available.\n";
  cout<<"\t3. View total Virtual memory. \n";
  cout<<"\t4. View free virtual memory available.\n";
  cout<<"=================================================================\n";
 
	
  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof (statex);

  GlobalMemoryStatusEx (&statex);
  
  cout<<"What's your choice?\n\tAnswer: ";
  cin>>x;

  switch(x)
  {
  case 1:{
  	printf (TEXT("\nThere is  %*ld percent of memory in use.\n"),
            WIDTH, statex.dwMemoryLoad);
            };
	  break;
  
  case 2:{ 
  printf (TEXT("\nThere are %*I64d total KB of physical memory.\n"),
            WIDTH, statex.ullTotalPhys/DIV);
  };
	  break;
  
  
  case 3:{
  printf (TEXT("\nThere are %*I64d total KB of virtual memory.\n"),
            WIDTH, statex.ullTotalVirtual/DIV);
 };
	  break;
  
  case 4: { 
   printf (TEXT("\nThere are %*I64d free  KB of virtual memory.\n"),
            WIDTH, statex.ullAvailVirtual/DIV);
  };
  break;
   default: 
   cout<<"\nInvalid Choice.\n";
  

  }
  
  do{
	  cout<<"\n\nEnter Option\n";
	  cout<<"\t1 to continue\n";
	  cout<<"\tAny other number to exit\n\t\tAns: ";
	  cin>>y;
	  
	  if (y==1){
		  main();
	  }
  } while(y==1);
  
	  
  }

