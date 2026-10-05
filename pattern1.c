#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct{
    int id;
    char Title[30],Author[30],Status[30];
    float price;

}Book;
int n;
Book* create(int *n)
{
    printf("Enter N\n");
    scanf("%d",n);
    Book *b=(Book*)malloc(*n*sizeof(Book));
    for(int i=0;i<*n;i++)
    {
        b[i].id=i+1;
        printf("Enter Title Author Price \n");
        scanf("%s %s %f", b[i].Title,b[i].Author,&b[i].price);
        strcpy(b[i].Status,"Available");
    }
    return b;

}

void Display(Book *b,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Title\t Author\t Price\t ID\n");
        printf("%s %s %f %d ",b[i].Title,b[i].Author,b[i].price,b[i].id);
    }
}
int  Search(Book *b,int n,int id)
{
    for(int i=0;i<n;i++)
    {
        if(b[i].id==id)
        return i;
    }
    return -1;
}

void Issue(Book *b,int n)
{
    int id;
    printf("Enter a book id to issue");
    scanf("%d",id);
    int idx=Search(b,n,id);
    if(idx==-1)
    {
        printf("Notfound\n");

    }
    else if(strcmp(b[idx].Status,"Available")==0)
    {
        strcpy(b[idx].Status,"issued");
        printf("issued the book");
    }
    else{
        printf("Already issued");
    }
}

void Return(Book *b,int n)
{
    int id;
    printf("Enter a bood id to return ");
    scanf("%d",id);
    int idx=Search(b,n,id);
    if(idx==-1)
    {
        printf("Not found");
    }
    else if(strcmp(b[idx].Status,"Issued")==0)
    {
        strcpy(b[idx].Status,"Available");
        printf("Returned\n");

    }
    else
    printf("Already Availble");

}

int main ()
{
    int n=0, choice,idx;
    Book *lib=NULL;
    while(1)
    {
        printf("1.ADD\n");
        printf("2.Display\n");
        printf("3.SEarch\n");
        printf("1.Issue\n");
        printf("1.Return\n");
        printf("1.exit\n");
        printf("Enter a choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            free(lib);
            lib=create(&n);
            break;
            case 2 :
            Display(lib,n);
            break;
            case 3:
            printf("Enter a book id to search ");
            scanf("%d",idx);
            Search(lib,n,idx);
            printf("Bookk found ");
            break;
            case 4:
            Issue(lib,n);
            break;
            case 5:
            Return(lib,n);
            break;
            case 6:
            printf("Exitinng programg");
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    return 0;

}