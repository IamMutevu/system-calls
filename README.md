# System_calls
The repository contains group work assignment to implement system calls. 


According to our research, we found out that system calls can be roughly grouped into five major categories:
    Process Control
        load
        execute
        end, abort
        create process (for example, fork on Unix-like systems, or NtCreateProcess in the Windows NT Native API)
        terminate process
        get/set process attributes
        wait for time, wait event, signal event
        allocate, free memory
    File Management
        create file, delete file
        open, close
        read, write, reposition
        get/set file attributes
    Device Management
        request device, release device
        read, write, reposition
        get/set device attributes
        logically attach or detach devices
    Information Maintenance
        get/set time or date
        get/set system data
        get/set process, file, or device attributes
    Communication
        create, delete communication connection
        send, receive messages
        transfer status information
        attach or detach remote devices

