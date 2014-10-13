//HOW THIS WORKS- YOU ENTER TEACHER NAME AND TIMTABLES
//ENTER PERIOD THEN ENTER ASSIGNED CLASS(FOR EXAMPLE 12 A) OR ENTER free FOR FREE PERIOD
//For now- teacher number, subject and timetables for tuesday-friday have been commented
//Reason: otherwise input will be very cumbersome and examiner won't be able to test my program
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

const int size=3;//this is the number of periods in a day
struct timetable
	{
		int period;
		char grade[5];//assigned class:example-12 A
	};

class teacher
	{
		protected:
		int number;
		char name[20];
		timetable monday[size];
		timetable tuesday[size];
		timetable wednesday[size];
		timetable thursday[size];
		timetable friday[size];
		public:
		void get_data();
		void display();
		char *return_tt(int day,int x);
		char *return_name();
	};

class subject_teacher:public teacher
	{
		char subject[20];
		public:
		void get_data();//funtion over riding
		void display();
	};

void teacher::get_data()
	{
		//cout<<"\nEnter teacher number:";
		//cin>>number;
		cout<<"\nEnter teacher name:";
		gets(name);
		cout<<"\nENTER WEEKLY TIMETABLE";
		cout<<"\nMonday:\n";
		int n;
		for(int i=0;i<size;i++)
		{
		cout<<"Enter period(0-"<<size-1<<"):";	cin>>n;
		monday[n].period=n;//in this input method if the user forgets to enter a period, then he can enter it afterwards
		cout<<"Enter assigned class during this period:";
		gets(monday[n].grade);
		}

		/*cout<<"\nTuesday:\n";
		for(i=0;i<size;i++)
		{
		cout<<"Enter period(0-"<<size-1<<"):";cin>>n;
		tuesday[n].period=n;
		cout<<"Enter assigned class during this period:";
		gets(tuesday[n].grade);
		}

		cout<<"\nWednesday:\n";
		for(i=0;i<size;i++)
		{
		cout<<"Enter period(0-"<<size-1<<"):";cin>>n;
		wednesday[n].period=n;
		cout<<"Enter assigned class during this period:";
		gets(wednesday[n].grade);
		}

		cout<<"\nThursday:\n";
		for(i=0;i<size;i++)
		{
		cout<<"Enter period(0-"<<size-1<<"):":";cin>>n;
		thursday[n].period=n;
		cout<<"Enter assigned class during this period:";
		gets(thursday[n].grade);
		}

		cout<<"\nFriday:\n";
		for(i=0;i<size;i++)
		{
		cout<<"Enter period(0-"<<size-1<<"):";	cin>>n;
		friday[n].period=n;
		cout<<"Enter assigned class during this period:";
		gets(friday[n].grade);
		}*/
	}

void teacher::display()
	{
		//cout<<"\nTeacher number:"<<number;
		cout<<"\nName of teacher:"<<name;
		cout<<"\nEnter the day of required timetable(Monday-1):";
		int n;
		cin>>n;
		switch(n)
			{
				case 1:
				cout<<"Monday";
				cout<<"\nPeriod\t\tClass\n";
				for(int i=0;i<size;i++)
					{
						cout<<i<<"\t\t"<<monday[i].grade;
						cout<<endl;
					}
				break;

				case 2:
				cout<<"Tuesday";
				cout<<"\nPeriod\t\tClass\n";
				for(i=0;i<size;i++)
					{
						cout<<i<<"\t\t"<<tuesday[i].grade;
						cout<<endl;
					}
				break;

				case 3:
				cout<<"Wednesday";
				cout<<"\nPeriod\t\tClass\n";
				for(i=0;i<size;i++)
					{
						cout<<i<<"\t\t"<<wednesday[i].grade;
						cout<<endl;
					}
				break;

				case 4:
				cout<<"Thursday";
				cout<<"\nPeriod\t\tClass\n";
				for(i=0;i<size;i++)
					{
						cout<<i<<"\t\t"<<thursday[i].grade;
						cout<<endl;
					}
				break;

				case 5:
				cout<<"Friday";
				cout<<"\nPeriod\t\tClass\n";
				for(i=0;i<size;i++)
					{
						cout<<i<<"\t\t"<<friday[i].grade;
						cout<<endl;
					}
				break;

			}
	}

