    #include<iostream>
    #include<vector>

    using namespace std;

    template <typename T>
    class MemoryCalculate{
        private:
            vector<int> v1;
            vector<string> v2;

        public:
            void addstudent(T id, string name){
                v1.push_back(id);
                v2.push_back(name);
                cout<<"Student added successfully."<<endl;
            }

            void displayall(){
                if (v1.empty()) {
                cout << "No students to display.\n";
                }
                cout<<"All students : "<<endl;
                for(int i = 0; i < v1.size(); i++){
                    cout<<"ID : "<<v1[i]<<" , Name: "<<v2[i]<<endl;
                }
            }

            void searchbyId(T id){
                for(int i = 0; i < v1.size(); i++){
                    if(v1[i] == id){
                        cout<<"student found - ID : "<< v1[i] <<" , Name: "<<v2[i]<<endl;
                        return;
                    }
                }
                cout<<"Student with ID " << id << " not found."<<endl;
            }

            void removebyId(T id){
                for(int i = 0; i < v1.size(); i++){
                    if(v1[i] == id){
                        v1.erase(v1.begin() + i);
                        v2.erase(v2.begin() + i);
                        cout<<"Student removed successfully."<<endl;
                        return;
                    }
                }
                cout << "Student with ID " << id << " not found."<<endl;
            }

    };

    int main()
    {
        MemoryCalculate<int> m;
        int choice;
        int id;
        string name;

        do{

            cout<< "\n--- Student Management Menu ---"<<endl;
            cout<< "1. Add Student to a list"<<endl;
            cout<< "2. Insert multiple data"<<endl;
            cout<< "3. Display All Students"<<endl;
            cout<< "4. Search Student by ID"<<endl;
            cout<< "5. Remove Student by ID"<<endl;
            cout<< "0. Exit"<<endl;
            cout<< "Enter your choice : ";
            cin >> choice;

            switch(choice){
                case 1 :
                    cout<<"Enter Student Id : ";
                    cin>>id;
                    cout<<"Enter Student Name : ";
                    cin>>name;
                    m.addstudent(id,name);
                    break;
                case 2 :
                    {
                        int size;
                        cout << "Enter Number of Student to add : ";
                        cin >> size;
                        for(int i = 0; i < size; i++)
                        {
                            cout << "Enter Student Id: ";
                            cin >> id;
                            cout << "Enter Student Name: ";
                            cin >> name;
                            m.addstudent(id, name);
                        }
                    }
                    break;
                case 3 :
                    m.displayall();
                    break;
                case 4 :
                    cout<<"Enter Student ID to search : ";
                    cin>>id;
                    m.searchbyId(id);
                    break;
                case 5 :
                    cout<<"Enter Student ID to remove : ";
                    cin>>id;
                    m.removebyId(id);
                    break;
                case 0 :
                    cout<<"Exiting....."<<endl;
                    break;
                default :
                    cout<<"invalid Choice!"<<endl;
            }

        }while(choice != 0);

        return 0;
    }