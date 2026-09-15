🖥️ Linux System Diagnostics Toolkit
📌 Project Description

The Linux System Diagnostics Toolkit is a command-line utility developed to monitor and analyze the health and performance of a Linux system. The toolkit collects and displays important system information such as CPU usage, memory utilization, disk space, running processes, network status, system uptime, and environment information. It helps users and system administrators identify performance bottlenecks, resource overutilization, and potential system issues efficiently.

The project is being developed incrementally through weekly milestones:

✅ Week 1 – Project Setup and Basic System Monitoring
Set up the Linux development environment using Ubuntu/WSL.
Created the project directory structure.
Developed a basic diagnostics program in C.
Retrieved and displayed:
System Uptime
Total RAM
Free RAM
Created a Makefile for compilation and execution.
Initialized a Git repository and pushed the project to GitHub.

✅ Week 2 – Dynamic Memory Management and Modular Design
Converted the application into a menu-driven diagnostic tool.
Implemented dynamic user input handling using:
malloc()
realloc()
free()
Separated the project into multiple source and header files.
Added reusable modules for:
Input handling
System diagnostics
Updated the Makefile to support multi-file compilation.
Enabled users to select and view diagnostic information interactively.

✅ Week 3 – Command Parsing and Tokenization
Implemented a parser module using strtok().
Added support for command-based interaction instead of only menu-based input.
Converted user input into tokens for processing and analysis.
Created separate parser source and header files:
parser.c
parser.h
Integrated the parser with the existing diagnostics modules.
Added support for commands such as:
uptime
memory
exit
Improved modularity and scalability of the toolkit.
Prepared the project for future CPU, disk, process, and network diagnostics.

✅ Week 4 – Process Creation and Linux Command Execution
Implemented process creation using fork().
Implemented Linux command execution using execvp().
Implemented parent-child synchronization using waitpid().
Added error handling using perror().
Implemented execution of external Linux system commands.
Added support for commands such as:
ls
date
whoami
uptime
free
df
Integrated process management with the command parser.
Improved the toolkit's ability to execute and display Linux system information.

✅ Week 5 – Built-in Commands and Environment Variables
Added support for built-in commands.
Implemented environment variable access.
Added support for the env command to display environment variables.
Added commands such as:
help
env
pwd
cd
clear
exit
Integrated built-in command handling with the existing parser and process execution modules.
Connected diagnostic commands such as:
uptime
memory
Improved command handling by distinguishing between built-in commands, diagnostic functions, and external Linux commands.
Continued developing the toolkit using a modular C programming structure.

🎯 Expected Outcome
Provide real-time system health and performance information.
Generate diagnostic reports for CPU, memory, disk, and network usage.
Enable faster detection and troubleshooting of system issues.
Improve understanding of Linux system administration and monitoring concepts.
Offer a user-friendly command-line interface for accessing diagnostic data.
Demonstrate practical use of Linux system calls and process management concepts.
Build a scalable toolkit that can be extended with advanced monitoring and reporting features in future milestones.

🚀 Future Enhancements
CPU Usage Monitoring
Disk Usage Analysis
Process Monitoring
Network Diagnostics
System Log Analysis
Performance Report Generation
Real-Time Monitoring Dashboard
Export Diagnostic Reports to Files
Automated Health Checks and Alerts
