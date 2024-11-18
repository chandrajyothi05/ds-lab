#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[500];
char rev[500];
int len;
struct node{
    struct node *prev;
    char data;
    struct node *next;
}*head = NULL,*tail = NULL,*newnode;
struct node* getnode(char s)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = s;
    newnode->next = NULL;
    newnode->prev = NULL;
}
void insertdll(char p)
{
    newnode = getnode(p);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void displayf()
{
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}
void displayb()
{
    struct node *p;
    p = tail;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p = p->prev;
    }
    printf("\n");
}
void ispalindrome()
{
    struct node *p;
    int i=0,pal;
    p = tail;
    while(p!=NULL)
    {
        rev[i] = p->data;
        i++;
        p = p->prev;
    }
    str[i] = '\0';
    pal = strcmp(str,rev);
    if(pal == 0)
    {
        printf("the string is palindrome!\n");
    }
    else
    {
        printf("string isn't palindrome\n");
    }
}
void main() {
    int ch;
    printf("enter a word/string\n");
    gets(str);
    //scanf("%s",str);
    len=strlen(str);
    do
    {
        printf("MENU\n1. create a doubly linked list with the characters of inputed string\n2. display list - forward\n3. display list -  reverse\n4. check if string is palindrome\n5. exit\n*enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
              for(int i=0 ; str[i]!='\0' ; i++)
              {
                  insertdll(str[i]);
              }
            break;
            case 2:
            displayf();
            break;
            case 3:
            displayb();
            break;
            case 4:
            ispalindrome();
            case 5:
            break;
            default:
            printf("invalid choice\n");
            break;
        }}while(ch!=6);
}