char * teacher::return_tt(int day,int x)
		{
			switch(day)
				{
					case 1:
					return monday[x].grade;
					case 2:
					return tuesday[x].grade;
					case 3:
					return wednesday[x].grade;
					case 4:
					return thursday[x].grade;
					case 5:
					return friday[x].grade;
				}
		}

char* teacher::return_name()
	{
		return name;
	}

void subject_teacher::get_data()
		{
			teacher::get_data();
			//cout<<"\nEnter teacher subject:";
			//gets(subject);
		}

void subject_teacher::display()
	{
		teacher::display();
		//cout<<"\nSubject:"<<subject;
	}

void delete_rec(fstream &);//sorted deletion
void insert_rec(fstream &);//sorted insertion
void modify_rec(fstream &);
void display_subs(fstream &);//this is the main function of this program
void display_all(fstream &);//display names of all teachers
void display_rec(fstream &);//display details of a single teacher

/*******************************************************************/

void main()
	{
		textbackground(WHITE);
		textcolor(BLACK);
		clrscr();
		ifstream fin;
		fin.open("Teachers.dat",ios::binary);
		if(!fin)
		{
		fin.close();
		ofstream fout;
		fout.open("Teachers.dat",ios::binary);
		fout.close();
		}

		char ch;
		do
			{
				fstream file;
				file.open("Teachers.dat",ios::in|ios::out|ios::binary);
				if(!file)
					{
						cout<<"\nCouldn't open file teachers.dat";
						exit(0);
					}
				clrscr();
				int c;
				cout<<"\nMENU";
				cout<<"\n1.Enter records";
				cout<<"\n2.Delete record";
				cout<<"\n3.Modify record";
				cout<<"\n4.List teachers available for substitution";
				cout<<"\n5.List names of all records";
				cout<<"\n6.Display details of a teacher";
				cout<<"\n7.Exit";
				cout<<"\nEnter choice:";
				cin>>c;
				switch(c)
					{
						case 1:
						insert_rec(file);
						break;

						case 2:
						delete_rec(file);
						break;

						case 3:
						modify_rec(file);
						break;

						case 4:
						display_subs(file);
						break;

						case 5:
						display_all(file);
						break;

						case 6:
						display_rec(file);
						break;

						case 7:
						exit(0);
				}
				cout<<"\nDo you want to continue(y/n):";
				cin>>ch;
			}
		while(ch=='y'||ch=='Y');
		getch();

	}

/*************************************************************************/

void display_subs(fstream &file)
	{
		int day;
		int period;
		char ptr[20][20];
		cout<<"\nEnter day number(Monday-1|Tuesday-2|etc):";
		cin>>day;
		cout<<"\nEnter current period:";
		cin>>period;
		cout<<"\nEnter names of teachers who are absent(for example:Rajender Shah)\n";
		char ch;int i=0;
			do
				{
					cout<<"Name:";
					gets(ptr[i++]);
					cout<<"\nDo you want to enter more names(y/n):";
					cin>>ch;
				}
	while(ch=='y'||ch=='Y');
	clrscr();
	cout<<"\nThe classes in which substitution is required are:";
	subject_teacher temp;
	int j=0;
	int flag=0;
	int flag2=0;
	int count=0;
	int none=0;
	ofstream fout;
	fout.open("Temp.dat",ios::binary);
		if(!fout)
			{
				cout<<"\nCouldn't open file temp.dat";
				getch();
				exit(0);
			}
	while(file.read((char*)&temp,sizeof(temp)))
		{
			j=0;
			count=0;
			while(j<i)//to match the name read from file with the names of absent teachers
				{
					if(strcmp(ptr[j++],temp.return_name())==0)
						{
							flag=1;//to see if entered absentees are matched or not
							count=1;//to note that found teacher is present and this record should not be written to temp file
								if(strcmp(temp.return_tt(day,period),"free"))//for any non-zero value if is entered
									{
										none=1;
										cout<<endl<<temp.return_tt(day,period);//if period of the absent teacher was not free, return the grade she was assigned
										break;
									}
						}
				}

					if(count==0)//if the traversed record is not in the 2d array of absent teachers, it is written to temp file
						{
						fout.write((char*)&temp,sizeof(temp));
						}

		}

fout.close();

if(flag==0)
	cout<<"\nNone of the entered absentees exist in records";
else if(none==0)
cout<<"\nSubstitution not required as entered teachers had free periods";
else
	{
		ifstream fin;
		fin.open("Temp.dat",ios::binary);
		if(!fin){cout<<"\ncould'nt open file temp.dat";exit(0);}

		cout<<"\nList of teachers available for substitution are:";

		while(fin.read((char*)&temp,sizeof(temp)))
			{
				if(strcmp(temp.return_tt(day,period),"free")==0)//only if the present teacher has a free period is she eligible for substitution
				{
				flag2=1;
				cout<<endl<<temp.return_name();
				}
			}
		if(flag2==0)
		cout<<"\nNo teachers are currently free";
	}
}

