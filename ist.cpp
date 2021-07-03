#include<iostream>
using namespace std;

class NODE
{
private:
	int data;
	NODE *next;
public:
	void setdata(int val)
	{
		data=val;
	}
	int getdata()const
	{
		return data;
	}
	void setnext(NODE *ptr)
	{
		next=ptr;
	}
	NODE* getnext()
	{
		return next;
	}
};

class LIST
{
private:
	NODE *headnode;
	NODE *current;
	NODE *previous;
	int size;
public:
	LIST()
	{
		headnode=new NODE();
		headnode->setnext(NULL);
		current=previous=NULL;
		size=0;
	}
	void add(int val)
	{
		NODE *newnode=new NODE();
		newnode->setdata(val);
		if(current!=NULL)
		{
			newnode->setnext(current->getnext());
			current->setnext(newnode);
			previous=current;
			current=newnode;
		}
		else
		{
			//newnode->setnext(newnode->getnext());
			newnode->setnext(NULL);
			headnode->setnext(newnode);
			previous=headnode;
			current=newnode;
		}
			size++;
	}
	void Delete()
	{
		if(current!=NULL||size!=0)
		{
			previous->setnext(current->getnext());
			delete current;
			current=previous->getnext();
			size--;
		}
	}
	void start()
	{
		previous=current=headnode;
	}
	int getvalue()
	{
		return current->getdata();
	}
	int length()
	{
		return size;
	}
	void next()
	{
		if(size!=0||current!=NULL)
		{
			previous=current;
			current=current->getnext();
		}
}
void sort() //for sorting the list
{
	int val;
	NODE* temp=headnode;
	for(int i=0;i<=this->length()-1;i++)
	{
		for(int j=0;j<=this->length()-i-1;j++)
		{
			if(temp->getdata()>temp->getnext()->getdata())
			{
				val=temp->getdata();
				temp->setdata(temp->getnext()->getdata());
				temp->getnext()->setdata(val);
			}
			temp=temp->getnext();
		}
		temp=headnode;
	}
}
/*
ye function do lists ly ga aik me values hn gi or dosri me indexes hn gy
or phr in dono sy aik third list bny gi according to indexes
jasa k  l1 -> 23,55,87,13,15......
        l2 -> 1,3,5 and list l3 will be l3 -> 23,87,15.
                                                                          */
LIST task(LIST list)                   
{
	list.sort();                                // passing list is a list of indexes
	NODE* node1=headnode->getnext();            // head is a dummy node so we move it to next
	NODE* node2=list.headnode->getnext();
    LIST l;	
	while(node1!=NULL&&node2!=NULL)
	{
		int val=node2->getdata();
		if(val<=0)
		{
			cout<<"Invalid index. Index is starting from 1 to onward."<<endl;
				exit(0);
		}
		else
		{
			{
		      for(int i=1;i<val;i++)
		      {
	     		node1=node1->getnext();
	     		if(node1==NULL)
			    {
				   cout<<"Sorry! index is going out of range."<<endl;
				   exit(0);
			    }
		      }
		         l.add(node1->getdata());
		         node1=headnode->getnext();
	           	 node2=node2->getnext();
	         }   
           }
	}
	return l;	
}
            
};



void display(LIST);


int main()
{
	LIST l,l2;
	l.add(55);
	l.add(44);
	l.add(3);
	l.add(22);
	l.add(11);
	l2.add(2);
	//l2.add(0);
	l2.add(1);
	l2.add(3);
	l2.add(4);
	//l.sort();
	display(l.task(l2));
	system("pause");
	return 0;
}
void display(LIST list)
{
	list.start();
	for(int i=0;i<list.length();i++)
	{
		list.next();
		cout<<list.getvalue()<<endl;
	}
}




