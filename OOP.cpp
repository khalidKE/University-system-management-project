#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
int studentCount;
const int MAX_SIZE = 10;

class user
{
protected:
    int id;
    int age;
    string name;
};

// Inheritance from user
class Student : public user
{
private:
    vector<Student> students;
    float gpa;
    string password;

public:
    Student()
    {
        name = "khalid";
        password = 123;
        gpa = 3.5;
        age = 20;
        id = 1111;
    }

    void registeration()
    {
        studentCount++;
        cout
            << "\n********* Register Student Information ********* " << endl;
        cout << "Enter student name:";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your id:";

        cin >> id;
        cout << "Enter your age: ";

        cin >> age;
        cout << "Enter your gpa: ";

        cin >> gpa;
        cout << "Enter student password: ";
        cin >> password;

        cout << "student add Successfully" << endl;
    }

    // Encapsulation -> Getter
    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    int getAge()
    {
        return age;
    }

    float getGpa()
    {
        return gpa;
    }

    string getPassword()
    {
        return password;
    }

    void displayStudents()
    {
        cout << "List of Students:\n";
        cout << "Name: " << getName() << ", ID: " << getId()
             << ", Age: " << getAge() << ", GPA: " << getGpa() << endl;
        string arr[] = {"Ahmed", "Ali", "Mohamed", "Khalid", "Omar"};
        for (int i = 0; i < 5; i++)
            cout << "Name: " << arr[i] << ", ID: " << 34 * i << ", Age: " << 20 + i << ", GPA: " << abs(4 - i) << endl;
    }
};

class FCAI
{
private:
    vector<Student> students;
    string admin_name;
    string admin_password;

public:
    FCAI()
    {
        cout << "\n\t********************************************************************" << endl;
        cout << "\t\t\t\tWelcome to FCAI\n\n";
    }

    bool admin() // fcai 123
    {
        cout << "Enter admin name: ";
        cin.ignore();
        getline(cin, admin_name);

        cout << "Enter admin password: ";
        getline(cin, admin_password);
        if (admin_name == "fcai" && admin_password == "123")
        {
            cout << "Signed in successfully! Welcome to FCAI " << endl;
            return true;
        }
        cout << "Invalid admin credentials!" << endl;
        return false;
    }

    bool login_user()
    {
        string uName, uPassword;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, uName);

        cout << "Enter password: ";
        getline(cin, uPassword);

        if ("khalid" == uName && "123" == uPassword)
        {
            cout << "Signed in successfully! Welcome, khalid" << endl;
            return true;
        }

        cout << "Invalid name or password!" << endl;
        return false;
    }
};

class Labs
{
private:
    string name;
    int number;
    int capacity;
    int enroll;

public:
    Labs() : number(0), capacity(0), enroll(0) {}

    Labs(const string &labName, int labNumber, int labCapacity, int labEnroll)
        : name(labName), number(labNumber), capacity(labCapacity), enroll(labEnroll) {}

    const string &getName() const
    {
        return name;
    }

    int getNumber() const
    {
        return number;
    }

    int getCapacity() const
    {
        return capacity;
    }

    int getEnroll() const
    {
        return enroll;
    }

    void setName(const string &labName)
    {
        name = labName;
    }

    void setNumber(int labNumber)
    {
        number = labNumber;
    }

    void setCapacity(int labCapacity)
    {
        capacity = labCapacity;
    }

    void setEnroll(int labEnroll)
    {
        enroll = labEnroll;
    }

    void displayLabInfo() const // info about lab
    {
        cout << "Lab Name: " << name << ", Lab Number: " << number
             << ", Capacity: " << capacity << ", Enroll: " << enroll << endl;
    }
};

class Subject
{
private:
    string name;
    string *professors;
    int prof_count;

public:
    Subject(string k = "Maths") : name(k), professors(nullptr), prof_count(0) {}

    Subject(string n, const string prof[], int size)
    {
        name = n;
        prof_count = size;
        professors = new string[prof_count];
        for (int i = 0; i < prof_count; ++i)
        {
            professors[i] = prof[i];
        }
    }

    ~Subject()
    {
        delete[] professors;
    }

    string getName()
    {
        return name;
    }

    string *getProfessors() const
    {
        return professors;
    }

    int getProfCount() const
    {
        return prof_count;
    }

    void displaySubjectInfo() const
    {
        cout << "Subject Name: " << name << ", Professors: ";
        for (int i = 0; i < prof_count; ++i)
        {
            cout << professors[i] << (i < prof_count - 1 ? ", " : "");
        }
        cout << endl;
    }
};

class Professors
{
public:
    void displayProf()
    {
        cout << "List of professors: \n";
        cout << "Prof. Mohamed Tony teaches Prog2\n";
        cout << "Prof. Ahmed Gmal teaches Multimedia\n";
        cout << "Prof. Gomaa Elmokhtar teaches Web\n";
        cout << "Prof. David teaches Operating System\n";
    }
};

