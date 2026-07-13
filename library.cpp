#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// ==========================================================================================================================================================================
class Library{
    public:
        int id ;
        string title;
        string author;
        string date;


        // Add book details 
        void addBook(){
            ofstream file("library.txt", ios::app);
            cout<<"Enter Book ID :";
            cin>>id;
            cin.ignore();

            cout<<"Enter Book Title :";
            getline(cin, title);

            cout<<"Enter Book Author :";
            getline(cin, author);

            cout<<"Enter Book Date (YYYY-MM-DD): ";
            getline(cin, date);

            file<<id<<" "<<title<<" "<<author<<" "<<date<<endl;


            cout<<"Book added successfully!"<<endl;
        }

        // dispay book details

        void displayBook(){
            ifstream file("library.txt");
            string line;
            while(getline(file, line)){
                cout<<line<<endl;
            }
            file.close();

            
        }

        // Remove book details 
        void removeBook(){
                int deleteId;
                cout<<"Enter Book ID to remove :";
                cin>>deleteId;

                ifstream file("library.txt");
                ofstream tempFile("temp.txt");

                int id;
                string title, author, date;
                bool found = false;

                while(file>>id>>title>>author>>date){
                    if(id != deleteId){
                        tempFile<<id<<" "<<title<<" "<<author<<" "<<date<<endl;
                    } else {
                        found = true;
                    }
                }

                file.close();
                tempFile.close();

                remove("library.txt");
                rename("temp.txt", "library.txt");

                if(found){
                    cout<<"Book with ID "<<deleteId<<" removed successfully!"<<endl;
                } 
                else{
                    cout<<"Book with ID "<<deleteId<<" not found!"<<endl;
                }
        }

        // Rename book details 
        void renameBook(){
            int renameId;
            cout<<"Enter Book ID to rename :";
            cin>>renameId;

            ifstream file("library.txt");
            ofstream tempFile("temp.txt");

            int id;
            string title, author, date;
            bool found = false;

            while(file>>id>>title>>author>>date){
                if(id == renameId){
                    found = true;
                    cout<<"Enter new title for the book :";
                    cin.ignore();
                    getline(cin, title);
                    cout<<"Enter new author for the book :";
                    getline(cin, author);
                    cout<<"Enter new date for the book (YYYY-MM-DD): ";
                    getline(cin, date);

                }
                tempFile<<id<<" "<<title<<" "<<author<<" "<<date<<endl;
            }

            file.close();
            tempFile.close();

            remove("library.txt");
            rename("temp.txt", "library.txt");

            if(found){
                cout<<"Book with ID "<<renameId<<" renamed and new author set successfully!"<<endl;
        
            } 
            else{
                cout<<"Book with ID "<<renameId<<" not found!"<<endl;
            }
        }

        // search book details
        void searchBook(){
            int searchId;
            cout<<"Enter Book ID to search :";
            cin>>searchId;

            ifstream file("library.txt");
            int id;
            string title, author;
            bool found = false;

            while(file>>id>>title>>author>>date){
                if(id == searchId){
                    found = true;
                    cout<<"Book Found!"<<endl;
                    cout<<"ID: "<<id<<endl;
                    cout<<"Title: "<<title<<endl;
                    cout<<"Author: "<<author<<endl;
                    break;
                }
            }

            file.close();

            if(!found){
                cout<<"Book with ID "<<searchId<<" not found!"<<endl;
            }
        }
        
        
};

