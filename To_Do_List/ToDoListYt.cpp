#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int ID = 0;
struct todoList
{
    int id;
    string task;
};
void banner(){
    cout<<"____________________________________"<<endl;
    cout<<"\t    My To-Do List           "<<endl;
    cout<<"____________________________________"<<endl;
}
void addTask()
{
    system( "cls" );
    banner();
    todoList todo;
    cout<<"Enter new task = "<<endl;
    cin.get();
    getline( cin, todo.task );
    char save;
    cout<<"Save( y / n ) : ";
    cin>>save;
    if( save=='y' )
    {
        ID++;
        ofstream fout;
        fout.open( "ToDoListYt.txt", ios::app );
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();
        char more;
        cout<<"Add more task ? ( y / n ) : ";
        cin>>more;
        if( more=='y') addTask();
        else
        {
            system( "cls" );
            cout<<"Added successfully "<<endl;
            return;
        }
    }
    system( "cls" );
}
void showTask()
{
    system( "cls" );
    banner();
    todoList todo;
    ifstream fin;
    fin.open( "ToDoListYt.txt" );
    cout<<"Task = "<<endl;
    while( !fin.eof() )
    {
        fin>>todo.id;
        fin.ignore();
        getline( fin, todo.task );
        if( todo.task!=" ")
            cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
        else
            cout<<"Empty "<<endl;
    }
    fin.close();
    char exit;
    cout<<"Exit ? ( y / n ) : ";
    cin>>exit;
    if( exit!='y' ) showTask();
    system( "cls" );
}
int searchTask()
{
    system( "cls" );
    banner();
    int id;
    cout<<"Enter task id = ";
    cin>>id;
    todoList todo;
    ifstream fin( "ToDoListYt.txt" );
    while( !fin.eof() )
    {
        fin>>todo.id;
        fin.ignore();
        getline( fin, todo.task );
        if( todo.id==id )
        {
            system( "cls" );
            cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
            return id;
        }
    }
    system( "cls" );
    cout<<"Not found"<<endl;
    return 0;
}
void deleteTask()
{
    system( "cls" );
    int id = searchTask();
    if( id!=0 )
    {
        char del;
        cout<<"\n\tDelete ? ( y / n ) : ";
        cin>>del;
        if( del=='y' )
        {
            todoList todo;
            ofstream tempFile;
            tempFile.open( "Temp.txt" );
            ifstream fin;
            fin.open( "ToDoListYt.txt" );
            int index = 1;
            while( !fin.eof() )
            {
                fin>>todo.id;
                fin.ignore();
                getline( fin, todo.task );
                if( todo.id!=id )
                {
                    tempFile<<"\n"<<index;
                    tempFile<<"\n"<<todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempFile.close();
            remove( "ToDoListYt.txt" );
            rename( "Temp.txt", "ToDo.txt" );
            system( "cls" );
            cout<<"\n\tDelete successfully"<<endl;
        }
        else
        {
            system( "cls" );
            cout<<"Not deleted"<<endl;
        }
    }
}
void updateTask()
{
    
}
int main()
{
    system( "cls" );
    while( true )
    {
        banner();
        cout<<"\n\t1. Add Task :";
        cout<<"\n\t2. Show Task :";
        cout<<"\n\t3. Search Task :";
        cout<<"\n\t4. Delete Task :";
        cout<<"\n\t5. Update Task :";
        int choice;
        cout<<"\n\tEnter choice = ";
        cin>>choice;
        switch( choice )
        {
            case 1:
                addTask();
                break;
            case 2:
                showTask();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                updateTask();
                break;
            default:
                break;
        }
    }
}