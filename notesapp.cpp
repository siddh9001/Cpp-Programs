#include <iostream>
#include <stdio.h>
//#include <string>

using namespace std;

struct node
{
	string str;
	node* next;
};

class Notes
{
	private:
		node* top = NULL;
		
	public:
		void push(string);
		void search(string);
		void del(string);
		void display();
		void self_exit();
};


void Notes::self_exit()
{
	cout << "\n\tThank you for using notes...";
	exit(1);
}

void Notes::push(string text) 
{
	node* temp;
	temp=new node;
	temp->str=text;
	temp->next=NULL;

	if(top == NULL)
	{
		top = temp;
		return;              //1mis
		
	}

	temp->next=top;
	top=temp;
}

void Notes::search(string text) 
{
	if(top==NULL)
	{
		cout<<"The list is Empty...Please add one!"<<endl;
		return;              //2mis
	}
	
	node* ptr=top;
	while(ptr->next!=NULL)
	{
		if(ptr->str==text)
		{
			cout<<ptr->str<<endl;
			// ptr=ptr->next;
			return;
		}
		ptr=ptr->next;
	}
	if(ptr->next==NULL && top->str==text)
	{
		cout<<ptr->str<<endl;
		//ptr=ptr->next;
	}
	else
	{
		cout<<"The list is empty...";
	}
}

void Notes::del(string text) 
{
	if(top == NULL)
	{
		cout<<"The list is Empty...Please add one!"<<endl;
		return;            //3rd mis
	}
	
	if(top->str == text)     //5mis
	{
		node* temp = top;
		top = top->next;
		delete temp;
		cout<<"Note Deleted Successfully..."<<endl;
		return;
	}
	//////////////////////////////////// BIGGEST MISTAKE :(  :(  :(
	// node* ptr=top;
	// while(ptr->next!=NULL)
	// {
	// 	if(ptr->str==text)
	// 	{
	// 		node* temp=ptr;
	// 		ptr=ptr->next;
	// 		delete temp;
	// 		cout<<"Note Deleted Successfully..."<<endl;
	// 		return;
	// 	}
	// 	ptr = ptr->next;           //4mis
	// }
	// if(ptr->str==text)
	// 	{
	// 		node* temp=ptr;
	// 		ptr=ptr->next;
	// 		delete temp;
	// 		cout<<"Note Deleted Successfully..."<<endl;
	// 	}
	// else
	// {
	// 	cout<<"The list is empty..."<<endl;
	// }

	node* curr = top;     
    while(curr->next != NULL  && curr->next->str != text)      
        curr = curr->next;

    if(curr->next == NULL)
    {
        cout << "\n\tNotes Not found !..";
        return;
    }

	node* temp = curr->next;        
    curr->next = temp->next;
    delete temp;

    cout << "\n\tNotes Deleted...";
}


void Notes::display()
{
	if(top==NULL)
	{
		cout<<"The list is Empty...Please add one!..";

	}
	else
	{
		node* ptr = top;
		while(ptr != NULL)
		{
			cout<<ptr->str<<endl;
			ptr=ptr->next;
		}
	}
}

int main()
{
	int choice;
	Notes notes;
	
	while(1)
	{
		cout<<"\n\n1. Add a Note"<<endl;
		cout<<"2. Search Note"<<endl;
		cout<<"3. Delete Note"<<endl;
		cout<<"4. See All Notes"<<endl;
		cout<<"5. Exit";
		cout<<"\nEnter choice: ";
		cin>>choice;
	
		switch(choice)
		{
			case 1: 
			{
				string text;
				cout<<"Create a note: ";
				//getline(cin, text);
				//scanf("%s",text);
				cin >> text;
				notes.push(text);
				break;
			}
			
			case 2: 
			{
				string text;
				cout<<"Enter note you want to search: ";
				//getline(cin, text);
				//scanf("%s",text);
				cin >> text;
				notes.search(text);
				break;
			}
			
			case 3: 
			{
				string text;
				cout<<"Enter note you want to delete: ";
				//getline(cin, text);
				//scanf("%s",text);
				cin >> text;
				notes.del(text);
				break;
			}
			
			case 4: 
			{
				notes.display();
				break;
			}
			
			case 5:
			{
				notes.self_exit();
				break;
			}
			
			default: {
				cout<<"Invalid choice...";
				break;
			}
		}
	}
	return 0;
}