/*************************************************************************/

void insert_rec(fstream &file)//insertion in ascending order
	{
		ofstream fout;
		fout.open("Temp2.dat",ios::binary);
		if(!fout)
			{
				cout<<"\nCouldn't open file:temp2.dat";
				exit(0);
			}
		subject_teacher s1;
		s1.get_data();//record to be inserted in file
		subject_teacher temp;//object in memory to receive data from file
		int flag=0;
		while(file.read((char*)&temp,sizeof(temp)))
			{
				if(strcmp(s1.return_name(),temp.return_name())<0 && flag!=1)
					{
						fout.write((char*)&s1,sizeof(s1));
						flag=1;
						fout.write((char*)&temp,sizeof(temp));
					}
				else
					fout.write((char*)&temp,sizeof(temp));
			}


		if(flag==0)
			{
				fout.write((char*)&s1,sizeof(s1));
			}
		file.close();
		fout.close();
		remove("Teachers.dat");
		rename("Temp2.dat","Teachers.dat");
	}

/*************************************************************************/

void display_all(fstream &file)
	{
		subject_teacher temp;
		while(file.read((char*)&temp,sizeof(subject_teacher)))
			{
				cout<<endl<<temp.return_name();
			}
		cout<<"\nRecords successfully displayed";
	}

/***************************************************************************/

void delete_rec(fstream &file)//sorted deletion
	{
		ofstream fout;
		fout.open("Temp3.dat",ios::binary);
		if(!fout){cout<<"\nCouldn't open file:temp3.dat";exit(0);}
		cout<<"\nEnter the name of the record to be deleted:";
		char name[20];
		gets(name);
		int flag=0;
		subject_teacher s1;
		while(file.read((char*)&s1,sizeof(s1)))
			{
				if(strcmp(s1.return_name(),name)==0)
					{
						flag=1;
						char ch;
						cout<<"\nAre you sure you want to delete the record(y/n)?:";
						cin>>ch;
						if(ch=='y'||ch=='Y')
							{
								cout<<"\nRecord successfully deleted";
							}
						else
							{
								fout.write((char*)&s1,sizeof(s1));
							}
					}

				else
					{
						fout.write((char*)&s1,sizeof(s1));
					}
			}

		if(flag==0)
			{
				cout<<"\nNo such record exists";
			}

		file.close();
		fout.close();

		remove("Teachers.dat");
		rename("Temp3.dat","Teachers.dat");
	}

/****************************************************************************/

void modify_rec(fstream &file)
{
cout<<"\nEnter name of teacher to be modified:";
char name[20];
gets(name);
subject_teacher temp;
int flag=0;
long pos=file.tellg();
while(file.read((char*)&temp,sizeof(subject_teacher)))
	{
		if(strcmp(temp.return_name(),name)==0)
			{
				flag=1;
				file.seekp(pos);

				subject_teacher s1;
				cout<<"\nEnter new details:\n";
				s1.get_data();
				file.write((char*)&s1,sizeof(s1));
				cout<<"\nRecord successfully modified";
				break;
			}
		pos=file.tellg();
	}
if(flag==0)
cout<<"\nNo such teacher name found";
file.close();
}

/****************************************************************************/

void display_rec(fstream &file)
	{
		subject_teacher temp;
		cout<<"\nEnter name of teacher whose details you want to see:";
		char string[20];
		gets(string);
		int count=0;
		while(file.read((char*)&temp,sizeof(temp)))
			{
				if(!strcmp(string,temp.return_name()))
					{
						count++;
						temp.display();
					}
			}

		if(count==0)
		cout<<"\nNo such record found";
		else if(count>1)
		cout<<"\nMultiple records were found";

	}

/***************************************************************************/































