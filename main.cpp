#include <iostream>
#include<graphics.h>
#include<cstdlib>
#include<math.h>
#include<cstdio>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    int x,y,S[10];
    initgraph(&gd,&gm, "C:\TURBOC3\BGI");

    char bexp[100],res[100];
    int a[100][100],kmap[100][100],arr1[100],narr[100],ar[100][100],value[100],cause[100],ck[100][100];
    int i,p=0,j,k=0,n=0,count=0,choice=0,t=0,var=0,size,cont=0,c1=0,row=0,col=0;
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
        a[i][j]=0;

    cout<<"\n\n\n1. Enter a Boolean Expression.";
    cout<<"\n\n2. Enter values in the truth table.\n\n";
    cout<<"\n\n Select from the choices given below : ";
    cin>>choice;
    if(choice==1)
    {
        system("cls");
        cout<<"\n\n Enter the Boolean Expression : ";
        cin>>bexp;

        for(int i=0;bexp[i]!='\0';i++)
		{
            if(bexp[i]>='a' && bexp[i]<='z' || bexp[i]>='A' && bexp[i]<='Z')
            {
                narr[k]=bexp[i];
                k++;
                cont++;
                for(int j=i+1;bexp[j]!='\0';j++)
                {
                    if(bexp[j]>='a' && bexp[j]<='z' || bexp[j]>='A' && bexp[j]<='Z')
                    {
                        if(bexp[i]==bexp[j])
                        {
                            cont--;
                            break;
                        }
                    }
                }
            }
		}

        for(int i=0;i<cont;i++)
        {
            for(int j=0;j<pow(2,cont);)
            {
                for(int f=0;f<pow(2,i);f++)
                {
                    a[i][j]=t;
                    j++;
                }
                if(t==0)
                    t++;
                else if(t==1)
                    t--;
            }
        }
        char b[cont];
        if(cont==2)
        {
            b[0]='A';
            b[1]='B';
        }
        else if(cont==3)
        {
            b[0]='A';
            b[1]='B';
            b[2]='C';
        }
        else if(cont==4)
        {
            b[0]='A';
            b[1]='B';
            b[2]='C';
            b[3]='D';
        }
        int cha1=0;
        for(y=0;y<pow(2,cont);y++)
        {
            c1=0;
            for(int q=0;q<bexp[q]!='\0';q++)
            {
                if(q!=bexp[q]!='\0'-1)
                {
                    cha1=bexp[q+1];
                }
                if(bexp[q]=='+')
                {
                    ar[y][c1]=9;
                    c1++;
                }
                else
                {
                    for(int w=0;w<cont;w++)
                    {
                        if(bexp[q]==b[w])
                        {
                            if(cha1=='^')
                            {
                                if(a[w][y]==0)
                                ar[y][c1]=1;
                                else if(a[w][y]==1)
                                ar[y][c1]=0;
                                c1++;
                            }
                            else
                            {
                                ar[y][c1]=a[w][y];
                                c1++;
                            }
                        }
                    }
                }
            }
        }
		for(int i=0;i<pow(2,cont);i++)
		{
			for(int j=0;j<c1;j++)
			{
				cout<<ar[i][j];
			}
			cout<<endl;
		}


	for(int u=0;u<pow(2,cont);u++)
	{
		for(int j=0;j<c1;j++)
		{
			if(ar[u][j]!=9)
			{
				value[u]=(ar[u][j])*value[u];
			}
			else
			{
				cause[u]=value[u]+cause[u];
				value[u]=1;
			}
		}
		cause[u]=cause[u]+value[u];
	}
	for(int i=0;cause[i]!='\0';i++)
	{
		if(cause[i]>1)
			cause[i]=1;
	}

	for(int u=0;u<pow(2,cont);u++)
	{
		cout<<cause[u]<<"\n";
	}

    if(cont%2==0)
	{
		row=cont;
		col=cont;
	}
	else
	{
		row=cont-1;
		col=2*(cont-1);
	}
	int p=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			kmap[i][j]=cause[p];
			ck[i][j]=0;
			p++;
		}
		cout<<endl;
	}
	int faltu=0;
	if(col>2)
	{
		for(int g=0;g<row;g++)
		{
			faltu=kmap[g][3];
			kmap[g][3]=kmap[g][2];
			kmap[g][2]=faltu;
		}
	}
	if(row>2)
	{
		for(int g=0;g<col;g++)
		{
			faltu=kmap[3][g];
			kmap[3][g]=kmap[2][g];
			kmap[2][g]=faltu;
		}
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<kmap[i][j];
		}
		cout<<endl;
	}

		if(cont==2)
        {
            outtextxy(83,15,"TRUTH TABLE");
            rectangle(64,40,196,250);
            line(108,40,108,250);
            line(152,40,152,250);
            line(196,40,196,250);
            line(64,80,196,80);
            outtextxy(82,52,"A");
            outtextxy(126,52,"B");
            for(i=0;i<pow(2,cont);i++)
            {
                for(j=0;j<cont;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(82+44*j,90+38*i,"0");
                    else
                        outtextxy(82+44*j,90+38*i,"1");
                }
                cout<<endl;
            }
            outtextxy(350,80,"K MAP");
            rectangle(320,150,420,250);
            line(370,150,370,250);
            line(420,150,420,250);
            line(320,200,420,200);
            line(280,125,320,150);
            outtextxy(290,140,"A");
            outtextxy(303,120,"B");
            outtextxy(340,130,"0");
            outtextxy(395,130,"1");
            outtextxy(295,168,"0");
            outtextxy(295,218,"1");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(kmap[i][j]==0)
                        outtextxy(340+55*j,168+50*i,"0");
                    else
                        outtextxy(340+55*j,168+50*i,"1");
                }
            }
        }
        else if(cont==3)
        {
            rectangle(20,40,196,380);
            line(64,40,64,380);
            line(108,40,108,380);
            line(152,40,152,380);
            line(196,40,196,380);
            line(20,80,196,80);
            outtextxy(38,52,"A");
            outtextxy(82,52,"B");
            outtextxy(126,52,"C");
            for(i=0;i<pow(2,cont);i++)
            {
                for(j=0;j<cont;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(38+44*j,90+38*i,"0");
                    else
                        outtextxy(38+44*j,90+38*i,"1");
                }
                cout<<endl;
            }
            rectangle(320,150,540,250);
            line(375,150,375,250);
            line(430,150,430,250);
            line(485,150,485,250);
            line(320,200,540,200);
            line(280,125,320,150);
            outtextxy(290,140,"A");
            outtextxy(303,120,"B C");
            outtextxy(340,130,"00");
            outtextxy(395,130,"01");
            outtextxy(450,130,"11");
            outtextxy(505,130,"10");
            outtextxy(295,168,"0");
            outtextxy(295,218,"1");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(kmap[i][j]==0)
                        outtextxy(340+55*j,168+50*i,"0");
                    else
                        outtextxy(340+55*j,168+50*i,"1");
                }
            }
        }
        else if(cont==4)
        {
            rectangle(20,40,240,455);
            line(64,40,64,455);
            line(108,40,108,455);
            line(152,40,152,455);
            line(196,40,196,455);
            line(20,80,240,80);
            outtextxy(38,52,"A");
            outtextxy(82,52,"B");
            outtextxy(126,52,"C");
            outtextxy(170,52,"D");
            for(i=0;i<pow(2,cont);i++)
            {
                for(j=0;j<cont;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(38+44*j,88+23*i,"0");
                    else
                        outtextxy(38+44*j,88+23*i,"1");
                }
                cout<<endl;
            }
            for(i=0;i<pow(2,cont);i++)
            {
                if(cause[i]==0)
                    outtextxy(214,88+23*i,"0");
                else
                    outtextxy(214,88+23*i,"1");
            }
            rectangle(320,150,540,350);
            line(375,150,375,350);
            line(430,150,430,350);
            line(485,150,485,350);
            line(320,200,540,200);
            line(320,250,540,250);
            line(320,300,540,300);
            line(280,125,320,150);
            outtextxy(280,140,"A B");
            outtextxy(303,120,"C D");
            outtextxy(340,130,"00");
            outtextxy(395,130,"01");
            outtextxy(450,130,"11");
            outtextxy(505,130,"10");
            outtextxy(295,168,"00");
            outtextxy(295,218,"01");
            outtextxy(295,268,"11");
            outtextxy(295,318,"10");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(kmap[i][j]==0)
                        outtextxy(340+55*j,168+50*i,"0");
                    else
                        outtextxy(340+55*j,168+50*i,"1");
                }
            }
        }
    }
    else if(choice==2)
    {
        system("cls");
        cout<<"\n\n1. 2 Variables";
        cout<<"\n\n2. 3 Variables";
        cout<<"\n\n3. 4 Variables";
        cout<<"\n\n\nSelect your choice for filling truth table : ";
        cin>>count;
        for(int i=0;i<count+1;i++)
            {
                for(int j=0;j<pow(2,count+1);)
                {
                    for(int f=0;f<pow(2,i);f++)
                    {
                        a[i][j]=t;
                        j++;
                    }
                    if(t==0)
                        t++;
                    else if(t==1)
                        t--;
                }
            }
        if(count==1)
        {
            cout<<"How many 1s you want in the KMap : ";
            cin>>size;
            int arr[size];
            for(int g=0;g<100;g++)
            {
                arr[g]=0;
                arr1[g]=0;
            }
            cout<<"Enter the positions where you want 1s in KMap : ";
            for(i=0;i<size;i++)
                {
                    cin>>arr[i];
                    arr1[arr[i]-1]=1;
                }
            outtextxy(83,15,"TRUTH TABLE");
            rectangle(64,40,196,250);
            line(108,40,108,250);
            line(152,40,152,250);
            line(196,40,196,250);
            line(64,80,196,80);
            outtextxy(82,52,"A");
            outtextxy(126,52,"B");
            for(i=0;i<pow(2,count+1);i++)
            {
                for(j=0;j<count+1;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(82+44*j,90+38*i,"0");
                    else
                        outtextxy(82+44*j,90+38*i,"1");
                }
                cout<<endl;
            }
            for(k=0;k<pow(2,count+1);k++)
            {
                if(arr1[k]==0)
                    outtextxy(170,90+38*k,"0");
                else
                    outtextxy(170,90+38*k,"1");
            }
            outtextxy(350,80,"K MAP");
            rectangle(320,150,420,250);
            line(370,150,370,250);
            line(420,150,420,250);
            line(320,200,420,200);
            line(280,125,320,150);
            outtextxy(290,140,"A");
            outtextxy(303,120,"B");
            outtextxy(340,130,"0");
            outtextxy(395,130,"1");
            outtextxy(295,168,"0");
            outtextxy(295,218,"1");
        }

        if(count==2)
        {
            cout<<"How many 1s you want in the KMap : ";
            cin>>size;
            int arr[size];
            for(int g=0;g<100;g++)
            {
                arr[g]=0;
                arr1[g]=0;
            }
            cout<<"Enter the positions where you want 1s in KMap : ";
            for(i=0;i<size;i++)
                {
                    cin>>arr[i];
                    arr1[arr[i]-1]=1;
                }
            rectangle(20,40,196,380);
            line(64,40,64,380);
            line(108,40,108,380);
            line(152,40,152,380);
            line(196,40,196,380);
            line(20,80,196,80);
            outtextxy(38,52,"A");
            outtextxy(82,52,"B");
            outtextxy(126,52,"C");
            for(i=0;i<pow(2,count+1);i++)
            {
                for(j=0;j<count+1;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(38+44*j,90+38*i,"0");
                    else
                        outtextxy(38+44*j,90+38*i,"1");
                }
                cout<<endl;
            }
            for(k=0;k<pow(2,count+1);k++)
            {
                if(arr1[k]==0)
                    outtextxy(170,90+38*k,"0");
                else
                    outtextxy(170,90+38*k,"1");
            }
            rectangle(320,150,540,250);
            line(375,150,375,250);
            line(430,150,430,250);
            line(485,150,485,250);
            line(320,200,540,200);
            line(280,125,320,150);
            outtextxy(290,140,"A");
            outtextxy(303,120,"B C");
            outtextxy(340,130,"00");
            outtextxy(395,130,"01");
            outtextxy(450,130,"11");
            outtextxy(505,130,"10");
            outtextxy(295,168,"0");
            outtextxy(295,218,"1");
        }

        if(count==3)
        {
            cout<<"How many 1s you want in the KMap : ";
            cin>>size;
            int arr[size];
            for(int g=0;g<100;g++)
            {
                arr[g]=0;
                arr1[g]=0;
            }
            cout<<"Enter the positions where you want 1s in KMap : ";
            for(i=0;i<size;i++)
            {
                cin>>arr[i];
                arr1[arr[i]-1]=1;
            }
            rectangle(20,40,240,455);
            line(64,40,64,455);
            line(108,40,108,455);
            line(152,40,152,455);
            line(196,40,196,455);
            line(20,80,240,80);
            outtextxy(38,52,"A");
            outtextxy(82,52,"B");
            outtextxy(126,52,"C");
            outtextxy(170,52,"D");
            for(i=0;i<pow(2,count+1);i++)
            {
                for(j=0;j<count+1;j++)
                {
                    if(a[j][i]==0)
                        outtextxy(38+44*j,88+23*i,"0");
                    else
                        outtextxy(38+44*j,88+23*i,"1");
                }
                cout<<endl;
            }
            for(k=0;k<pow(2,count+1);k++)
            {
                if(arr1[k]==0)
                    outtextxy(214,88+23*k,"0");
                else
                    outtextxy(214,88+23*k,"1");
            }
            rectangle(320,150,540,350);
            line(375,150,375,350);
            line(430,150,430,350);
            line(485,150,485,350);
            line(320,200,540,200);
            line(320,250,540,250);
            line(320,300,540,300);
            line(280,125,320,150);
            outtextxy(280,140,"A B");
            outtextxy(303,120,"C D");
            outtextxy(340,130,"00");
            outtextxy(395,130,"01");
            outtextxy(450,130,"11");
            outtextxy(505,130,"10");
            outtextxy(295,168,"00");
            outtextxy(295,218,"01");
            outtextxy(295,268,"11");
            outtextxy(295,318,"10");
        }
    }
    getch();
    closegraph();


















    /*int  t=0,flag=0,c1=0;
		double	row=0,col=0;
		int a[][]=new int[100][100];
		char arr[]=new char[100];
		char b[]=new char[100];
		int value[]=new int[100];
		int cause[]=new int[100];
		int ar[][]=new int[1000][1000];
		int ck[][]=new int[1000][1000];
		char cha1=' ';
		int kmap[][]=new int[1000][1000];

		for(int i=0;i<100;i++)
		{
			value[i]=1;
			cause[i]=0;
		}
		for(int i=0;i<input.length();i++)
		{
			char c= input.charAt(i);
                        if(c>='a'&&c<='z'||c>='A'&&c<='Z')
                        {
                        arr[k]=c;
			k++;
			count++;
			for(int j=i+1;j<input.length();j++)
			{
				char ch= input.charAt(j);
				if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
				{

					if(c==ch){
						count--;
						break;
					}

				}
			}
		}
		}
		for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (arr[i] == arr[j]) // checking one element with all the elements
                {int s=j;
                for(int f=j+1;f<k;f++,s++)
                {
                	arr[s]=arr[f];
                }
                    arr[j] = arr[j + 1];// shifting the values
                    k--;
                    j--;
                }
            }
        }
            if(count==1 || count>4)
                t2.setText("Max. 4 variables allowed");
            else
            {
                for(int i=0;i<count;i++)
                {
                    for(int j=0;j<pow(2,count);)
                    {
                        for(int f=0;f<pow(2,i);f++)
                        {
                            a[i][j]=t;
                            j++;
                        }
                    if(t==0)
                        t++;
                    else if(t==1)
                        t--;
                    }
                }
                for(int i=0;i<count;i++)
                {
                    for(int j=0;j<pow(2,count);j++)
                    {
                        cout<<a[i][j];
                    }
                    cout<<endl;
                }
                for(int y=0;y<pow(2,count);y++)
                {
                    c1=0;
                    for(int q=0;q<bexp[q]!='\0';q++)
                    {
                        cin>>bexp[q];
                        if(q!=input.length()-1)
                        {
                            cha1=input.charAt(q+1);
                        }
                        if(cha=='+')
                        {
                            ar[y][c1]=2;
                            c1++;
                        }
                        else
                        {
                            for(int w=0;w<k;w++)
                            {
                                if(cha==b[w])
                                {
                                    if(cha1=='^')
                                    {
                                        if(a[w][y]==0)
                                        ar[y][c1]=1;
                                        else if(a[w][y]==1)
                                            ar[y][c1]=0;
                                        c1++;
                                    }
                                    else
                                    {
                                        ar[y][c1]=a[w][y];
                                        c1++;
                                    }
                                }
                            }
                        }
                    }
                }

		for(int i=0;i<pow(2,count);i++)
		{
			for(int j=0;j<c1;j++)
			{
				System.out.print(ar[i][j]);
			}
			System.out.println();
		}


	for(int u=0;u<pow(2,count);u++)
	{
		for(int j=0;j<c1;j++)
		{
			if(ar[u][j]!=2)
			{
				value[u]=(ar[u][j])*value[u];
			}
			else
			{
				cause[u]=value[u]+cause[u];
				value[u]=1;
			}
		}
		cause[u]=cause[u]+value[u];
	}
	for(int i=0;i<cause.length;i++)
	{
		if(cause[i]>1)
			cause[i]=1;
	}

	for(int u=0;u<pow(2,count);u++)
	{
		System.out.println(cause[u]);
	}
	if(count%2==0)
	{
		row=count;
		col=count;
	}
	else
	{
		row=count-1;
		col=2*(count-1);
	}
	System.out.println(row);
	System.out.println(col);
	int p=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			kmap[i][j]=cause[p];
			ck[i][j]=0;
			p++;
		}
		System.out.println();
	}
	int faltu=0;
	if(col>2)
	{
		for(int g=0;g<row;g++)
		{
			faltu=kmap[g][3];
			kmap[g][3]=kmap[g][2];
			kmap[g][2]=faltu;
		}
	}
	if(row>2)
	{
		for(int g=0;g<col;g++)
		{
			faltu=kmap[3][g];
			kmap[3][g]=kmap[2][g];
			kmap[2][g]=faltu;
		}
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			System.out.print(kmap[i][j]);
		}
		System.out.println();
	}

	// Converting Decimal to Binary

    int binary[][] = new int[4][2];
    binary[0][0]=0;
    binary[0][1]=0;
    binary[1][0]=0;
    binary[1][1]=1;
    binary[2][0]=1;
    binary[2][1]=1;
    binary[3][0]=1;
    binary[3][1]=0;

		int c2=0;
	String op="";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(kmap[i][j]==0)
			{
				c2++;
			}
			if(c2==pow(2,count))
			{
				op=op+1;
			}
			if(count==4)
			{
				 if(kmap[i][j]==1&&ck[i][j]==0)
				 {
			{ flag=0;
			if(flag==0)
			{
			if(kmap[i][0]==1&&kmap[i][1]==1&&kmap[i][2]==1&&kmap[i][3]==1&&kmap[(i+1)%4][0]==1&&kmap[(i+1)%4][1]==1&&kmap[(i+1)%4][2]==1&&kmap[(i+1)%4][3]==1)
				{
					if(binary[i][0]==binary[(i+1)%4][0])
					{
						if(binary[i][0]==0)
						{
							op=arr[0]+"^"+"+"+op;
						//	break;
						}
						else
						{
							op=arr[0]+"+"+op;
							//break;
						}

					}
					else if(binary[i][1]==binary[(i+1)%4][1])
					{
						if(binary[i][0]==0)
						{
							op=arr[1]+"^"+"+"+op;
							//break;
						}
						else
						{
							op=arr[1]+"+"+op;
							//break;
						}
					}
					flag=1;
					 ck[i][0]=1;ck[i][1]=1;ck[i][2]=1;ck[i][3]=1;
					   ck[(i+1)%4][0]=1;ck[(i+1)%4][1]=1;ck[(i+1)%4][2]=1;ck[(i+1)%4][3]=1;
				}
				else	 if(kmap[i][0]==1&&kmap[i][1]==1&&kmap[i][2]==1&&kmap[i][3]==1&&kmap[(4+(i-1))%4][0]==1&&kmap[(4+(i-1))%4][1]==1&&kmap[(4+(i-1))%4][2]==1&&kmap[(4+(i-1))%4][3]==1)
				 {
						if(binary[i][0]==binary[(4+(i-1))%4][0])
						{
							if(binary[i][0]==0)
							{
								op=arr[0]+"^"+"+"+op;
								//break;
							}
							else
							{
								op=arr[0]+"+"+op;
								//break;
							}
						}
						else if(binary[i][1]==binary[(4+(i-1))%4][1])
						{
							if(binary[i][0]==0)
							{
								op=arr[1]+"^"+"+"+op;
								//break;
							}
							else
							{
								op=arr[1]+"+"+op;
								//break;
							}
						}
						//break;
						flag=1;
						 ck[i][0]=1;ck[i][1]=1;ck[i][2]=1;ck[i][3]=1;
						   ck[(4+(i-1))%4][0]=1;ck[(4+(i-1))%4][1]=1;ck[(4+(i-1))%4][2]=1;ck[(4+(i-1))%4][3]=1;
				 }
				 else  if(kmap[0][j]==1&&kmap[1][j]==1&&kmap[2][j]==1&&kmap[3][j]==1&&kmap[0][(j+1)%4]==1&&kmap[1][(j+1)%4]==1&&kmap[2][(j+1)%4]==1&&kmap[3][(j+1)%4]==1)
				  {
						if(binary[j][0]==binary[(j+1)%4][0])
						{
							if(binary[j][0]==0)
							{
								op=arr[2]+"^"+"+"+op;
								//break;
							}
							else
							{
								op=arr[2]+"+"+op;
								//break;
							}
						}
						else if(binary[j][1]==binary[(j+1)%4][1])
						{
							if(binary[i][0]==0)
							{
								op=arr[3]+"^"+"+"+op;
							//	break;
							}
							else{
								op=arr[3]+"+"+op;
								//break;
							}
						}
						//break;
						flag=1;
						 ck[0][j]=1;ck[1][j]=1;ck[2][j]=1;ck[3][j]=1;
						   ck[0][(j+1)%4]=1;ck[1][(j+1)%4]=1;ck[2][(j+1)%4]=1;ck[3][(j+1)%4]=1;
				  }
				  else	  if(kmap[0][j]==1&&kmap[1][j]==1&&kmap[2][j]==1&&kmap[3][j]==1&&kmap[0][(4+(j-1))%4]==1&&kmap[1][(4+(j-1))%4]==1&&kmap[2][(4+(j-1))%4]==1&&kmap[3][(4+(j-1))%4]==1)
				  {
						if(binary[j][0]==binary[4+(j-1)%4][0])
						{
							if(binary[j][0]==0)
							{
								op=arr[2]+"^"+"+"+op;
								//break;
							}
							else
							{
								op=arr[2]+"+"+op;
								//break;
							}
						}
						else if(binary[j][1]==binary[4+(j-1)%4][1])
						{
							if(binary[i][0]==0)
							{
								op=arr[3]+"^"+"+"+op;
							//	break;
							}
							else
							{
								op=arr[3]+"+"+op;
							//	break;
							}
						}
						//break;
						flag=1;
						ck[0][j]=1;ck[1][j]=1;ck[2][j]=1;ck[3][j]=1;
						   ck[0][(4+(j-1))%4]=1;ck[1][(4+(j-1))%4]=1;ck[2][(4+(j-1))%4]=1;ck[3][(4+(j-1))%4]=1;
				  }
			}

				  if(flag==0)
				  {
				 flag=0;
				    if(kmap[i][0]==1&&kmap[i][1]==1&&kmap[i][2]==1&&kmap[i][3]==1)
				  {
					  if(i==0)
					  {
						  op=arr[0]+"^"+arr[1]+"^"+"+"+op;
					  }
					  else if(i==1)
					  {
						  op=arr[0]+"^"+arr[1]+"+"+op;
					  }
					  else if(i==2)
					  {
						  op=arr[0]+arr[1]+"+"+op;
					  }
					  else if(i==3)
					  {
						  op=arr[0]+arr[1]+"^"+"+"+op;
					  }
					//  break;
					  flag=1;
					  ck[i][0]=1;ck[i][1]=1;ck[i][2]=1;ck[i][3]=1;

				  }
				  else  if(kmap[0][j]==1&&kmap[1][j]==1&&kmap[2][j]==1&&kmap[3][j]==1)
				  {
					  if(j==0)
					  {
						  op=arr[2]+"^"+arr[3]+"^"+"+"+op;
					  }
					  else if(j==1)
					  {
						  op=arr[2]+"^"+arr[3]+"+"+op;
					  }
					  else if(j==2)
					  {
						  op=arr[2]+arr[3]+"+"+op;
					  }
					  else if(j==3)
					  {
						  op=arr[2]+arr[3]+"^"+"+"+op;
					  }
					 // break;
					  flag=1;
					  ck[0][j]=1;ck[1][j]=1;ck[2][j]=1;ck[3][j]=1;
				  }
				  else  if(kmap[i][j]==1&&kmap[i][(j+1)%4]==1&&kmap[(i+1)%4][j]==1&&kmap[(i+1)%4][(j+1)%4]==1)
				  {
					   if(i==0)
					   {
						   op=op+arr[i]+"^";
					   }
					   if(i==1)
					   {
						   op=op+arr[i];
					   }
					   if(i==2)
					   {
						   op=op+arr[0];
					   }
					   if(i==3)
					   {
						   op=op+arr[1]+"^";
					   }
					   if(j==0)
					   {
						   op=op+arr[2]+"^"+"+";
					   }
					   if(j==1)
					   {
						   op=op+arr[3]+"+";
					   }
					   if(j==2)
					   {
						   op=op+arr[2]+"+";
					   }
					   if(j==3)
					   {
						   op=op+arr[3]+"^"+"+";
					   }
					 //  break;
					   flag=1;
					   ck[i][j]=1;ck[i][(j+1)%4]=1;ck[(i+1)%4][j]=1;ck[(i+1)%4][(j+1)%4]=1;
				  }
				  else  if(kmap[i][(4+(j-1))%4]==1&&kmap[i][j]==1&&kmap[(i+1)%4][(4+(j-1))%4]==1&&kmap[(i+1)%4][j]==1)
				  {
					  if(i==0)
					   {
						   op=op+arr[i]+"^";
					   }
					   if(i==1)
					   {
						   op=op+arr[i];
					   }
					   if(i==2)
					   {
						   op=op+arr[0];
					   }
					   if(i==3)
					   {
						   op=op+arr[1]+"^";
					   }
					   if(j==0)
					   {
						   op=op+arr[3]+"^"+"+";
					   }
					   if(j==1)
					   {
						   op=op+arr[2]+"^"+"+";
					   }
					   if(j==2)
					   {
						   op=op+arr[3]+"+";
					   }
					   if(j==3)
					   {
						   op=op+arr[2]+"^"+"+";
					   }
					  // break;
					   flag=1;
					   ck[i][(4+(j-1))%4]=1;ck[i][j]=1;ck[(i+1)%4][(4+(j-1))%4]=1;ck[(i+1)%4][j]=1;
				  }
				  else  if(kmap[(4+(i-1))%4][(4+(j-1))%4]==1&&kmap[(4+(i-1))%4][j]==1&&kmap[i][(4+(j-1))%4]==1&&kmap[i][j]==1)
				  {if(i==0)
				   {
					   op=op+arr[1]+"^";
				   }
				   if(i==1)
				   {
					   op=op+arr[0]+"^";
				   }
				   if(i==2)
				   {
					   op=op+arr[1];
				   }
				   if(i==3)
				   {
					   op=op+arr[0];
				   }
				   if(j==0)
				   {
					   op=op+arr[3]+"^"+"+";
				   }
				   if(j==1)
				   {
					   op=op+arr[2]+"^"+"+";
				   }
				   if(j==2)
				   {
					   op=op+arr[3]+"+";
				   }
				   if(j==3)
				   {
					   op=op+arr[2]+"^"+"+";
				   }
				 //  break;
				   flag=1;
				   ck[(4+(i-1))%4][(4+(j-1))%4]=1;ck[(4+(i-1))%4][j]=1;ck[i][(4+(j-1))%4]=1;ck[i][j]=1;

				  }
				  else  if(kmap[(4+(i-1))%4][j]==1&&kmap[(4+(i-1))%4][(j+1)%4]==1&&kmap[i][j]==1&&kmap[i][(j+1)%4]==1)
				  {  if(i==0)
				   {
					   op=op+arr[1]+"^";
				   }
				   if(i==1)
				   {
					   op=op+arr[0]+"^";
				   }
				   if(i==2)
				   {
					   op=op+arr[1];
				   }
				   if(i==3)
				   {
					   op=op+arr[0];
				   }
				   if(j==0)
				   {
					   op=op+arr[2]+"^"+"+";
				   }
				   if(j==1)
				   {
					   op=op+arr[3]+"+";
				   }
				   if(j==2)
				   {
					   op=op+arr[3]+"+";
				   }
				   if(j==3)
				   {
					   op=op+arr[2]+"^"+"+";
				   }
					//  break;
				   flag=1;
				   ck[(4+(i-1))%4][j]=1;ck[(4+(i-1))%4][(j+1)%4]=1;ck[i][j]=1;ck[i][(j+1)%4]=1;
				  }
				  }
				    if(flag==0)
				    {
				    	flag=0;
				  	  if(kmap[i][j]==1&&kmap[i][(j+1)%4]==1)
				  {
				   if(i==0)
				   {
				    op=op+arr[0]+"^"+arr[1]+"^";
				   }
				   if(i==1)
				   {
				    op=op+arr[0]+"^"+arr[1];
				   }
				   if(i==2)
				   {
				    op=op+arr[0]+arr[1];
				   }
				   if(i==3)
				   {
				    op=op+arr[0]+arr[1]+"^";
				   }
				   if(j==0)
				   {
				    op=op+arr[2]+"^"+"+";
				   }
				   if(j==1)
				   {
				    op=op+arr[3]+"+";
				   }
				   if(j==2)
				   {
				    op=op+arr[2]+"+";
				   }
				   if(j==3)
				   {
					   op=op+arr[3]+"^"+"+";
				   }
				 //  break;
				   flag=1;
				   ck[i][j]=1;ck[i][(j+1)%4]=1;
			}
				  else  if(kmap[i][(4+(j-1))%4]==1&&kmap[i][j]==1)
				  {
				   if(i==0)
				   {
					   op=op+arr[0]+"^"+arr[1]+"^";
				   }
				   if(i==1)
				   {
					   op=op+arr[0]+"^"+arr[1];
				   }
				   if(i==2)
				   {
					   op=op+arr[0]+arr[1];
				   }
				   if(i==3)
				   {
					   op=op+arr[0]+arr[1]+"^";
				   }
				   if(j==0)
				   {
					   op=op+arr[3]+"^"+"+";
				   }
				   if(j==1)
				   {
					   op=op+arr[2]+"^"+"+";
				   }
				   if(j==2)
				   {
					   op=op+arr[3]+"+" ;
				   }
				   if(j==3)
				   {
					   op=op+arr[2]+"+";
				   }
				//   break;
				   flag=1;
				   ck[i][(4+(j-1))%4]=1;ck[i][j]=1;

		}
				  else  if(kmap[i][j]==1&&kmap[(i+1)%4][j]==1)
				  {
				   if(i==0)
				   {
				    op=op+arr[0]+"^";
				   }
				   if(i==1)
				   {
				    op=op+arr[1];
				   }
				   if(i==2)
				   {
				    op=op+arr[0];
				   }
				   if(i==3)
				   {
				    op=op+arr[1]+"^";
				   }
				   if(j==0)
				   {
				    op=op+arr[2]+"^"+arr[3]+"^"+"+";
				   }
				   if(j==1)
				   {
					   op=op+arr[2]+"^"+arr[3]+"+";
				   }
				   if(j==2)
				   {
					   op=op+arr[2]+arr[3]+"+";
				   }
				   if(j==3)
				   {
					   op=op+arr[2]+arr[3]+"^"+"+";
				   }
				  // break;
				  flag=1;
				  ck[i][j]=1;ck[(i+1)%4][j]=1;
	}
				  else  if(kmap[i][j]==1&&kmap[(4+(i-1))%4][j]==1)
				  {
				   if(i==0)
				   {
					   op=op+arr[1]+"^";
				   }
				   if(i==1)
				   {
					   op=op+arr[0]+"^";
				   }
				   if(i==2)
				   {
					   op=op+arr[1];
				   }
				   if(i==3)
				   {
					   op=op+arr[0];
				   }
				   if(j==0)
				   {
					   op=op+arr[2]+"^"+arr[3]+"^"+"+";
				   }
				   if(j==1)
				   {
					   op=op+arr[2]+"^"+arr[3]+"+";
				   }
				   if(j==2)
				   {
					   op=op+arr[2]+arr[3]+"+";
				   }
				   if(j==3)
				   {
					   op=op+arr[2]+arr[3]+"^"+"+";
				   }
				   //break;
				  flag=1;
				  ck[i][j]=1;ck[(4+(i-1))%4][j]=1;
			}
				    }

				  if(flag==0)
				  {

				   if(i==0)
			  {
				 op=op+arr[0]+"^"+arr[1]+"^";
			  }
					  if(i==1)
			  {
				  op=op+arr[0]+"^"+arr[1];
			  }
					  if(i==2)
			  {
				  op=op+arr[0]+arr[1];
			  }
					  if(i==3)
			  {
				  op=op+arr[0]+arr[1]+"^";
			  }
					  if(j==0)
			  {
				  op=op+arr[2]+"^"+arr[3]+"^"+"+";
			  }
				      if(j==1)
			  {
				  op=op+arr[2]+"^"+arr[3]+"+" ;
			  }
				     if(j==2)
			  {
				  op=op+arr[2]+arr[3]+"+";
			  }
				     if(j==3)
			  {
				  op=op+arr[2]+arr[3]+"^"+"+";
			  }
				     ck[i][j]=1;
				  }

				    }

				  }
			}
			if(count==3)
			{
				 if(kmap[i][j]==1&&ck[i][j]==0)
				 {
			{
				flag=0;

			if(flag==0)
			{
				if(kmap[i][0]==1 && kmap[i][1]==1 && kmap[i][2]==1 && kmap[i][3]==1)
				{
					if(i==0)
					{
					op=op+arr[0]+"^"+"+";
					}
					 if(i==1)
					{
						op=op+arr[0]+"+";
					}
					flag=1;
					  ck[i][0]=1;ck[i][1]=1;ck[i][2]=1;ck[i][3]=1;
				}
				else if(kmap[i][j]==1&&kmap[i][(j+1)%4]==1&&kmap[(i+1)%2][j]==1&&kmap[(i+1)%2][(j+1)%4]==1)
				{
					if(j==0)
					{
						op=op+arr[1]+"^"+"+";
					}
					if(j==1)
					{
						op=op+arr[2]+"+";
					}
					if(j==2)
					{
						op=op+arr[1]+"+";
					}
					if(j==3)
					{
						op=op+arr[2]+"^"+"+";
					}
					flag=1;
					 ck[i][j]=1;ck[i][(j+1)%4]=1;ck[(i+1)%2][j]=1;ck[(i+1)%4][(j+1)%4]=1;
				}
				else if(kmap[i][(4+(j-1))%4]==1&&kmap[i][j]==1&&kmap[(i+1)%2][(4+(j-1))%4]==1&&kmap[(i+1)%2][j]==1)
				{
					if(j==0)
					{
						op=op+arr[2]+"^"+"+";
					}
					if(j==1)
					{
						op=op+arr[1]+"^"+"+";
					}
					if(j==2)
					{
						op=op+arr[2]+"+";
					}
					if(j==3)
					{
						op=op+arr[1]+"+";
					}
					flag=1;
					 ck[i][(4+(j-1))%4]=1;ck[i][j]=1;ck[(i+1)%2][(4+(j-1))%4]=1;ck[(i+1)%2][j]=1;

				}

			}
			if(flag==0)
			{
				flag=0;
				if(kmap[i][j]==1&&kmap[i][(j+1)%4]==1)
				{
					if(i==0)
					{
						op=op+arr[0]+"^";
					}
					 if(i==1)
					{
						op=op+arr[0];
					}
					 if(j==0)
					 {
						 op=op+arr[1]+"^"+"+";
					 }
					 if(j==1)
					 {
						 op=op+arr[2]+"+";
					 }

					 if(j==2)
					 {
						 op=op+arr[1]+"+";
					 }
					 if(j==3)
					 {
						 op=op+arr[2]+"^"+"+";
					 }
					 flag=1;
					 ck[i][j]=1;ck[i][(j+1)%4]=1;
				}
				else if(kmap[i][j]==1&&kmap[(i+1)%2][j]==1)
						{
					if(j==0)
					{
						op=op+arr[1]+"^"+arr[2]+"^"+"+";
					}
					if(j==1)
					{
						op=op+arr[1]+"^"+arr[2]+"+";
					}
					if(j==2)
					{
						op=op+arr[1]+arr[2]+"^"+"+";
					}
					if(j==3)
					{
						op=op+arr[1]+arr[2]+"^"+"+";
					}
					flag=1;
					ck[i][j]=1;ck[(i+1)%2][j]=1;
						}
				else	if(kmap[i][(4+(j-1))%4]==1&&kmap[i][j]==1)
				{
					if(i==0)
					{
						op=op+arr[0]+"^";
					}
					 if(i==1)
					{
						op=op+arr[0];
					}
					 if(j==0)
					 {
						 op=op+arr[2]+"^"+"+";
					 }
					 if(j==1)
					 {
						 op=op+arr[1]+"^"+"+";
					 }
					 if(j==2)
					 {
						 op=op+arr[2]+"+";
					 }
					 if(j==3)
					 {
						 op=op+arr[1]+"+";
					 }
					 flag=1;
					 ck[i][(4+(j-1))%4]=1;ck[i][j]=1;
				}
				if(flag==0)
				{
					if(i==0)
					{
						op=op+arr[0]+"^";
					}
					if(i==1)
					{
						op=op+arr[0];
					}
					if(j==0)
					{
						op=op+arr[1]+"^"+arr[2]+"^"+"+";
					}
					if(j==1)
					{
						op=op+arr[1]+"^"+arr[2]+"+";
					}
					if(j==2)
					{
						op=op+arr[1]+arr[2]+"+";
					}
					if(j==3)
					{
						op=op+arr[1]+arr[2]+"^"+"+";
					}
					ck[i][j]=1;


			}
			}
				 }
			}
			}
				 if(count==2)
					{
						 if(kmap[i][j]==1&&ck[i][j]==0)
						 {
					{
						flag=0;

					if(flag==0)
					{	 flag=0;
						if(kmap[i][j]==1&&kmap[i][(j+1)%2]==1)
						{
							if(i==0)
							{
								op=op+arr[0]+"^"+"+";
							}
							if(i==1)
							{
								op=op+arr[0]+"+";
							}
							flag=1;
							ck[i][j]=1;ck[i][(j+1)%2]=1;
						}
						else if(kmap[i][j]==1&&kmap[(i+1)%2][j]==1)
						{
							if(j==0)
							{
								op=op+arr[1]+"^"+"+";
							}
							if(j==1)
							{
								op=op+arr[1]+"+";
							}
							flag=1;
							ck[i][j]=1;ck[(i+1)%2][j]=1;
						}
					}
					if(flag==0)
					{
						if(i==0)
						{
							op=op+arr[0]+"^"+"+";
						}
						if(i==1)
						{
							op=op+arr[0]+"+";
						}
						if(j==0)
						{
							op=op+arr[1]+"^"+"+";
						}
						if(j==1)
						{
							op=op+arr[1]+"+";
						}
						ck[i][j]=1;
					}

					}
						 }
					}

			}






		//System.out.println(op);

}
	System.out.println(op);
        String ok="";
        ok=ok+op.substring(0,op.length()-1);
        t2.setText(ok);
            }*/
    return 0;
}
