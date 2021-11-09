#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
char pb[10][10];
int n;
unordered_set<char> terminals;
unordered_set<char> non_terminals;
/*map<char, unordered_set<char>> firstmap;

void first(char c, int ind, int size, unordered_set<char> map){
    if(size==n){
        return;
    }
    if(pb[ind][0]==c){
        if(terminals.find(pb[ind][3])!=terminals.end()){
            map.insert(pb[ind][3]);
            firstmap.insert(pair<char, unordered_set<char>>(c, map));3
        
            first(c, )
        }
    }
}*/

void first(char c, int ind, int size){
    if(size==n){
        return;
    }
    if(terminals.find(pb[ind][3])!=terminals.end()){
        cout<<pb[ind][3]<<" ";
        first(c, (ind+1)%n, size+1);
    }else{
        first(c, (ind+1)%n, size+1);
    }

}

int main(){
    cout<<"Enter the no. of production rule-";
    cin>>n;
    int i=0;
    while(i<n){
        cout<<"Enter the production rule-";
        cin>>pb[i];
        i++;
    }
    for(i=0; i<n; i++){
        if(pb[i][0]=='S'){
            for(int j=0; j<10; j++){
                swap(pb[i][j], pb[0][j]);
            }
            break;
        }
    }

    for(i=0; i<n; i++){
        non_terminals.insert(pb[i][0]);
    }
    for(int row=0; row<n; row++){
        for(int col=0; col<10; col++){
            if('a'<=pb[row][col] && pb[row][col]<='z'){
                terminals.insert(pb[row][col]);
            }
        }
    }
    
    cout<<"----Finding the First--------"<<endl;
    cout<<"Enter \"$\" to stop"<<endl;
    char temp;
    do{
        cout<<"Enter the term to find the first-";
        cin>>temp;
        if(terminals.find(temp)!=terminals.end()){
            cout<<temp;
        }else if(non_terminals.find(temp)!=non_terminals.end()){
            for(i=0; i<n; i++){
                if(pb[i][0]==temp){
                    break;
                }
            }
            //unordered_set<char> s;
            first(temp, i, 0);
        }else if(temp!='$'){
            cout<<"Not a valid term";
        }
        cout<<endl;
    }while(temp!='$');

    return 0;
}