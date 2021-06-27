#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <unistd.h>


int choose ;
char pass[100] , back ;
int i = 0 ;

void screen();
void Add ();
void assign ();
void show();
void Delete();

struct patient
{
	char name[100];
	char age[100];
	char date[100];
	char address[200];
	int id;
}p1,p2;


int main ()
{
	ag :
	system("cls");
	printf("\n\t\t\t * Covid-19 Patient Data System *\n");
	printf("\n\n\n\n\t\tEnter Your Password : ");
	gets (pass);
	if ( pass[0] == '1' && pass[1] == '2' && pass[2] == '3' && pass[3] == '4' && pass[4] == '5' )
	{
		printf("\n\n\t\tAccess Granted Welcome\n");
		sleep(2);
	}		
	else {
		printf("\n\t\tPassword Wrong try again\n");
		sleep(2);
		i++;
		if ( i < 3 )
		{
			goto ag;
		}
		else {
			printf("\n\n\t\tYou Entered Password Wrong 3 times\n");
			printf("\n\t\tProgram Exit\n\n");
			exit(1);
		}
	}
	
	m :
	screen();
	scanf("%d",&choose);
	switch (choose)
	{
		case 1 : Add();
					printf("\n\t\tDo you want to back menu , Y or N : ") ; 
					getch();
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto m ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 
		
				break ;
				
		case 2 : 
				assign();
				
					printf("\n\t\tDo you want to back menu , Y or N : ") ; 
					getch();
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto m ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 
		
				break ;
				
		case 3 :	
				show();
					printf("\n\t\tDo you want to back menu , Y or N : ") ; 
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto m ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 

				break ;
				
		case 4 : 
				Delete();
				printf("\n\t\tDo you want to back menu , Y or N : ") ; 
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto m ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 
		
				break ;
				
		case 5 :
				printf("\n\n\t\tProgram Exit\n\n");
				break ;
				
		default : 
				printf("\n\t\tYou entered wrong choice\n");
				sleep(2);
				goto m ;
		
	}


}

void screen()
{
	system("cls");
	printf("\n");
	printf("\t\t - Covid-19 Patient Data System -\n") ;
	printf("\n\t\t**********************************\n") ;
	printf("\n\t\t(1) Add New Patient               ") ;
	printf("\n\t\t(2) Assign to Hospital            ") ;
	printf("\n\t\t(3) Search Patient                ") ;
	printf("\n\t\t(4) Delete Patient                ") ;
	printf("\n\t\t(5) EXIT 				     	    ") ;
	printf("\n\n\t\t*********************************") ;
	printf("\n\n\t\tChoose : ");
}

void Add () // add patient 
{
	system("cls");
	printf("\n");
	printf("\t\t  		-	ADD Patient	  - 	    \n") ;
	printf("\n\t\t**************************************************\n") ;
	printf("\n\t\tName : ") ;
	scanf("%s",p1.name);
	printf("\n\t\tAge : ") ;
	scanf("%s",p1.age);
	printf("\n\t\tDate of Infection : ") ;
	scanf("%s",p1.date);
	printf("\n\t\tAddress : ") ;
	scanf("%s",p1.address);
	printf("\n\t\t**************************************************\n") ;
}

void assign() // assign patient to hospital 
{
	FILE *fptr , *fptr2 ;
	char hospitalname[100];
	char hospitalid[100];
	int capacity;
	gc :
	system("cls");
	printf("\t\t  		-	Assign to Hospital	  - 	    \n") ;
	printf("\n\t\t**************************************************\n") ;
	printf("\n\t\tAll Hospitals ->\n") ;
	
	fptr = fopen("hospitals.txt","r");
	fscanf(fptr,"%s",hospitalname);
	fscanf(fptr,"%s",hospitalid);
	while (!feof(fptr))
	{
		fptr2 = fopen(hospitalid,"r");
		fscanf(fptr2,"%s",hospitalname);
		fscanf(fptr2,"%s",hospitalid);
		fscanf(fptr2,"%d",&capacity);
		fclose(fptr2);
		printf("\n\t\tName : %s",hospitalname);
		printf("\t\tID : %s",hospitalid);
		printf("\t Available Capacity : %d",capacity);
		printf("\n");
		fscanf(fptr,"%s",hospitalname);
		fscanf(fptr,"%s",hospitalid);
	}
	fclose(fptr);
	printf("\n\t\t**************************************************\n") ;
	printf("\n\n\t\tChoose ID : ");
	scanf("%s",hospitalid);
	fptr = fopen(hospitalid,"r");
	if (!fptr)
	{
		printf("\n\t\tYou Entered Wrong ID Try Again");
		sleep(2);
		goto gc;
	}
	else {
		fscanf(fptr,"%s",hospitalname);
		fscanf(fptr,"%s",hospitalid);
		fscanf(fptr,"%d",&capacity);
		fclose(fptr);
		fptr = fptr = fopen(hospitalid,"w");
		capacity -- ;
		fprintf(fptr,"%s\t%s\t%d",hospitalname,hospitalid,capacity);
		fprintf(fptr,"\n%s\t%s\t%s\t%s\nEOF",p1.name,p1.age,p1.date,p1.address);
		printf("\n\n\t\tPatient Assigned To Hospital %s Succeessfully\n\n",hospitalid);
	}
	fclose(fptr);
}

