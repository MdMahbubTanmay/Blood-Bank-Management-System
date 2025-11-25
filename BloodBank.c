#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> 
#else
#include <unistd.h> 
#endif

struct LoadData{
	
	int totalUser;
	long int Date[1000];
	char Group[1000][5];
	char AreaNo[1000][5];
	char Name[1000][128];
	char Mobile[1000][15];
	char Pass[1000][25];
	
};


struct LoadData Ldata;
int MyPosition = 0;




void isValidSession();
void LoadingAnimation(int);
void ClearScreen();
void MainMenu();
void Login();
void Register();
void ClearInputBuffer();
void LoadData();
void UserPanel();
void DisplayDonor(int);
void LastDonationUpdate();
void WriteData();
void DrawSpace(int , int);
void AreaFinder(int );
void GroupFinder(int );
void FilterDonor();
void ReturnToUserPanel();
void BackupOrRestore();
long int DateFunction();





//*****************************************************************

int main()
{
	
  isValidSession();	
	
// BackupOrRestore();

return 0;		
}




//Login Validation check + Database Ceator and Data Loader

void isValidSession(){
	FILE *BloodBankData = fopen("blood_data.bin","rb");
	
LoadingAnimation(5);
	ClearScreen();
	
	if(BloodBankData==NULL){
		
		printf("No Database Found.Creating Database...\n");
		
		Ldata.totalUser=1;
		Ldata.Date[0] = 1000;
		strcpy(Ldata.AreaNo[0],"10");
		strcpy(Ldata.Group[0] ,"3");
		strcpy(Ldata.Name[0],"Md Mahbub Tanmay");
		strcpy(Ldata.Mobile[0],"01816787999");
		strcpy(Ldata.Pass[0],"MAHBUB69");
		
		
WriteData();

      LoadingAnimation(3);
      ClearScreen();
      printf("Database Succesfully Created.Restart To Continue...");
      
      
	}
	else{
	 LoadData();
		printf("Database Successfully Loaded\n");
		fclose(BloodBankData);
		//Hello from Mahbub
		MainMenu();
		
	}
	
	
}




//Loading Animation
void LoadingAnimation(int mahbub)
{
	char mahbubLoadingAnim[3]={'/','_','\\'};
	
	for(int i= 0;i<mahbub;i++){
	printf("\rLoading... %c",mahbubLoadingAnim[i%3]);
	#ifdef _WIN32
    Sleep(500);
    #else
    usleep(500000);
    #endif
	fflush(stdout);

	}
}


//Clear Screen
void ClearScreen(){
	
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif	
}


//Main Menu

void MainMenu(){

	
	while(1){
				char temp;
				ClearScreen();
		//	ClearInputBuffer();
			
	printf("Enter your choice:\n");
	printf("1.Enter\n");
	//printf("2.Register\n");
	printf("2.Backup/Restore\n");
	printf(">");
	scanf(" %c",&temp);
	
		if(temp=='1'){
			ClearScreen();
			Login();
			break;
		}
		/*else if(temp =='2'){
			ClearScreen();
			Register();
			break;
		}*/
		else if(temp =='2'){
			ClearScreen();
			BackupOrRestore();
			break;
		}
		
	}
	
	
}



//Login Menu
void Login(){
	LoadingAnimation(3);
	ClearScreen();
	char mobile[15];
	char pass[25];
	
	int check=0;
	ClearInputBuffer();
	printf("\nLogin with ur number and password. If u are a new user then just give your mobile number and a password to go to registration page");
	printf("\nEnter Mobile Number:\n");
	fgets(mobile,sizeof(mobile),stdin);
	mobile[strcspn(mobile,"\n")]='\0';
	
	
	printf("Enter Password:\n");
	fgets(pass,sizeof(pass),stdin);
	pass[strcspn(pass,"\n")]='\0';

	for(int i = 0;i<Ldata.totalUser;i++){
		if(strcmp(mobile,Ldata.Mobile[i])==0  && strcmp(pass,Ldata.Pass[i])==0){
			check=1;
			MyPosition = i;
			break;
		}
		
	}
	
	if(check<=0){
		printf("User Not Found or Incorrect Password\nRegister First.Go To Register Panel?\n(Y to yes. any other key to exit\n");
		printf(">");
		char temp;
		scanf("%c",&temp);
		if(temp=='Y' || temp== 'y'){
			Register();
		}
		else{
			exit(1);
		}
		
	}
	else{
		
		LoadingAnimation(3);
		ClearScreen();
		UserPanel();
		
	}
	
}


