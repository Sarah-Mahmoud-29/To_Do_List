#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Task{

string name;
string priority;
string description;
bool complete;

public:
    Task(string n,string d,string p,bool c){
        name=n;
        description=d;
        priority=p;
        complete=c;
    }
    void setComplete(bool s){
    complete=s;
    }

    void setPriority(string p){
    priority=p;
    }

    void setDes(string D){
    description=D;
    }

    bool getComlete(){
    return complete;
    }

    string getName(){
    return name;
    }

     string getDes(){
    return description;
    }

    string getPri(){
    return priority;
    }
};


bool compareTask(Task task1, Task task2) {
    if (task1.getPri() == "High" && task2.getPri() != "High")
        return true;
    if (task1.getPri() == "Medium" && task2.getPri() == "Low")
        return true;
    return false;
}

class List{
vector<Task>mission;

public:

    void addMission(){

    cout<<"enter name of task"<<endl;
    string name;cin>>name;

    cout<<"enter description of task"<<endl;
    string des;cin>>des;

    cout<<"enter priority of task"<<endl;
    string pri;cin>>pri;

    cout<<"if you complete task enter 1 else enter 0"<<endl;
    bool com;cin>>com;

    Task Add{name,des,pri,com};
    mission.push_back(Add);

    cout<<"complete adding "<<endl;
    }

    vector<Task> completedTask(){
     vector<Task>result;
     for(int i=0;i<mission.size();i++){
        if(mission[i].getComlete())
            result.push_back(mission[i]);
     }
     return result;
    }

    void view(){
        if(mission.empty()){
            cout<<"No tasks available."<<endl;
            return;
        }
        for(int i=0;i<mission.size();i++){
   cout<<"Name : "<<mission[i].getName()<<endl;
   cout<<"Description : "<<mission[i].getDes()<<endl;
   cout<<"Priority : "<<mission[i].getPri()<<endl;
   cout<<"isCompleted : "<<mission[i].getComlete()<<endl;
        }
   }

    void makeComplete(string name){
        bool t=false;
     for(int i=0;i<mission.size();i++){
        if(mission[i].getName()==name){
                t=true;
           cout<<"enter new value"<<endl;
           bool value;cin>>value;
           mission[i].setComplete(value);
           break;
        }
     }
     if(t){
        cout<<"done"<<endl;
     }
     else{
        cout<<"error name not exist "<<endl;
     }
    }
//5
    void editTask(string name,string edit,string newVal){
        bool found=false;
        for(int i=0;i<mission.size();i++){
            if(mission[i].getName()==name){
                found=true;
                if(edit=="description")
                    mission[i].setDes(newVal);
                else if (edit=="priority")
                    mission[i].setPriority(newVal);
                   break;
                }
            }
            if(found)
                cout<<"done"<<endl;
            else
                cout<<"error"<<endl;
            }


    void SORT(){

  sort(mission.begin(),mission.end(),compareTask);
  cout<<"Tasks sorted by priority successfully!"<<endl;
  }
};



int main(){

List obj;
int choice;
while (true) {
        cout << "\n=== To-Do List Menu ==="<<endl;
        cout << "1. Add New Task"<<endl;
        cout << "2. View All Tasks"<<endl;
        cout << "3. Mark Task Complete Status"<<endl;
        cout << "4. Edit Task (Description / Priority)"<<endl;
        cout << "5. Sort Tasks by Priority"<<endl;
        cout << "6. View Completed Tasks"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            obj.addMission();
        }
        else if (choice == 2) {
            obj.view();
        }
        else if (choice == 3) {
            cout << "enter name of task" << endl;
            string name; cin >> name;
            obj.makeComplete(name);
        }
        else if (choice == 4) {
            cout << "enter name then what you want to update (description/priority) then new value" << endl;
            string name, update, newVal;
            cin >> name >> update >> newVal;
            obj.editTask(name, update, newVal);
        }
        else if (choice == 5) {
            obj.SORT();
        }
        else if (choice == 6) {
            vector<Task> comp = obj.completedTask();
            cout << "\n--- Completed Tasks ---\n";
            if (comp.empty()) {
                cout << "No completed tasks yet.\n";
            } else {
                for (size_t i = 0; i < comp.size(); i++) {
                    cout << "- " << comp[i].getName() << " (" << comp[i].getDes() << ")\n";
                }
            }
        }
        else if (choice == 7) {
            cout << "Goodbye!"<<endl;
            break;
        }

        else {
            cout << "Invalid choice! Try again."<<endl;
        }
    }
return 0;

}
