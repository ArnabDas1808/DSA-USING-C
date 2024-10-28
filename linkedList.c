#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* head = NULL;

void beginsert(){   
    int item;  
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if(!newNode){  
        printf("Memory allocation failed!\n");
        exit(1);
    }  
    else{  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        newNode->data = item;  
        newNode->next = head;  
        head = newNode;  
        printf("\nNode inserted");  
    }  
      
}  

void lastinsert(){  
    int item;  
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){  
        printf("Memory allocation failed!\n");
        exit(1);  
    } 
    else{  
        printf("\nEnter value: ");  
        scanf("%d", &item);  
        newNode->data = item;  
        newNode->next = NULL;  

        if(head == NULL){  
            head = newNode;  
            printf("\nNode inserted\n");  
        } 
        else{  
            Node *temp = head;  
            while(temp->next != NULL) { 
                temp = temp->next;  
            }
            temp->next = newNode;  
            printf("\nNode inserted\n");  
        }  
    }  
}



void randominsert(){  
    int i, loc, item;   
    Node *newNode = (Node*)malloc(sizeof(Node));  
    if(!newNode){  
        printf("Memory allocation failed!\n");
        exit(1);  
    } 
    else{  
        printf("\nEnter element value: ");  
        scanf("%d", &item);  
        newNode->data = item;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("%d", &loc);  

        Node *temp = head;  
        for(i = 0; i < loc-1; i++){  
            temp = temp->next;  
            if(temp == NULL){  
                printf("\nCan't insert\n");  
                return;  
            }  
        }  
        newNode->next = temp->next;   
        temp->next = newNode;   
        printf("\nNode inserted\n");  
    }  
}

void begin_delete(){  
    Node *temp; 
    if(head == NULL){  
        printf("\nList is empty\n");  
    } 
    else{  
        temp = head;  
        head = temp->next;  
        free(temp);  
        printf("\nNode deleted from the beginning...\n");  
    }  
}

void last_delete(){  
    Node *temp, *prev; 
    if(head == NULL){  
        printf("\nList is empty\n");  
    } 
    else if(head->next == NULL){  
        free(head);  
        head = NULL;  
        printf("\nOnly node of the list deleted...\n");  
    }
    else{  
        temp = head;   
        while(temp->next != NULL){  
            prev = temp;  
            temp = temp->next;  
        }  
        prev->next = NULL;  
        free(temp);  
        printf("\nDeleted node from the last...\n");  
    }     
}



void random_delete(){  
    Node *temp, *prev;  
    int loc, i;    
    printf("\nEnter the location of the node after which you want to perform deletion: ");  
    scanf("%d", &loc);  
    
    if(head == NULL){  
        printf("\nList is empty\n");  
        return;
    }

    temp = head;  
    for(i = 0; i < loc; i++){  
        prev = temp;       
        temp = temp->next;  
              
        if(temp == NULL){  
            printf("\nCan't delete, location out of bounds\n");  
            return;  
        }  
    }  
    prev->next = temp->next;  
    free(temp);  
    printf("\nDeleted node at location %d\n", loc + 1);  
}  


void search(){  
    Node *temp;  
    int item, i = 0, flag = 1; 
    temp = head;   
    
    if(temp == NULL){  
        printf("\nEmpty List\n");  
    } 
    else{   
        printf("\nEnter item which you want to search: ");   
        scanf("%d", &item);  
        while(temp != NULL){  
            if(temp->data == item){  
                printf("Item found at location %d\n", i + 1);  
                flag = 0;  
                break;  
            }   
            i++;  
            temp = temp->next;  
        }  
        if(flag == 1){  
            printf("Item not found\n");  
        }  
    }     
}


void display(){  
    Node *node;  
    node = head;  
    if(node == NULL){  
        printf("Nothing to print");  
    }  
    else{  
        printf("\nPrinting values . . . . .\n");   
        while (node!=NULL){  
            printf("%d -> ",node->data);  
            node = node -> next;  
        }
        printf("NULL\n");  
    }  
}



int main (){  
    int choice =0;  
    while(choice != 9){  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice){  
            case 1:  
                beginsert();      
                break;  
            case 2:  
                lastinsert();         
                break;  
            case 3:  
                randominsert();       
                break;  
            case 4:  
                begin_delete();       
                break;  
            case 5:  
                last_delete();        
                break;  
            case 6:  
                random_delete();          
                break;  
            case 7:  
                search();         
                break;   
            case 8:  
                display();        
                break;  
            case 9:  
                exit(0);  
                break; 
            default:  
                printf("Please enter valid choice..");  
        }  
    }  
}  