void show() // Patients Data 
{
	FILE *fptr , *fptr2 ;
	char hospitalname[100];
	char hospitalid[100];
	int capacity;
	system("cls");
	printf("\t\t  		-   	Patients Data	     - 	    \n") ;
	printf("\n\t\t**************************************************\n") ;
	printf("\n\t\tAll Hospitals ->\n") ;
	
	fptr = fopen("hospitals.txt","r");
	fscanf(fptr,"%s",hospitalname);
	fscanf(fptr,"%s",hospitalid);
	while (!feof(fptr))
	{
		fptr2 = fopen(hospitalid,"r");
		fscanf(fptr2,"%s",hospitalname);
		fscanf(fptr2,"%s",hospitalid);
		fscanf(fptr2,"%d",&capacity);
		fclose(fptr2);
		printf("\n\t\tName : %s",hospitalname);
		printf("\t\tID : %s",hospitalid);
		printf("\t Available Capacity : %d",capacity);
		printf("\n");
		fscanf(fptr,"%s",hospitalname);
		fscanf(fptr,"%s",hospitalid);
	}
	fclose(fptr);
	printf("\n\t\t**************************************************\n") ;
	printf("\n\n\t\tChoose ID : ");
	scanf("%s",hospitalid);
	fptr2 = fopen(hospitalid,"r");
	fscanf(fptr2,"%s",hospitalname);
	fscanf(fptr2,"%s",hospitalid);
	fscanf(fptr2,"%d",&capacity);
	printf("\n\t\tHospital : %s Patients\n\n",hospitalid);
	while (!feof(fptr2))
	{
		fscanf(fptr2,"%s",p2.name);
		fscanf(fptr2,"%s",p2.age);
		fscanf(fptr2,"%s",p2.date);
		fscanf(fptr2,"%s",p2.address);
		if (p2.name[0] != 'E' && p2.name[1] != 'O' && p2.name[2] != 'F')
		{
		printf("\n\t\tPatient Name : %s\tAge : %s\tDate of Infection : %s\n\t\tAddress : %s\n",p2.name,p2.age,p2.date,p2.address);
		}
		else 
		{
			
		}
	}
	printf("\n\t\t**************************************************\n") ;
	fclose(fptr2);
}

void Delete () // delete data
{
	FILE *fptr , *fptr2 ;
	char hospitalname[100];
	char hospitalid[100];
	int capacity;
	gr :
	system("cls");
	printf("\t\t  		-   	Delete Data	     - 	    \n") ;
	printf("\n\t\t**************************************************\n") ;
	printf("\n\t\tAll Hospitals ->\n") ;
	
	fptr = fopen("hospitals.txt","r");
	fscanf(fptr,"%s",hospitalname);
	fscanf(fptr,"%s",hospitalid);
	while (!feof(fptr))
	{
		fptr2 = fopen(hospitalid,"r");
		fscanf(fptr2,"%s",hospitalname);
		fscanf(fptr2,"%s",hospitalid);
		fscanf(fptr2,"%d",&capacity);
		fclose(fptr2);
		printf("\n\t\tName : %s",hospitalname);
		printf("\t\tID : %s",hospitalid);
		printf("\t Available Capacity : %d",capacity);
		printf("\n");
		fscanf(fptr,"%s",hospitalname);
		fscanf(fptr,"%s",hospitalid);
	}
	fclose(fptr);
	printf("\n\t\t**************************************************\n") ;
	printf("\n\n\t\tChoose ID : ");
	scanf("%s",hospitalid);
	fptr2 = fopen(hospitalid,"r");
	if (!fptr2)
	{
		printf("\n\t\tYou Entered Wrong ID Try Again\n");
		sleep(2);
		goto gr;
	}
	else {
		
		fscanf(fptr2,"%s",hospitalname);
		fscanf(fptr2,"%s",hospitalid);
		fscanf(fptr2,"%d",&capacity);
		fclose(fptr2);
	}
	fptr = fopen(hospitalid,"w");
	fprintf(fptr,"%s\t%s\t%d\nEOF",hospitalname,hospitalid,capacity);
	fclose(fptr);
	printf("\n\t\tData Patient Deleted Succeessfully\n\n");
}