// library menu
void libraryMenu(){
    Library lib;
    int choice;
    do{
        cout<<"1. Add Book"<<endl;
        cout<<"2. Display Books"<<endl;
        cout<<"3. Remove Book"<<endl;
        cout<<"4. Rename Book"<<endl;
        cout<<"5. Search Book"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;

        switch(choice){
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBook();
                break;
            case 3:
                lib.removeBook();
                break;
            case 4:
                lib.renameBook();
                break;
            case 5:
                lib.searchBook();
                break;
            case 6:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 6);
}

// =========================================================================================================================================================================
class Request{
    public:  
        // book request sent to admin
        void requestBook(){
            string bookTitle;
            string studentName;
            string authorname;
            string studentId;
            string date;

            cout<<"Enter Student Name :";
            cin.ignore();
            getline(cin, studentName);
            
            cout<<"Enter Student ID :";
            getline(cin, studentId);

            cout<<"Enter Book Title to request :";
            cin.ignore();
            getline(cin, bookTitle);

            cout<<"Enter Author Name :";
            getline(cin, authorname);  

            cout<<"Enter Date (YYYY-MM-DD): ";
            getline(cin, date);

            ofstream file("requests.txt", ios::app);
            file<<studentName<<" "<<studentId<<" "<<bookTitle<<" "<<authorname<<" "<<date<<endl;
            file.close();

            cout<<"Book request sent to admin!"<<endl;
        }

        // view book requests 
        void viewRequests(){
            ifstream file("requests.txt");
            string line;
            cout<<"Book Requests:"<<endl;
            while(getline(file, line)){
                cout<<line<<endl;
            }
            file.close();
        }

        // request delete
        void deleteRequest(){
            string studentId;
            cout<<"Enter Student ID to delete request :";
            cin>>studentId;

            ifstream file("requests.txt");
            ofstream tempFile("temp.txt");

            string line;
            bool found = false;

            while(getline(file, line)){
                if(line.find(studentId) == string::npos){
                    tempFile<<line<<endl;
                } else {
                    found = true;
                }
            }

            file.close();
            tempFile.close();

            remove("requests.txt");
            rename("temp.txt", "requests.txt");

            if(found){
                cout<<"Request for Student ID "<<studentId<<" deleted successfully!"<<endl;
            } else {
                cout<<"Request for Student ID "<<studentId<<" not found!"<<endl;
            }
        }

        // request search
        void searchRequest(){
            string studentId;
            cout<<"Enter Student ID to search request :";
            cin>>studentId;

            ifstream file("requests.txt");
            string line;
            bool found = false;

            while(getline(file, line)){
                if(line.find(studentId) != string::npos){
                    found = true;
                    cout<<"Request Found: "<<line<<endl;
                }
            }

            file.close();

            if(!found){
                cout<<"Request for Student ID "<<studentId<<" not found!"<<endl;
            }
        }

        // request update
        void updateRequest(){
            string studentId;
            cout<<"Enter Student ID to update request :";
            cin>>studentId;

            ifstream file("requests.txt");
            ofstream tempFile("temp.txt");

            string line;
            bool found = false;

            while(getline(file, line)){
                if(line.find(studentId) != string::npos){
                    found = true;
                    cout<<"Enter new request details for Student ID "<<studentId<<":"<<endl;
                    string newRequest;
                    cin.ignore();
                    getline(cin, newRequest);
                    tempFile<<newRequest<<endl;
                } else {
                    tempFile<<line<<endl;
                }
            }

            file.close();
            tempFile.close();

            remove("requests.txt");
            rename("temp.txt", "requests.txt");

            if(found){
                cout<<"Request for Student ID "<<studentId<<" updated successfully!"<<endl;
            } else {
                cout<<"Request for Student ID "<<studentId<<" not found!"<<endl;
            }
        }

};

// book request menu
void RequestMenu(){
    Request req;
    int choice;
    do{
        
        cout<<"1. View Requests"<<endl;
        cout<<"2. Delete Request"<<endl;
        cout<<"3. Search Request"<<endl;
        cout<<"4. Update Request"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;

        switch(choice){
            case 1:
                req.viewRequests();
                break;
            case 2:
                req.deleteRequest();
                break;
            case 3:
                req.searchRequest();
                break;
            case 4:
                req.updateRequest();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 5);
}

// ===========================================================================================================================================================================
class complaint{
    public:
        // complain 
        void Complaint(){
            string studentName;
            string studentId;
            string complaint;

            cout<<"Enter Student Name :";
            cin.ignore();
            getline(cin, studentName);

            cout<<"Enter Student ID :";
            getline(cin, studentId);

            cout<<"Enter Complaint :";
            getline(cin, complaint);

            ofstream file("complaints.txt", ios::app);
            file<<studentName<<" "<<studentId<<" "<<complaint<<endl;
            file.close();

            cout<<"Complaint added successfully!"<<endl;

        }

        // view complaints
        void viewComplaints(){
            ifstream file("complaints.txt");
            string line;
            cout<<"Complaints:"<<endl;
            while(getline(file, line)){
                cout<<line<<endl;
            }
            file.close();
        }

        // feedback
        void giveFeedback(){
            string studentName;
            string studentId;
            string feedback;

            cout<<"Enter Student Name :";
            cin.ignore();
            getline(cin, studentName);

            cout<<"Enter Student ID :";
            getline(cin, studentId);

            cout<<"Enter Feedback :";
            getline(cin, feedback);

            ofstream file("feedback.txt", ios::app);
            file<<studentName<<" "<<studentId<<" "<<feedback<<endl;
            file.close();
            cout<<"Feedback added successfully!"<<endl;
        }

        // search complaint
        void searchComplaint(){
            string studentId;
            cout<<"Enter Student ID to search complaint :";
            cin>>studentId;

            ifstream file("complaints.txt");
            string line;
            bool found = false;

            while(getline(file, line)){
                if(line.find(studentId) != string::npos){
                    found = true;
                    cout<<"Complaint Found: "<<line<<endl;
                }
            }

            file.close();

            if(!found){
                cout<<"Complaint for Student ID "<<studentId<<" not found!"<<endl;
            }
        }


};

// complaint menu for admin
void AdminComplaintMenu(){
    complaint comp;
    int choice;
    do{
        cout<<"1. View Complaint"<<endl;
        cout<<"2. Search Complaints"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice :";
        cin>>choice;
        cout << "\n";

        switch(choice){
            case 1:
                comp.viewComplaints();
                break;

            case 2:
                comp.searchComplaint();
                break;

            case 3:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 3);
}

// complaint for student menu

void StudentComplaintMenu(){
    complaint comp;
    int choice;
    do{
        cout<<"1. Book and Any_Problem Complaint"<<endl;
        cout<<"2. Give Feedback"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        cout << "\n";

        switch(choice){
            case 1:
                comp.Complaint();
                break;

            case 2:
                comp.giveFeedback();
                break;

            case 3:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice != 3);
}
// ===========================================================================================================================================================================

// book request
class bookrequest{
    public:
    // bookissue 
        void issueBook() {
        ofstream file("issue.txt", ios::app);

        int bookId;
        string studentName;

        cout << "Enter Student Name: ";
        cin >> studentName;

        cout << "Enter Book ID: ";
        cin >> bookId;

        file << studentName << " " << bookId << endl;

        file.close();

        cout << "\nBook Issued Successfully!\n";
}

    // book return
    void returnBook() {
        int bookId;
        string studentName;

        cout << "Enter Student Name: ";
        cin >> studentName;

        cout << "Enter Book ID: ";
        cin >> bookId;

        ifstream file("issue.txt");
        ofstream temp("temp.txt");

        string name;
        int id;
        bool found = false;

        while (file >> name >> id) {
            if (name == studentName && id == bookId) {
                found = true;   // Skip this record (book returned)
            } else {
                temp << name << " " << id << endl;
            }
        }

        file.close();
        temp.close();

        remove("issue.txt");
        rename("temp.txt", "issue.txt");

        if (found)
            cout << "Book Returned Successfully!\n";
        else
            cout << "Book Issue Record Not Found!\n";
    }

};
// =======================================================================================================================
// student menu
void studentMenu() {
    int ch;
    bookrequest b;
    Library lib;
    Request req;

    do {
        cout << "\n===== STUDENT MENU =====\n";
        cout << "1. Display Books\n";
        cout << "2. Search Book\n";
        cout << "3. Request Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. ComplaintMenu \n";
        cout << "7. Back\n";
        cout << "Enter Choice: ";
        cin >> ch;
        cout << "\n";

        switch (ch) {
            case 1:
                lib.displayBook();
                break;

            case 2:
                lib.searchBook();
                break;

            case 3:
                req.requestBook();
                break;

            case 4:
                b.issueBook();
                break;

            case 5:
                b.returnBook();
                break;

            case 6:
                StudentComplaintMenu();
                break;

            case 7:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (ch != 7);
}

// =============================================================================================================
// Admin menu
void adminMenu() {
    int ch;
    Library lib;

    do {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Library_Menu \n";
        cout << "2. Complaints_Menu \n";
        cout << "3. Request_Menu\n";
        cout << "4. Back \n";
        cout << "Enter Choice: ";
        cin >> ch;
        cout << "\n";

        switch (ch) {
            case 1: libraryMenu(); break;
            case 2: AdminComplaintMenu(); break;
            case 3: RequestMenu(); break;
            case 4: break;
            default: cout << "Invalid Choice!\n";
        }

    } while (ch != 4);
}

// =======================================================================================================================================
// admin login
bool adminLogin() {
    string username, password;

    cout << "\n===== ADMIN LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "1234") {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";
    return false;
}

// ====================================================================================================
// student login
bool studentLogin() {
    string username, password;

    cout << "\n===== STUDENT LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "student" && password == "1234") {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";
    return false;
}




// main function 
int main(){
    
    int choice;

do {
    cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "1. Admin Login\n";
    cout << "2. Student Login\n";
    cout << "3. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            if(adminLogin())
                adminMenu();
            break;

        case 2:
            if(studentLogin())
                studentMenu();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
    }

} while(choice != 3);
    
    return 0;
}