/*
	Name: Library Management System
	Copyright: GNU General Public Liscence v3.0
	Author: Saad Rajpoot
	Date: 16/06/19 05:35
	Description: C++ code for Library Management System Program.
	
	Features:
	
		1:  View Book in Database
 		2:  Search for Specific Book
 		3:  Search Books by Category
 		4:  Edit a Book's info
 		5:  Add a New Book
 		6:  Change Book's Lend state
 		7:  Remove sold Books
 		8:  View Client's Lended Books
 		9:  Generate Reports
 		10: Return Exit to DOS
*/

#include <iostream>
#include <fstream>
using namespace std;

fstream file;

struct books
{
	string name;
	string type;
	string author;
	int lend;
};
books data[50];

class book
{
	private:
		int id,lend,count;
		string name,type,author,cat,nm;
	public:
		void view_all()
		{
			file.open("Book.txt",ios::in);
			system("cls");
			count=0;
			while(file>>name>>type>>author>>lend)
			{
				cout<<"Name: "<<name<<endl;
				cout<<"Type: "<<type<<endl;
				cout<<"Author: "<<author<<endl;
				if(lend==0){
					cout<<"Book is available for lending\n"<<endl;
				}
				else{
					cout << "Books is already lended\n"<<endl;
				}
				count++;
			}
			file.close();
			cout<<"Total Books: "<<count<<"\n"<<endl;
		}
		
		void search_category()
		{
			system("cls");
			cout<<"1:Electronics"<<endl;
			cout<<"2:Programming"<<endl;
			cout<<"3:Business"<<endl;
			cout<<"4:Maths"<<endl;
			cout<<"5:Communication"<<endl;
			cout<<"Enter Type name: "<<endl;
			cin>>cat;
			
			file.open("Book.txt",ios::in);
			while(file>>name>>type>>author>>lend)
			{
				if(cat==type){
					cout<<"Name: "<<name<<endl;
					cout<<"Type: "<<type<<endl;
					cout<<"Author: "<<author<<endl;
					if(lend==0){
						cout<<"Book is available for lending\n"<<endl;
					}
					else{
						cout << "Books is already lended\n"<<endl;
					}
				}
			}
			file.close();
		}
		
		void edit()
		{
			string newnm,newty,newau;
			int op,k=0,l=0,m=0;
			file.open("Book.txt",ios::in);
			system("cls");
			int count=0,i=0,j=0;
			while(file>>data[i].name>>data[i].type>>data[i].author>>data[i].lend)
			{
				cout<<"Name: "<<data[i].name<<endl;
				cout<<"Type: "<<data[i].type<<endl;
				cout<<"Author: "<<data[i].author<<endl;
				i++;
			}
			file.close();
			
			file.open("Book.txt",ios::out);
			cout<<"Name of Book"<<endl;
			cin>>nm;
			cout<<"1.Name"<<endl;
			cout<<"2.Type"<<endl;
			cout<<"3.Author"<<endl;
			cin>>op;
				switch(op)
				{			
				case 1:
				cout<<"New Name"<<endl;
				cin>>newnm;
				
				while(k<i){
					if(data[k].name==nm)
					{
						data[k].name=newnm;
					}
					k++;
				}
				break;
				
				
				case 2:
				cout<<"New Type"<<endl;
				cin>>newty;
				while(l<i){
					if(data[l].name==nm)
					{
						data[l].type=newty;
					}
					l++;
				}
					break;
				
				case 3:
				cout<<"New Author"<<endl;
				cin>>newau;
				while(m<i){
					if(data[m].name==nm)
					{
						data[m].author=newau;
					}
					m++;
				}
				break;
			}
				
				while(j<i){
					file<<data[j].name<<" "<<data[j].type<<" "<<data[j].author<<" "<<data[j].lend<<endl;
					j++;
				}
			file.close();
		}
		
		void add()
		{
			file.open("Book.txt",ios::app);
			cout<<"Enter Name"<<endl;
			cin>>name;
			cout<<"Enter Type"<<endl;
			cin>>type;
			cout<<"Enter Author Name"<<endl;
			cin>>author;
			file<<name<<" "<<type<<" "<<author<<" "<<0<<endl;
			file.close();
			cout<<"Book Added successfully"<<endl;
		}	
		
		void view_lend()
		{
		    file.open("Book.txt",ios::in);
			system("cls");
			count=0;
			while(file>>name>>type>>author>>lend)
			{
				if(lend==1)
				{
				cout<<"Name: "<<name<<endl;
				cout<<"Type: "<<type<<endl;
				cout<<"Author: "<<author<<endl;
				count++;
			}
			}
			file.close();
			cout<<"\nTotal lended Books: "<<count<<"\n"<<endl;
		}	
		
