//Header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//main functions
void hostelAllocation();
void Cafeteria();
void timeInOut();

//functions of Hostel allocation
void addHostel();
void displayHostel();
void searchHostel();
void deleteHostel();

//functions of Cafeteria
void addItem();
void displayItem();
void searchItem();
void deleteItem();

//functions of Visitor's Entry
void addEntry();
void displayEntry();
void searchEntry();
void deleteEntry();

//Declaration of structures 
struct hostel{
    int sno;
    char fname[20];
    char lname[20];
    char hostelno[5];
    int room_no;

}s;

struct cafeteria{
    char item[20];
    int MRP;
    int qty;
}c;

struct visitor{
    char vfname[20];
    char vlname[20];
    int inhour;
    int inmins;
    int outhour;
    int outmins;
    int phonenumber;
}v;


int main(){
    char username[20];
    int password,try,compare,choice,try2;
    
    //******************************login***********************************************************

    printf("************* Welcome To The campus facilities Section ****************");
    printf("\nEnter your Credentials :\n");
    try=0;try2=0;
    while(try==0){
        printf("Enter your username:\t");
        scanf("%s",username);
        compare=strcmp(username,"employee123");
        if(compare==0){
            printf("Enter your password: \t");
            scanf("%d",&password);
            if(password==12345){
                printf("\n******************** ACCESS GRANTED! *********************\n");
                printf("Press any key to continue:\t");
                getchar();
                try=1;
                while(try2==0){
                    system("cls");
                    printf("Please Enter your choice:\n");
                    printf("1. Hostel Allocation\n");
                    printf("2. Cafeteria\n");
                    printf("3. Visitors Entry\n");
                    printf("4. Exit\n");
                    scanf("%d",&choice);
                    switch(choice){
                        case 1:
                            system("cls");
                            hostelAllocation();
                            break;
                        case 2:
                            system("cls");
                            Cafeteria();
                            break;
                        case 3:
                            system("cls");
                            timeInOut();

                            break;
                        case 4:
                            system("cls");
                            printf("Existing Campus facility Section\n");
                            goto end;
                            break;
                    }
                }

            }else{
                printf("Invalid password. Try again!\n");
            }
        }else{
            printf("Invalid username. Try again!\n");
        }
    }
    end:
    return 0;
}


void hostelAllocation(){
    int try1=0;
    int choice1;
    printf("\n HOSTEL ALLOCATION SECTION");
    while(try1==0){
        printf("\nPlease Enter your choice:\n");
        printf("1. Add a Hosteler Entry\n");
        printf("2. Display all hostelers\n");
        printf("3. Search a hosteler \n");
        printf("4. Delete a hosteler\n");
        printf("5. Exit\n");
        scanf("%d",&choice1);
        if(choice1==1){
            system("cls");
            addHostel();
        }else if(choice1==2){
            system("cls");
            displayHostel();
        }else if(choice1==3){
            system("cls");
            searchHostel();
        }else if(choice1==4){
            system("cls");
            deleteHostel();
        }else if(choice1==5){
            try1=1;
        }else{
            printf("Invalid choice");
        }
    }

}



void addHostel(){
    FILE *fptr;
    char try4;
    fptr = fopen("hostel.txt", "a");
    printf("\nEnter the details of the Hosteler:\n");
    printf("Enter the first name: ");
    scanf("%s",s.fname);
    printf("Enter the last name: ");
    scanf("%s",s.lname);
    printf("Enter Hostel No:");
    scanf("%s",s.hostelno);
    printf("Enter the room no: ");
    scanf("%d",&s.room_no);
    fprintf(fptr,"%s\t%s\t%s\t%d\t\n",s.fname,s.lname,s.hostelno,s.room_no);
    printf("Data Entered Successfully.\n");
    fclose(fptr);

    
}


void displayHostel(){
    FILE *fptr;
    char ch;
    fptr = fopen("hostel.txt", "r");
    if (fptr == NULL)
    {
        printf("File do not exist.\n");
    }
    while(fscanf(fptr,"%s\t%s\t%s\t%d\t\n",s.fname,s.lname,s.hostelno,&s.room_no) != EOF){
        
        printf("%10s\t%10s\t%10s\t%d\t\n",s.fname,s.lname,s.hostelno,s.room_no);
        printf("\n");
    }
    fclose(fptr);

}

