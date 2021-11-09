#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void main(){
	int i;
	int j =5;
	char str[20];
	printf("Enter the no. of Production rule: \n");
	scanf("%d",&i);
	char p[i][j];
	for(int r = 0 ; r < i; r++){
		for(int c = 0 ; c < j ; c++){
			scanf("%c",&p[r][c]);
		}
	}
	printf("The Production rule entered is : \n");
	for(int r = 0 ; r < i ; r++){
		for(int c = 0 ; c < j ; c++){
			printf("%c",p[r][c]);
			if(c == 5){
				printf("\n");
			}
		}
	}
	printf("Enter the String to parse: \n");
	scanf("%[^\n]%*c",str);
	printf("The String to parse is : %s \n",str);

void parser(int index){
    for(int j = 0; j<strlen(pb[index]); j++){
        if(non_terminal(pb[index][j])){
            parser(first_occurence);
        }
        else{
            if(pb[index][j]==str[string_index])
            {
                cout<<str[string_index]<<" Matched with "<<pb[index][j]<<"\n";
                string_index++;
            }
            else{
                cout<<str[string_index]<<" Not matched with "<<pb[index][j]<<"\n";
                cout<<"Backtracking.......!\n";
                string_index--;
                parser(index+1);
            }
        }
    }
}

bool non_terminal(char ch){
    for(int i = 0; i<n; i++){
        if(ch==p[i]){
            first_occurence = i;
            return true;
        }
    }
    return false;
}
}