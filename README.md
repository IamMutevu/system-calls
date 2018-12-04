# System_calls
The repository contains group work assignment to implement system calls. 


According to our research, we found out that system calls can be roughly grouped into five major categories:
	1. Process Control
        load
        execute
        end, abort
        create process (for example, fork on Unix-like systems, or NtCreateProcess in the Windows NT Native API)
        terminate process
        get/set process attributes
        wait for time, wait event, signal event
        allocate, free memory
	
        2. File Management
        create file, delete file
        open, close
        read, write, reposition
        get/set file attributes
	
        3. Device Management
        request device, release device
        read, write, reposition
        get/set device attributes
        logically attach or detach devices
	
        4. Information Maintenance
        get/set time or date
        get/set system data
        get/set process, file, or device attributes
	
        5. Communication
        create, delete communication connection
        send, receive messages
        transfer status information
        attach or detach remote devices

The categories implemented in the assignment include:
        1. Process Control
        2. Memory management
        3. Communication
        4. Information maintenance
        5. File management
        6. Device management