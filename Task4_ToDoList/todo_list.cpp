#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store a task
struct Task {
    string description;
    bool completed;
};

// Display menu options
void showMenu() {
    cout << "\n==== TO-DO LIST MENU ====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Add a new task
void addTask(vector<Task> &tasks) {
    string task;
    cout << "Enter task description: ";
    cin.ignore(); // to ignore previous newline
    getline(cin, task);
    tasks.push_back({task, false});
    cout << "Task added successfully!" << endl;
}

// Display all tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\n--- TASK LIST ---" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

// Mark a task as completed
void markCompleted(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Remove a task
void removeTask(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter task number to remove: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Main function
int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