void searchHostel(){
    FILE *fptr;
    int try5 = 0;
    char namestudent[20];
    fptr = fopen("hostel.txt", "r");
    printf("Enter the name of the hosteler you want to search:\n");
    scanf("%s",namestudent);
    if (fptr == NULL){
        printf("File do not exist.\n");
    }else{
        while(fscanf(fptr,"%s\t%s\t%s\t%d\t\n",s.fname,s.lname,s.hostelno,&s.room_no) != EOF){
            if(strcmp(namestudent,s.fname)==0)
            {
                try5 = 1;
                printf("\n Record founded successfully.\n");
                printf("%10s\t%10s\t%10s\t%d\t\n",s.fname,s.lname,s.hostelno,s.room_no);
                printf("\n");
            }else{
                continue;
            }
            if(try5 == 0){
                printf("Record is not found.\nPlease check the name of the Hosteler again.\n");
            }
            fclose(fptr);
        }
    }


}

void deleteHostel(){
    FILE *fptr;
    FILE *fdel;
    int try=0;
    fptr=fopen("hostel.txt","r");
    fdel=fopen("delete2.txt","a+");
    if(fptr==NULL){
        printf("File does not exist");
    }
    char namestudent[20];
    printf("Enter the name of the hosteler whose data you want to delete.\n");
    scanf("%s",namestudent);
    while(fscanf(fptr,"%s\t%s\t%s\t%d\t\n",s.fname,s.lname,s.hostelno,&s.room_no)!= EOF){
        if(strcmp(namestudent,s.fname)!=0){
         fprintf(fdel,"%10s\t%10s\t%10s\t%d\t\n",s.fname,s.lname,s.hostelno,s.room_no);
        }
        else{
            try = 1;
            printf("Data deleted successfully.\n");
            continue;
        }
    }
        if(try == 0){
            printf("Record is not found.\nPlease check the name of the student again.\n");
        }
    
    fclose(fptr);
    fclose(fdel);
    remove("hostel.txt");
    rename("delete2.txt", "hostel.txt");


}


void Cafeteria(){
    int try2=0;
    int choice2;
    printf("\n CAFETERIA SECTION");
    while(try2==0){
        printf("\nPlease Enter your choice:\n");
        printf("1. Add a new item\n");
        printf("2. Display all items\n");
        printf("3. Search an item \n");
        printf("4. Delete an item\n");
        printf("5. Exit\n");
        scanf("%d",&choice2);
        if(choice2==1){
            system("cls");
            addItem();
        }else if(choice2==2){
            system("cls");
            displayItem();
        }else if(choice2==3){
            system("cls");
            searchItem();
        }else if(choice2==4){
            system("cls");
            deleteItem();
        }else if(choice2==5){
            try2=1;
        }else{
            printf("Invalid choice");
        }

   }
}




void addItem(){
    FILE *fptr;
    fptr = fopen("cafeteria.txt", "a");
    printf("\nEnter the details of the Item:\n");
    printf("Enter the item name: ");
    scanf("%s",c.item);
    printf("Enter the MRP of the item: ");
    scanf("%d",&c.MRP);
    printf("Enter the quantity: ");
    scanf("%d",&c.qty);
    fprintf(fptr,"%s\t%d\t%d\n",c.item,c.MRP,c.qty);
    fclose(fptr);

}

void displayItem(){
    FILE *fptr;
    char ch;
    fptr = fopen("cafeteria.txt", "r");
    if (fptr == NULL)
    {
        printf("File do not exist.\n");
    }
    while(fscanf(fptr,"%s\t%d\t%d\n",c.item,&c.MRP,&c.qty) != EOF){
        
        printf("%10s\t%10d\t%10d\n",c.item,c.MRP,c.qty);
        printf("\n");
    }
    fclose(fptr);

}

void searchItem(){
    FILE *fptr;
    int try5 = 0;
    char nameitem[20];
    fptr = fopen("cafeteria.txt", "r");
    printf("Enter the name of the item you want to search:\n");
    scanf("%s",nameitem);
    if (fptr == NULL){
        printf("File do not exist.\n");
    }else{
        while(fscanf(fptr,"%s\t%d\t%d\n",c.item,&c.MRP,&c.qty) != EOF){
            if(strcmp(nameitem,c.item)==0)
            {
                try5 = 1;
                printf("\n Record founded successfully.\n");
                printf("%10s\t%10d\t%10d\n",c.item,c.MRP,c.qty);
                printf("\n");
            }else{
                continue;
            }
            if(try5 == 0){
                printf("Record is not found.\nPlease check the name of the Item again.\n");
            }
            fclose(fptr);
        }
    }


}