class University : public Professors
{
protected:
    Student *students[MAX_SIZE];
    Subject *subjects[MAX_SIZE];
    Labs *labs[MAX_SIZE];
    int subjectCount;
    int labCount;

public:
    University() : subjectCount(0), labCount(0)
    {
    }

    ~University()
    {
        for (int i = 0; i < studentCount; ++i)
        {
            delete students[i];
        }
        for (int i = 0; i < subjectCount; ++i)
        {
            delete subjects[i];
        }
        for (int i = 0; i < labCount; ++i)
        {
            delete labs[i];
        }
    }

    void addStudent(const Student &s)
    {
        if (studentCount < MAX_SIZE)
        {
            students[studentCount++] = new Student(s);
        }
        else
        {
            cout << "Cannot add more students. University capacity reached 10, please change max size." << endl;
        }
    }

    void addSubject(const Subject &sub)
    {
        if (subjectCount < MAX_SIZE)
        {
            subjects[subjectCount++] = new Subject(sub);
        }
        else
        {
            cout << "Cannot add more subjects. University capacity reached, please change max size." << endl;
        }
    }

    void addLab(const Labs &lab)
    {
        if (labCount < MAX_SIZE)
        {
            labs[labCount++] = new Labs(lab);
        }
        else
        {
            cout << "Cannot add more labs. University capacity reached, please change max size." << endl;
        }
    }

    void displayLabs() const
    {
        cout << "List of Labs:\n";
        for (int i = 0; i < labCount; ++i)
        {
            labs[i]->displayLabInfo();
        }
    }

    void displaySubjects() const
    {
        cout << "List of Subjects:\n";
        for (int i = 0; i < subjectCount; ++i)
        {
            subjects[i]->displaySubjectInfo();
        }
    }
};

class Library
{
private:
    string studentName;
    string nationalNumber;
    string location;
    string bookTitle;
    string bookAuthor;
    bool isAvailable;

public:
    void addStudent()
    {
        cout << "Enter student name: ";
        cin >> studentName;
        cout << "Enter national number: ";
        cin >> nationalNumber;
        cout << "Enter location: ";
        cin >> location;
    }

    void addBook()
    {
        cout << "Enter book title: ";
        cin >> bookTitle;
        cout << "Enter book author: ";
        cin >> bookAuthor;
        bool isAvailable = true; // Assume it is available at first
    }

    void borrowBook()
    {
        if (isAvailable)
        {
            cout << "Book '" << bookTitle << "' borrowed successfully by " << studentName << endl;
        }
        else
        {
            isAvailable = false;
            cout << "Book '" << bookTitle << "' is currently unavailable." << endl;
        }
    }
    void returnBook()
    {
        string name;
        cout << "enter name to return book " << endl;
        cin >> name;
        if (studentName == name)
        {
            cout << "Book '" << bookTitle << "' returned successfully." << endl;
        }
        else
        {
            isAvailable = false;
            cout << "No book to return or book already available." << endl;
        }
    }
};

class Worker 
{
public:
    vector<int> id;
    vector<int> age;
    vector<string> name;
    vector<string> job;
    vector<int> salary;

    Worker work()
    {
        Worker wor;
        cout << "Enter number of workers: ";
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i)
        {
            int id, age, salary;
            string name, job;
            cout << "ID: ";
            cin >> id;
            wor.id.push_back(id);
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            wor.name.push_back(name);
            cout << "Job: ";
            getline(cin, job);
            wor.job.push_back(job);
            cout << "Age: ";
            cin >> age;
            wor.age.push_back(age);
            cout << "Salary: ";
            cin >> salary;
            wor.salary.push_back(salary);
        }
        return wor;
    };

    void showData(Worker wor)
    {
        for (size_t i = 0; i < wor.id.size(); ++i)
        {
            cout << "ID: " << wor.id[i] << "\n"
                 << "Name: " << wor.name[i] << "\n"
                 << "Job: " << wor.job[i] << "\n"
                 << "Age: " << wor.age[i] << "\n"
                 << "Salary: " << wor.salary[i] << "\n\n";
        }
    }

    Worker addWorkers(Worker wor)
    {
        int id, age, salary;
        string name, job;

        cout << "ID: ";
        cin >> id;
        wor.id.push_back(id);
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        wor.name.push_back(name);
        cout << "Job: ";
        getline(cin, job);
        wor.job.push_back(job);
        cout << "Age: ";
        cin >> age;
        wor.age.push_back(age);
        cout << "Salary: ";
        cin >> salary;
        wor.salary.push_back(salary);
        cout << "\n";
        return wor;
    }

    Worker editInfoWorker(Worker wor)
    {
        int id, age, salar;
        string name, job;
        cout << "Enter the ID of the worker: ";
        cin >> id;
        for (size_t i = 0; i < wor.id.size(); ++i)
        {
            if (wor.id[i] == id)
            {
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                wor.name[i] = name;
                cout << "Job: ";
                getline(cin, job);
                wor.job[i] = job;
                cout << "Age: ";
                cin >> age;
                wor.age[i] = age;
                cout << "Salary: ";
                cin >> salar;
                wor.salary[i] = salar;
                cout << "\n";
                return wor;
            }
        }
        cout << "ID not found\n";
        return wor;
    }

    Worker deleteWorker(Worker wor)
    {
        int id;
        cout << "Enter the ID of the worker: ";
        cin >> id;
        for (size_t i = 0; i < wor.id.size(); ++i)
        {
            if (wor.id[i] == id)
            {
                wor.id.erase(wor.id.begin() + i);
                wor.name.erase(wor.name.begin() + i);
                wor.job.erase(wor.job.begin() + i);
                wor.salary.erase(wor.salary.begin() + i);
                wor.age.erase(wor.age.begin() + i);
                cout << "\n";
                return wor;
            }
        }
        cout << "ID not found\n";
        return wor;
    }

    void processOfWorkers()
    {
        cout << "\n\nWelcome\n";
        Worker wor2;
        int n;
        cout << "Select the operation:\n1) Show Workers Data\n2) Add new worker\n3) Edit worker data\n4) Delete worker\n0) Exit\n";
        cin >> n;
        switch (n)
        {
        case 0:
            break;
        case 1:
            showData(wor2);
            break;
        case 2:
            showData(addWorkers(wor2));
            break;
        case 3:
            showData(editInfoWorker(wor2));
            break;
        case 4:
            showData(deleteWorker(wor2));
            break;
        default:
            break;
        }
    }
};