//Register
void Register(){
	LoadingAnimation(3);
	ClearScreen();
	
	LoadData();
	printf("Total Donor %d . Register To be a donor",Ldata.totalUser);
	ClearInputBuffer();
	char mobile[15];
	char pass[25];
	char AreaNo[5];
	char Group[5];
	char Name[128];
	int Date=1;
	int check=2025;
	
	
	printf("\nEnter Mobile Number:\n");
	fgets(mobile,sizeof(mobile),stdin);
	mobile[strcspn(mobile,"\n")]='\0';
	
		for(int i = 0;i<Ldata.totalUser;i++){
		if(strcmp(mobile,Ldata.Mobile[i])==0){
			check=1;
			break;
		}
		
	}
	
	if(check==1){
		printf("Mobile Number already used\nUse that number to login or use another number to create new User");
		
		char tanmay;
printf("\nEnter Y to Go to Login Panel. Any other Key to exit\n >");
scanf(" %c",&tanmay);
if(tanmay=='Y' || tanmay=='y'){
	LoadingAnimation(3);
	ClearScreen();
	Login();
}
{
	exit(1);
}
		
	}
	else{
	strcpy(Ldata.Mobile[Ldata.totalUser],mobile);
		
	printf("\nEnter New Password:\n");
	fgets(pass,sizeof(pass),stdin);
	pass[strcspn(pass,"\n")]='\0';	
	
	strcpy(Ldata.Pass[Ldata.totalUser],pass);
	
	
	printf("\nEnter Your Name:\n");
	fgets(Name,sizeof(Name),stdin);
	Name[strcspn(Name,"\n")]='\0';	
	
	strcpy(Ldata.Name[Ldata.totalUser],Name);
		
	
    printf("Enter Area:\n1. Atabaha\n2. Boali\n3. Chapair\n4. Dhaljora\n5. Fulbaria\n6. Madhyapara\n7. Mouchak\n8. Sreefaltali\n9. Sutrapur\n10. Kaliakair Municipality\n11. Chandra\n12. Safipur\n");
    
    fgets(AreaNo,sizeof(AreaNo),stdin);
	AreaNo[strcspn(AreaNo,"\n")]='\0';
	
    strcpy(Ldata.AreaNo[Ldata.totalUser],AreaNo);
    
 
//ClearInputBuffer();


  printf("Enter Blood Group:\n1. A+\n2. A-\n3. B+\n4. B-\n5. AB+\n6. AB-\n7. O+\n8. O-\n");

    fgets(Group,sizeof(Group),stdin);
	Group[strcspn(Group,"\n")]='\0';
	
	strcpy(Ldata.Group[Ldata.totalUser],Group);
    
    //ClearInputBuffer();
    char buffer[64];
    int a;
    printf("Enter Last Donated Month(Use Birth Month if never donated):\n");
    fgets(buffer,sizeof(buffer),stdin);
	buffer[strcspn(buffer,"\n")]='\0';
	sscanf(buffer,"%d",&a);
	Date+=a*30;
	
	
	printf("Enter Last Donated YEAR(Use Birth Year if never donated):\n");
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strcspn(buffer,"\n")]='\0';
	sscanf(buffer,"%d",&a);
	Date+=a*365;
	
	Ldata.Date[Ldata.totalUser]=Date;
	
	Ldata.totalUser++;
	LoadingAnimation(5);

WriteData();
ClearScreen();
}
ClearScreen();
char tanmay;
printf("**Registration Successful**\nEnter Y to Go to Login Panel. Any other Key to exit\n >");
scanf(" %c",&tanmay);
if(tanmay=='Y' || tanmay=='y'){
	LoadingAnimation(3);
	ClearScreen();
	Login();
}
{
	LoadingAnimation(4);
		ClearScreen();
		printf("\t******Thanks for using!******\nCheckout My Github: github.com/MdMahbubTanmay\nSincerely,\nMd Mahbub Tanmay");
	exit(1);
}

}


//User Pannel
void UserPanel(){
	ClearScreen();
	LoadData();
printf("Total Donor %d\n",Ldata.totalUser);

	while(1){
				char temp;
				ClearScreen();
	#ifdef _WIN32
    Sleep(1000);
    #else
    usleep(1000000);
    #endif
		//	ClearInputBuffer();
	printf("Total Donor: %d\n",Ldata.totalUser);		
	printf("\nEnter your choice:\n");
	printf("1.Display All Donors\n");
	printf("2.Find Spesific Donors\n");
	printf("3.View Your Profile\n");
	printf("4.Edit Last Donation Date\n");
	printf("5.Logout and exit\n");
	printf("\n>");
	scanf(" %c",&temp);
	
		if(temp=='1'){
						LoadingAnimation(3);
						ClearScreen();
				LoadData();
			
			
			for(int i=0;i<Ldata.totalUser;i++){
	
				DisplayDonor(i);
			}
			ReturnToUserPanel();
			break;
		}
		else if(temp =='2'){
			
		LoadingAnimation(6);
		ClearScreen();
		FilterDonor();
			break;
		}
		else if(temp =='3'){
		LoadingAnimation(6);
		ClearScreen();
		DisplayDonor(MyPosition);
			break;
		}
		else if(temp =='4'){
		LoadingAnimation(3);
		ClearScreen();
		LastDonationUpdate();
			break;
		}
		else if(temp=='5'){
				ClearScreen();
		printf("Loging Out..\n");
		LoadingAnimation(4);
		ClearScreen();
		printf("\t******Thanks for using!******\nCheckout My Github: github.com/MdMahbubTanmay\nSincerely,\nMd Mahbub Tanmay");
		exit(1);
		}
		
	}
	
}



