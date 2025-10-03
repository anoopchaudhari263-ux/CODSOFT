#include<bits/stdc++.h>

struct Task {
    std::string description;
    bool completed;
};

void displayMenu();
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void removeTask(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int choice = 0;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye! " << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n" << std::endl;
                break;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, description);

    Task newTask = {description, false};
    tasks.push_back(newTask);

    std::cout << "Task added successfully! \n" << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- Your Tasks ---" << std::endl;
    if (tasks.empty()) {
        std::cout << "Your to-do list is empty. Great job! " << std::endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (i + 1) << ". "
                      << (tasks[i].completed ? "[X] " : "[ ] ")
                      << tasks[i].description << std::endl;
        }
    }
    std::cout << "------------------\n" << std::endl;
}

void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark. Please add a task first.\n" << std::endl;
        return;
    }

    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to mark as completed: ";
    std::cin >> taskNumber;

    if (std::cin.fail() || taskNumber <= 0 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed! \n" << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove. The list is already empty.\n" << std::endl;
        return;
    }
    
    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to remove: ";
    std::cin >> taskNumber;

    if (std::cin.fail() || taskNumber <= 0 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully! \n" << std::endl;
    }
}
