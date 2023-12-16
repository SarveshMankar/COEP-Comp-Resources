#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);


    printf("\nFirst Pattern:\n");
    int stars=-1;
    int totalStars=2*n-1;
    for(int i=0; i<n;i++){
        stars+=2;
        int spaces=(totalStars-stars)/2;
        for (int j=0;j<spaces;j++){
            printf(" ");
        }
        for(int j=0; j<stars; j++){
            printf("%s","*");
        }
        printf("\n");
    }


    printf("\nSecond Pattern:\n");
    int n1=0;
    int num=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            printf("%d ",num);
            num++;
        }
        printf("\n");
    }


    printf("\nThird Pattern:\n");
    stars=0;
    for(int i=0;i<n;i++){
        stars+=2;
        char c='0';
        for(int j=0;j<(stars/2);j++){
            printf("%c",c);
            if (c=='0'){
                c='1';
            }else{
                c='0';
            }
        }

        int n1 = ((n*2)-stars);
        for(int j=0;j<n1;j++){
            printf(" ");
        }
        
        c='0';
        for(int j=0;j<(stars/2);j++){
            printf("%c",c);
            if (c=='0'){
                c='1';
            }else{
                c='0';
            }
        }
        printf("\n");
    }


    printf("\nForth Pattern:\n");
    int arr1[n];
    int arr2[n];
    int nos=15;

    for(int i1 = 0; i1 < n; i1++){
        for(int j1=0;j1<n;j1++){
            if (i1==0){
                arr2[0]=1;
                break;
            }else if(i1==1){
                arr2[0]=1;
                arr2[1]=1;
                break;
            }
            else{
                if(j1==0){
                    arr2[0]=1;
                }else if(j1==i1){
                    arr2[j1]=1;
                }else{
                    arr2[j1]=arr1[j1-1]+arr1[j1];
                }
            
            }
        }
        
        for(int a1=0;a1<=i1;a1++){
            arr1[a1]=arr2[a1];
        }

        for(int a1=-1;a1<nos;a1++){
            printf("  ");
        }
        nos--;
        
        for (int s1=0;s1<=i1;s1++){
            printf("%3d ",arr1[s1]);
            arr2[s1]=0;
        }
        printf("\n");

    }

}