//Admin Pannel

void AdminPannel(){
	LoadData();
printf("Total Donor %d",Ldata.totalUser);	
}





//Clear Input Buffers
void ClearInputBuffer(){
	char c;
	while((c=getchar())!='\n' && c!= EOF);
}




//Read Data From File
void LoadData(){
		FILE *read = fopen("blood_data.bin", "rb");        
		if(read != NULL){
		fread(&Ldata, sizeof(Ldata), 1, read);
		fclose(read);
		}
		else{
			printf("Open Error!!\n");
			exit(1);
		}
}



//Write Data To File
void WriteData(){
	
	FILE *write = fopen("blood_data.bin","wb");

	if(write!=NULL){
	fwrite(&Ldata,sizeof(Ldata),1,write);
	fclose(write);
	}
	else{
		printf("Read Failed");
		exit(1);
	}
}



//Display Donor List
void DisplayDonor(int pos){

printf(" ____________________________________\n");


	printf("|  Name   | %s",Ldata.Name[pos]);
	DrawSpace(25,strlen(Ldata.Name[pos]));
	printf("|\n");
printf("|_________|__________________________|\n");


		printf("|  Mobile | %s",Ldata.Mobile[pos]);
	DrawSpace(25,strlen(Ldata.Mobile[pos]));
	printf("|\n");
printf("|_________|__________________________|\n");


		printf("|  Group  |");
		GroupFinder(atoi(Ldata.Group[pos]));
	DrawSpace(25,4);
	printf("|\n");
printf("|_________|__________________________|\n");		
		
		
		printf("|  Area   |");
		AreaFinder(atoi(Ldata.AreaNo[pos]));
	printf("|\n");
printf("|_________|__________________________|\n");

		
		printf("|Last Gave| %8ld Days Ago",DateFunction()-Ldata.Date[pos]);
	DrawSpace(25,17);
	printf("|\n");
printf("|_________|__________________________|\n");

	
}




//Draw Space
void DrawSpace(int len, int size){
	for(int i=0;i<len-size;i++){
		printf(" ");
		
	}
	
}







//Update Last Donation Date
void LastDonationUpdate(){
	    LoadingAnimation(3);
	    LoadData();
	    ClearScreen();
	    LoadData();
	    int Date=0;
	    ClearInputBuffer();
    char buffer[64];
    long int a;
    	printf("Enter Last Donated Month:\n");
    fgets(buffer,sizeof(buffer),stdin);
	buffer[strcspn(buffer,"\n")]='\0';
	sscanf(buffer,"%ld",&a);
	Date+=a*30;
	
	
	printf("Enter Last Donated YEAR:\n");
	 fgets(buffer,sizeof(buffer),stdin);
	buffer[strcspn(buffer,"\n")]='\0';
	sscanf(buffer,"%ld",&a);
	Date+=a*365;
	
	Ldata.Date[MyPosition]=Date;
	
	LoadingAnimation(3);
	WriteData();
	
	ReturnToUserPanel();
}




//Calculate present day/month
long int DateFunction(){
	time_t mahbub;
struct tm *myTime;
time(&mahbub);
myTime = localtime(&mahbub);

	
	return (myTime->tm_year+1900)*365+(myTime->tm_mon+1)*30;
}




//Number to area 
void AreaFinder(int x){
	  int size =0;
	  switch(x){
	  case 1:
            printf("Atabaha");
            size = 7;
            break;
        case 2:
            printf("Boali");
             size = 5;
            break;
        case 3:
            printf("Chapair");
             size = 7;
            break;
        case 4:
            printf("Dhaljora");
             size = 8;
            break;
        case 5:
            printf("Fulbaria");
             size = 8;
            break;
        case 6:
            printf("Madhyapara");
             size = 10;
            break;
        case 7:
            printf("Mouchak");
             size = 7;
            break;
        case 8:
            printf("Sreefaltali");
             size = 11;
            break;
        case 9:
            printf("Sutrapur");
             size = 8;
            break;
        case 10:
            printf("Kaliakair Municipality");
             size = 22;
            break;
        case 11:
            printf("Chandra");
             size = 7;
            break;
        case 12:
            printf("Safipur");
             size = 7;
            break;
        default:
            printf("Kaliakair Municipality");
             size = 22;
            break;
    }
    	DrawSpace(25,size-1);
	
}