void re()
{
    Worker w;
    FCAI fcai;
    int choice;
    while (true)
    {
    mainMenu:
        cout << "\nFCAI System\n";
        cout << "1. Admin Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Student newStudent;
        University uni;
        Library lib;
        Worker wrk;

        switch (choice)
        {
        case 1:
        {
            if (fcai.admin()) // fcai 123
            {
                int adminChoice;
                while (true)
                {
                    cout << "\nFCAI Admin Panel\n";
                    cout << "1. Register Student\n";
                    cout << "2. Display Students\n";
                    cout << "3. Add Lab\n";
                    cout << "4. Display Labs\n";
                    cout << "5. Add Subject\n";
                    cout << "6. Display Subjects\n";
                    cout << "7. Display Professors\n";
                    cout << "8. Operation for Workers\n";
                    cout << "9. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice)
                    {
                    case 1:
                        newStudent.registeration();
                        break;
                    case 2:
                        newStudent.displayStudents();
                        break;
                    case 3:
                    {
                        cout << "Enter name of lab: ";
                        string nm;
                        cin.ignore();
                        getline(cin, nm);
                        cout << "Enter no. lab: ";
                        int num, n, en;
                        cin >> num;
                        cout << "Enter capacity: ";
                        cin >> n;
                        cout << "Enter enroll: ";
                        cin >> en;
                        Labs newLab(nm, num, n, en);
                        uni.addLab(newLab);
                        cout << "Lab added successfully" << endl;
                        break;
                    }
                    case 4:
                        uni.displayLabs();
                        break;
                    case 5:
                    {
                        cout << "Enter subject name: ";
                        string k;
                        cin.ignore();
                        getline(cin, k);
                        cout << "Enter number of Assistants: ";
                        int num;
                        cin >> num;
                        string *profs = new string[num];
                        cin.ignore();
                        for (int i = 0; i < num; ++i)
                        {
                            cout << "Enter Assistant " << i + 1 << ": ";
                            getline(cin, profs[i]);
                        }
                        Subject newSubject(k, profs, num);
                        uni.addSubject(newSubject);
                        delete[] profs;
                        cout << "Subject added successfully" << endl;
                        break;
                    }
                    case 6:
                        uni.displaySubjects();
                        break;
                    case 7:
                        uni.displayProf();
                        break;
                    case 8:
                        w.processOfWorkers();
                    case 9:
                        goto mainMenu;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
            }
            break;
        }
        case 2:
            if (fcai.login_user())
            {
                cout << "login Successfully" << endl;
                int userChoice;
                while (true)
                {

                    cout << "\n1. Display Info\n";
                    cout << "2. Borrow Book\n";
                    cout << "3. Return Book\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;
                    switch (userChoice)
                    {
                    case 1:
                        cout << "\nname = khalid" << endl;

                        cout << "gpa = 3.5\n";
                        cout << "age = 20\n";
                        cout << "id = 1111\n";
                        break;
                    case 2:
                        lib.addStudent();
                        lib.addBook();
                        lib.borrowBook();
                        break;
                    case 3:
                        lib.returnBook();
                        break;
                    case 4:
                        goto mainMenu;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
            }
            break;
        case 3:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}


int main()
{
    re();

    return 0;
}