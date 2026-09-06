#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class task{

string name;
string priority;
string description;
bool complete;

public:
    task(string n,string d,string p,bool c){
        name=n;
        description=d;
        priority=p;
        complete=c;
    }
    void SetComplete(bool s){
    complete=s;
    }

    void SetPriority(string p){
    priority=p;
    }

    void SetDes(string D){
    description=D;
    }

    bool get_comlete(){
    return complete;
    }

    string get_name(){
    return name;
    }

     string get_des(){
    return description;
    }

    string get_pri(){
    return priority;
    }
};


bool compareTask(task task1, task task2) {
    if (task1.get_pri() == "High" && task2.get_pri() != "High")
        return true;
    if (task1.get_pri() == "Medium" && task2.get_pri() == "Low")
        return true;
    return false;
}

class List{
vector<task>mission;

public:
//1
    void addMission(){

    cout<<"enter name of task"<<endl;
    string name;cin>>name;

    cout<<"enter description of task"<<endl;
    string des;cin>>des;

    cout<<"enter priority of task"<<endl;
    string pri;cin>>pri;

    cout<<"if you complete task enter 1 else enter 0"<<endl;
    bool com;cin>>com;

    task Add{name,des,pri,com};
    mission.push_back(Add);

    cout<<"complete adding "<<endl;
    }
//2
    vector<task> CompletedTask(){
     vector<task>result;
     for(int i=0;i<mission.size();i++){
        if(mission[i].get_comlete())
            result.push_back(mission[i]);
     }
     return result;
    }
//3
    void view(){
        if(mission.empty()){
            cout<<"No tasks available."<<endl;
            return;
        }
        for(int i=0;i<mission.size();i++){
   cout<<"Name : "<<mission[i].get_name()<<endl;
   cout<<"Description : "<<mission[i].get_des()<<endl;
   cout<<"Priority : "<<mission[i].get_pri()<<endl;
   cout<<"isCompleted : "<<mission[i].get_comlete()<<endl;
        }
   }
//4
    void makeComplete(string name){
        bool t=false;
     for(int i=0;i<mission.size();i++){
        if(mission[i].get_name()==name){
                t=true;
           cout<<"enter new value"<<endl;
           bool value;cin>>value;
           mission[i].SetComplete(value);
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
    void edit_task(string name,string edit,string newVal){
        bool found=false;
        for(int i=0;i<mission.size();i++){
            if(mission[i].get_name()==name){
                found=true;
                if(edit=="description")
                    mission[i].SetDes(newVal);
                else if (edit=="priority")
                    mission[i].SetPriority(newVal);
                   break;
                }
            }
            if(found)
                cout<<"done"<<endl;
            else
                cout<<"error"<<endl;
            }
//6
    void SORT(){

  sort(mission.begin(),mission.end(),compareTask);
  cout<<"Tasks sorted by priority successfully!"<<endl;
  }
};



int main(){

List obj;
int choice;
int q;
//cout<<"enter numbers of Query"<<endl;
//cin>>q;
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
            obj.edit_task(name, update, newVal);
        }
        else if (choice == 5) {
            obj.SORT();
        }
        else if (choice == 6) {
            vector<task> comp = obj.CompletedTask();
            cout << "\n--- Completed Tasks ---\n";
            if (comp.empty()) {
                cout << "No completed tasks yet.\n";
            } else {
                for (size_t i = 0; i < comp.size(); i++) {
                    cout << "- " << comp[i].get_name() << " (" << comp[i].get_des() << ")\n";
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
   // --q;
    }
return 0;

}