void deleteItem(){
    FILE *fptr;
    FILE *fdel;
    int try=0;
    fptr=fopen("cafeteria.txt","r");
    fdel=fopen("delete2.txt","a+");
    if(fptr==NULL){
        printf("File does not exist");
    }
    char nameitem[20];
    printf("Enter the name of the item whose data you want to delete.\n");
    scanf("%s",nameitem);
    while(fscanf(fptr,"%s\t%d\t%d\n",c.item,&c.MRP,&c.qty)!= EOF){
        if(strcmp(nameitem,c.item)!=0){
         fprintf(fdel,"%s\t%d\t%d\n",c.item,c.MRP,c.qty);
        }
        else{
            try = 1;
            printf("Data deleted successfully.\n");
            continue;
        }
    }
        if(try == 0){
            printf("Record is not found.\nPlease recheck the name of the item.\n");
        }
    
    fclose(fptr);
    fclose(fdel);
    remove("cafeteria.txt");
    rename("delete2.txt", "cafeteria.txt");

}

void timeInOut(){

    int try3=0;
    int choice3;
    printf("\nVISITORS ENTRY SECTION");
    while(try3==0){
        printf("\nPlease Enter your choice:\n");
        printf("1. Add a Visitor Entry\n");
        printf("2. Display all Visitors\n");
        printf("3. Search a Visitor \n");
        printf("4. Delete a Visitor\n");
        printf("5. Exit\n");
        scanf("%d",&choice3);
        if(choice3==1){
            system("cls");
            addEntry();
        }else if(choice3==2){
            system("cls");
            displayEntry();
        }else if(choice3==3){
            system("cls");
            searchEntry();
        }else if(choice3==4){
            system("cls");
            deleteEntry();
        }else if(choice3==5){
            try3=1;
        }else{
            printf("Invalid choice");
        }

        
    }
}


void addEntry(){
    FILE *fptr;
    fptr = fopen("visitor.txt", "a");
    printf("\nEnter the details of the Visitor:\n");
    printf("Enter the first name: ");
    scanf("%s",v.vfname);
    printf("Enter the last name: ");
    scanf("%s",v.vlname);
    printf("Enter the Entry time (HH:MM):");
    scanf("%d:%d",&v.inhour,&v.inmins);
    printf("Enter the Exit time (HH:MM):");
    scanf("%d:%d",&v.outhour,&v.outmins);
    fprintf(fptr,"%s\t%s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,v.inhour,v.inmins,v.outhour,v.outmins);
    fclose(fptr);    
}

void displayEntry(){
    FILE *fptr;
    fptr = fopen("visitor.txt", "r");
    if (fptr == NULL)
    {
        printf("File do not exist.\n");
    }
    while(fscanf(fptr,"%s\t%s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,&v.inhour,&v.inmins,&v.outhour,&v.outmins) != EOF){
        
        printf("%10s\t%10s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,v.inhour,v.inmins,v.outhour,v.outmins);
        printf("\n");
    }
    fclose(fptr);

}

void searchEntry(){
    FILE *fptr;
    int try5 = 0;
    char namevisitor[20];
    fptr = fopen("visitor.txt", "r");
    printf("Enter the name of the visitor you want to search:\n");
    scanf("%s",namevisitor);
    if (fptr == NULL){
        printf("File do not exist.\n");
    }else{
        while(fscanf(fptr,"%s\t%s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,&v.inhour,&v.inmins,&v.outhour,&v.outmins) != EOF){
            if(strcmp(namevisitor,v.vfname)==0)
            {
                try5 = 1;
                printf("\n Record founded successfully.\n");
                printf("%10s\t%10s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,v.inhour,v.inmins,v.outhour,v.outmins);
                printf("\n");
            }else{
                continue;
            }
            if(try5 == 0){
                printf("Record is not found.\nPlease recheck the name of the visitor again.\n");
            }
            fclose(fptr);
        }
    }
}

void deleteEntry(){
    FILE *fptr;
    FILE *fdel;
    int try=0;
    fptr=fopen("visitor.txt","r");
    fdel=fopen("delete2.txt","a+");
    if(fptr==NULL){
        printf("File does not exist");
    }
    char namevisitor[20];
    printf("Enter the name of the visitor whose data you want to delete.\n");
    scanf("%s",namevisitor);
    while(fscanf(fptr,"%s\t%s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,&v.inhour,&v.inmins,&v.outhour,&v.outmins)!= EOF){
        if(strcmp(namevisitor,v.vfname)!=0){
         fprintf(fdel,"%s\t%s\t%d:%d\t%d:%d\t\n",v.vfname,v.vlname,v.inhour,v.inmins,v.outhour,v.outmins);
        }
        else{
            try = 1;
            printf("Data deleted successfully.\n");
            continue;
        }
    }
        if(try == 0){
            printf("Record is not found.\nPlease check the name of the visitor again.\n");
        }
    
    fclose(fptr);
    fclose(fdel);
    remove("visitor.txt");
    rename("delete2.txt", "visitor.txt");
}
