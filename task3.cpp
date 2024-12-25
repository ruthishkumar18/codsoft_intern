#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; 
string taskDescriptions[MAX_TASKS]; 
bool taskStatuses[MAX_TASKS];       
int taskCount = 0;                  

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks.\n";
        return;
    }

    cout << "Enter the task description (end input with a period '.'): ";
    string word, task = "";
    while (cin >> word) {
        if (word == ".") break; 
        if (!task.empty()) task += " "; 
        task += word; 
    }

    taskDescriptions[taskCount] = task;
    taskStatuses[taskCount] = false; 
    taskCount++;
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "Your to-do list is empty.\n";
        return;
    }

    cout << "To-Do List:\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << taskDescriptions[i]
             << " [" << (taskStatuses[i] ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed : ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number.\n";
    } else {
        taskStatuses[taskNumber - 1] = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask() {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number.\n";
    } else {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            taskDescriptions[i] = taskDescriptions[i + 1];
            taskStatuses[i] = taskStatuses[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the To-Do List Manager.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
