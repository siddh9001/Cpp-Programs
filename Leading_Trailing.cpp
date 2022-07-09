// #include<bits/stdc++.h>
// using namespace std;


// void leading(char var, int terms, vector<char>& term, unordered_map<char, vector<string>>& productions)
// {
//     vector<char> ans;


//     cout << "\nLEADING("<<var<<"): {" << ans[0];
//     for(int i=0;i<ans.size();i++)
//         cout << "," <<ans[i];
//     cout << "}\n";
// }

// void trailing(char var, int terms, vector<char>& term, unordered_map<char, vector<string>>& productions)
// {
//     vector<char> ans;
    

//     cout << "\nTRAILING("<<var<<"): {" << ans[0];
//     for(int i=0;i<ans.size();i++)
//         cout << "," <<ans[i];
//     cout << "}\n";
// }

// main()
// {
//     int vars, terms, prods;
//     unordered_map<char, vector<string>> productions;
    
//     //taking variables
//     cout << "\nEnter the number of variables : \n";
//     cin >> vars;
//     vector<char> var(vars);
//     cout << "\nEnter the variables : \n";
//     for(int i=0;i<vars;i++)
//         cin >> var[i];    
        
//     // taking terminals   
//     cout << "\nEnter the number of terminals : \n";
//     cin >> terms;
//     vector<char> term(terms);
//     cout << "\nEnter the terminals : \n";
//     for(int i=0;i<terms;i++)
//         cin >> term[i];
     
//     //Entering the number of productions 
//     cout << "\nEnter the number of productions : \n";
//     cin >> prods;
//     cout << "\nEnter the productions : \n";
//     for(int i=0;i<prods;i++)
//     {
//         char lhs;
//         string rhs;
//         cout << "\nEnter the lhs of production number "<< i+1 << ": \n";
//         cin >> lhs;
//         cout << "\nEnter the rhs of production number "<< i+1 << ": \n";
//         cin >> rhs;
//         productions[lhs].push_back(rhs);
//     }
    
    
//     for(int i=0;i<vars;i++){
//         cout<< "Leading for variable "<< var[i] << ": ";
//         leading(var[i], terms, term, productions);
//         cout<< "Trailing for the variable "<< var[i] << ": ";
//         trailing(var[i], terms, term, productions);
//     }
// }
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int vars,terms,i,j,k,m,rep,count,temp=-1;
char var[10],term[10],lead[10][10],trail[10][10];
struct grammar
{	
	int prodno;
	char lhs,rhs[20][20];
}gram[50];

void get()
{
	cout<<"\nLEADING AND TRAILING\n";
	cout<<"\nEnter the no. of variables : ";
	cin>>vars;
	cout<<"\nEnter the variables : \n";
	for(i=0;i<vars;i++)
	{
		cin>>gram[i].lhs;
		var[i]=gram[i].lhs;
	}
	cout<<"\nEnter the no. of terminals : ";
	cin>>terms;
	cout<<"\nEnter the terminals : \n";
	for(j=0;j<terms;j++)
		cin>>term[j];
	cout<<"\nPRODUCTION DETAILS\n";
	for(i=0;i<vars;i++)
	{
		cout<<"\nEnter the no. of production of "<<gram[i].lhs<<":";
		cin>>gram[i].prodno;
		for(j=0;j<gram[i].prodno;j++)
		{
			cout<<gram[i].lhs<<"->";
			cin>>gram[i].rhs[j];
		}
	}
}
void leading()
{
	for(i=0;i<vars;i++)
	{
		for(j=0;j<gram[i].prodno;j++)
		{
			for(k=0;k<terms;k++)
			{
				if(gram[i].rhs[j][0]==term[k])
					lead[i][k]=1;
				else
				{
					if(gram[i].rhs[j][1]==term[k])
						lead[i][k]=1;
				}
			}
		}
	}
	for(rep=0;rep<vars;rep++)
	{
		for(i=0;i<vars;i++)
		{
			for(j=0;j<gram[i].prodno;j++)
			{
				for(m=1;m<vars;m++)
				{
					if(gram[i].rhs[j][0]==var[m])
					{
						temp=m;
                        break;
					}
				}
				for(k=0;k<terms;k++)
				{
					if(lead[temp][k]==1)
						lead[i][k]=1;
				}
			}
		}
	}
}
void trailing()
{
	for(i=0;i<vars;i++)
	{
		for(j=0;j<gram[i].prodno;j++)
		{
			count=0;
			while(gram[i].rhs[j][count]!='\x0')
				count++;
			for(k=0;k<terms;k++)
			{
				if(gram[i].rhs[j][count-1]==term[k])
					trail[i][k]=1;
				else
				{
					if(gram[i].rhs[j][count-2]==term[k])
						trail[i][k]=1;
				}
			}
		}
	}
	for(rep=0;rep<vars;rep++)
	{
		for(i=0;i<vars;i++)
		{
			for(j=0;j<gram[i].prodno;j++)
			{
				count=0;
				while(gram[i].rhs[j][count]!='\x0')
					count++;
				for(m=1;m<vars;m++)
				{
					if(gram[i].rhs[j][count-1]==var[m])
						temp=m;
				}
				for(k=0;k<terms;k++)
				{
					if(trail[temp][k]==1)
						trail[i][k]=1;
				}
			}
		}
	}
}
void display()
{
	for(i=0;i<vars;i++)
	{
		cout<<"\nLEADING("<<gram[i].lhs<<") = {";
		for(j=0;j<terms;j++)
		{
			if(lead[i][j]==1)
				cout<<term[j]<<",";
		}
        cout << "}";
	}
    
	cout<<endl;
	for(i=0;i<vars;i++)
	{
		cout<<"\nTRAILING("<<gram[i].lhs<<") = {";
		for(j=0;j<terms;j++)
		{
			if(trail[i][j]==1)
				cout<<term[j]<<",";
		}
        cout << "}";
	}
    
}
int main()
{

	get();
	leading();
	trailing();
	display();

}