//Number to blood Group
void GroupFinder(int x){

    switch (x) {
        case 1:
            printf("   A+");
            break;
        case 2:
            printf("   A-");
            break;
        case 3:
            printf("   B+");
            break;
        case 4:
            printf("   B-");
            break;
        case 5:
            printf("  AB+");
            break;
        case 6:
            printf("  AB-");
            break;
        case 7:
            printf("   O+");
            break;
        case 8:
            printf("   O-");
            break;
        default:
            printf("   B+");
            break;
    }
    	
}




//To filter Which users are eliagable

void FilterDonor(){
	    LoadData();
	    char AreaNo[5];
	    char Group[5];
	    int total=0;
	    printf("Enter Area:\n1. Atabaha\n2. Boali\n3. Chapair\n4. Dhaljora\n5. Fulbaria\n6. Madhyapara\n7. Mouchak\n8. Sreefaltali\n9. Sutrapur\n10. Kaliakair Municipality\n11. Chandra\n12. Safipur\n >");
    
    ClearInputBuffer();
    fgets(AreaNo,sizeof(AreaNo),stdin);
	AreaNo[strcspn(AreaNo,"\n")]='\0';
	
    
 
//ClearInputBuffer();


  printf("Enter Blood Group:\n1. A+\n2. A-\n3. B+\n4. B-\n5. AB+\n6. AB-\n7. O+\n8. O-\n >");

    fgets(Group,sizeof(Group),stdin);
	Group[strcspn(Group,"\n")]='\0';
	
	LoadingAnimation(6);
	ClearScreen();
	
		for(int i= 0;i<Ldata.totalUser;i++){
	   if(atoi(Ldata.AreaNo[i])==atoi(AreaNo) && atoi(Ldata.Group[i])==atoi(Group)){
	   
	   	total++;
	   }
	   
	}
	
	printf("\nDonor Found On Requirements: %d\n",total);
	
	
	for(int i= 0;i<Ldata.totalUser;i++){
	   if(atoi(Ldata.AreaNo[i])==atoi(AreaNo) && atoi(Ldata.Group[i])==atoi(Group)){
	   	DisplayDonor(i);
	   }
	   
	}
	ReturnToUserPanel();
	 
}



//Return To User Panel
void ReturnToUserPanel(){
	char tanmay;
	printf("\nEnter Y to Return To user panel.any other key to exit\n >");
	scanf(" %c",&tanmay);
	if(tanmay=='Y' || tanmay=='y'){
		LoadingAnimation(4);
		ClearScreen();
		UserPanel();
	}
	else{
		ClearScreen();
		printf("Loging Out..\n");
		LoadingAnimation(4);
		ClearScreen();
		printf("\t******Thanks for using!******\nCheckout My Github: github.com/MdMahbubTanmay\nSincerely,\nMd Mahbub Tanmay");
		exit(1);
	}
	
}



//Backup Data or restore data
void BackupOrRestore(){
	ClearScreen();
	char path[50];
	char Mahbub;
	printf("Enter Your Choice(1 or 2 to interact. Any other key to return to main menu:\n1.Restore Data\n2.Backup Data\n >");
	ClearInputBuffer();
	scanf("%c",&Mahbub);
	
	if(Mahbub=='1'){
		//Restore
		printf("Enter Path>");
		ClearInputBuffer();
		fgets(path,sizeof(path),stdin);
		path[strcspn(path,"\n")]='\0';
		FILE *backup = fopen(path,"rb");
		if(backup!=NULL){
		fread(&Ldata,sizeof(Ldata),1,backup);
		fclose(backup);
		WriteData();
			ClearScreen();
			printf("Restore must be successful if %s was a correct path of a .bin for this tool\n",path);
		LoadingAnimation(15);
		ClearScreen();
		MainMenu();
		}
		else{
			printf("\nThe path u entered is Invalid.Try again\n");
			LoadingAnimation(2);
			ClearScreen();
			BackupOrRestore();
		}
	}
	else if(Mahbub=='2'){
		//Backup
		LoadData();
			printf("Enter Path>");
			ClearInputBuffer();
				fgets(path,sizeof(path),stdin);
		path[strcspn(path,"\n")]='\0';
		FILE *backup = fopen(strcat(path,"blood_data.bin"),"wb");
		
		fwrite(&Ldata,sizeof(Ldata),1,backup);
		fclose(backup);
		ClearScreen();
		printf("Backup Successful to path %s\n",path);
		LoadingAnimation(15);
		ClearScreen();
		MainMenu();
		}
		
	else{
		LoadingAnimation(3);
		ClearScreen();
		MainMenu();
	}
}