		void search_specfic_book()
		{
			system("cls");
			cout<<"Enter Book name: "<<endl;
			cin>>nm;
			
			file.open("Book.txt",ios::in);
			while(file>>name>>type>>author>>lend)
			{
				if(nm==name){
					cout<<"Name: "<<name<<endl;
					cout<<"Type: "<<type<<endl;
					cout<<"Author: "<<author<<endl;
					if(lend==0){
						cout<<"Book is available for lending\n"<<endl;
					}
					else{
						cout << "Books is already lended\n"<<endl;
					}
				}
			}
			file.close();
			
			
		}
		
		void report()
		{
			file.open("Book.txt",ios::in);
			int ac=0;
			system("cls");
			count=0;
			while(file>>name>>type>>author>>lend)
			{
				if(lend==0){
					ac++;
				}
				count++;
			}
			file.close();
			cout<<"Total Books: "<<count<<"\n"<<endl;
			cout<<"Available Books: "<<ac<<endl;
			cout<<"Lended Books: "<<count-ac<<endl;
			cout<<"Total Book Types: "<<5<<"\n"<<endl;
		}
		
		void change_lend_state()
		{
			file.open("Book.txt",ios::in);
			system("cls");
			string nm;
			count=0;
			int i=0,j=0;
			while(file>>data[i].name>>data[i].type>>data[i].author>>data[i].lend)
			{
				if(data[i].lend==1)
				{
					cout<<"Name: "<<data[i].name<<endl;
					cout<<"Type: "<<data[i].type<<endl;
					cout<<"Author: "<<data[i].author<<endl;
					cout<<"Lend :"<<data[i].lend<<endl;
					count++;
				}
				i++;
			}
			file.close();
			cout<<"\nTotal lended Books: "<<count<<"\n"<<endl;
			file.open("Book.txt",ios::out);
			cout<<"Name of Book"<<endl;
			cin>>nm;
			while(j<i)
			{
				if(nm==data[j].name)
				{
					data[j].lend=0;
				}
				file<<data[j].name<<" "<<data[j].type<<" "<<data[j].author<<" "<<data[j].lend<<endl;
				j++;
			}
			
			file.close();
			
		}
		
		void remove()
		{
			string nm;
			int i=0,j=0;
			file.open("Book.txt",ios::in);
			system("cls");
			while(file>>data[i].name>>data[i].type>>data[i].author>>data[i].lend)
			{
				cout<<"Name: "<<data[i].name<<endl;
				cout<<"Type: "<<data[i].type<<endl;
				cout<<"Author: "<<data[i].author<<endl;
				i++;
			}
			file.close();
			
			file.open("Book.txt",ios::out);
			cout<<"Name of Book"<<endl;
			cin>>nm;
			while(j<i){
				if(data[j].name!=nm){
					file<<data[j].name<<" "<<data[j].type<<" "<<data[j].author<<" "<<data[j].lend<<endl;
				}
				j++;
			}
			file.close();
		}
};

int main(){
 int n;
 book bk;
 cout<<"1:View Book in Database"<<endl;
 cout<<"2:Search for Specific Book"<<endl;
 cout<<"3:Search Books by Category"<<endl;
 cout<<"4:Edit a Book's info"<<endl;
 cout<<"5:Add a New Book"<<endl;
 cout<<"6:Change Book's Lend state"<<endl;
 cout<<"7:Remove sold Books"<<endl;
 cout<<"8:View Client's Lended Books"<<endl;
 cout<<"9:Reports"<<endl;
 cout<<"10:Exit"<<endl;
 
 cout<<"Enter Choice"<<endl;
 cin>>n;
 switch(n)
 {
 	case 1: 
	{
	 	bk.view_all();
	 	main();
	 	break;
	}	
	case 2: 
	{
	 	bk.search_specfic_book();
	 	main();
		break;
	}	
	case 3:
	{
		bk.search_category();
		main();
		break;
	}
	case 4:
	{
		bk.edit();
		main();
		break;
	}
    case 5:
	{
		bk.add();
		main();
		break;
	}
	case 6:
	{
		bk.change_lend_state();
		main();
		break;
	}
	case 7:
	{
		bk.remove();
		main();
		break;
	}
	case 8:
	{
		bk.view_lend();
		main();
		break;
	}
	case 9:
	{
		bk.report();
		main();
		break;
	}
	case 10:
	{
		system("exit");
		break;
	}
	default:
		cout<<"Invalid"<<endl;
 }
	return 0;
}
