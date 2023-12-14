// Purpose: Task Manager
// Author(s): Seif Khaled
// Last Modification Date: Dec 13, 2023

#include <iostream>
#include <iomanip> // library for formatted output
#include <vector>
#include <algorithm> // for sorting functionality
#include <limits> // for handling numeric limits
#include <windows.h> // Windows API library for Windows-specific functionality
#include <tlhelp32.h> // ToolHelp32 library for taking snapshots of processes
#include <psapi.h> // for process memory information

/* --- Define Color Codes --- */
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

using namespace std;

// class definition for representing a process
class Process {
private:
    string name; // name of the process
    DWORD pid;   // process ID
    SIZE_T memoryUsage; // memory usage of the process

public:
    // constructor to initialize process information
    Process(const string& n, DWORD id, SIZE_T mem)
        : name(n), pid(id), memoryUsage(mem) {}

    string getName() const { return name; } // getter function for retrieving the process name

    DWORD getPID() const { return pid; } // getter function for retrieving the process ID

    SIZE_T getMemoryUsageInMB() const { return memoryUsage / (1024 * 1024); } // getter function for retrieving the memory usage in megabytes
};


// class definition for managing processes
class ProcessManager {
private:
    vector<Process> processes;

public:
    // function to load processes into the vector
    void loadProcesses() {
        processes.clear();// clear the existing process vector

        // create a snapshot of the current processes
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);

        // check if the snapshot creation failed
        if (hSnapshot == INVALID_HANDLE_VALUE) {
            cerr << "Error creating process snapshot!" << endl;
            return;
        }

        // iterate through the processes in the snapshot
        if (Process32First(hSnapshot, &pe32)) {
            do {
                // get the memory usage of each process
                SIZE_T memoryUsage = GetProcessMemoryUsage(pe32.th32ProcessID);

                // add the process information to the vector
                processes.emplace_back(pe32.szExeFile, pe32.th32ProcessID, memoryUsage);
            } while (Process32Next(hSnapshot, &pe32));
        }

        CloseHandle(hSnapshot);
    }


    // function to display processes in a formatted way
    void displayProcesses(const string& title) {
        cout << title << ":\n";
        cout << YELLOW << "Name                     PID            Memory Usage (MB)\n" RESET;
        cout << CYAN << "======================== =============  ===================\n" RESET;

        for (const auto& process : processes) {
            cout << left << setw(25) << process.getName()
                << setw(15) << process.getPID()
                << setw(20) << process.getMemoryUsageInMB() << '\n';
        }
        cout << RED << "=====================================================================\n" RESET;
    }

    // function to sort processes by name and display
    void sortByProcessName() {
        sort(processes.begin(), processes.end(),
            [](const Process& a, const Process& b) {
                return a.getName() < b.getName();
            });
        displayProcesses("Sorted by Name");
    }

    // function to sort processes by PID and display
    void sortByProcessID() {
        sort(processes.begin(), processes.end(),
            [](const Process& a, const Process& b) {
                return a.getPID() < b.getPID();
            });
        displayProcesses("Sorted by PID");
    }

    // function to sort processes by memory usage and display
    void sortByMemoryUsage() {
        sort(processes.begin(), processes.end(),
            [](const Process& a, const Process& b) {
                return a.getMemoryUsageInMB() > b.getMemoryUsageInMB();
            });
        displayProcesses("Sorted by Memory Usage (Descending)");
    }

private:
    // function to get the memory usage of a process
    SIZE_T GetProcessMemoryUsage(DWORD processID) {
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
        if (hProcess == nullptr) {
            return 0;
        }

        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
            CloseHandle(hProcess);
            return pmc.WorkingSetSize;
        }

        CloseHandle(hProcess);
        return 0;
    }
};

// main function
int main() {
    ProcessManager taskManager;
    int choice;

    do {
        // ASCII art title and menu
        cout << MAGENTA <<
            "  ______           __       __  ___\n"
            " /_  __/___ ______/ /__    /  |/  /___ _____  ____ _____ ____  _____\n"
            "  / / / __ `/ ___/ //_/   / /|_/ / __ `/ __ \\/ __ `/ __ `/ _ \\/ ___/\n"
            " / / / /_/ (__  ) ,<     / /  / / /_/ / / / / /_/ / /_/ /  __/ /    \n"
            "/_/  \\__,_/____/_/|_|   /_/  /_/\__,_/_/ /_/\__,_/\__, /\\___/_/     \n"
            "                                                 /____/\n"
            "                   By: Seif Khaled                       \n\n" RESET;
        cout << RED << "=====================================================================\n" RESET;
        cout << GREEN << "[+] Choose sorting option:\n" << RESET
            << YELLOW << "[+] [1] Sort by Name\n"
            << "[+] [2] Sort by PID\n"
            << "[+] [3] Sort by Memory Usage (Descending)\n" << RESET
            << RED << "[+] [0] Exit\n" << RESET
            << "Your Choice Here --> ";
        cin >> choice;

        cin.clear(); // to clear the error if user choice was wrong
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        // handle user choices
        if (choice == 1) {
            taskManager.loadProcesses();
            taskManager.sortByProcessName();
        } else if (choice == 2) {
            taskManager.loadProcesses();
            taskManager.sortByProcessID();
        } else if (choice == 3) {
            taskManager.loadProcesses();
            taskManager.sortByMemoryUsage();
        } else if (choice == 0) {
            cout << RED << "[+] Exiting program ...\n" << RESET;
        } else {
            cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }

    } while (choice != 0);

    return 0;
}

// Version: v1.0 > Base Task Manager. [Dec 6, 2023]
// Version: v1.1 > Add ASCII Art Title and Colors. [Dec 7, 2023]
// Version: v1.1.1 > Fix some bugs. [Dec 12, 2023]
// Version: v1.1.2 > Fix some bugs. [Dec 13, 2023]